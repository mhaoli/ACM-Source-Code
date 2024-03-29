/*
 * Author:  Plumrain
 * Created Time:  2014/4/30 12:01:31
 * File Name: Mincost-COGS-741.cpp
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
    int s, e, cap, flow, cost;
    edge(){ }
    edge (int _s, int _e, int c, int f, int _c) : s(_s), e(_e), cap(c), flow(f), cost(_c){ }
};

template <class Tf, class Tc> struct MCMF{
    const static int maxn = 1000;
    
    int n, m, s, t;
    vector<edge> pat;
    vi g[maxn];
    int inq[maxn];
    int p[maxn];        //from which path
    Tc d[maxn];         //SPFA, min cost
    Tf ff[maxn];

    void init(int _n){
        n = _n; m = 0;
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
        clr (d, 127); clr (inq, 0);
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

        if (d[t] >= inf) return 0;
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
        Tf flow = 0; Tc cost = 0;
        while (SPFA(flow, cost));
        return cost;
    }
};

MCMF<int, int> gao;
int an[105];

int main()
{
    freopen("overload.in","r",stdin);
    freopen("overload.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, sum = 0;
    cin >> n;
    repf (i, 1, n) cin >> an[i], sum += an[i];
    int tmp = sum / n;
    
    int sta = 0, tar = 2 * n + 1;
    gao.init (tar + 1);
    repf (i, 1, n){
        if (an[i] < tmp) gao.add (2*i, tar, tmp - an[i], 0);
        if (an[i] > tmp) gao.add (sta, 2*i-1, an[i] - tmp, 0);
    }
    repf (i, 1, n){
        int t1, t2, t3;
        if (i == n) t1 = 2*i-1, t2 = 2, t3 = 2*i - 2;
        else if (i == 1) t1 = 1, t2 = 4, t3 = 2*n;
        else t1 = 2*i-1, t2 = 2*i + 2, t3 = 2*i - 2;
        gao.add (t1, t2, inf, 1); gao.add (t1, t3, inf, 1);
        gao.add (t1, t2-1, inf, 1); gao.add (t1, t3-1, inf, 1);
    }
    cout << gao.mincost(sta, tar) << endl;
    return 0;
}
