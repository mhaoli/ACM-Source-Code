/*
 * Author:  Plumrain
 * Created Time:  2014/8/29 13:05:01
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
//template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
template <class T> int sgn(const T &x) { return x;}

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
    const static int maxn = 666;  //max node number
    const static int maxe = 666666;  //max edge number
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

int len[205];
char str[205][1005];

int calc (char *s, const int &ls, char *t, const int &lt){
    int ps = ls - 1, pt = 0, ret = 0;
    while (ps >= 0 && pt < lt){
        if (s[ps] != t[pt]) return ret;
        ++ ret; -- ps; ++ pt;
    }
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF){
        gao.init ();
        rep (i, 0, n-1) scanf ("%s", str[i]), len[i] = strlen (str[i]);

        int sta = n << 1, tar = sta | 1;
        rep (i, 0, n-1){
            gao.add (sta, i<<1, 1, 0);
            gao.add (i<<1|1, tar, 1, 0);
            gao.add (i<<1, i<<1|1, 1, 0);
        }
        rep (i, 0, n-1) rep (j, 0, n-1) if (i != j) 
            gao.add (i<<1, j<<1|1, 1, -1 * calc (str[i], len[i], str[j], len[j]));
        pair<int, int> ans = gao.costflow (tar + 1, sta, tar);
        printf ("%d\n", -ans.y);
    }
    return 0;
}
