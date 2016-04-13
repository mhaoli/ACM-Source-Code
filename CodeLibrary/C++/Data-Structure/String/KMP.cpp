//match(s1, s2): return the position of the first s2[] in s1[]
//time: O(n + m)
void fail(int *s, int n, int *f) {
        f[0] = f[1] = 0;
        int j = 0;
        for(int i = 2; i <= n; ++i) {
                while(j && s[i-1] != s[j]) j = f[j];
                if(s[i-1] == s[j]) ++j;
                f[i] = j;
        }
}
int match(int*s, int n, int *p, int m, int *f) {
        fail(p, m, f);
        int j = 0;
        for(int i = 0; i < n; ++i) {
                while(j && s[i] != p[j]) j = f[j];
                if(s[i] == p[j]) ++j;
                if(j == m) return i - m + 1;
        }
        return -2;
}
