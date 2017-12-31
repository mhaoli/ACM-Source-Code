//Create Time: 2017-12-29 13:21:07
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
int n,m;
int sta[1<<23];
bool connected[1<<23];
int main(){
    cin>>n>>m;
    if(m==n*(n-1)/2){
        puts("0");return 0;
    }
    rep(i,0,m){
        int u,v;
        scanf("%d%d",&u,&v); --u;--v;
        sta[1<<u]|=1<<v;
        sta[1<<v]|=1<<u;
    }
    rep(i,0,n)sta[1<<i]|=1<<i;
    rep(i,0,n)connected[1<<i]=1;
    int as=1<<n,ans=-1;
    rep(i,1,as)if(connected[i]){
        rep(j,0,n)if(i&(1<<j))sta[i]|=sta[1<<j];
        rep(j,0,n)if(sta[i]&(1<<j))connected[i|(1<<j)]=1;
        if(sta[i]+1==as){
            if(ans==-1||__builtin_popcount(ans)>__builtin_popcount(i))
                ans=i;
        }
    }
    // cout<<bitset<22>(sta[3])<<endl;
    // OUT(ans);
    cout<<__builtin_popcount(ans)<<endl;
    while(ans>0){
        int t=__builtin_ffs(ans);
        cout<<t<<" ";
        ans^=1<<(t-1);
    }
    return 0;
}
