//Create Time: 2018-04-12 22:07:49
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
const int N=(int)2e5+9;
const int mod=(int)1e9+7;
int an[N],fa[N];
ll dp[N][2],df[N][2];
vi eg[N];
void dfs1(int x,int f){
    fa[x]=f;
    dp[x][1]=1;dp[x][0]=0;
    for(int y: eg[x])if(y!=f){
        dfs1(y,x);
        dp[x][1]=(dp[x][1]+dp[y][0])%mod;
        dp[x][0]=(dp[x][0]+dp[y][1])%mod;
    }
}
ll ans;
void dfs2(int x){
    int f=fa[x];
    if(x){
        df[x][1]=(df[f][0]+dp[f][0]+mod-dp[x][1]+1ll)%mod;
        df[x][0]=(df[f][1]+dp[f][1]+mod-dp[x][0]+mod-1ll)%mod;
    }
    for(int y: eg[x])if(y!=f){
        dfs2(y);

        ans+=(dp[x][0]+mod-dp[y][1])%mod * dp[y][1] % mod * (mod-an[x]) % mod;
        ans%=mod;
        ans+=(dp[x][1]-1+mod-dp[y][0])%mod * dp[y][0] % mod * an[x] % mod;
        ans%=mod;
        // TST(x);TST(y);OUT(ans);
    }

    // OUT(ans);
    ans+=2 * dp[x][0]*df[x][0] % mod * (mod-an[x]) % mod;
    ans%=mod;
    ans+=2 * dp[x][1]*df[x][1] % mod * an[x] % mod;
    ans%=mod;
    // TST(x);OUT(ans);
}
int main(){
    int n;scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",an+i);
        if(an[i]<0)an[i]+=mod;
    }

    rep(i,0,n-1){
        int u,v;scanf("%d%d",&u,&v);--u;--v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    dfs1(0,-1);
    df[0][0]=0;df[0][1]=1;
    dfs2(0);

    // rep(i,0,n)TST(i),OUT(fa[i]);
    // rep(i,0,n){
        // TST(i);TST(dp[i][0]);TST(dp[i][1]);TST(df[i][0]);OUT(df[i][1]);
    // }

    rep(i,0,n)ans=(ans+mod-an[i])%mod;
    cout<<ans<<endl;
    return 0;
}
