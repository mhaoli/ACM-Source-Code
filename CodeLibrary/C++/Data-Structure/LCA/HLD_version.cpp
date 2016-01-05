// time: O(nlogn)
struct Edge {
        int u, v, w;
        Edge *nxt;
        void Set(int _u, int _v, int _w, Edge*n) {
                u = _u; v = _v; w = _w; nxt = n;
        }
};
struct Tree {
        //Tree
        Edge E[Max_N<<1];
        Edge*head[Max_N], *mem;
        int n;
        void init(int n) {
                this->n = n;
                mem = E;
                memset(head, 0, sizeof head);
        }
        void addE(int u, int v, int w) {
                mem->Set(u, v, w, head[u]);
                head[u] = mem++;
        }

        //LCA
        int Q[Max_N];                   //queue
        int siz[Max_N];                 //子树节点数
        int dep[Max_N];                 //deep
        int belong[Max_N];              //重链最上方的顶点
        int fa[Max_N];                  //父节点
        void LAC_init(int rt) {
                memset(belong, -1, sizeof belong);
                memset(siz, 0, sizeof siz);

                int l = 0, r = 1;
                Q[0] = rt; dep[rt] = 0; fa[rt] = -1;
                while(l < r) {
                        int x = Q[l++];
                        for(Edge*p = head[x]; p; p = p->nxt) if(p->v != fa[x]){
                                fa[p->v] = x;
                                dep[p->v] = dep[x] + 1;
                                Q[r++] = p->v;
                        }
                }

                for(int i = r-1; i; --i) siz[fa[Q[i]]] += ++siz[Q[i]];
                belong[rt] = rt;
                for(int i = 0; i < r; ++i) {
                        int t = Q[i], ma = -1, son = -1;
                        if(belong[t] == -1) belong[t] = t;
                        for(Edge*p = head[t]; p; p = p->nxt) if(p->v != fa[t] && siz[p->v] > ma){
                                ma = siz[p->v];
                                son = p->v;
                        }
                        if(son != -1) belong[son] = belong[t];
                }
        }
        int LCA(int x, int y) {
                while(1) {
                        if(dep[x] > dep[y]) std::swap(x, y);
                        if(belong[x] == belong[y]) return x;
                        if(dep[belong[x]] < dep[belong[y]]) std::swap(x, y);
                        x = fa[belong[x]];
                }
                return y;
        }
};
