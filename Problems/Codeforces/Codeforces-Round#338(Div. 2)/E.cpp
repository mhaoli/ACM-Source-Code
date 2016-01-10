#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
int _;
int main() {
        ll n; rd(n);
        if(n == 0) return puts("0 0"), 0;

        ll res = 0;
        {
                ll l = 1, r = 1e9, mid;
                while(l <= r) {
                        mid = l + r >> 1;
                        if((mid+1) * mid * 3 < n) {
                                res = mid;
                                l = mid + 1;
                        } else r = mid - 1;
                }
        }

        n -= 3 * res * (res + 1);
        ll l = res + 1;

        auto ans = mp(-1, -1);
        if(n <= l) ans = mp(2*l-n, 2*n);
        else if(n <= 2*l) n -= l, ans = mp(l-2*n, 2*l);
        else if(n <= 3*l) n -= 2*l, ans = mp(-l-n, 2*l-2*n);
        else if(n <= 4*l) n -= 3*l, ans = mp(-2*l+n, -2*n);
        else if(n <= 5*l) n -= 4*l, ans = mp(-l+2*n, -2*l);
        else n -= 5*l, ans = mp(l+n, -2*l+2*n);
        cout << ans.x << " " << ans.y;
        return 0;
}
