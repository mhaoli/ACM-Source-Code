//Create Time: 2017-12-17 15:24:28
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
typedef pair<int, ll> pil;
vector<pii> dir;
ll pow_int(ll x,int n){
    ll ans=1;
    while(n--)ans*=x;
    return ans;
}
int calc(int n, ll s){
    if(2*n-1<s) return 0;
    int l,r;
    if(1+n>=s){
        l=1;r=s-1;
    }else{
        l=s-n;r=n;
    }
    int cnt=r-l+1;
    return cnt/2;
}
int main(){
    rep(i,1,10)dir.pb(pii(i,pow_int(10,i)-1));
    reverse(all(dir));
    // for(auto &i: dir)TST(i.x),OUT(i.y);
    int n;cin>>n;
    if(n<5){
        printf("%d\n",n*(n-1)/2);
        return 0;
    }
    int L,suf;
    for(auto&i: dir){
        if(2*n-1>=i.y){
            L=i.x;suf=i.y;
            break;
        }
    }
    // TST(L); OUT(suf);
    int ans=0;
    rep(i,0,9){
        ans+=calc(n,suf+i*pow_int(10,L));
    }
    cout<<ans<<endl;
    return 0;
}
