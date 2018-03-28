//Create Time: 2018-03-28 14:01:45
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
int dp[2][11111];
pii an[11111];
int main(){
    int n,tl,tr,sum=0;
    scanf("%d%d%d",&n,&tl,&tr);
    rep(i,0,n)scanf("%d",&an[i].y),an[i].y=-an[i].y,sum-=an[i].y;
    rep(i,0,n)scanf("%d",&an[i].x);
    sort(an,an+n);
    int l=sum-tr,r=sum-tl;
    int ans=0,mx=0;
    mem(dp,-1);
    dp[0][0]=0;
    dp[0][-an[0].y]=0;
    if(an[0].x==1 && l<=-an[0].y && -an[0].y<=r) dp[0][-an[0].y]=1;
    mx=-an[0].y;
    int now=0,nxt=1;
    rep(i,0,n-1){
        // OUT(mx);
        rep(j,0,min(r,mx)+1)if(dp[now][j]!=-1){
            // TST(i);TST(j);OUT(dp[now][j]);
            chmax(dp[nxt][j],dp[now][j]);
            int t=0,height=j-an[i+1].y;;
            if(an[i+1].x && l<=height & height<=r)t=1;
            chmax(dp[nxt][height],dp[now][j]+t);
            chmax(mx,height);
        }
        swap(now,nxt);
    }
    rep(i,0,r+1)chmax(ans,dp[now][i]);
    cout<<ans<<endl;
    return 0;
}
