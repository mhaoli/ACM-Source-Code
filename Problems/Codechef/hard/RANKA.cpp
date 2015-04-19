#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
int n;
bool u, first;
void calc(int x, int y) {
        if(y == 10) y = 1, ++x;
        if(x == 10) return;
        if(!n) return;

        if(u) puts("0 0"), --n;
        u = 1;
        if(n == 0) return;
        printf("%d %d\n", x, y);
        if(--n == 0) return;
        calc(x, y + 1);
}
void dfs(int x, int y) {
        if(y == 10) y = 1, ++x;
        if(x == 10) return;
        if(!n) return;

        if(x == 9 && y == 9 && !first) {
                first = 1;
                puts("9 9"); --n;
                dfs(1, 1);
                return;
        }

        //if(x == 1 && y == 1) u = 1;
        //else u = 0;
        u = 0;
        calc(x, y + 1);
        if(!n) return;
        printf("%d %d\n", x, y);
        if(--n == 0) return;
        dfs(x, y + 1);
}
int main() {
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        scanf("%d", &n);
        //printf("%d\n", n);
        dfs(1, 1);
        return 0;
}
