/*
 * Author:  Plumrain
 * Created Time:  2014/8/1 12:45:30
 * File Name: HDU-4897.cpp
 * one test data:
 1
 8
 2 1
 3 2
 4 2
 5 2
 6 2
 7 1
 8 3
 10
 2 4 4
 2 2 3
 1 1 1
 3 3 5
 1 6 4
 1 3 7
 2 3 3
 3 1 5
 1 1 7
 3 1 7
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct Seg{
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

    int sum[maxn<<2];
    int cha[maxn<<2];
    int num[maxn]; 

    int ask_sum (int l, int r, int rt){
        if (!cha[rt]) return sum[rt];
        return r - l + 1 - sum[rt];
    }
    void pushup (int l, int r, int rt){
        int m = (l + r) >> 1;
        sum[rt] = ask_sum (lson) + ask_sum (rson);
    }
    void pushdown (int l, int r, int rt){
        if (cha[rt]){
            cha[rt] = 0;
            cha[rt<<1] ^= 1; cha[rt<<1|1] ^= 1;
        }
    }
    void build(int l, int r, int rt){
        cha[rt] = 0;
        if (l == r){
            sum[rt] = num[l]; return;
        }
        int m = (l + r) >> 1;
        build (lson); build (rson); 
        pushup(l, r, rt);
    }
    void modify (int ql, int qr, int l, int r, int rt){
        if (ql <= l && qr >= r){
            cha[rt] ^= 1; return;
        }
        pushdown (l, r, rt);
        int m = (l + r) >> 1;
        if (ql <= m) modify (ql, qr, lson);
        if (qr > m) modify (ql, qr, rson);
        pushup (l, r, rt);
    }
    int query (int ql, int qr, int l, int r, int rt){
        if (ql <= l && qr >= r) return ask_sum (l, r, rt);
        pushdown (l, r, rt);
        int m = (l + r) >> 1, ret = 0;
        if (m >= ql) ret += query (ql, qr, lson);
        if (m < qr) ret += query (ql, qr, rson);
        pushup (l, r, rt);
        return ret;
    }
}seg, pnt;

struct edge{
    int s, e, cost, nxt;
};

struct HLD{
    int n, r, id;
    int tot;
    int head[maxn];
    edge pat[2*maxn];
    int son[maxn];
    int siz[maxn];
    int dep[maxn];
    int fa[maxn];
    int hson_idx[maxn];
    int top[maxn];
    int pos[maxn];

    int pnt_pos[maxn], pnt_tot;

    void init(int _n, int _r){
        n = _n; r = _r; id = 0; 
        clr (head, -1); clr (son, -1);
    }
    void add (int s, int e, int w){
        pat[id].s = s; pat[id].e = e; pat[id].cost = w;
        pat[id].nxt = head[s]; head[s] = id ++;
    }
    void calc (){
        dfs1 (r, -1);
        tot = 0; top[r] = r; 
        pnt_tot = 0; pnt_pos[r] = ++ pnt_tot;
        dfs2 (r, -1);

        clr (seg.num, 0); clr (pnt.num, 0);
        seg.build(1, tot, 1); pnt.build (1, tot, 1);
    }
    void dfs1 (int u, int pre){
        fa[u] = pre; dep[u] = (pre==-1 ? 0 : dep[pre]) + 1;

        siz[u] = 1;
        int ma = 0, pos = -1, idx = -1;
        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e; if (v == pre) continue;
            dfs1 (v, u);
            siz[u] += siz[v];
            if (ma < siz[v]) ma = siz[v], pos = v, idx = i;
        }
        son[u] = pos; hson_idx[u] = idx;
    }
    void dfs2 (int u, int pre){
        if (son[u] != -1){
            top[son[u]]= top[u]; pos[son[u]] = ++tot;
            pnt_pos[son[u]] = ++ pnt_tot;
            dfs2 (son[u], u);
        }

        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e;
            if (son[u] == v || v == pre) continue;
            top[v] = v;
            pos[v] = ++tot;
            pnt_pos[v] = ++ pnt_tot;
            dfs2 (v, u);
        }
    }

    void modify1 (int t1, int t2){
        if (t1 == t2) return;
        int f1 = top[t1], f2 = top[t2];
        if (f1 == f2){
            if (dep[t1] < dep[t2]) swap (t1, t2);
            seg.modify (pos[son[t2]], pos[t1], 1, tot, 1);
            return;
        }

        if (dep[f1] < dep[f2]) swap (t1, t2), swap (f1, f2);
        if (f1 != t1){
            seg.modify (pos[son[f1]], pos[t1], 1, tot, 1);
            seg.modify (pos[f1], pos[f1], 1, tot, 1);
        }
        else seg.modify (pos[t1], pos[t1], 1, tot, 1);
        modify1 (fa[f1], t2);
    }
    void modify2 (int t1, int t2){
        if (t1 == t2){
            pnt.modify (pnt_pos[t1], pnt_pos[t1], 1, pnt_tot, 1);
            if (son[t1] != -1) seg.modify (pos[son[t1]], pos[son[t1]], 1, tot, 1);
            if (fa[t1] != -1 && son[fa[t1]] == t1) seg.modify (pos[t1], pos[t1], 1, tot, 1);
            return;
        }
        int f1 = top[t1], f2 = top[t2];
        if (f1 == f2){
            if (dep[t1] < dep[t2]) swap (t1, t2);
            pnt.modify (pnt_pos[t2], pnt_pos[t1], 1, pnt_tot, 1);
            if (son[t1] != -1) seg.modify (pos[son[t1]], pos[son[t1]], 1, tot, 1);
            if (fa[t2] != -1 && son[fa[t2]] == t2) seg.modify (pos[t2], pos[t2], 1, tot, 1);
            return;
        }

        if (dep[f1] < dep[f2]) swap (t1, t2), swap (f1, f2);
        if (t1 != f1) pnt.modify (pnt_pos[son[f1]], pnt_pos[t1], 1, pnt_tot, 1);
        pnt.modify (pnt_pos[f1], pnt_pos[f1], 1, pnt_tot, 1);
        if (son[t1] != -1) seg.modify (pos[son[t1]], pos[son[t1]], 1, tot, 1);
        modify2 (fa[f1], t2);
    }
    int query (int t1, int t2){
        if (t1 == t2) return 0;
        int f1 = top[t1], f2 = top[t2], ret = 0;
        if (f1 == f2){
            if (dep[t1] < dep[t2]) swap (t1, t2);
            return seg.query (pos[son[t2]], pos[t1], 1, tot, 1);
        }

        if (dep[f1] < dep[f2]) swap (t1, t2), swap (f1, f2);
        if (f1 != t1) ret += seg.query (pos[son[f1]], pos[t1], 1, tot, 1);

        t1 = f1;
        int tmp = pnt.query (pnt_pos[t1], pnt_pos[t1], 1, pnt_tot, 1);
        tmp ^= pnt.query (pnt_pos[fa[t1]], pnt_pos[fa[t1]], 1, pnt_tot, 1);
        ret += (seg.query (pos[t1], pos[t1], 1, tot, 1) ^ tmp);

        ret += query (fa[f1], t2);
        return ret;
    }
}gao;

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("1001.out","w",stdout);
    repcase{
        int n; scanf ("%d", &n);
        gao.init (n, 0);
        repf (i, 0, n-2){
            int t1, t2; 
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            gao.add (t1, t2, 0); gao.add (t2, t1, 0);
        }

        gao.calc ();

        int q; scanf ("%d", &q);
        while (q--){
            int t, l, r; scanf ("%d%d%d", &t, &l, &r); -- l; -- r;
            if (t == 1) gao.modify1 (l, r);
            else if (t == 2) gao.modify2 (l, r);
            else printf ("%d\n", gao.query (l, r));
        }
    }
    return 0;
}
