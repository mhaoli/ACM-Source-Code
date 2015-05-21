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
int _;
long long mod;
void add(int&a, int b) {
        a += b; if(a >= mod) a -= mod;
}
int dp[505][505], cnt[505];
int main() {
        int n, m, up;
        std::cin >> n >> m >> up >> mod;
        for(int i = 0; i < n; ++i) {
                scanf("%d", cnt + i);
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 0, j, k; i < n; ++i) {
                for(j = 0; j <= m; ++j) {
                        for(k = 0; k <= up; ++k) if(dp[j][k]){
                                if(k + cnt[i] <= up){
                                        add(dp[j+1][k+cnt[i]], dp[j][k]);
                                }
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i <= up; ++i) {
                add(ans, dp[m][i]);
        }
        printf("%d\n", ans);
        return 0;
}
