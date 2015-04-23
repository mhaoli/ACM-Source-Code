#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int n, an[20010];
int solve2() {
        int mx = 0, ret = 0;
        for(int i = 1; i < n; ++i) mx = std::max(mx, an[i-1] - an[i]);
        for(int i = 0; i < n-1; ++i) {
                ret += std::min(mx, an[i]);
        }
        return ret;
}
int solve1() {
        int ret = 0;
        for(int i = 1; i < n; ++i) ret += std::max(0, an[i-1] - an[i]);
        return ret;
}
int main() {
        freopen("a.out","w",stdout);
        int _, cas = 0;
        scanf("%d", &_);
        while(_--) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) scanf("%d", an + i);
                printf("Case #%d: %d %d\n", ++cas, solve1(), solve2());
        }
        return 0;
}
