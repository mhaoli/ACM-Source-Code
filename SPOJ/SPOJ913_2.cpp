#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 20009;
std::vector<std::pair<int, int> > E[Max_N];
int lg2[Max_N], dep[Max_N], fa[Max_N][30], dis[Max_N][30];
void dfs(int u, int d) {
        dep[u] = d;
        for(int i = 1; i <= lg2[d]; ++i) {
                fa[u][i] = fa[fa[u][i-1]][i-1];
                dis[u][i] = dis[u][i-1] + dis[fa[u][i-1]][i-1];
        }
        snuke(it, E[u]) if(it->first != fa[u][0]) {
                fa[it->first][0] = u;
                dis[it->first][0] = it->second;
                dfs(it->first, d + 1);
        }
}
std::pair<int, int> Up(int a, int K) {
        int d = 0;
        for(; K > 0; K -= 1<<lg2[K]) {
                d += dis[a][lg2[K]];
                a = fa[a][lg2[K]];
        }
        return std::make_pair(a, d);
}
int lca(int a, int b) {
        if(dep[a] < dep[b]) std::swap(a, b);
        if((a = Up(a, dep[a] - dep[b]).first) == b) return a;
        for(int k = lg2[dep[a]]; k >= 0; --k)
                if(fa[a][k] != fa[b][k]) a = fa[a][k], b = fa[b][k];
        return fa[a][0];
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        for(int i = 2; i < Max_N; ++i) lg2[i] = lg2[i-1] + (i == 2 << lg2[i-1]);

        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) E[i].clear();
                for(int i = 0, u, v, c; i < n-1; ++i) {
                        scanf("%d%d%d", &u, &v, &c);
                        E[--u].push_back(std::make_pair(--v, c));
                        E[v].push_back(std::make_pair(u, c));
                }
                memset(fa, -1, sizeof fa);
                fa[0][0] = -1;
                dfs(0, 0);
                char op[15];
                for(int a, b, K, A, ans; scanf("%s", op), op[1] != 'O'; ) {
                        scanf("%d%d", &a, &b);
                        A = lca(--a, --b);
                        if(op[1] == 'I') ans = Up(a, dep[a] - dep[A]).second + Up(b, dep[b] - dep[A]).second;
                        else {
                                scanf("%d", &K);
                                if(K > dep[a] + dep[b] - (dep[A] << 1) + 1) ans = -2;
                                else ans = dep[a] - dep[A] >= --K ? Up(a, K).first : Up(b, dep[b] - dep[A] - (K - dep[a] + dep[A])).first;
                                ++ans;
                        }
                        printf("%d\n", ans);
                }
                puts("");
        }
        return 0;
}
