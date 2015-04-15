#include<bits/stdc++.h>
const long long inf = (long long)1e17;
const int N = 9 + (int)1e5;
const double eps = 1e-13;
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
struct nod{
    nod *pre, *ch[2];
    int sz;
    long long s, v;
    void up ();
    void setc (nod *c, int d){
        ch[d] = c;
        c->pre = this;
        up ();
    }
}Tnull, *null, memo[N<<1], *bat, *rt, *pool, *a[N];
void nod::up (){
    (v==inf || v==-inf) ? sz=s=0 : (sz=1,s=v);
    for (int i = 0; i < 2; ++ i){
        sz += ch[i]->sz; s += ch[i]->s;
    }
}
void rotate (nod *x, int c){
    nod *y = x->pre;
    y->ch[!c] = x->ch[c];
    if (x->ch[c] != null) x->ch[c]->pre = y;
    x->pre = y->pre;
    if (y->pre != null) y->pre->ch[y->pre->ch[1]==y] = x;
    x->ch[c] = y; y->pre = x;
    y->up ();
}
void splay (nod *x, nod *go){
    nod *y, *z;
    while (x->pre != go){
        if (x->pre->pre == go) rotate (x, x->pre->ch[0] == x);
        else{
            y = x->pre; z = y->pre;
            int f = z->ch[1] == y;
            if (y->ch[f] == x) rotate (y, !f);
            else rotate (x, f);
            rotate (x, !f);
        }
    }
    x->up ();
    if (go == null) rt = x;
}
nod *newnod (long long c){
    nod *x = pool ? pool : bat++;
    pool = 0;
    x->s = x->v = c; x->sz = 1;
    x->ch[0] = x->ch[1] = null;
    x->up ();
    return x;
}
void init (){
    null = &Tnull;
    null->ch[0] = null->ch[1] = null;
    null->sz = null->v = null->s = 0;
    pool = 0;
    bat = memo;
    rt = newnod (-inf); rt->pre = null;
    rt->setc (newnod (inf), 1);
}
nod *insert (int t, nod *x){
    nod *last, *res;
    while (x != null){
        last = x;
        if (t >= x->v) x = x->ch[1];
        else x = x->ch[0];
    }
    last->setc (res = newnod (t), t >= last->v);
    splay (res, null);
    return res;
}
nod *find (nod *x, int c){
    while (x->ch[c] != null) x = x->ch[c];
    return x;
}
void del (nod *t){
    splay (t, null);
    nod *pre = find (t->ch[0], 1), *nxt = find (t->ch[1], 0);
    splay (pre, null); splay (nxt, pre);
    nxt->ch[0] = null; nxt->up (); 
}
bool check (double m, long long up){
    nod *x = rt, *last;
    while (x != null){
        last = x;
        if (m >= x->v) x = x->ch[1];
        else x = x->ch[0];
    }
    if (sgn (last->v - m) <= 0){
        splay (last, null); 
        nod *nxt = find (last->ch[1], 0);
        splay (nxt, null);
        last = nxt->ch[0];
    } else{
        splay (last, null); 
        last = last->ch[0];
    }
    return (bool)(last->s + up <= last->sz * m);
}
int main(){
    int n, q; 
    scanf ("%d%d", &n, &q);
    init ();
    for (int i = 0, t; i < n; ++i){
        scanf ("%d", &t);
        a[i] = insert (t, rt);
    }

    long long t;
    for (int op, t1, t2, cnt; q; --q){
        scanf ("%d", &op);
        if (op == 1){
            scanf ("%d%d", &t1, &t2);
            del (pool = a[--t1]);
            a[t1] = insert (t2, rt);
        } else{
            scanf ("%I64d", &t);
            double r = (double)(1e16), l = 0, m;
            for (cnt = 0; cnt < 100; ++ cnt){
                m = (l + r) / 2;
                if (check (m, t)) r = m;
                else l = m;
            }
            printf ("%.5f\n", l);
        }
    }
    return 0;
}
