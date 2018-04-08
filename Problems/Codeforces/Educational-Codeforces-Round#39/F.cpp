//Create Time: 2018-04-08 23:29:24
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
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const int N=111;
const ll mod=(int)1e9+7;
void add(int&a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
string s;
ll p2[N];
int dp[N][N][N];
int main(){
    int n,K;cin>>n>>K>>s;
    p2[0]=p2[1]=2;
    rep(i,2,K+1)p2[i]=p2[i-1]*p2[i-2]%mod;
    rep(i,0,n){
        if(s[i]=='0')dp[0][i][i]=1;
        else dp[1][i][i]=1;
    }
    rep(k,2,K+1) rep(i,0,n) rep(j,i,n){
        dp[k][i][j]=dp[k-1][i][j];
        add(dp[k][i][j],dp[k-2][i][j]);
        rep(t,i,j){
            add(dp[k][i][j],1ll*dp[k-1][i][t]*dp[k-2][t+1][j]%mod);
        }
        if(i==0)add(dp[k][i][j],dp[k-2][i][j]*(p2[k-1]+mod-1)%mod);
        if(j==n-1)add(dp[k][i][j],dp[k-1][i][j]*(p2[k-2]+mod-1)%mod);
    }
    cout<<dp[K][0][n-1]<<endl;
    return 0;
}
