/*
 * Author:  Plumrain
 * Created Time:  2014/9/12 15:16:57
 * File Name: ZOJ3760.cpp
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

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
//const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
//template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

template <class T> int sgn(T x) { return (x > 0) - (x < 0);}

template <class T> struct dinic{
    const static int maxn = 555;
    const static int maxe = int(6e5) + 9;
    const static T inf = 1LL << 50;

    struct edge{
        int s, e;
        T cap, f;
        edge *nxt;
        void add (int _s, int _e, T c, edge *t){
            f = 0; s = _s; e = _e; cap = c; nxt = t;
        }
        T flow(){ return cap - f;}
    };

    T flow;
    int n, m, s, t;         // 0,1,2...n-1
    edge memo[maxe];        //edge
    edge *bat, *head[maxn], *cur[maxn];
    int d[maxn]; // distance
    bool vis[maxn];    

    void init(){
        bat = memo;
        clr (head, 0);
    }
    void add (int s, int e, T cap){
        bat -> add (s, e, cap, head[s]); head[s] = bat++;
        bat -> add (e, s, 0, head[e]); head[e] = bat++;
    }
    bool bfs(){
        queue<int> q;
        q.push (s); d[s] = 0;
        clr (vis, 0); vis[s] = 1; 
        while (sz(q)){
            int x = q.front(); q.pop();
            for (edge *e = head[x]; e; e = e->nxt){
                if (!vis[e->e] && e->flow() > 0){
                    q.push (e->e);
                    vis[e->e] = 1;
                    d[e->e] = d[x] + 1;
                }
            }
        }
        return vis[t];
    }
    T dfs (int x, T rf){
        if (x == t || sgn(rf) == 0) return rf;
        T flow = 0, ff;
        for (edge *&e = cur[x]; e; e = e->nxt){
            T tmp = rf; chmin (tmp, e->flow());
            if (d[e->e] == d[x] + 1 && (ff = dfs (e->e, tmp)) > 0){
                e->f += ff;
                memo[(e-memo)^1].f -= ff;
                flow += ff; rf -= ff;
                if (sgn(rf) == 0) break;
            }
        }
        return flow;
    }
    T maxflow(int _n, int _s, int _t){
        n = _n; flow = 0;
        s = _s; t = _t;
        while (bfs()){
            //clr (cur, 0);
            for (int i = 0; i < n; ++ i) cur[i] = head[i];
            flow += dfs (s, inf);
        }
        return flow;
    }
};

dinic<int64> gao;

const int maxn = int(1e5) + 9;
const int64 inf = 1LL << 50;
int col[maxn], val[maxn];
pii cor[maxn];

bool connect (const int &t1, const int &t2, const int &p){
    int t = cor[t1].x ^ cor[t2].x ^ cor[t1].y ^ cor[t2].y;
    return __gcd (t, p) == 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, p;
    while (scanf ("%d%d", &n, &p) != EOF){
        clr (col, 0);
        int64 sum = 0;
        rep (i, 0, n-1){
            scanf ("%d%d", &cor[i].x, &cor[i].y);
            val[i] = cor[i].x & cor[i].y;
            sum += val[i];
        }

        int sta = n, tar = n + 1;
        gao.init ();
        rep (i, 0, n-1) rep (j, 0, n-1)
            if (i != j && connect (i, j, p)){
                if (!col[i] && !col[j]){
                    col[i] = 1; col[j] = 2;
                    gao.add (i, j, inf);
                } else{
                    if (col[i]) col[j] = 3 - col[i];
                    else col[i] = 3 - col[j];
                    if (col[i] == 1) gao.add (i, j, inf);
                    else gao.add (j, i, inf);
                }
            }

        rep (i, 0, n-1){
            if (col[i] == 1) gao.add (sta, i, val[i]);
            else gao.add (i, tar, val[i]);
        }
        printf ("%lld\n", sum - gao.maxflow (tar + 1, sta, tar));
    }
    return 0;
}
