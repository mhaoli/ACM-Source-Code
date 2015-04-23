#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
char str[1111];
int main() {
        freopen("a.in","r",stdin);
        freopen("my.out","w",stdout);
        int _, n, cas = 0;
        scanf("%d", &_);
        while(_--) {
                scanf("%d%s", &n, str); ++n;
                int sum = 0, ans = 0;
                for(int i = 0; i < n; ++i) {
                        sum += str[i] - '0';
                        if(sum <= i) {
                                ans += i + 1 - sum;
                                sum = i + 1;
                        }
                }
                printf("Case #%d: %d\n", ++cas, ans);
        }
        return 0;
}
