/*
 * Author:  Plumrain
 * Created Time:  2014/10/25 15:01:18
 * File Name: B.cpp
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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++ it)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/
const int N = 9 + (int)2e5;
struct edge{
    int v; edge *nxt;
    void add (int _v, edge *n){ v = _v; nxt = n;}
}memo[N], *bat, *head[N];
void add (int u, int v){
    bat->add (v, head[u]); head[u] = bat++;
}

int q[N], fa[N], sz[N], belong[N], dep[N], val[N];

void init(int rt){
    int qr = 0, ql;
    q[qr++] = 0; dep[rt] = 0; fa[rt] = -1;
    for (int i = 0, x; i != qr; ++ i){
        x = q[i];
        for (edge*p = head[x]; p; p = p->nxt) if (p->v != fa[x]){
            fa[p->v] = x;
            dep[p->v] = dep[x] + 1;
            q[qr++] = p->v;
        }
    }
    memset (sz, 0, sizeof sz);
    for (ql = qr - 1; ql; -- ql) sz[fa[q[ql]]] += (++ sz[q[ql]]);
    memset (belong, -1, sizeof belong);
    for (int mx, x, id; ql != qr; ++ ql){
        x = q[ql]; mx = -1; id = -1;
        if (belong[x] == -1) belong[x] = x;
        for (edge*p = head[x]; p; p = p->nxt) if (p->v != fa[x]){
            if (sz[p->v] > mx) mx = sz[id = p->v];
        }
        if (mx != -1) belong[id] = belong[x];
    }
}

bool ans[N<<1];
int last[N<<2];
int typ[N<<1];
vector<pair<int, int> > que[N];

int LCA (int x, int y){
    while (1){
        if (dep[x] > dep[y]) swap (x, y);
        if (belong[x] == belong[y]) return x;
        if (dep[belong[x]] > dep[belong[y]]) swap (x, y);
        y = fa[belong[y]];
    }
    return y;
}

void dfs (int r, int pre){
    int tmp = last[val[r]];
    last[val[r]] = dep[r];
    foreach (it, que[r]){
        int A = LCA (r, it->first), t = typ[it->second];
        if (last[t] >= dep[A]) ans[it->second] = 1;
    }
    for (edge*p = head[r]; p; p = p->nxt)
        if (p->v != pre) dfs (p->v, r);
    last[val[r]] = tmp;
}

set<int> st;
map<int, int> has;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        bat = memo;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", val + i);
            st.insert (val[i]);
        }
        memset (head, 0, sizeof head);
        for (int i = 0, t1, t2; i < n-1; ++ i){
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            add (t1, t2); add (t2, t1);
        }
        init (0);

        pair<int, int> tmp;
        for (int i = 0; i < n; ++ i) que[i].clear ();
        for (int i = 0, t1, t2; i < m; ++ i){
            scanf ("%d%d%d", &t1, &t2, typ + i); -- t1; -- t2;
            st.insert (typ[i]);
            tmp.first = t2; tmp.second = i;
            que[t1].push_back (tmp);
            tmp.first = t1;
            que[t2].push_back (tmp);
        }

        int cnt = 0;
        foreach (it, st) has[*it] = cnt++;
        for (int i = 0; i < n; ++ i) val[i] = has[val[i]];
        for (int i = 0; i < m; ++ i) typ[i] = has[typ[i]];
        
        memset (ans, 0, sizeof ans);
        memset (last, -1, sizeof last);
        dfs (0, -1);
        for (int i = 0; i < m; ++ i)
            puts (ans[i] ? "Find" : "NotFind");
    }
    return 0;
}
