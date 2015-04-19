/*
 * Author:  Plumrain
 * Created Time:  2014/7/16 15:27:37
 * File Name: 194.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

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
    const static int maxn = 300;
    
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

Flow<int> gao;
pii idx[205][205];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    gao.init (n);
    int ts, te, c, l;
    repf (i, 0, n-1) repf (j, 0, n-1) idx[i][j] = mp (-1, -1);
    repf (i, 0, m-1){
        cin >> ts >> te >> l >> c; -- ts; -- te;
        idx[ts][te] = mp (i, l);
        gao.add_call (ts, te, l, c);
    }

    bool ans_u = gao.maxflow ();
    if (!ans_u) puts ("NO");
    else{
        puts ("YES");
        vi ans(m, 0);
        repf (i, 0, sz(gao.pat)-1){
            edge x = gao.pat[i];
            if (x.s == gao.s || x.s == gao.t || x.e == gao.t || x.e == gao.s || idx[x.s][x.e].x == -1) continue;
            ans[idx[x.s][x.e].x] = idx[x.s][x.e].y + x.flow;
        }
        repf (i, 0, sz(ans)-1) cout << ans[i] << endl;
    }
    return 0;
}
