/*
 * Author:  Plumrain
 * Created Time:  2014/8/8 10:53:07
 * File Name: G.cpp
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
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const int eps = 0;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int in[505], ou[505];

template<class Tf, class Tc> 
struct Costflow{
    const static int maxn = 205;  //max node number
    const static int maxe = 5000;  //max edge number
    const static Tc maxx = 3e6;  //max cost
    //3 * maxx < maxint
    //change the type of eps

    struct edge{
        int v, nxt;
        Tf f, cap;
        Tc c;
        edge(){}
        edge(int _v, Tf cp, Tc _c, int n):v(_v), cap(cp), c(_c), nxt(n){f = 0;}
        Tf flow(){ return cap - f; }
    };

    int head[maxn];
    int pre[maxn];
    int vis[maxn];
    int n, m, s, t;
    edge e[maxe];    //edge
    Tc dis[maxn];
    void add(int u, int v, Tf f, Tc c){
        e[m] = edge(v, f, c, head[u]); head[u] = m++;
        e[m] = edge(u, 0, -c, head[v]); head[v] = m++; 
    }
    void init(){
        m = 0; clr (head, -1);
    }
    int spfa(){
        for (int i = 0; i <= n; ++i) dis[i] = maxx; dis[s] = 0;
        memset(vis, 0, sizeof(vis)); vis[s] = 1;
        memset(pre, -1, sizeof(pre));
        queue<int> q; q.push(s); 
        int p, u, v;
        while (!q.empty()){
            for (p = head[u=q.front()]; ~p; p = e[p].nxt){
                v = e[p].v;
                if (sgn (dis[v] - dis[u] - e[p].c) > 0 && sgn (e[p].flow()) > 0){
                    dis[v] = dis[u] + e[p].c;
                    pre[v] = p;
                    if (!vis[v]) vis[v] = 1, q.push(v);
                }   
            }
            vis[u] = 0; q.pop(); 
        }
        return sgn (maxx - dis[t]) > 0;  
    }
    pair<Tf, Tc> costflow(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        Tc cost = 0; Tf flow = 0;
        while (spfa()){
            Tf f = maxx;
            for (int p = pre[t]; p != -1; p = pre[e[p^1].v]) chmin(f, e[p].flow());
            flow += f;
            cost += f * dis[t];
            for (int p = pre[t]; p != -1; p = pre[e[p^1].v])
                e[p].f += f, e[p^1].f -= f;     
        }
        return make_pair(flow, cost);
    }
    /***********/ 
};

Costflow<int, int> gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n, m, s, t; cin >> n >> m >> s >> t; -- s; -- t;
        int sta = n, tar = sta + 1;
        gao.init ();
        //gao.add (sta, s, 1, 0);
        //gao.add (t, tar, 1, 0);

        int sum = 0;
        clr (in, 0); clr (ou, 0); ++ in[s]; ++ ou[t];
        repf (i, 0, m-1){
            int t1, t2, a, b;
            cin >> t1 >> t2 >> a >> b; -- t1; -- t2;
            if (a >= b) gao.add (t1, t2, 1, a-b), sum += b;
            else gao.add (t2, t1, 1, b-a), ++ ou[t1], ++ in[t2], sum += a;
        }

        int tsum = 0;
        repf (i, 0, n-1){
            if (in[i] > ou[i]) gao.add (sta, i, in[i]-ou[i], 0), tsum += in[i] - ou[i];
            else gao.add (i, tar, ou[i]-in[i], 0);
        }
        printf ("Case %d: ", ++ cas);
        pii ans = gao.costflow (tar+1, sta, tar);
        if (ans.x == tsum) printf ("%d\n", ans.y + sum);
        else puts ("impossible");
    }
    return 0;
}
