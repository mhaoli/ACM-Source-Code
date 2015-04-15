/*
 * Author:  Plumrain
 * Created Time:  2014/7/23 11:11:24
 * File Name: HDU-4862.cpp
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
#define idx(i,j) (((i)*m + (j)) << 1)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxx = 10000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

char s[15][15];

struct edge{
    int s, e, cap, flow, cost;
    edge(){ }
    edge (int _s, int _e, int c, int f, int _c) : s(_s), e(_e), cap(c), flow(f), cost(_c){ }
};

template <class Tf, class Tc> struct MCMF{
    const static int maxn = 500;
    const static Tf maxx = 1e8;          //max flow
    
    Tc cost; Tf flow;
    int n, m, s, t;
    vector<edge> pat;
    vi g[maxn];
    int inq[maxn];
    int p[maxn];        //from which path
    Tc d[maxn];         //SPFA, min cost
    Tf ff[maxn];

    void init(int _n){
        n = _n; m = 0; flow = 0; cost = 0;
        repf (i, 0, n-1) g[i].clear();
        pat.clear();
    }
    void add (int s, int e, Tf cap, Tc cost){
        pat.pb (edge(s, e, cap, 0, cost));
        pat.pb (edge(e, s, 0, 0, -cost));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
    }
    bool SPFA(Tf &flow, Tc &cost){
        repf (i, 0, n-1) d[i] = maxx;
        clr (inq, 0);
        d[s] = 0; p[s] = -1; ff[s] = inf;

        queue<int> q; q.push (s); inq[s] = 1;
        while (sz(q)){
            int u = q.front(); q.pop(); inq[u]= 0;
            repf (i, 0, sz(g[u])-1){
                edge &e = pat[g[u][i]];
                if (e.cap > e.flow && d[e.e] > d[e.s] + e.cost){
                    d[e.e] = d[e.s] + e.cost;
                    p[e.e] = g[u][i];
                    ff[e.e] = ff[u]; chmin (ff[e.e], e.cap - e.flow);
                    if (!inq[e.e]) q.push (e.e), inq[e.e] = 1;
                }
            }
        }

        if (d[t] > 0) return 0;
        flow += ff[t];
        cost += d[t] * ff[t];
        int u = t;
        while (u != s){
            pat[p[u]].flow += ff[t];
            pat[p[u]^1].flow -= ff[t];
            u = pat[p[u]].s;
        }
        return 1;
    }
    Tc mincost(int _s, int _t){
        s = _s; t = _t;
        while (SPFA(flow, cost));
        return cost;
    }
};

MCMF<int, int> gao;

int calc (int x1, int y1, int x2, int y2){
    int ret = abs (x1-x2) + abs(y1-y2) - 1;
    if (s[x1][y1] == s[x2][y2]) ret -= s[x1][y1] - '0';
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0; scanf ("%d", &T);
    while (T--){
        int n, m, k;
        printf ("Case %d : ", ++ cas);
        scanf ("%d%d%d", &n, &m, &k);
        repf (i, 0, n-1) scanf ("%s", s[i]);
        int ans;
        if (k < min(n,m)) ans = -1;
        else{
            int ss = 2*n*m, sta = ss + 1, tar = sta + 1;
            gao.init (tar + 1);
            gao.add (ss, sta, k, 0);
            repf (i, 0, n-1) repf (j, 0, m-1){
                gao.add (sta, idx(i,j), 1, 0);
                gao.add (idx(i,j)+1, tar, 1, 0);
                gao.add (idx(i,j), idx(i,j)+1, 1, -maxx);
                repf (t1, i+1, n-1) gao.add (idx(i,j)+1, idx(t1,j), 1, calc(i,j,t1,j));
                repf (t1, j+1, m-1) gao.add (idx(i,j)+1, idx(i,t1), 1, calc(i,j,i,t1));
            }
            ans = - (gao.mincost (ss, tar) + n*m*maxx);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
