#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void RD(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
const long long mod = 1e9 + 7;
int _;
bool v[1<<20];
int main() {
        long long p, k;
        cin >> p >> k;
        //if(!k) return cout << pow_mod(p, p-1, mod), 0;

        int cnt = 0;
        long long ans = 1;
        for(int i = 0; i < p; ++i) if(!v[i]){
                for(long long j = i; !v[j]; j = j * k % p) {
                        v[j] = 1;
                }
                if(i * k % p == i) {
                        ++cnt;
                } else ans = ans * p % mod;
        }
        ans = ans * pow_mod(cnt, cnt, mod) % mod;
        cout << ans;
        return 0;
}
