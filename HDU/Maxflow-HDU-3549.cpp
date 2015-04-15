/*
 * Author:  Plumrain
 * Created Time:  2014/4/24 20:48:59
 * File Name: Maxflow-HDU-3549.cpp
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
    const static int maxn = 100;
    
    int n, m, s, t;
    vector<edge> pat;
    vector<int> g[maxn];
    int d[maxn], cur[maxn];
    bool vis[maxn];
    
    void init(int _n){
        n = _n; m = 0;
        pat.clear();
        repf (i, 0, n-1) g[i].clear();
    }
    void add (int s, int e, int cap){
        pat.pb (edge(s, e, cap, 0));
        pat.pb (edge(e, s, 0, 0));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
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
    T dfs (int x, int rf){
        if (x == t || sgn(rf) == 0) return rf;
        T flow = 0, ff;
        for (int &i = cur[x]; i < sz(g[x]); ++ i){
            edge &e = pat[g[x][i]];
            T tmp = rf; chmin (tmp, T(e.cap - e.flow));
            if (d[e.e] == d[x] + 1 && (ff = dfs (e.e, tmp)) > 0){
                e.flow += ff;
                pat[g[x][i]^1].flow -= ff;
                rf -= ff; flow += ff;
                if (sgn(rf) == 0) break;
            }
        }
        return flow;
    }
    T maxflow(int _s, int _t){
        s = _s; t = _t;
        T flow = 0;
        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
            //cout << " ---------------------- " << endl;
            //repf (i, 0, n-1) tst (i), out (d[i]);
        }
        return flow;
    }
};

dinic<int> gao;

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        int n, m;
        scanf ("%d%d", &n, &m);
        gao.init(n);
        
        int s, e, cost;
        repf (i, 0, m-1){
            scanf ("%d%d%d", &s, &e, &cost);
            gao.add (s-1, e-1, cost);
        }

        printf ("Case %d: %d\n", ++ cas, gao.maxflow(0, n-1));
    }
    return 0;
}
