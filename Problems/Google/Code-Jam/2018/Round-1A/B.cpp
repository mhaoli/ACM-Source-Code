//Create Time: 2018-04-14 09:32:17
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
struct oo{
    ll m,s,p;
};
const int N=1111;
const ll M=(ll)2e18;
oo an[N];
ll K; int n,m;
ll stk[N];
bool ok(ll up){
    int top=0;
    ll t=0;
    rep(i,0,n){
        t=(up-an[i].p)/an[i].s;
        if(t<0)t=0;
        if(t>an[i].m)t=an[i].m;
        stk[top++]=t;
    }
    sort(stk,stk+top,greater<ll>());
    // rep(i,0,n)TST(stk[i]);puts("");
    ll s=0;
    rep(i,0,m)s+=stk[i];
    return s>=K;
}
ll solve(){
    cin>>m>>K>>n;
    rep(i,0,n){
        ll t1,t2,t3;
        scanf("%lld%lld%lld",&t1,&t2,&t3);
        an[i]=oo{t1,t2,t3};
    }
    ll ans=M,l=0,r=M-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return ans==M?-1:ans;
}
int main(){
    int _,cas=0;scanf("%d",&_);
    while(_--){
        printf("Case #%d: %lld\n",++cas,solve());
    }
    return 0;
}
