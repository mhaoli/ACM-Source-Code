/*
other: http://codeforces.com/contest/615/submission/15260890
   */
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
const ll mod = 1e9 + 7;

ll cnt[1<<18];

ll phi;

int main() {
        phi = mod - 1;
        int n; rd(n);
        while(n--) {
                int t; rd(t);
                ++cnt[t];
        }
        
        bool fg = 0;
        ll t = 1, td = 1, ans = 1, x;
        for(int i = 1; i <= 2e5; ++i) if(cnt[i]) {
                t = t * (cnt[i] + 1) % phi;

                if((cnt[i] & 1) && !fg) {
                        fg = 1;
                        td = td * ((cnt[i]+1) / 2) % phi;
                } else td = td * (cnt[i] + 1) % phi;
        }
        for(int i = 1; i <= 2e5; ++i) if(cnt[i]) {
                if(cnt[i] & 1) {
                        x = td * cnt[i] % phi;
                        ans = ans * pow_mod(i, x, mod) % mod;
                } else {
                        x = t * (cnt[i]/2) % phi;
                        ans = ans * pow_mod(i, x, mod) % mod;
                }
        }
        cout << ans;
        return 0;
}
