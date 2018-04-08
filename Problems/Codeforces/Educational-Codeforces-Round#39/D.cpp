//Create Time: 2018-03-15 23:09:02
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
#define TST(x) std::cout<<(x)<<" "
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
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
int dp[505][505],cnt[505][505],an[505],tn[505];
char s[505];
int main(){
    mem(dp,127);
    mem(cnt,127);
    int temp=dp[0][0];
    int n,m,K;cin>>n>>m>>K;
    rep(i,0,n){
        scanf("%s",s);
        int top=0;
        rep(j,0,m)if(s[j]=='1')an[top++]=j;
        rep(j,0,top)rep(k,j,top)chmin(cnt[i][top-k+j-1],an[k]-an[j]+1);
        chmin(cnt[i][top],0);
        tn[i]=top+1;
    }
    rep(i,0,tn[0])dp[0][i]=cnt[0][i];
    rep(i,0,n-1)rep(j,0,K+1)if(dp[i][j]!=temp){
        rep(k,0,tn[i+1]) if(j+k<=K) chmin(dp[i+1][j+k],dp[i][j]+cnt[i+1][k]);
    }
    int ans=temp;
    rep(i,0,K+1)chmin(ans,dp[n-1][i]);
    cout<<ans<<endl;
    return 0;
}
