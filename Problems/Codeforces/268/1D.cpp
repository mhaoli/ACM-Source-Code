/*
 * Author:  Plumrain
 * Created Time:  2014/9/23 11:09:03
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

const int N = int(1e5) + 9;

int mi[N<<2];

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int L, R, X, n;
int st[N], ed[N];

void modify (int l, int r, int rt){
    if (l < r){
        int m = (l + r) >> 1;
        if (L <= m) modify (lson);
        else modify (rson);
        mi[rt] = min (mi[rt<<1], mi[rt<<1|1]);
    } else mi[rt] = X;
}

int query (int l, int r, int rt){
    if (L > R) return inf;
    if (L <= l && r <= R){
        return mi[rt];
    }
    int m = (l + r) >> 1, ret = inf;
    if (L <= m) chmin (ret, query (lson));
    if (R > m) chmin (ret, query (rson));
    return ret;
}

int query (int u, int k){
    if (k){
        L = 0; R = st[u] - 1;
        int ret = query (0, n-1, 1);
        L = ed[u] + 1; R = n - 1;
        chmin (ret, query (0, n-1, 1));
        return ret;
    } else{
        L = st[u]; R = ed[u];
        return query (0, n-1, 1);
    }
}

struct Edge{
    int v, w;
    Edge (int _v = 0, int _w = 0) : v(_v), w(_w){}
};
vector<Edge> E[N];

int son[N], mxs[N], q[N], f[N], vis[N];

int get_rt (int u){
    int top = 0;
    q[top++] = u; f[u] = -1; son[u] = 1;
    rep (i, 0, n-2){
        for (auto v: E[q[i]]){
            if (v.v == f[q[i]]) continue;
            q[top++] = v.v;
            f[v.v] = q[i];
            mxs[v.v] = son[v.v] = 1;
        }
    }
    red (i, top-1, 1){
        son[f[q[i]]] += son[q[i]];
        chmax (mxs[q[i]], n - son[q[i]]);
        if (mxs[q[i]] * 2 <= n) return q[i];
        chmax (mxs[f[q[i]]], son[q[i]]);
    }
    return 0;
}

ll ans_num;
int brh[N], dfs_clock;

void dfs (int u, int pre, int br, ll dep){
    ans_num += 2 * dep;
    brh[u] = br;
    st[u] = dfs_clock ++;
    son[u] = 1;
    for (auto v: E[u]){
        if (v.v == pre) continue;
        dfs (v.v, u, br, dep + v.w);
        son[u] += son[v.v];
    }
    ed[u] = dfs_clock-1;
}

vi must;
int ans[N];
set<int> has[N];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf ("%d", &n);
    rep (i, 0, n-2){
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w); -- u; -- v;
        E[u].pb (Edge (v, w));
        E[v].pb (Edge (u, w));
    }
    int rt = get_rt (0);
    son[rt] = 1;
    brh[rt] = rt;
    st[rt] = dfs_clock ++;
    for (auto v: E[rt]){
        dfs (v.v, rt, v.v, v.w);
        has[son[v.v] = son[v.v]<<1].insert (v.v);
    }
    ed[rt] = 0;

    rep (i, 0, n-1){
        L = st[i]; X = i;
        modify (0, n-1, 1);
    }
    rep (i, 0, n-1){
        must.clear ();
        for (auto v: has[n-i]) must.pb (v);

        if (sz (must) == 2){
            ans[i] = query (must[brh[i] == must[0]], 0);
        } else if (sz (must) == 1){
            if (must[0] == brh[i]) ans[i] = query (brh[i], 1);
            else ans[i] = query (must[0], 0);
        } else{
            if (i == rt) ans[i] = mi[1];
            else ans[i] = query (brh[i], 1);
        }

        int u = brh[i], v = brh[ans[i]];
        L = st[ans[i]]; X = inf;
        modify (0, n-1, 1);
        if (u != rt){
            has[son[u]].erase (u);
            has[--son[u]].insert (u);
        }
        if (v != rt){
            has[son[v]].erase (v);
            has[--son[v]].insert (v);
        }
    }
    printf ("%I64d\n", ans_num);
    rep (i, 0, n-1){
        printf ("%d%c", ans[i] + 1, " \n"[i==n-1]);
    }
    return 0;
}
