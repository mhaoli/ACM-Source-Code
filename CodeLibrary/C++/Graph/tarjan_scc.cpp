struct SCC{
    int dfs_clock, cnt;
    int pre[maxn], lowlink[maxn];
    int stk[maxn], top;

    void dfs (int u, int*sccno){ 
        pre[u] = lowlink[u] = ++dfs_clock;
        stk[top++] = u;
        for (edge *p = head[u]; p; p = p->nxt){
            int v = p->v;
            if (!pre[v]){
                dfs (v, sccno);
                lowlink[u] = min (lowlink[u], lowlink[v]);
            } else if (sccno[v] == -1){
                lowlink[u] = min (lowlink[u], pre[v]);
            }
        }
        if (lowlink[u] == pre[u]){
            cnt ++;
            for (;;){
                int x = stk[--top];
                sccno[x] = cnt;
                if (x == u) break;
            }
        }
    }

    int find (int n, int*sccno){
        dfs_clock = top = 0; cnt = -1;
        memset (pre, 0, sizeof pre);
        for (int i = 0; i < n; ++ i)
            if (!pre[i]) dfs (i, sccno);
        return ++cnt;
    }
}scc;