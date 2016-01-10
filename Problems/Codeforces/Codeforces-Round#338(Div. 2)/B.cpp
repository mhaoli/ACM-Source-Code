#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
int _;
int dp[1<<18];
vector<int> E[1<<18];
int main() {
        int n, m; rd(n); rd(m);
        for(int i = 0, t1, t2; i < m; ++i) {
                rd(t1); rd(t2); --t1; --t2;
                E[t1].pb(t2); E[t2].pb(t1);
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
                dp[i] = 1;
                for(auto it : E[i]) if(it < i){
                        chmax(dp[i], dp[it] + 1);
                }
                chmax(ans, 1ll * dp[i] * SZ(E[i]));
        }
        cout << ans;
        return 0;
}
