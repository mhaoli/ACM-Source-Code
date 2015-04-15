#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int tot, dig[111];
void init(int n) {
        for(tot = 0; n; n /= 10) dig[tot++] = n % 10;
}
int calc() {
        int ret = 0;
        for(int i = tot-1; i >= 0; --i) ret = ret * 10 + dig[i];
        return ret;
}
std::vector<int> ans;
int main() {
        freopen("cooking_the_books.txt","r",stdin);
        freopen("a.out","w",stdout);
        int _; scanf("%d", &_);
        for(int n, cas = 0; _--; ) {
                printf("Case #%d: ", ++cas);
                scanf("%d", &n);
                if(!n) {
                        puts("0 0"); continue;
                }
                init(n);
                ans.clear(); ans.push_back(n);
                for(int i = 0, j; i < tot; ++i) {
                        for(j = i+1; j < tot; ++j){
                                std::swap(dig[i], dig[j]);
                                if(dig[tot-1]) ans.push_back(calc());
                                std::swap(dig[i], dig[j]);
                        }
                }
                std::sort(ans.begin(), ans.end());
                printf("%d %d\n", ans[0], ans.back());
        }
        return 0;
}
