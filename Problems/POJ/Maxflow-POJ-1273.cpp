/*
 * Author:  Plumrain
 * Created Time:  2014/4/24 16:45:13
 * File Name: flow-POJ-1273.cpp
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
#define INF 999999999999999999
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
const int inf = 2047483647;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

struct edge{
    int from, to, cap, flow;
};

struct dinic{
    const static int maxn = 205;

    int n, m, s, t;
    vector<edge> pat;
    vector<int> g[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int _n){
        n = _n; m = 0;
        pat.clear(); 
        repf (i, 0, n-1) g[i].clear();
    }
    void add(int from, int to, int cap){
        pat.pb ((edge){from, to, cap, 0});
        pat.pb ((edge){to, from, 0, 0});
        m += 2;
        g[from].pb (m - 2);
        g[to].pb (m - 1);
    }
    bool bfs(){
        queue<int> q;
        q.push (s);
        clr (vis, 0);
        vis[s] = 1; d[s] = 0;
        while (sz(q)){
            int x = q.front(); q.pop();
            repf (i, 0, sz(g[x])-1){
                edge e = pat[g[x][i]];
                if (!vis[e.to] && e.cap > e.flow){
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push (e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, int rf){
        if (x == t || rf == 0) return rf;
        int flow = 0, ff;
        for (int &i = cur[x]; i < sz(g[x]); ++ i){
            edge &e = pat[g[x][i]];
            if (d[x] + 1 == d[e.to] && (ff = dfs (e.to, min (rf, e.cap-e.flow))) > 0){
                e.flow += ff;
                pat[g[x][i]^1].flow -= ff;
                flow += ff; rf -= ff;
                if (rf == 0) break;
            }
        }
        return flow;
    }
    int maxflow(int _s, int _t){
        s = _s; t = _t;
        int flow = 0;
        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }
        return flow;
    }
};

dinic gao;

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &m, &n) != EOF){
        gao.init(n);
        repf (i, 0, m-1){
            int s, e, cost;
            scanf ("%d%d%d", &s, &e, &cost);
            gao.add (s-1, e-1, cost);
        }
        printf ("%d\n", gao.maxflow(0, n-1));
    }
    return 0;
}
