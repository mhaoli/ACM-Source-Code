#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const long long mod = 7 + (int)1e9;
const int Max_N = 9 + (int)1e5;
void fail (char *s, int *f){
    f[0] = f[1] = 0;
    int n = strlen(s);
    for(int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[j] == s[i] ? j+1 : 0;
    }
}

void match(char *s1, char *s2, int *f, int *vis){         
    fail (s2, f);
    int n = strlen(s1), m = strlen(s2), j = 0;
    for(int i = 0; i < n; ++i) {
        while (j && s1[i] != s2[j]) j = f[j];
        if (s1[i] == s2[j]) ++ j;
        if (j == m) vis[i] = 1;
    }
}
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
char s[Max_N], t[Max_N];
int f[Max_N], vis[Max_N], dp[Max_N], sum[Max_N];
int main() {
        scanf("%s%s", s, t);
        match(s, t, f, vis);
        int mx = -1, tmx, S = 0;
        if(vis[0]) dp[0] = sum[0] = 1, mx = 0;
        int n = strlen(s), m = strlen(t);
        //for(int i = 0; i < n; ++i) if(vis[i]) out(i);
        for(int j, i = 1, k; i < n; ++i) {
                if(vis[i]) {
                        tmx = i - m + 1;
                        if(mx > 0) add(S, (long long)sum[mx-1] * (tmx - mx) % mod);
                        for(j = tmx-1, k = 1; j >= mx; --j, ++k) add(S, (long long)k * dp[j] % mod);
                        mx = tmx;
                }
                if(mx >= 0) {
                        dp[i] = mx + 1;
                        add(dp[i], S);
                }
                sum[i] = sum[i-1];
                add(sum[i], dp[i]);
        }
        printf("%d\n", sum[n-1]);
        return 0;
}
