#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 9 + (int)1e5;
char str[Max_N];
int map[Max_N];
int dp[Max_N][2];
int transform(int a, int b) {
        return map[a] != b;
}
int main() {
        int _; Read(_);
        map['-'] = 0; map['+'] = 1;
        for(int n, ans; _--; ) {
                scanf("%s", str); n = strlen(str);
                dp[0][map[str[0]]] = 0;
                dp[0][map[str[0]]^1] = 1;
                for(int i = 1, j; i < n; ++i) {
                        for(j = 0; j < 2; ++j) {
                                dp[i][j] = dp[i-1][j^1] + transform(str[i], j);
                        }
                }
                ans = std::min(dp[n-1][0], dp[n-1][1]);
                printf("%d\n", ans);
        }
        return 0;
}
