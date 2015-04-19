/*
 * Author:  Plumrain
 * Created Time:  2014/5/3 14:33:17
 * File: 无源无汇，有容量上下界的网络判断是否有可行流
 */
#define clr(x,y) memset(x, y, sizeof(x))
#define sz(v) ((int)(v).size())
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)

typedef vector<int> vi;
const int inf = 2147483647 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

//use : Flow<int/double> gao; gao.init(); gao.maxlow();

struct edge{
    int s, e;
    int cap, flow;
    edge(){ }
    edge (int _s, int _e, int c, int f) : s(_s), e(_e), cap(c), flow(f){ }
};

template <class T> struct Flow{
    const static int maxn = ;
    
    T flow;
    T mn[maxn];             // sigma (low[u,i]) - sigma(low[i,v])
    int n, m, s, t;         // 0,1,2...n-1
    vector<edge> pat;       // edge
    vector<int> g[maxn];    // graph
    int d[maxn], cur[maxn]; // distance
    bool vis[maxn];    

    void init(int _n){
        n = _n; m = 0;
        repf (i, 0, n+1) g[i].clear();
        pat.clear(); m = 0;
        clr (mn, 0);
    }
    // build graph with S and T 
    void add (int s, int e, T cap){
        pat.pb (edge(s, e, cap, 0));
        pat.pb (edge(e, s, 0, 0));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
    }
    // build graph without S and T 
    void add_call (int s, int e, T low, T high){
        mn[e] += low; mn[s] -= low;
        add (s, e, high-low);
    }
    bool bfs(){
        queue<int> q;
        q.push (s); d[s] = 0;
        clr (vis, 0); vis[s] = 1; 
        while (sz(q)){
            int x = q.front(); q.pop();
            repf (i, 0, sz(g[x])-1){
                edge e = pat[g[x][i]];
                if (!vis[e.e] && e.cap > e.flow){
                    q.push (e.e);
                    vis[e.e] = 1;
                    d[e.e] = d[x] + 1;
                }
            }
        }
        return vis[t];
    }
    T dfs (int x, T rf){
        if (x == t || sgn(rf) == 0) return rf;
        T flow = 0, ff;
        for (int &i = cur[x]; i < sz(g[x]); ++ i){
            edge &e = pat[g[x][i]];
            T tmp = rf; chmin (tmp, T(e.cap - e.flow));
            if (d[e.e] == d[x] + 1 && (ff = dfs (e.e, tmp)) > 0){
                e.flow += ff;
                pat[g[x][i]^1].flow -= ff;
                flow += ff; rf -= ff;
                if (sgn(rf) == 0) break;
            }
        }
        return flow;
    }
    bool maxflow(){
        s = n; t = ++n;
        T tot = 0;
        repf (i, 0, s-1){
            if (mn[i] >= 0) add (s, i, mn[i]), tot += mn[i];
            else add (i, t, -mn[i]);
        }

        flow = 0;
        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }

        return flow >= tot;
    }
};

