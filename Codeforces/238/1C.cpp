#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e5;
struct Edge {
        int v, id; Edge*nxt;
        void add(int _v, int i, Edge*t) { v = _v; id = i; nxt = t; }
} mem[Max_N<<1], *bat = mem, *head[Max_N];
void adde(int u, int v, int id) {
        bat->add(v, id, head[u]); head[u] = bat++;
}

std::pair<int, int> a[Max_N];
bool vis[Max_N];
int x[Max_N], y[Max_N], z[Max_N], deg[Max_N], stk[Max_N], top[Max_N], ans_cnt;
void dfs(int r) {
        for(Edge*p = head[r]; p; p = p->nxt) if(!vis[p->id]){
                vis[p->id] = 1;
                dfs(p->v);
                if(top[p->v]) {
                        x[ans_cnt] = stk[p->v];
                        y[ans_cnt] = p->v;
                        z[ans_cnt++] = r;
                        --top[p->v];
                } else if(top[r]) {
                        x[ans_cnt] = stk[r];
                        y[ans_cnt] = r;
                        z[ans_cnt++] = p->v;
                        --top[r];
                } else {
                        ++top[r]; stk[r] = p->v;
                }
        }
}
int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0, u, v; i < m; ++i) {
                scanf("%d%d", &u, &v);
                adde(--u, --v, i); adde(v, u, i);
                ++deg[u]; ++deg[v];
        }
        ans_cnt = 0;
        for(int i = 0; i < n; ++i) dfs(i);
        for(int i = 0; i < n; ++i) if(top[i]) return puts("No solution"), 0;
        for(int i = 0; i < ans_cnt; ++i)
                printf("%d %d %d\n", x[i] + 1, y[i] + 1, z[i] + 1);
        return 0;
}
