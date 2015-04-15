/*
 * Author:  Plumrain
 * Created Time:  2014/9/19 19:37:49
 * File Name: D.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
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

const int maxn = int(1e6) + 9;

struct edge{
    int v;
    edge *nxt;
    void add (int _v, edge *n){
        v = _v; nxt = n;
    }
}E[maxn], *bat, *head[maxn], E2[maxn], *bat2, *last[maxn];

struct SCC{
    int dfs_clock, cnt;
    int pre[maxn], lowlink[maxn];
    int stk[maxn], top;

    void dfs (int u, int*sccno){ 
        pre[u] = lowlink[u] = ++dfs_clock;
        stk[top++] = u;
        for (edge *p = head[u]; p; p = p->nxt){
            int v = p->v;
            if (!pre[v]){
                dfs (v, sccno);
                lowlink[u] = min (lowlink[u], lowlink[v]);
            } else if (sccno[v] == -1){
                lowlink[u] = min (lowlink[u], pre[v]);
            }
        }
        if (lowlink[u] == pre[u]){
            cnt ++;
            for (;;){
                int x = stk[--top];
                sccno[x] = cnt;
                if (x == u) break;
            }
        }
    }

    int find (int n, int*sccno){
        dfs_clock = top = 0; cnt = -1;
        memset (pre, 0, sizeof pre);
        for (int i = 0; i < n; ++ i)
            if (!pre[i]) dfs (i, sccno);
        return ++cnt;
    }
}scc;

vs vec;
int sccno[maxn];
map<string, int> has;
map<string, int>::iterator it;
pii w[maxn], wn[maxn], scc_w[maxn];
char str[maxn], ss[maxn];

void calc (char *s, pii &v){
    v.x = v.y = 0;
    while (s[0]){
        if (s[0] <= 'Z') s[0] = s[0] - 'A' + 'a';
        if (s[0] == 'r') ++ v.x;
        ++ s; ++ v.y;
    }
}

void add (int &t, char *str, int &tot){
    it = has.find (str);
    if (it == has.end ()){
        t = tot;
        has[str] = tot++;
    } else t = it->second;
}

void add_edge (int u, int v, edge*&bat, edge*head[]){
    bat->add (v, head[u]); head[u] = bat ++;
}

vi idx[maxn];
int stk[maxn], top, edge_num[maxn];
pii d[maxn];

void dfs (int u){
    if (~d[u].x) return;
    d[u] = scc_w[u];
    for (edge*p = last[u]; p; p = p->nxt){
        dfs (p->v);
        chmin (d[u], d[p->v]);
    }
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    pii Inf = pii(inf, inf);
    int n;
    while (scanf ("%d", &n) != EOF){
        vec.clear ();
        rep (i, 0, n-1){
            scanf ("%s", str);
            calc (str, wn[i]);
            vec.pb (string(str));
        }

        bat = E;
        clr (head, 0);
        has.clear ();
        int m, tot = 0;
        scanf ("%d", &m);
        while (m--){
            int t1, t2;
            pii tmp1, tmp2;
            scanf ("%s%s", str, ss);

            calc (str, tmp1);
            calc (ss, tmp2);

            add (t1, str, tot);
            add (t2, ss, tot);
            w[t1] = tmp1; w[t2] = tmp2;
            add_edge (t1, t2, bat, head);
        }

        clr (sccno, -1);
        int cnt = scc.find (tot, sccno);
        for (int i = 0; i < cnt; ++ i)
            scc_w[i] = Inf;

        bat2 = E2;
        rep (i, 0, cnt-1) idx[i].clear ();
        for (int i = 0; i < tot; ++ i){
            chmin (scc_w[sccno[i]], w[i]);
            idx[sccno[i]].pb (i);
        }
        clr (last, 0);
        for (int i = 0; i < cnt; ++ i){
            top = 0;
            for (int u: idx[i])
                for (edge*p = head[u]; p; p = p->nxt){
                    stk[top++] = sccno[p->v];
                }
            sort (stk, stk+top);

            if (top && stk[0] != i) add_edge (i, stk[0], bat2, last);
            rep (j, 1, top-1) if (stk[j] != stk[j-1] && stk[j] != i){
                add_edge (i, stk[j], bat2, last);
            }
        }

        pii temp = pii(-1, -1);
        rep (i, 0, cnt-1) d[i] = temp;
        for (int i = 0; i < cnt; ++ i) dfs (i);
        pair<ll, ll> ans(0, 0);
        pii tmp;
        rep (i, 0, sz (vec)-1){
            it = has.find (vec[i]);
            tmp = wn[i];
            if (it != has.end ()){
                chmin (tmp, d[sccno[it->second]]);
            }
            ans.x += tmp.x; ans.y += tmp.y;
        }
        cout << ans.x << " " << ans.y << endl;
    }
    return 0;
}
