/*
 * Author:  Plumrain
 * Created Time:  2014/8/28 14:16:45
 * File Name: J.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int v, nxt;
    int f, cap;
    int c;
    edge(){}
    edge(int _v, int cp, int _c, int n):v(_v), cap(cp), c(_c), nxt(n){f = 0;}
    int flow(){ return cap - f; }
};

template<class Tf, class Tc> 
struct Costflow{
    const static int maxn = 205;  //max node number
    const static int maxe = 5000;  //max edge number
    const static Tc maxx = 3e6;  //max cost

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

vi pos[5][40];

int calc (int t1, int t2){
    int p1 = 0, p2 = 0, ans = 0;
    while (p1 < sz (pos[0][t1]) && p2 < sz (pos[1][t2])){
        if (pos[0][t1][p1] == pos[1][t2][p2]) ++ p1, ++ p2, ++ ans;
        else if (pos[0][t1][p1] < pos[1][t2][p2]) ++ p1;
        else ++ p2;
    }
    return ans;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n, k, m;
        scanf ("%d%d%d", &n, &k, &m);
        rep (i, 0, 30) pos[0][i].clear ();

        char op[5];
        rep (i, 0, n-1){
            scanf ("%s", op);
            pos[0][op[0]-'A'].pb (i);
        }
        rep (xt, 0, m-1){
            rep (j, 0, 30) pos[1][j].clear ();
            rep (j, 0, n-1){
                scanf ("%s", op);
                pos[1][op[0]-'A'].pb (j);
            }

            int sta = 60, tar = 61;
            gao.init ();
            rep (j, 0, 25) rep (k, 0, 25){
                gao.add (j, k+26, 1, -1 * calc (j, k));
            }
            rep (j, 0, 25) gao.add (sta, j, 1, 0), gao.add (j+26, tar, 1, 0);
            pair<int, int> ans = gao.costflow (tar + 1, sta, tar);
            printf ("%.4f\n", -1.0 * ans.y / n);
        }
    }
    return 0;
}
