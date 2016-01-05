#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
using namespace std;
/****head****/
int _;
int an[1<<18];
int main() {
        int n, sum = 0;
        cin >> n;
        for(int i = 0; i < n; ++i) {
                scanf("%d", an + i);
                sum += an[i];
        }
        if(sum == (sum/n) * n) {
                int t = sum / n, ans = 0;
                for(int i = 0; i < n; ++i) {
                        if(an[i] > t) ans += an[i] - t;
                }
                cout << ans;
        } else {
                int t = sum / n;
                int t1 = 0, t2 = 0;
                for(int i = 0; i < n; ++i) {
                        if(an[i] > t+1) {
                                t1 += an[i] - t - 1;
                        } else if(an[i] < t) {
                                t2 += t - an[i];
                        }
                }
                cout << max(t1, t2);
        }
        return 0;
}
