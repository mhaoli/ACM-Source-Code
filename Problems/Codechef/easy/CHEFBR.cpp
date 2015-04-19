#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const long long mod = 7 + (int)1e9;
int f[105][105], sing[105][105], g[105][105], s[105], a[105];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
bool check(int l, int r) {
        return a[l] < 0 && a[r] > 0 && !(a[l]+a[r]);
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        for(int i, j, k, l = 2; l <= n; ++l) {
                for(i = 0, j = l-1; j < n; ++i, ++j) {
                        if(check(i, j)) {
                                sing[i][j] = 1; add(sing[i][j], g[i+1][j-1]);
                                f[i][j] = sing[i][j];
                        }
                        for(k = i; k <= j+1; ++k) s[k] = 0;
                        for(k = j; k > i; --k) s[k] = f[k][j], add(s[k], s[k+1]);
                        for(k = i; k < j; ++k) {
                                add(f[i][j], (long long)sing[i][k] * s[k+1] % mod);
                        }

                        g[i][j] = g[i+1][j-1];
                        add(g[i][j], f[i][j]);
                        for(k = j-1; k > i; --k) {
                                add(g[i][j], f[i][k]);
                                add(g[i][j], f[k][j]);
                        }
                }
        }
        add(g[0][n-1], 1);
        printf("%d\n", g[0][n-1]);
        return 0;
}
