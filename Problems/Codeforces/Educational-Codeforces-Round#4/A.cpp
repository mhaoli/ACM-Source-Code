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
int dp[200], pre[200];
int main() {
        int n, p, q;
        string s;
        cin >> n >> p >> q >> s;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
                if(i >= p && dp[i-p]) {
                        dp[i] = dp[i-p] + 1;
                        pre[i] = p;
                } else if(i >= q && dp[i-q]) {
                        dp[i] = dp[i-q] + 1;
                        pre[i] = q;
                }
        }
        if(dp[n]) {
                printf("%d\n", dp[n]-1);
                int p = n;
                vector<string> ans;
                while(p) {
                        ans.push_back(s.substr(p-pre[p], pre[p]));
                        p -= pre[p];
                }
                for(int i = SZ(ans)-1; i >= 0; --i) cout << ans[i] << endl;
        } else {
                puts("-1");
        }
        return 0;
}
