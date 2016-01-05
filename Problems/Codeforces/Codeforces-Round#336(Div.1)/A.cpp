#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
pair<int, int> an[1<<17];
int dp[1<<17];
int main() {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
                scanf("%d%d", &an[i].first, &an[i].second);
        }
        sort(an, an + n);
        
        memset(dp, 0, sizeof dp);
        int mx = 1;
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
                int p = an[i].first - an[i].second;
                pair<int, int> tmp = make_pair(p, 0);
                int pos = lower_bound(an, an + n, tmp) - an;
                if(--pos < 0) dp[i] = 1;
                else {
                        dp[i] = dp[pos] + 1;
                }
                chmax(mx, dp[i]);
        }
        printf("%d\n", n - mx);
        return 0;
}
