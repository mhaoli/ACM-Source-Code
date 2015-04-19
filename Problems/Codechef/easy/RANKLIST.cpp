#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int main() {
        int _; Read(_);
        long long sum, tmp;
        for(int n; _--; ) {
                Read(n); Read(sum);
                int ans = n;
                for(int i = n; i; --i) {
                        tmp = sum - (i + 1ll) * i / 2;
                        if(tmp < 0) continue;
                        if(tmp >= (n - i) && tmp <= (long long)(n - i) * i) {
                                ans = n - i; break;
                        }
                }
                printf("%d\n", ans);
        }
        return 0;
}
