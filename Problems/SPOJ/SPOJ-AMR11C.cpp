/*
 * Author:  Plumrain
 * Created Time:  2014/7/30 13:15:07
 * File Name: C.cpp
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int s, e, cap, flow, cost;
    edge(){ }
    edge (int _s, int _e, int c, int f, int _c) : s(_s), e(_e), cap(c), flow(f), cost(_c){ }
};

template <class Tf, class Tc> struct MCMF{
    const static int maxn = 500;
    const static Tc maxx = 10;          //max cost
    
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
        //tst (s), tst (e), tst (cap), out (cost);
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

        if (d[t] >= maxx) return 0;
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

int vn[55], an[30];
int num1[20000], num2[20000];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T; scanf ("%d", &T);
    while (T--){
        int n, m; scanf ("%d%d", &m, &n);
        repf (i, 0, m-1) scanf ("%d", &vn[i]);

        int sta = m + n, tar = sta + 1;
        gao.init (tar + 1);
        repf (i, 0, n-1) gao.add (sta, i, 1, 0);
        repf (i, 0, m-1) gao.add (i+n, tar, 1, -vn[i]);

        int tn = n;

        while (n--){
            int cnt; scanf ("%d", &cnt);
            repf (j, 0, cnt-1) scanf ("%d", &an[j]);

            int n1 = cnt / 2, n2 = cnt - n1, s1 = (1<<n1) - 1, s2 = (1<<n2) - 1;

            num1[0] = num2[0] = 0;
            repf (i, 0, s1) repf (j, 0, n1-1) if ((i>>j) & 1){
                num1[i] = num1[i ^ (1<<j)] + an[j]; break;
            }
            
            repf (i, 0, s2) repf (j, 0, n2-1) if ((i>>j) & 1){
                num2[i] = num2[i ^ (1<<j)] + an[j+n1]; break;
            }

            sort (num1, num1+s1+1); sort (num2, num2+s2+1);
            repf (i, 0, m-1){
                int pos = 0;
                repd (j, s2, 0){
                    while (pos < s1 && num1[pos] + num2[j] < vn[i]) ++ pos;
                    if (num1[pos] + num2[j] == vn[i]){
                        gao.add (n, i+tn, 1, 0); break;
                    }
                }
            }
        }

        printf ("%d\n", -1 * gao.mincost (sta, tar));
    }
    return 0;
}
