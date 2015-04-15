#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e7;
const long long mod = 7 + (int)1e9;
bool check[Max_N];
int prm[Max_N], mo[Max_N], G[Max_N], mi[Max_N];
inline int mobius(int n) {
        memset(check, 0, sizeof check);
        mo[1] = 1;
        int tot = 0;
        for(int j, i = 2; i <= n; ++i) {
                if (!check[i]) prm[tot++] = i, mo[i] = -1;
                for (j = 0; j < tot; ++ j) {
                        if (i * prm[j] > n) break;
                        check[i*prm[j]] = 1;
                        mi[i*prm[j]] = prm[j];
                        if (i % prm[j] == 0){
                                mo[i*prm[j]] = 0; break;
                        }
                        else mo[i*prm[j]] = -mo[i];
                }
        }
        return tot;
}
inline int pow_mod(long long p, int n) {
        long long ret = 1;
        for(; n; n >>= 1) {
                if(n & 1) ret = ret * p % mod;
                p = p * p % mod;
        }
        return (int)ret;
}
inline void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
int n, m, sum[Max_N];
int solve(int R) {
        if(R == 0) return 0;
        int ans = G[m], up = m / (R + 1);
        for(int j, i = 1; i <= up; ++i) if(mo[i]){
                for(j = i * (R + 1); j <= m; j += i) {
                        if(mo[i] > 0) add(ans, mod - G[m/j]);
                        else add(ans, G[m/j]);
                }
        }
        return ans;
}
int main() {
        int tot = mobius(Max_N - 5);
        int _; scanf("%d", &_);
        for(int l, r; _--; ) {
                scanf("%d%d%d%d", &n, &m, &l, &r);
                G[1] = 1;
                for(int i = 2; i <= m; ++i) G[i] = check[i] ? (long long)G[mi[i]] * G[i/mi[i]] % mod : pow_mod(i, n);
                //for(int i = 1; i <= m; ++i) G[i] = pow_mod(i, n);
                printf("%d\n", (solve(r) - solve(l-1) + mod) % mod);
        }
        return 0;
}
