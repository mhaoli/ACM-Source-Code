#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
const long long inf = 1e18;
const int Max_N = 1e5 + 9;
int idx[1<<17];
int col[Max_N];
long long cnt[Max_N][30];
long long C[30][30], S[1<<16][30], dp[1<<16], Sum[30];
int _;
void solve() {
        int n, K;
        scanf("%d%d", &n, &K);

        //memset
        for(int i = 0; i < K; ++i) {
                Sum[i] = 0;
                for(int j = 0; j < K; ++j) {
                        C[i][j] = 0;
                }
        }

        for(int i = 0, j; i < (1 << K); ++i) {
                for(j = 0; j < K; ++j) {
                        S[i][j] = 0;
                }
        }
        
        for(int i = 0, j; i < n; ++i) {
                scanf("%d", col + i);
                --col[i];

                for(j = 0; j < K; ++j) cnt[i][j] = 0;
        }

        for(int i = 0, j; i < n; ++i) {
                for(j = 0; j < K; ++j) {
                        C[col[i]][j] += cnt[i-1][j];
                }
                for(j = 0; j < K; ++j) {
                        cnt[i][j] = cnt[i-1][j];
                }
                ++cnt[i][col[i]];
        }

        for(int i = 0, j; i < K; ++i) {
                Sum[i] = 0;
                for(j = 0; j < K; ++j) if(i != j){
                        Sum[i] += C[i][j];
                }
        }

        for(int i = 0, j, k, t; i < (1 << K); ++i) {
                for(j = 0; j < K; ++j) {
                        S[i][j] = Sum[j];
                        for(k = i; k; k ^= t) {
                                t = k & (-k);
                                S[i][j] -= C[j][idx[t]];
                        }
                }
        }

        for(int i = 0; i < (1 << K); ++i) dp[i] = inf;
        dp[0] = 0;
        for(int i = 0, j; i < (1 << K); ++i) {
                for(j = 0; j < K; ++j) if(!(i & (1 << j))) {
                        chmin(dp[i|(1<<j)], dp[i] + S[i][j]);
                }
        }
        std::cout << dp[(1 << K) - 1] << "\n";

        //for(int i = 0; i < n; ++i) {
                //for(int j = 0; j < K; ++j) printf("%I64d ", cnt[i][j]);
                //puts("");
        //}

        //for(int i = 0; i < K; ++i) {
                //printf("%I64d ", Sum[i]);
        //}
//
        //puts("");
}
int main() {
        for(int i = 0, t = 1; i < 16; ++i, t <<= 1) idx[t] = i;

        for(scanf("%d", &_); _--; ) {
                static int cas = 0;
                std::cout << "Case #" << cas << ": ";
                solve();
        }
        return 0;
}
