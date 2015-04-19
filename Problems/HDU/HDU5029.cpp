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
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#define foreach(it,T) for(vector<int>::iterator it = T.begin(); it != T.end(); ++ it)
using namespace std;
const int N = 9 + (int)1e5;
struct SegT;
struct nod{
    nod *belong, *f;
    SegT *rt;
    int head, dep, sz, ans;
    vector<int> v1, v2;
    void clear (){
        sz = dep = head = 0; belong = f = 0;
        v1.clear (); v2.clear ();
    }
}T[N], *Q[N], *to[N<<1];
int nxt[N<<1], e_tot, qr;
void adde (int u, int v){
    nxt[e_tot] = T[u].head; to[e_tot] = T + v;
    T[u].head = e_tot++;
}
void tree_init (){
    int ql = 0, p, mx;
    qr = 0;
    (Q[qr++] = &T[0])->dep = 0;
    for (nod *x; ql != qr; ++ql){
        x = Q[ql];
        for (p = x->head; p; p = nxt[p]) if (to[p] != x->f){
            to[p]->dep = x->dep + 1;
            to[p]->f = x;
            Q[qr++] = to[p];
        }
    }
    for (ql = qr-1; ql; -- ql) Q[ql]->f->sz += ++ (Q[ql]->sz);
    for (nod *id, *x; ql != qr; ++ql){
        x = Q[ql];
        mx = -1;
        if (!x->belong) x->belong = x;
        for (p = x->head; p; p = nxt[p]) if (to[p] != x->f){
            if (to[p]->sz > mx) mx = (id = to[p])->sz;
        }
        if (mx != -1) id->belong = x->belong;
    }
}
nod *LCA (nod *x, nod *y){
    while (1){
        if (x->dep < y->dep) swap (x, y);
        if (x->belong == y->belong) return y;
        if (x->belong->dep < y->belong->dep) swap (x, y);
        x = x->belong->f;
    }
    return x;
}
struct SegT{
    SegT *ls, *rs, *f;
    int l, r, sz, mx;
    void up (){
        mx = max (ls->mx, rs->mx);
        sz = ls->sz + rs->sz;
    }
}memo[N*50], *bat, *stack[N*50], Tnull, *null=&Tnull;
int top;
SegT *newnod (int l = 0, int r = 100000, SegT*f = null){
    SegT *x = top ? stack[--top] : bat++;
    x->ls = x->rs = null; x->f = f;
    x->l = l; x->r = r;
    x->sz = x->mx = 0;
    return x;
}
void modify (int p, int c, SegT *r){
    int m;
    while (r->l != r->r){
        m = (r->l + r->r) >> 1;
        if (p <= m){
            if (r->ls == null) r->ls = newnod (r->l, m, r);
            r = r->ls;
        } else{
            if (r->rs == null) r->rs = newnod (m+1, r->r, r);
            r = r->rs;
        }
    }
    r->mx += c;
    if (r->mx > 0) r->sz = 1;
    r = r->f;
    while (r != null) r->up (), r = r->f;
}
int find_mx (SegT *r){
    if (!r->mx) return 0;
    while (r->l != r->r){
        if (r->ls->mx >= r->rs->mx) r = r->ls;
        else r = r->rs;
    }
    return r->l;
}
void merge (SegT *a, SegT *b){
    if (!b->sz) return;
    if (b->l != b->r) merge (a, b->ls), merge (a, b->rs);
    else modify (b->l, b->mx, a);
}
void recycle (SegT *x){
    if (x == null) return;
    recycle (x->ls); recycle (x->rs);
    stack[top++] = x;
}
void bfs (nod *x){
    int p;
    SegT *a, *b;
    for (int i = qr-1; i >= 0; -- i){
        (x = Q[i])->rt = newnod ();
        for (p = x->head; p; p = nxt[p]) if (to[p] != x->f){
            a = x->rt; b = to[p]->rt;
            if (a->sz < b->sz)
                swap (a, b), x->rt = a;
            merge (a, b);
            recycle (b);
        }
        foreach (it, x->v1) modify (*it, 1, x->rt);
        foreach (it, x->v2) modify (*it, -1, x->rt);
        x->ans = find_mx (x->rt);
        foreach (it, x->v2) modify (*it, -1, x->rt);
    }
}
int main(){
    null->ls = null->rs = null;
    null->sz = null->mx = 0;

    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF && n + m){
        for (int i = 0; i < n; ++ i) T[i].clear ();
        e_tot = 1;
        for (int i = 0, u, v; i < n-1; ++ i){
            scanf ("%d%d", &u, &v);
            adde (--u, --v); adde (v, u);
        }
        tree_init ();
        nod *A;
        for (int i = 0, a, b, c; i < m; ++ i){
            scanf ("%d%d%d", &a, &b, &c);
            T[--a].v1.push_back (c);
            T[--b].v1.push_back (c);
            A = LCA (T + a, T + b);
            A->v2.push_back (c);
        }
        bat = memo; top = 0;
        bfs (&T[0]);
        for (int i = 0; i < n; ++ i)
            printf ("%d\n", T[i].ans);
    }
    return 0;
}

