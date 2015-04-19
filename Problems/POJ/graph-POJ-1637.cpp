/*
 * Author:  Plumrain
 * Created Time:  2014/6/6 10:25:46
 * File Name: graph-POJ-1637.cpp
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

struct Elgraph{
    const static int maxn = 2005;
    
    int flow;
    int n, m, s, t;         // n: 1,2...n  build: s=0, t=n+1
    vector<edge> pat;       // edge
    vector<int> g[maxn];    // graph
    int d[maxn], cur[maxn]; // distance
    int chu[maxn], ru[maxn];
    bool vis[maxn];    

    void init(int _n){
        n = _n + 2; m = 0; flow = 0;
        repf (i, 0, n-1) g[i].clear();
        pat.clear(); m = 0;
        clr (chu, 0); clr (ru, 0);
    }
    void add_call (int s, int e, bool bidirect){
        if (bidirect) add (s, e, 1);
        ++ chu[s]; ++ ru[e];
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
    int dfs (int x, int rf){
        if (x == t || sgn(rf) == 0) return rf;
        int flow = 0, ff;
        for (int &i = cur[x]; i < sz(g[x]); ++ i){
            edge &e = pat[g[x][i]];
            int tmp = rf; chmin (tmp, int(e.cap - e.flow));
            if (d[e.e] == d[x] + 1 && (ff = dfs (e.e, tmp)) > 0){
                e.flow += ff;
                pat[g[x][i]^1].flow -= ff;
                flow += ff; rf -= ff;
                if (sgn(rf) == 0) break;
            }
        }
        return flow;
    }
    bool calc(){
        s = 0; t = n;
        int sum = 0;
        repf (i, 1, n){
            int cnt = chu[i] - ru[i];
            if (abs(cnt) & 1) return 0;
            cnt /= 2;
            if (cnt < 0) add (i, t, -cnt);
            else add (s, i, cnt), sum += cnt;
        }

        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }
        return flow == sum;
    }
};

Elgraph gao;

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; cin >> T;
    while ( T-- ){
        int n, m; cin >> n >> m;
        gao.init(n);
        int t1, t2, u;
        repf (i, 0, m-1) cin >> t1 >> t2 >> u, gao.add_call (t1, t2, !u);
        cout << (gao.calc () ? "possible" : "impossible") << endl;
    }
    return 0;
}
