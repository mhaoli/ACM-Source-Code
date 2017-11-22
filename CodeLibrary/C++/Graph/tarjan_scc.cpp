//time: O(n+m)
namespace SCC{
    int dfs_clock, cnt;
    int pre[Max_N], lowlink[Max_N];
    int stk[Max_N], top;

    void dfs(int u, int*sccno, Edge *hd[]){
        pre[u] = lowlink[u] = ++dfs_clock;
        stk[top++] = u;
        for(Edge *p = hd[u]; p; p = p->nxt){
            int v = p->t;
            if(!pre[v]){
                dfs(v, sccno, hd);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            } else if(sccno[v] == -1){
                lowlink[u] = min(lowlink[u], pre[v]);
            }
        }
        if(lowlink[u] == pre[u]){
            cnt++;
            for(;;){
                int x = stk[--top];
                sccno[x] = cnt;
                if(x == u) break;
            }
        }
    }

    //index 0-based
    int calc_scc(int n, int *sccno, Edge *hd[]){
        dfs_clock = top = 0; cnt = -1;
        memset(sccno, -1, n * sizeof sccno[0]);
        memset(pre, 0, n * sizeof pre[0]);
        for(int i = 0; i < n; ++ i)
            if(!pre[i]) dfs(i, sccno, hd);
        return ++cnt;
    }
}

