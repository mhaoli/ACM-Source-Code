#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
int a[Max_N], tmp[3];
int main() {
        int _; Read(_);
        for(int n; _--; ) {
                Read(n);
                memset(a, 0, sizeof a);
                for(int i = 0, t; i < n; ++i) {
                        Read(t); a[t]++;
                }
                memset(tmp, 0, sizeof tmp);
                tmp[2] = n;
                int ans = n;
                for(int i = 1; i < Max_N; ++i) {
                        tmp[0] += tmp[1];
                        tmp[2] -= (tmp[1] = a[i]);
                        ans = std::min(ans, tmp[0] + tmp[2]);
                }
                printf("%d\n", ans);
        }
        return 0;
}
