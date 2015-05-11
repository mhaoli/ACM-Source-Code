#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const int Max_N = 1111;
const long long mod = 100007;
char str[1111];
int dp[Max_N][Max_N], f[Max_N][Max_N], g[Max_N][Max_N];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
void add(int &a, int t1, int t2, int t3) {
        add(a, t1); add(a, t2); add(a, t3);
}
int main() {
        int _, cas = 0; 
        scanf("%d", &_);
        for(; _--; ) {
                scanf("%s", str);
                int n = strlen(str);
                memset(dp, 0, sizeof dp);
                memset(f, 0, sizeof f);
                memset(g, 0, sizeof g);
                for(int i = 0, tmp; i < n; ++i) {
                        dp[i][i] = f[i][i] = g[i][i] = 1;
                        tmp = str[i] == str[i+1];
                        dp[i][i+1] = 2 + tmp;
                        f[i][i+1] = 1 + tmp;
                        g[i][i+1] = 1 + tmp;
                }
                for(int l = 3, i, j; l <= n; ++l) {
                        for(i = 0, j = l - 1; j < n; ++i, ++j) {
                                //out(j);
                                //out(f[i][j-1]); out(g[i+1][j]); out(dp[i+1][j-1]);
                                add(dp[i][j], f[i][j-1], g[i+1][j], dp[i+1][j-1]);
                                //out(dp[i][j]);
                                f[i][j] = f[i][j-1];
                                g[i][j] = g[i+1][j];
                                if(str[i] == str[j]) {
                                        add(f[i][j], dp[i+1][j-1] + 1);
                                        add(g[i][j], dp[i+1][j-1] + 1);
                                        add(dp[i][j], dp[i+1][j-1] + 1);
                                }
                        }
                }
                //for(int i = 0; i < n; ++i) {
                        //for(int j = 0; j < n; ++j) printf("%d ", dp[i][j]);
                        //puts("");
                //}
                printf("Case #%d: %d\n", ++cas, dp[0][n-1]);
        }
        return 0;
}
