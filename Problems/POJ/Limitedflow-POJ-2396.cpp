/*
 * Author:  Plumrain
 * Created Time:  2014/5/3 14:33:17
 * File Name: Maflow-POJ-2396.cpp
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

template <class T> struct Flow{
    const static int maxn = 1000;
    
    T flow;
    T mn[maxn];             // sigma (low[u,i]) - sigma(low[i,v])
    int n, m, s, t;         // 0,1,2...n-1
    vector<edge> pat;       // edge
    vector<int> g[maxn];    // graph
    int d[maxn], cur[maxn]; // distance
    bool vis[maxn];    

    void init(int _n){
        n = _n; m = 0; flow = 0;
        repf (i, 0, n+1) g[i].clear();
        pat.clear(); m = 0;
        clr (mn, 0);
    }
    // build graph with S and T 
    void add2 (int s, int e, T cap){
        pat.pb (edge(s, e, cap, 0));
        pat.pb (edge(e, s, 0, 0));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
    }
    // build graph without S and T 
    void add (int s, int e, T low, T high){
        mn[e] += low; mn[s] -= low;
        add2 (s, e, high-low);
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
        s = n; t = n + 1;
        int tot = 0;
        repf (i, 0, n-1){
            if (mn[i] >= 0) add2 (s, i, mn[i]), tot += mn[i];
            else add2 (i, t, -mn[i]);
        }

        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }

        return flow >= tot;
    }
};

Flow<int> gao;
int low[300][300], high[300][300];
int an[300][300], mn[300], ans_num[300][300];

void calc(int t1, int t2, char cc, int t3){
    if (cc == '=') low[t1][t2] = high[t1][t2] = t3;
    else if (cc == '<') chmin (high[t1][t2], t3-1);
    else chmax (low[t1][t2], t3+1);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, u = 0;
    cin >> T;
    while (T--){
        if (u) cout << endl;
        u = 1;

        int n, m;
        cin >> n >> m;
        int tmp, sta = 0, tar = n + m + 1;
        gao.init (tar + 1);
        repf (i, 1, n) cin >> tmp, gao.add (sta, i, tmp, tmp);
        repf (i, 1, m) cin >> tmp, gao.add (i+n, tar, tmp, tmp);

        clr (low, 0); clr (high, 127);
        int q; cin >> q;
        while (q--){
            int t1, t2, t3;
            string buf;
            cin >> t1 >> t2 >> buf >> t3;

            if (t1 && t2) calc (t1, t2, buf[0], t3);
            else if (!t1 && !t2) repf (i, 1, n) repf (j, 1, m) calc (i, j, buf[0], t3);
            else if (!t1) repf (i, 1, n) calc (i, t2, buf[0], t3);
            else repf (j, 1, m) calc (t1, j, buf[0], t3);
        }
        gao.add (tar, sta, 0, inf);

        bool ans = 1;
        repf (i, 1, n) repf (j, 1, m)
            if (high[i][j] < low[i][j]){ ans = 0; break; }
            else gao.add (i, j+n, low[i][j], high[i][j]);

        if (!ans) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        ans = gao.maxflow();
        if (!ans) cout << "IMPOSSIBLE" << endl;
        else{
            repf (i, 1, n) repf (j, 1, m) ans_num[i][j] = low[i][j];

            repf (i, 0, sz(gao.pat)-1){
                edge e = gao.pat[i];
                if (e.s == 0 || e.e == tar || !e.cap) continue;
                ans_num[e.s][e.e-n] += e.flow;
            }

            repf (i, 1, n){
                bool uu = 0;
                repf (j, 1, m){
                    if (uu) cout << " ";
                    uu = 1;
                    cout << ans_num[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
