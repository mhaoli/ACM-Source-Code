#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int inf = ~0u>>1;
const int Max_N = 9 + (int)1e4;
struct Edge {
        int v; Edge*nxt;
        void add(int _v, Edge*n) { v = _v; nxt = n; }
} mem2[Max_N<<1], *bat2, *head2[Max_N];
void adde(int u, int v) {
        bat2->add(v, head2[u]); head2[u] = bat2++;
}

struct Node {
        int p;
        Node*nxt;
} Tnull, mem[Max_N], *bat, *null, *head[Max_N], *tmp;
Node* newNode(int p) {
        bat->p = p;
        bat->nxt = null;
        return bat++;
}
Node* merge(Node*t1, Node*t2) {
        while(t2 != null) {
                tmp = t2->nxt;
                t2->nxt = t1;
                t1 = t2;
                t2 = tmp;
        }
        return t1;
}

std::vector<Node*> que[Max_N][101];
int col[Max_N], sz[Max_N], ans[Max_N], Now;
void init() {
        memset(head, 0, sizeof head);
        bat2 = mem2;
        bat = mem;
        null = &Tnull;
        null->nxt = null;
}
int dfs(int u, int pre) {
        head[u] = null;
        sz[u] = 0;
        int tc = inf;
        for(Edge*p = head2[u]; p; p = p->nxt) if(p->v != pre){
                tc = std::min(tc, dfs(p->v, u));
                if(sz[u] < sz[p->v]) {
                        head[u] = merge(head[p->v], head[u]);
                } else head[u] = merge(head[u], head[p->v]);
                sz[u] += sz[p->v];
        }

        if(col[u] == Now && u < tc) tc = u;
        snuke(it, que[u][Now]) {
                (*it)->nxt = head[u];
                head[u] = *it;
                ++sz[u];
        }
        if(tc != inf) {
                while(head[u] != null) {
                        ans[head[u]->p] = tc + 1;
                        head[u] = head[u]->nxt;
                }
                sz[u] = 0;
        }
        return tc;
}
int main() {
        init();
        int n, R, K;
        scanf("%d%d%d", &n, &K, &R); --R;
        for(int i = 0, u, v; i < n-1; ++i) {
                scanf("%d%d", &u, &v);
                adde(--u, --v); adde(v, u);
        }
        for(int i = 0; i < n; ++i) {
                scanf("%d", col + i); --col[i];
        }
        int nq; scanf("%d", &nq);
        for(int p, t, i = 0; i < nq; ++i) {
                scanf("%d%d", &p, &t);
                que[--p][--t].push_back(newNode(i));
        }
        memset(ans, -1, sizeof ans);
        for(Now = 0; Now < K; ++Now) {
                dfs(R, -1);
        }
        for(int i = 0; i < nq; ++i) printf("%d\n", ans[i]);
        return 0;
}
