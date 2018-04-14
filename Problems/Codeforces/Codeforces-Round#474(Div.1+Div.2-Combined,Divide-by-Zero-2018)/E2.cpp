//Create Time: 2018-04-13 11:14:24
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define TST(x) std::cout<<(#x)<<":"<<(x)<<" "
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define DEBUG
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long powmod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const ll mod=(int)1e9+7;
const int N=(int)2e5+9;
int val[N];
ll dp[N],f[N][2],cnt[N][2],ans;
vi eg[N];
void dfs(int u,int fa){
    cnt[u][1]=1;
    dp[u]=f[u][1]=val[u];
    for(int v:eg[u])if(v!=fa){
        dfs(v,u);
        
        rep(p,0,2){
            // TST(v);TST(cnt[u][p^1]);TST(f[v][p]);TST(f[u][p]);OUT(cnt[v][p^1]);
            dp[u]=(dp[u]+cnt[u][p^1]*f[v][p]*2ll+f[u][p]*cnt[v][p^1]*2ll)%mod;
        }
        rep(p,0,2){
            cnt[u][p]=(cnt[u][p]+cnt[v][p^1])%mod;
            f[u][p]=(f[u][p]+f[v][p^1]+cnt[v][p^1]*(2ll*p-1ll)*val[u])%mod;
        }
    }
    // TST(u);TST(cnt[u][0]);TST(cnt[u][1]);OUT(dp[u]);
    ans=(ans+dp[u])%mod;
}
int main(){
    int n;scanf("%d",&n);
    rep(i,0,n)scanf("%d",val+i);
    rep(i,0,n-1){
        int u,v;
        scanf("%d%d",&u,&v);--u;--v;
        eg[u].pb(v);eg[v].pb(u);
    }
    dfs(0,-1);
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}
