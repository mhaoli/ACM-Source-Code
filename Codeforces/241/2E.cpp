#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 505;
const int Max_M = 1111;
const int inf = ~0u>>2;
struct Edge {
        int v, l, id; Edge*nxt;
        void add(int _v, int _l, int i, Edge*n) { v = _v; l = _l; id = i; nxt = n; }
} mem[Max_N * Max_N], *bat = mem, *head[Max_N];
void adde(int u, int v, int l, int id) {
        bat->add(v, l, id, head[u]); head[u] = bat++;
}

int dis[Max_N][Max_N], cnt[Max_N][Max_N];

int main() {
        int n, m; scanf("%d%d", &n, &m);
        memset(dis, 0, sizeof dis);
        for(int i = 0, j; i < n; ++i)
                for(j = 0; j < n; ++j) dis[i][j] = i == j ? 0 : inf;
        for(int i = 0, u, v, l; i < m; ++i) {
                scanf("%d%d%d", &u, &v, &l);
                adde(--u, --v, l, i); adde(v, u, l, i);
                dis[u][v] = dis[v][u] = l;
        }
        for(int i = 0, j, k; i < n; ++i)
                for(j = 0; j < n; ++j) if(i != j)
                        for(k = 0; k < n; ++k) if(k != i && k != j) 
                                dis[j][k] = std::min(dis[j][k], dis[j][i] + dis[i][k]);
        //for(int i = 0, j; i < n; ++i) {
                //for(j = 0; j < n; ++j) printf("%d ", dis[i][j]);
                //puts("");
        //}
        Edge*p;
        for(int i = 0, j, k; i < n; ++i)
                for(j = 0; j < n; ++j) if(i != j){
                        for(p = head[j]; p; p = p->nxt) if(p->l + dis[p->v][i] == dis[i][j]) ++cnt[i][j];
                }
        for(int ans, i = 0, j, k; i < n; ++i) {
                for(j = i+1; j < n; ++j) {
                        ans = 0;
                        for(k = 0; k < n; ++k) 
                                if(k != j && dis[k][j] + dis[k][i] == dis[i][j]) ans += cnt[j][k];
                        printf("%d%c", ans, " \n"[i==n-2]);
                }
        }
        return 0;
}
