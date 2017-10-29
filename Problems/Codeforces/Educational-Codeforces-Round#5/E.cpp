//Create Time: 2017-10-13 15:34:28
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
using namespace std;
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define SZ(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define debug
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;
/****head****/
ll mod = (int)1e9 + 7;
ll calc(ll l, ll r) {
    if((l+r) % 2 == 0) {
        return (((l+r)/2) % mod) * ((r-l+1) % mod) % mod;
    } else {
        return (((l+r)) % mod) * ((r-l+1)/2 % mod) % mod;
    }
}
int main() {
    ll n, m; cin >> n >> m;
    ll ans = ((n%mod) * (m%mod)) % mod;
    ll mid = (ll)(sqrt(n)) + 1;
    //cout << mid << endl;
    ll r, l;
    for(ll i = 1; i <= mid && i <= m; ++i) {
        ans = (ans + mod - (i * ((n / i) % mod) % mod)) % mod;
        r = n / i; l = n / (i+1ll);
        r = min(r, m);
        l = max(l+1ll, mid+1ll);
        //cout << i << " " << l << " " << r << endl;
        if(l <= r) ans = (ans + mod - (i * calc(l,r) % mod)) % mod;
    }
    cout << ans << endl;
    return 0;
}
