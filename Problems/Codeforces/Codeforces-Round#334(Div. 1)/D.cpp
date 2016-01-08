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
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
struct pnt {
        ll a, b, c;
        pnt(){ }
        pnt(ll t1, ll t2, ll t3) : a(t1), b(t2), c(t3) { }
};
int _;
vector<pnt> p;
map<pair<ll,ll>, int> hs;
int main() {
        int n, cnt = 0;
        cin >> n;
        for(int i = 0, t1, t2, t3; i < n; ++i) {
                scanf("%d%d%d", &t1, &t2, &t3);
                if(t3) p.pb(pnt(t1, t2, t3));
                else ++cnt;
        }
        ll ans = cnt * (cnt-1ll) * (n-cnt) / 2ll;
        for(int i = 0; i < SZ(p); ++i) {
                hs.clear();
                pnt p1 = p[i];
                for(int j = i+1; j < SZ(p); ++j) {
                        pnt p2 = p[j];
                        ll t1 = p1.a*p1.a + p1.b*p1.b;
                        ll t2 = p2.a*p2.a + p2.b*p2.b;
                        ll a = p1.a*p1.c*t2 - p2.a*p2.c*t1;
                        ll b = p1.b*p1.c*t2 - p2.b*p2.c*t1;
                        ll d = __gcd(a, b);
                        a /= d; b /= d;
                        if(a < 0) a *= -1, b *= -1;
                        else if(a == 0) {
                                if(b < 0) b *= -1;
                        }
                        ans += hs[mp(a, b)];
                        ++hs[mp(a, b)];
                }
        }
        cout << ans;
}
