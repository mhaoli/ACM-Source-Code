//Create Time: 2018-04-13 15:52:16
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
const ll M=(ll)1e18;
const int N=111;
ll sf[N],dn[N],L[N],st[N];
void down(int dep){
    if(dn[dep]){
        sf[dep]=(sf[dep]+dn[dep])%L[dep];
        dn[dep+1]=(dn[dep+1]+dn[dep]*2)%L[dep+1];
        dn[dep]=0;
    }
}
ll dfs(int dep,ll x){
    down(dep);
    ll pos;
    if(st[dep]+L[dep]<=x){
        pos=dfs(dep+1,x);
        ll tx=(pos-sf[dep])%L[dep];
        if(tx<0)tx+=L[dep];
        printf("%lld ",tx+st[dep]);
        return pos/2;
        
    } else {
        printf("%lld ",x);
        pos=x-st[dep];
        pos=(pos+sf[dep])%L[dep];
        if(pos<0)pos+=L[dep];
        return pos/2;
    }
}
int main(){
    for(ll l=0,i=2,t=1;i<=M*4;++l,i<<=1,t<<=1){
        st[l]=t;
        L[l]=t;
    }
    int q;scanf("%d",&q);
    while(q--){
        int ty;scanf("%d",&ty);
        if(ty==1){
            ll x,K;scanf("%lld%lld",&x,&K);
            int len;ll t;
            for(len=0,t=2;t<=x;t<<=1,len++);
            sf[len]=(sf[len]+K)%L[len];
        } else if(ty==2){
            ll x,K;scanf("%lld%lld",&x,&K);
            int len;ll t;
            for(len=0,t=2;t<=x;t<<=1,len++);
            dn[len]=(dn[len]+K)%L[len];
        } else{
            ll x; scanf("%lld",&x);
            dfs(0,x);
            puts("");
        }
    }
    return 0;
}
