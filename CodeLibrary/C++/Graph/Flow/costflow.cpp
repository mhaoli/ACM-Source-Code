namespace costflow {
        typedef int Tf;
        typedef int Tc;
        const static int Max_N = 1009;  //max node number
        const static int Max_E = 240009;  //max edge number
        const static Tc Max_C = 5e8;  //max cost
        //3 * Max_C < max_int
        //template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
        template <class T> int sgn(T x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }

        struct Edge{
                int v;
                Edge *nxt;
                Tf f, cap;
                Tc c;
                void add(int _v, Tf cp, Tc _c, Edge*n){
                        v = _v; cap = cp; c = _c; nxt = n; f = 0;
                }
                Tf flow(){ return cap - f; }
        };

        Edge *head[Max_N], e[Max_E], *bat, *pre[Max_N];
        int vis[Max_N];
        int n, m, s, t;
        Tc dis[Max_N];
        void add(int u, int v, Tf f, Tc c){
                bat->add(v, f, c, head[u]); head[u] = bat++;
                bat->add(u, 0, -c, head[v]); head[v] = bat++;
        }
        void init(){
                bat = e; m = 0; memset(head, 0, sizeof head);
        }
        int spfa(){
                for (int i = 0; i < n; ++i) dis[i] = Max_C; dis[s] = 0;
                memset(vis, 0, sizeof(vis)); vis[s] = 1;
                memset(pre, 0, sizeof(pre));
                queue<int> q; q.push(s); 
                int u, v;
                Edge *p;
                while (!q.empty()){
                        p = head[u=q.front()]; q.pop();
                        for (; p; p = p->nxt){
                                v = p->v;
                                if (sgn(dis[v] - dis[u] - p->c) > 0 && sgn(p->flow()) > 0){
                                        dis[v] = dis[u] + p->c;
                                        pre[v] = p;
                                        if (!vis[v]) vis[v] = 1, q.push(v);
                                }   
                        }
                        vis[u] = 0; 
                }
                return sgn(Max_C - dis[t]) > 0;  
        }
        // Node index from 0 to _n-1
        pair<Tf, Tc> solve(int _n, int _s, int _t){
                n = _n; s = _s; t = _t;
                Tc cost = 0; Tf flow = 0;
                while (spfa()){
                        Tf f = Max_C;
                        for (Edge *p = pre[t]; p; p = pre[e[(p-e)^1].v]) chmin(f, p->flow());
                        flow += f;
                        cost += f * dis[t];
                        for (Edge *p = pre[t]; p; p = pre[e[(p-e)^1].v])
                                p->f += f, e[(p-e)^1].f -= f;     
                }
                return make_pair(flow, cost);
        }
}

