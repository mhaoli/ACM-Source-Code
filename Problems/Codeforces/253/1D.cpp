#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e6;
int dp[Max_N], fa[Max_N], vis[Max_N];
void check(int u, int f) {
        if(f == -1) return;
        if(dp[u] == dp[f]) {
                if(vis[f]) vis[f] = 0, ++dp[f], check(f, fa[f]);
                else vis[f] = 1;
        } else if(dp[u] > dp[f]) {
                dp[f] = dp[u]; vis[f] = 1; check(f, fa[f]);
        }
}
int main() {
        int n; scanf("%d", &n);
        fa[0] = -1; dp[0] = 0; vis[0] = 0;
        for(int i = 1, t; i <= n; ++i) {
                scanf("%d", &t);
                dp[i] = 1; vis[i] = 0;
                fa[i] = --t;
                check(i, t);
                printf("%d%c", vis[0]?dp[0]:dp[0]-1, " \n"[i==n]);
        }
        return 0;
}
