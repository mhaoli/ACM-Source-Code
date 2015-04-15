#include<bits/stdc++.h>
using namespace std;
const int inf = 100000;
template<class T> bool chmin (T&a, const T&b){ return a > b ? a=b, 1: 0; }
template<class Tf, class Tc> 
struct Costflow{
    const static int maxn = 1111;  //max node number
    const static int maxe = 33333;  //max edge number
    const static Tc maxx = 3e8;  //max cost
    //3 * maxx < maxint
    //change the type of eps

    struct edge{
        int v, nxt;
        Tf f, cap;
        Tc c;
        void modify (int _v, Tf cp, Tc _c, int n){
            f = 0;
            v = _v; cap = cp; c = _c; nxt = n;
        }
        Tf flow(){ return cap - f; }
    };

    int head[maxn];
    int pre[maxn];
    int vis[maxn];
    int n, m, s, t;
    edge e[maxe];    //edge
    Tc dis[maxn];
    void add(int u, int v, Tf f, Tc c){
        e[m].modify(v, f, c, head[u]); head[u] = m++;
        e[m].modify(u, 0, -c, head[v]); head[v] = m++; 
    }
    void init(){
        m = 0; memset (head, -1, sizeof head);
    }
    int spfa(){
        for (int i = 0; i <= n; ++i) dis[i] = maxx; dis[s] = 0;
        memset(vis, 0, sizeof(vis)); vis[s] = 1;
        memset(pre, -1, sizeof(pre));
        queue<int> q; q.push(s); 
        int p, u, v;
        while (!q.empty()){
            for (p = head[u=q.front()]; ~p; p = e[p].nxt){
                v = e[p].v;
                if (dis[v] - dis[u] - e[p].c > 0 && e[p].flow() > 0){
                    dis[v] = dis[u] + e[p].c;
                    pre[v] = p;
                    if (!vis[v]) vis[v] = 1, q.push(v);
                }   
            }
            vis[u] = 0; q.pop(); 
        }
        return maxx - dis[t] > 0;  
    }
    pair<Tf, Tc> costflow(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        Tc cost = 0; Tf flow = 0;
        while (spfa()){
            Tf f = maxx;
            for (int p = pre[t]; p != -1; p = pre[e[p^1].v]) chmin(f, e[p].flow());
            flow += f;
            cost += f * dis[t];
            for (int p = pre[t]; p != -1; p = pre[e[p^1].v])
                e[p].f += f, e[p^1].f -= f;     
        }
        return make_pair(flow, cost);
    }
    /***********/ 
};

Costflow<int, int> gao;
int main(){
    int n, m; scanf ("%d%d", &n, &m);
    int sta = n + 1, tar = sta + 1;
    gao.init ();
    for (int c, t, last = 0, i = 0; i < n; ++ i){
        scanf ("%d", &c);
        t = c; c -= last; last = t;
        if (c >= 0) gao.add (sta, i, c, 0);
        else gao.add (i, tar, -c, 0);
        if (i == n-1) gao.add (n, tar, last, 0);
    }
    for (int i = 0; i < n; ++ i) gao.add (i+1, i, inf, 0);
    for (int t1, t2, c, i = 0; i < m; ++ i){
        scanf ("%d%d%d", &t1, &t2, &c);
        gao.add (t1-1, t2, inf, c);
    }
    printf ("%d\n", gao.costflow (tar+1, sta, tar).second);
    return 0;
}
