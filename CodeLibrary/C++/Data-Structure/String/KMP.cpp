/*
 * Author:  Plumrain
 * Created Time:  2014-03-11 22:48
 * File Name: KMP.cpp
 */

#define clr(x,y) memset(x, y, sizeof(x))
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)

//use : match (s1, s2);

void fail (char *s, int *f){
    f[0] = f[1] = 0;
    int n = strlen(s);
    repf (i, 1, n-1){
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[j] == s[i] ? j+1 : 0;
    }
}

int match(char *s1, char *s2){         //return the position of the first s2[] in s1[]
    fail (s2, f);
    int n = strlen(s1), m = strlen(s2), j = 0;
    repf (i, 0, n-1){
        while (j && s1[i] != s2[j]) j = f[j];
        if (s1[i] == s2[j]) ++ j;
        if (j == m) return;
    }
}
