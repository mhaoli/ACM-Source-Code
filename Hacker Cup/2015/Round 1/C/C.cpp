#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int mod = 1000000007;
int f[2009][2009], g[2009][2009][2];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
void init() {
        f[1][0] = 1;
        for(int i = 1, j; i <= 2000; ++i) {
                for(j = 0; j < i; ++j) if(f[i][j]){
                        add(f[i+1][j], f[i][j]);
                        if(i > j + 1) add(f[i][j+1], f[i][j]);
                }
        }
        g[0][1][1] = 1;
        for(int i, j = 1, k; j <= 2000; ++j) {
                for(i = 0; i <= j; ++i) for(k = 0; k < 2; ++k) {
                        if(i < j) add(g[i+1][j][0], g[i][j][k]);
                        add(g[i][j+1][1], g[i][j][k]);
                }
        }
}
int main() {
        freopen("winning_at_sports.txt","r",stdin);
        freopen("C.out","w",stdout);
        init();
        int _; scanf("%d", &_);
        for(int cas = 0, l, r, ans2; _--; ) {
                scanf("%d-%d", &l, &r);
                if(!r) ans2 = 1;
                else {
                        ans2 = 0;
                        for(int i = 0; i < r; ++i) add(ans2, g[i][r][1]);
                }
                printf("Case #%d: %d %d\n", ++cas, f[l][r], ans2);
        }
        return 0;
}
