//Create Time: 2018-01-05 23:45:32
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
long long llmul(long long a, long long b, long long MX=LLONG_MAX){if(a>MX/b)return MX;else return a*b;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
/****head****/
const ll N=(ll)1e18;
const int M=(int)5e6 + 9;
int n;
void dfs(vi &pn,vector<ll> &ans,int p,ll v){
    if(p==SZ(pn)){
        ans.pb(v);
        return;
    }
    while(1){
        dfs(pn,ans,p+1,v);
        v=llmul(v,pn[p]);
        if(v>N)return;
    }
}
ll count(vector<ll> &a, vector<ll> &b, ll v){
    ll cnt=0;
    rep(i,0,SZ(a)){
        cnt+=upper_bound(all(b),v/a[i])-b.begin();
    }
    return cnt;
}
int main(){
    cin>>n;
    vi an,bn;
    rep(i,0,n){
        int t; cin>>t;
        if(i&1)an.pb(t);
        else bn.pb(t);
    }
    vector<ll> c,d;
    dfs(an,c,0,1ll);
    // puts("________________");
    dfs(bn,d,0,1ll);

    sort(all(c));
    sort(all(d));

    // puts("________________");
    // rep(i,0,SZ(c))TST(c[i]);puts("");
    // rep(i,0,SZ(d))TST(d[i]);puts("");
    // puts("________________");
    // OUT(SZ(c));
    // OUT(SZ(d));

    ll l=1,r=N,mid,ans=1,K;
    cin>>K;
    while(l<=r){
        mid=(l+r)>>1;
        if(count(c,d,mid)>=K){
            r=mid-1;
            ans=mid;
        } else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
