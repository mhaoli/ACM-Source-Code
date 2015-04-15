#include<bits/stdc++.h>
const int N = 9 + (int)2e5;
char s[N];
int r[N<<1], le[N<<1], ri[N<<1];
int Manacher (char *str, int *len, int n){  //len[i] means the max palindrome length centered i/2
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
int main(){
    scanf ("%s", s);
    int n = strlen (s);
    Manacher (s, r, n);
    for (int i = 0, j = 0; i < (n<<1); ++ i){
        for( ; j <= ((i + r[i]) >> 1); ++ j)
            le[j] = (j<<1) - i + 1;
    }
    for (int i = (n<<1)-1, j = i; i >= 0; -- i){
        for ( ; j >= ((i - r[i] + 1) >> 1); -- j)
            ri[j] = i - (j<<1) + 1;
    }
    int res = 0;
    for (int i = 0; i < n-1; ++ i) res = std::max (res, le[i] + ri[i+1]);
    printf ("%d\n", res);
    return 0;
}
