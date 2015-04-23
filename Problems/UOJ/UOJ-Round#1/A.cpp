#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e6;
const int Max_M = 9 + (int)1e6;
int cnt[Max_M];
int an[Max_N];
int main() {
        int n, mx = 0;
        long long ans = 0, tmp, sum = 0;
        scanf("%d", &n);
        for(int i = 0, t; i < n; ++i) {
                scanf("%d", &t);
                ++cnt[t];
                mx = std::max(mx, t);
                sum += t;
        }
        for(int i = 1; i <= mx + 1; ++i) cnt[i] += cnt[i-1];
        for(int i = 2, j, l, r; i <= mx; ++i) {
                tmp = 0;
                for(j = 1; j * i <= mx; ++j) {
                        l = j * i - 1; r = i * (j + 1);
                        if(r > mx) r = mx + 1;
                        tmp += (long long)j * (cnt[r-1] - cnt[l]);
                }
                tmp *= i - 1;
                if(ans < tmp) ans = tmp;
        }
        printf("%lld\n", sum - ans);
        return 0;
}
