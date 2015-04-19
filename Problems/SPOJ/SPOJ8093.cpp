#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof((T).begin()) it = (T).begin(); it != (T).end(); ++ it)
using namespace std;
const int N = 9 + (int)5e5;
char s[400009];
struct nod;
struct edge{
    nod *v; edge *nxt;
    void add (nod*t, edge*n){
        v = t; nxt = n;
    }
}memo2[N], *bat2=memo2;
void adde (nod *v, edge *&hd){
    bat2->add (v, hd); hd = bat2++;
}
struct nod{
    map<int, nod*> c;
    nod *f, *belong;
    int ans, dep, sz;
    edge *head;
    vector<int> v;
}memo[N], *bat = memo, *rt=bat++, *q[N], *pos[N], *last[N];
map<int, nod*>::iterator it;
void insert (char *s, int id){
    nod *x = rt;
    for (; s[0]; ++ s){
        it = x->c.find (s[0]);
        if (it == x->c.end ()) x->c[s[0]] = bat, x = bat++;
        else x = it->second;
        if (id > 0) x->v.push_back (id);
    }
    if (id < 0){
        pos[-id] = x;
    }
}
void AC_build (){
    int ql = 0, qr = 0;
    q[qr++] = rt;
    for (nod *x; ql != qr; ++ ql){
        x = q[ql];
        if (ql) adde (x, x->f->head);
        foreach (p, x->c){
            nod *last = x->f;
            while (last && last->c.find (p->first) == last->c.end ()) last = last->f;
            if (last) p->second->f = last->c[p->first];
            else p->second->f = rt;
            q[qr++] = p->second;
        }
    }
}
void fail_init (){
    int ql = 0, qr = 0;
    q[qr++] = rt; rt->dep = 0;
    for (nod *x; ql != qr; ++ ql){
        x = q[ql];
        for (edge *p = x->head; p; p = p->nxt){
            p->v->dep = x->dep + 1;
            q[qr++] = p->v;
        }
    }
    for (ql = qr-1; ql; -- ql) q[ql]->f->sz += ++(q[ql]->sz);
    for (nod *x, *id; ql != qr; ++ ql){
        x = q[ql];
        if (!x->belong) x->belong = x;
        int mx = -1;
        for (edge *p = x->head; p; p = p->nxt){
            if (p->v->sz > mx) mx = p->v->sz, id = p->v;
        }
        if (~mx) id->belong = x->belong;
    }
}
nod *LCA (nod *a, nod *b){
    while (1){
        if (a->dep < b->dep) swap (a, b);
        if (a->belong == b->belong) return b;
        if (a->belong->dep < b->belong->dep) swap (a, b);
        a = a->belong->f;
    }
    return b;
}
void dfs1 (nod *r){
    foreach (p, r->v){
        nod *A = LCA (r, last[*p]);
        last[*p] = r;
        A->ans -= 1; r->ans += 1;
    }
    for (edge *p = r->head; p; p = p->nxt){
        dfs1 (p->v);
    }
}
void dfs2 (nod *r){
    for (edge *p = r->head; p; p = p->nxt){
        dfs2 (p->v);
        r->ans += p->v->ans;
    }
}
int main(){
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf ("%s", s);
        insert (s, i);
    }
    for (int i = 1; i <= m; ++ i){
        scanf ("%s", s);
        insert (s, -i);
    }
    AC_build ();
    fail_init ();
    for (int i = 1; i <= n; ++ i) last[i] = rt;
    dfs1 (rt);
    dfs2 (rt);
    for (int i = 1; i <= m; ++ i)
        printf ("%d\n", pos[i]->ans);
    return 0;
}
