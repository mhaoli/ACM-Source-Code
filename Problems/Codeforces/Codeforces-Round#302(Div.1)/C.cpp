#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
const int inf = ~0u>>1;
int _;
int cost[22][22], a[22][22];
int dp[1<<20], f[22][22], g[22][22];
char s[22][22], idx[1<<20];;
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1, j = 0; j < n; ++j, i <<= 1) {
                idx[i] = j;
        }

        for(int i = 0; i < n; ++i) {
                scanf("%s", s[i]);
        }
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                        scanf("%d", &a[i][j]);
                }
        }
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                        int mx = 0;
                        for(int k = 0; k < n; ++k) if(s[i][j] == s[k][j]) {
                                g[i][j] |= 1 << k;
                                cost[i][j] += a[k][j];
                                chmax(mx, a[k][j]);
                        }
                        cost[i][j] -= mx;
                }
        }
        memset(dp, 127, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i < (1 << n); ++i) {
                int t = idx[i & (-i)];
                for(int j = 0; j < m; ++j) {
                        chmin(dp[i], dp[i ^ (1<<t)] + a[t][j]);
                        chmin(dp[i], dp[i & (i ^ g[t][j])] + cost[t][j]);
                }
        }
        printf("%d\n", dp[(1 << n) - 1]);
        return 0;
}
