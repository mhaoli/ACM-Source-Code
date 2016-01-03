/*
 * Author:  Plumrain
 * Created Time:  2014/9/12 18:46:21
 * Algorithm: manacher
 */
//传入字符串str和长度n，返回数组len[]
//len[i]表示以i/2为圆心的最长回文子串的直径
//比如字符串babbaa，看作b.a.b.b.a.a
//相应的len[]为{1, 0, 3, 0, 1, 4, 1, 0, 1, 2, 1}
//str[N], len[N<<1];
int manacher (char *str, int *len, int n){  //len[i] means the max palindrome length centered i/2
    for (int i = 0; i < 2*n; ++ i) len[i] = 0;
    int mx = 0;
    for (int i = 0, j = 0, k; i < 2*n; i += k, j = std::max (j-k, 0)){
        while (i - j >= 0 && i + j + 1 < 2*n && str[(i-j) / 2] == str[(i+j+1) / 2]) ++ j;
        len[i] = j;
        mx = std::max (mx, j);
        for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; ++ k){
            len[i+k] = std::min (len[i - k], j - k);
        }
    }
    return mx;
}
