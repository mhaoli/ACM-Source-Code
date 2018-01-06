//Create Time: 2018-01-05 23:13:15
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
void calc(vector<int> &a,int n,int r){
    int mi=min(n-r+1,r);
    rep(i,0,mi)a[i]=i+1;
    int t=1;
    per(i,SZ(a),SZ(a)-mi){
        a[i]=t;++t;
    }
    rep(i,0,SZ(a))if(a[i]==0)a[i]=mi;
}
typedef pair<ll,pii> oo;
void test(vi &a, vi &b, int K){
    vi c;
    for(auto i:a) for(auto j:b) c.pb(i*j);
    sort(all(c),greater<int>());
    ll ans=0;
    rep(i,0,K)ans+=c[i];
    OUT(ans);
}
int main(){
    int n,m,r,K;
    scanf("%d%d%d%d",&n,&m,&r,&K);
    vector<int> a(n,0), b(m,0);
    calc(a,n,r);
    calc(b,m,r);

    // for(auto i:a) TST(i);puts("");
    // for(auto i:b) TST(i);puts("");

// #ifdef DEBUG
    // test(a,b,K);
// #endif

    sort(all(a),greater<int>());
    sort(all(b),greater<int>());

    // for(auto i:a) TST(i);puts("");
    // for(auto i:b) TST(i);puts("");

    set<oo> has;
    rep(i,0,SZ(a)){
        has.insert(oo(-1ll*a[i]*b[0],pii(i,0)));
    }
    ll ans=0;
    oo x,y;
    while(K--){
        x=*has.begin();
        has.erase(has.begin());
        ans-=x.x;
        if(x.y.y+1 < SZ(b)){
            y.y.x=x.y.x;
            y.y.y=x.y.y+1;
            y.x=-1ll*a[x.y.x]*b[y.y.y];
            has.insert(y);
        }
    }
    // OUT(ans);
    printf("%.11f\n",(ans+0.0)/((m-r+1ll)*(n-r+1ll)*1.0));
    return 0;
}
