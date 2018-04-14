//Create Time: 2018-04-14 10:17:36
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
const int N=111;
const int M=40009;
const double eps=1e-9;
pii an[N];
double dp[N][M];
double len(const pii &a){
    return sqrt(a.x*a.x+a.y*a.y+0.0);
}
int mi(const pii &a){
    return min(a.x,a.y);
}
void solve(){
    int n,K,s=0;scanf("%d%d",&n,&K);
    rep(i,0,n){
        scanf("%d%d",&an[i].x,&an[i].y);
        s+=2*an[i].x+2*an[i].y;
    }
    K-=s;
    rep(i,0,n)rep(j,0,M-5)dp[i][j]=-1;
    int t=mi(an[0]),up=t+1,newup;
    dp[0][0]=0;
    dp[0][t]=len(an[0])-mi(an[0]);
    rep(i,1,n){
        newup=up;
        rep(j,0,up)if(dp[i-1][j]>-0.5){
            t=j+mi(an[i]);
            chmax(dp[i][j],dp[i-1][j]);
            chmax(dp[i][t],dp[i-1][j]+len(an[i])-mi(an[i]));
            chmax(newup,t+1);
        }
        chmax(up,newup);
    }
    double mx=0;
    double KK=(double)K/2.0;
    rep(i,0,up)if(dp[n-1][i]>-0.5){
        if(i*2>K)break;
        if(i*2==K || i+dp[n-1][i]>=KK-eps){
            printf("%d\n",s+K);
            return;
        }
        chmax(mx,2*i+2.0*dp[n-1][i]);
    }
    printf("%f\n",mx+s);
}
int main(){
    int _,cas=0;cin>>_;
    while(_--){
        printf("Case #%d: ",++cas);
        solve();
    }
    return 0;
}
