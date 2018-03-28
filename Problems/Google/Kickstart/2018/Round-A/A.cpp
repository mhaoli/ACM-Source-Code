//Create Time: 2018-03-18 13:12:31
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
const ll mod=1ll<<62;
int d[33],len;
void gao(ll x){
    len=0;
    while(x)d[len++]=x%10,x/=10;
}
ll get(){
    ll ret=0,t=1;
    rep(i,0,len)ret+=d[i]*t,t*=10;
    return ret;
}
ll up(){
    ll t=get();
    if(t==1)return 2;
    if(t==0)return 0;
    ll dig=pow_mod(10,len-1,mod),n=0;
    bool flag=0;
    per(i,len,0){
        n+=d[i]*dig;
        if(d[i]&1){
            n+=dig;
            flag=1;
            break;
        }
        dig/=10;
    }
    if(flag){
        gao(n);
        return up();
    }
    return get();
}
ll down(){
    ll t=get();
    if(t==1||t==0)return 0;
    ll dig=pow_mod(10,len-1,mod),n=0;
    bool flag=0;
    per(i,len,0){
        n+=d[i]*dig;
        if(d[i]&1){
            n-=1;
            flag=1;
            break;
        }
        dig/=10;
    }
    if(flag){
        gao(n);
        return down();
    }
    return get();
}
int main(){
    // OUT(mod>(1e18));
    int _,K=0;scanf("%d",&_);
    while(_--){
        ll n;cin>>n;
        gao(n);
        // OUT(up());
        ll ans=up()-n;
        gao(n);
        // OUT(down());
        chmin(ans,n-down());
        printf("Case #%d: %lld\n",++K,ans);
    }
    return 0;
}
