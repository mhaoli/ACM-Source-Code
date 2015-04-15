/*
 * Author:  Plumrain
 * Created Time:  2014/5/5 0:31:52
 * File Name: Mincut-POJ-3204.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int s, e;
    int cap, flow;
    edge(){ }
    edge (int _s, int _e, int c, int f) : s(_s), e(_e), cap(c), flow(f){ }
};

template <class T> struct dinic{
    const static int maxn = 1000;
    
    T flow;
    int n, m, s, t;         // 0,1,2...n-1
    vector<edge> pat;       // edge
    vector<int> g[maxn], rg[maxn];    // graph
    int d[maxn], cur[maxn]; // distance
    bool vis[maxn];

    void init(int _n){
        n = _n; m = 0; flow = 0;
        repf (i, 0, n-1) g[i].clear(), rg[i].clear();
        pat.clear(); m = 0;
    }
    void add (int s, int e, T cap){
        pat.pb (edge(s, e, cap, 0));
        pat.pb (edge(e, s, 0, 0));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
        rg[e].pb (m - 2); rg[s].pb (m - 1);
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
    T maxflow(int _s, int _t){
        s = _s; t = _t;
        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }
        return flow;
    }
};

int num[505];
dinic<int> gao;

void dfs1 (int x){
    num[x] = 1;
    repf (i, 0, sz(gao.g[x])-1){
        edge e = gao.pat[gao.g[x][i]];
        if (e.cap && e.cap > e.flow && !num[e.e]) dfs1 (e.e);
    }
}

void dfs2 (int x){
    num[x] = 2;
    repf (i, 0, sz(gao.rg[x])-1){
        edge e = gao.pat[gao.rg[x][i]];
        if (e.cap && e.cap > e.flow && !num[e.s]) dfs2 (e.s);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int sta = 0, tar = n - 1;
    gao.init (tar + 1);
    int t1, t2, cap;
    repf (i, 0, m-1) cin >> t1 >> t2 >> cap, gao.add (t1, t2, cap);
    gao.maxflow (sta, tar);

    clr (num, 0); dfs1 (sta); dfs2 (tar);
    int ans = 0;
    repf (i, 0, sz(gao.pat)-1){
        edge e = gao.pat[i];
        if (!e.cap) continue;
        if (num[e.s] == 1 && num[e.e] == 2) ++ ans;
    }
    cout << ans << endl;
    return 0;
}
