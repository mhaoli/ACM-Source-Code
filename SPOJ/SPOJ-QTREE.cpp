/*
 * Author:  Plumrain
 * Created Time:  2014/5/18 16:27:34
 * File Name: Tree-SPOJ-QTREE.cpp
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
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
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
const int maxn = 10005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int s, e, cost, nxt;
};

struct Seg{
    int ma[maxn<<2], num[maxn];

    void pushup (int rt){
        int ls = rt << 1, rs = ls | 1;
        ma[rt] = max (ma[ls], ma[rs]);
    }
    void build(int l, int r, int rt){
        if (l == r){
            ma[rt] = num[l]; return;
        }
        int m = (l + r) >> 1;
        build (lson); build (rson); pushup(rt);
    }
    void update (int q, int w, int l, int r, int rt){
        if (l == r){
            num[l] = w; ma[rt] = w; return;
        }

        int m = (l + r) >> 1;
        if (m >= q) update (q, w, lson);
        else update (q, w, rson);
        pushup (rt);
    }
    int calc (int ql, int qr, int l, int r, int rt){
        if (ql <= l && qr >= r) return ma[rt];
        int m = (l + r) >> 1, ret = 0;
        if (m >= ql) chmax (ret, calc (ql, qr, lson));
        if (m < qr) chmax (ret, calc (ql, qr, rson));
        return ret;
    }
}seg;

struct HLD{
    int n, r, tot;
    int head[maxn], son[maxn], siz[maxn], dep[maxn], fa[maxn], son_idx[maxn];
    int top[maxn], w[maxn];
    edge pat[2*maxn];

    void init (){
        dfs1 (r, -1);
        tot = -1; top[r] = r; dfs2 (r, -1);
        clr (seg.ma, 0); seg.build(0, tot, 1);
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
        son[u] = pos; son_idx[u] = idx;
    }
    void dfs2 (int u, int pre){
        if (son[u] != -1){
            top[son[u]]= top[u]; w[son[u]] = ++tot;
            seg.num[w[son[u]]] = pat[son_idx[u]].cost;
            dfs2 (son[u], u);
        }

        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e;
            if (son[u] == v || v == pre) continue;
            top[v] = v;
            w[v] = ++tot; seg.num[w[v]] = pat[i].cost;
            dfs2 (v, u);
        }
    }

    void add (int s, int e, int w, int id){
        pat[id].s = s; pat[id].e = e; pat[id].cost = w;
        pat[id].nxt = head[s]; head[s] = id;
    }
    void change (int id, int cost){
        int t1 = pat[id].s, t2 = pat[id].e;
        //tst (t1); out (t2); out (dep[t1] < dep[t2] ? w[t2] : w[t1]); out (cost); out (tot);
        seg.update (dep[t1] < dep[t2] ? w[t2] : w[t1], cost, 0, tot, 1);
    }
    int ask (int t1, int t2){
        if (t1 == t2) return 0;
        int f1 = top[t1], f2 = top[t2];
        if (f1 == f2){
            if (dep[t1] < dep[t2]) swap (t1, t2);
            return seg.calc (w[son[t2]], w[t1], 0, tot, 1);
        }
        if (dep[f2] > dep[f1]) swap (t1, t2), swap (f1, f2);

        int tmp = f1 == t1 ? 0 : seg.calc (w[son[f1]], w[t1], 0, tot, 1);
        return max (max (tmp, seg.num[w[f1]]), ask (fa[f1], t2));
    }
}tree;


int main()
{
    freopen("tst.in","r",stdin);
    freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &tree.n);
        int s, e, w;
        clr (tree.head, -1);
        int tot = 0;
        repf (i, 0, tree.n-2){
            scanf ("%d%d%d", &s, &e, &w);
            tree.add (s-1, e-1, w, tot);
            tree.add (e-1, s-1, w, tot + 1);
            tot += 2;
        }

        tree.r = 0;
        tree.init ();

        int t1, t2;
        while (1){
            char buf[100];
            scanf ("%s", buf);
            if (buf[0] == 'D') break;
            if (buf[0] == 'Q'){
                scanf ("%d%d", &t1, &t2);
                printf ("%d\n", tree.ask (t1-1, t2-1));
            }
            else{
                scanf ("%d%d", &t1, &t2);
                tree.change (2*t1-1, t2);
            }
        }
    }
    return 0;
}
