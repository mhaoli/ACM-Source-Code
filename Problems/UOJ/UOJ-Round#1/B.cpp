#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/****head****/
const long long mod = 998244353;
int _;
int dp[15][1005][5005];
bool vis[15][1005][5005];
int an[1005];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
int main() {
        //freopen("a.out","w",stdout);
        int n, x;
        scanf("%d%d", &n, &x);
        for(int i = 0; i < n; ++i) {
                scanf("%d", an + i);
        }
        if(n == 1) return printf("%d %d\n", x % an[0], 1), 0;

        std::sort(an, an + n, std::greater<int>());
        int ans = -1, cnt = 0;
        for(int i = 0, up = x, j, k, tmp; i <= 13; ++i, up >>= 1) {
                if(!i) {
                        vis[0][0][x] = 1;
                        dp[0][0][x] = n-1;
                        if(x < an[0]) ++dp[0][0][x];
                }
                else if(i == 1) {
                        if(x >= an[0]) vis[1][0][x%an[0]] = dp[1][0][x%an[0]] = 1;
                }
                for(j = 0; j < n-1; ++j) {
                        for(k = up; k >= 0; --k) if(vis[i][j][k]){
                                //printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
                                if(j != n-2) {
                                        vis[i][j+1][k] = 1;
                                        add(dp[i][j+1][k], dp[i][j][k] * (n - 2ll - j) % mod);
                                }
                                if(k >= an[j+1]) {
                                        tmp = k % an[j+1];
                                        vis[i+1][j+1][tmp] = 1;
                                        add(dp[i+1][j+1][tmp], dp[i][j][k]);
                                } else {
                                        vis[i][j+1][k] = 1;
                                        add(dp[i][j+1][k], dp[i][j][k]);
                                }
                        }
                }
                for(k = up; k >= 0; --k) {
                        if(vis[i][n-1][k]) {
                                if(k > ans) ans = k, cnt = dp[i][n-1][k];
                                else if(k == ans) add(cnt, dp[i][n-1][k]);
                        }
                }
                if(!up) break;
        }
        printf("%d\n%d\n", ans, cnt);
        return 0;
}
