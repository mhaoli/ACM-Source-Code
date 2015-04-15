#include<bits/stdc++.h>
#define foreach(i,T) for(__typeof(T.begin()) i = (T).begin(); i != T.end(); ++ i)
using namespace std;
const int N = 9 + (int)3e5;

struct nod;

struct edge{
    nod *v;
    edge *nxt;
    void add (nod *t, edge*n){ v = t; nxt = n;}
}memo2[N], *stp=memo2;
void adde (nod *v, edge *&hd){
    stp->add (v, hd); hd = stp++;
}

struct nod{
    nod *f, *belong;
    map<int, nod*> c;
    vector<int> q1, q2;
    int v1, v2, dep, sz;
    edge *head;
    nod*go (int ch);
}memo[N], *bat=memo, *rt = bat++, *q[N];
nod *nod::go (int ch){
    map<int, nod*>::iterator it = c.find (ch);
    if (it == c.end ()) return c[ch] = bat, bat++;
    return it->second;
}
void insert (int *t1, int *t2, int fg){
    nod*x = rt;
    for (; t1 != t2; ++ t1){
        x = x->go (*t1);
        if (fg > 0) x->q1.push_back (fg);
    }
    if (fg < 0) x->q2.push_back (-fg);
}
void build_AC (){
    int ql = 0, qr = 0;
    q[qr++] = rt;
    while (ql != qr){
        nod *x = q[ql++];
        foreach (it, x->c){
            nod *last = x->f;
            while (last && last->c.find (it->first) == last->c.end ()) last = last->f;
            if (last) it->second->f = last->c[it->first];
            else it->second->f = rt;
            q[qr++] = it->second;
        }
    }
    for (int i = 1; i < qr; ++ i) adde (q[i], q[i]->f->head);
}

int ans1[N], ans2[N];
nod *Q[N], *last[N];
void fail_tree_init (){
    int ql = 0, qr = 0;
    (Q[qr++] = rt)->dep = 0;
    for (; ql != qr; ++ ql){
        nod *x = Q[ql];
        for (edge*p = x->head; p; p = p->nxt){
            p->v->dep = x->dep + 1;
            p->v->v2 += x->v2 + p->v->q2.size ();
            Q[qr++] = p->v;
        }
    }
    for (ql = qr-1; ql; -- ql) Q[ql]->f->sz += ++(Q[ql]->sz);
    for (ql = 0; ql != qr; ++ ql){
        nod *x = Q[ql], *id;
        int mx = -1;
        if (!x->belong) x->belong = x;
        for (edge*p = x->head; p; p = p->nxt){
            if (p->v->sz > mx) mx = p->v->sz, id = p->v;
        }
        if (~mx) id->belong = x->belong;
    }
}

nod *LCA (nod *t1, nod *t2){
    while (true){
        if (t1->dep > t2->dep) swap (t1, t2);
        if (t1->belong == t2->belong) return t1;
        if (t1->belong->dep < t2->belong->dep) swap (t1, t2);
        t1 = t1->belong->f;
    }
    return t2;
}

void calc2 (nod *u){
    foreach (it, u->q1){
        nod *a = LCA (last[*it], u);
        last[*it] = u;
        ans2[*it] += u->v2 - a->v2;
        --a->v1; ++ u->v1;
    }
    for (edge*p = u->head; p; p = p->nxt) calc2 (p->v);
}

void calc1 (nod *u){
    for (edge*p = u->head; p; p = p->nxt){
        calc1 (p->v);
        u->v1 += p->v->v1;
    }
    foreach (it, u->q2) ans1[*it] = u->v1;
}

int tot;
int s[N];
void init (int n, int m){
    for (int i = 1, l; i <= n; ++ i){
        int *t = &s[tot];
        scanf ("%d", &l);
        for (int j = 0; j < l; ++ j)
            scanf ("%d", &s[tot++]);
        s[tot++] = -1;
        scanf ("%d", &l);
        for (int j = 0; j < l; ++ j)
            scanf ("%d", &s[tot++]);
        insert (t, &s[tot], i);
    }
    for (int i = 1, l; i <= m; ++ i){
        int *t = &s[tot];
        scanf ("%d", &l);
        for (int j = 0; j < l; ++ j)
            scanf ("%d", &s[tot++]);
        insert (t, &s[tot], -i);
    }
}

int main(){
    int n, m;
    scanf ("%d%d", &n, &m);
    init (n, m);

    build_AC ();
    fail_tree_init ();

    for (int i = 1; i <= n; ++ i) last[i] = rt;
    calc2 (rt);
    calc1 (rt);
    for (int i = 1; i <= m; ++ i) printf ("%d\n", ans1[i]);
    for (int i = 1; i <= n; ++ i) printf ("%d%c", ans2[i], " \n"[i==n]);
    return 0;
}
