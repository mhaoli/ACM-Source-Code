#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int a[1111], n;
bool check(int up) {
        for(int i = 1, j, tmp; i <= up; ++i) {
                tmp = 0;
                for(j = n-1; j >= 0 && a[j] > i; --j) {
                        tmp += (a[j] - 1) / i;
                        if(tmp + i > up) break;
                }
                if(tmp + i <= up) return 1;
        }
        return 0;
}
int main() {
        freopen("my.out","w",stdout);
        int _, cas = 0;
        scanf("%d", &_);
        while(_--) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) scanf("%d", a + i);
                std::sort(a, a + n);
                int ans = a[n-1];
                for(int l = 1, r = a[n-1], mid; l <= r; ) {
                        mid = (l + r) >> 1;
                        if(check(mid)) ans = std::min(ans, mid), r = mid - 1;
                        else l = mid + 1;
                }
                printf("Case #%d: %d\n", ++cas, ans);
        }
        return 0;
}
