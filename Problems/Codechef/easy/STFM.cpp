#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
long long mod;
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
const int Max_N = 9 + (int)1e7;
long long fac[Max_N], tmp;
int sum[Max_N];
long long calc(long long t) {
        tmp = t % mod;
        if(t & 1) return (t + 1) / 2 % mod * tmp % mod * tmp % mod;
        else return (t + 1) % mod * (t / 2 % mod) % mod * tmp % mod;
}
int main() {
        int n;
        Read(n); Read(mod);
        fac[0] = 1; sum[0] = 0;
        for(int i = 1; i < mod; ++i) {
                fac[i] = fac[i-1] * i % mod;
                sum[i] = sum[i-1];
                add(sum[i], fac[i] * i % mod);
        }

        long long t;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
                Read(t);
                add(ans, calc(t));
                if(t >= mod) t = mod - 1;
                add(ans, sum[t]);
        }
        printf("%d\n", ans);
        return 0;
}
