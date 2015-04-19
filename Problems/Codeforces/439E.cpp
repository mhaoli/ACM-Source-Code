#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define div aaaa1111
const int Max_N = 9 + (int)1e5;
const long long mod = 7 + (int)1e9;
int fac[Max_N], fac_inv[Max_N], inv[Max_N], clk, ans[Max_N], flag[Max_N];
std::vector<int> div[Max_N];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
void init(int n) {
        fac_inv[0] = fac[0] = 1;
        for(int i = 1, j; i <= n; ++i) {
                for(j = i<<1; j < n; j += i) div[j].push_back(i);
                if(i != 1) inv[i] = (long long)(mod - mod / i) * inv[mod%i] % mod, fac[i] = (long long)fac[i-1] * i % mod;
                else inv[i] = fac[i] = 1;
        }
        fac_inv[1] = inv[1];
        for(int i = 2; i <= n; ++i) {
                fac_inv[i] = (long long)fac_inv[i-1] * inv[i] % mod;
        }
}
int C(int n, int m) {
        long long ret = fac[n];
        ret = ret * fac_inv[m] % mod;
        ret = ret * fac_inv[n-m] % mod;
        return (int)ret;
}
int solve(int n, int m) {
        if(n < m) return 0;
        if(n == m) return 1;
        int &ret = ans[n];
        if(flag[n] == clk) return ret;
        flag[n] = clk;
        ret = C(n-1, m-1);
        snuke(it, div[n]) {
                ret -= solve(*it, m);
                if(ret < 0) ret += mod;
        }
        return ret;
}
int main() {
        init(Max_N - 5);
        int nq; scanf("%d", &nq);
        for(int n, m; nq--;) {
                scanf("%d%d", &n, &m);
                ++clk;
                printf("%d\n", solve(n, m));
        }
        return 0;
}
