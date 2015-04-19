#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const static int inf = 1e8;
namespace maxflow{
        typedef int T;
        const static int Max_N = 9 + (int)2e4;
        const static int Max_E = 9 + (int)5e5;

        template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
        template <class T> int sgn(T x) { return (x > 0) - (x < 0);}

        struct edge{
                int s, e;
                T cap, f;
                edge *nxt;
                void add (int _s, int _e, T c, edge *t){
                        f = 0; s = _s; e = _e; cap = c; nxt = t;
                }
                T flow(){ return cap - f;}
        };

        T flow;
        int n, m, s, t;         // 0,1,2...n-1
        edge memo[Max_E];        //edge
        edge *bat, *head[Max_N], *cur[Max_N];
        int d[Max_N]; // distance
        bool vis[Max_N];    

        void init(){
                bat = memo;
                memset(head, 0, sizeof head);
        }
        void add (int s, int e, T cap){
                bat -> add (s, e, cap, head[s]); head[s] = bat++;
                bat -> add (e, s, 0, head[e]); head[e] = bat++;
        }
        bool bfs(){
                std::queue<int> q;
                q.push (s); d[s] = 0;
                memset (vis, 0, sizeof vis); vis[s] = 1; 
                while (q.size ()){
                        int x = q.front(); q.pop();
                        for (edge *e = head[x]; e; e = e->nxt){
                                if (!vis[e->e] && e->flow() > 0){
                                        q.push (e->e);
                                        vis[e->e] = 1;
                                        d[e->e] = d[x] + 1;
                                }
                        }
                }
                return vis[t];
        }
        T dfs (int x, T rf){
                if (x == t || sgn(rf) == 0) return rf;
                T flow = 0, ff;
                for (edge *&e = cur[x]; e; e = e->nxt){
                        T tmp = rf; chmin(tmp, e->flow());
                        if (d[e->e] == d[x] + 1 && (ff = dfs (e->e, tmp)) > 0){
                                e->f += ff;
                                memo[(e-memo)^1].f -= ff;
                                flow += ff; rf -= ff;
                                if (sgn(rf) == 0) break;
                        }
                }
                return flow;
        }
        T maxflow(int _n, int _s, int _t){
                n = _n; flow = 0;
                s = _s; t = _t;
                while (bfs()){
                        //clr (cur, 0);
                        for (int i = 0; i < n; ++ i) cur[i] = head[i];
                        flow += dfs (s, inf);
                }
                return flow;
        }
}
const int bigNumber = 1000;
int n, m, K, src, tar;
int node(int u, int x) {
        return x == -1 ? src : u * m + x;
}
int main() {
        scanf("%d%d%d", &n, &m, &K);
        src = n * m + 10; tar = src + 1;
        maxflow::init();
        for(int i = 0, j, t; i < n; ++i) {
                for(j = 0; j < m; ++j) {
                        scanf("%d", &t);
                        maxflow::add(node(i, j-1), node(i, j), t==-1 ? inf : bigNumber - t);
                }
                maxflow::add(node(i, m-1), tar, inf);
        }
        for(int i, u, v; K--;) {
                scanf("%d%d", &u, &v); --u; --v;
                for(i = 0; i < m; ++i) {
                        maxflow::add(node(u, i-1), node(v, i), inf);
                }
        }
        printf("%.2f\n", (n * bigNumber - maxflow::maxflow(tar + 1, src, tar) + 0.0) / n);
        return 0;
}
