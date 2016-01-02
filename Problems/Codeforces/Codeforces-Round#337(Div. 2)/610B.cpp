#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
using namespace std;
int _;
const int Max_N = 200005;
int an[Max_N];
int mx1[Max_N], mx2[Max_N], pos1[Max_N], pos2[Max_N];
int main() {
        int n;
        scanf("%d", &n);
        mx1[0] = 1<<30;
        for(int i = 1; i <= n; ++i) {
                scanf("%d", an + i);
                if(an[i] < mx1[i-1]) {
                        mx1[i] = an[i];
                        pos1[i] = i;
                } else {
                        pos1[i] = pos1[i-1];
                        mx1[i] = mx1[i-1];
                }
        }

        mx2[n+1] = mx1[0];
        for(int i = n; i; --i) {
                if(an[i] <= mx2[i+1]) {
                        mx2[i] = an[i];
                        pos2[i] = i;
                } else {
                        mx2[i] = mx2[i+1];
                        pos2[i] = pos2[i+1];
                }
        }

        long long ans = 0, tmp;
        for(int i = 1; i <= n; ++i) {
                tmp = n - i + 1;
                if(mx2[i]-1 < mx1[i-1]) {
                        tmp += (mx2[i]-1ll) * n;
                        tmp += pos2[i] - 1;
                } else {
                        tmp += 1ll * mx1[i-1] * n;
                        tmp += pos1[i] - 1;
                }
                chmax(ans, tmp);
        }
        std::cout << ans;
        return 0;
}
