//bzoj 2733
#include<bits/stdc++.h>
const int N = 9 + (int)1e5;
const int inf = ~0u>>1;
struct nod{
    nod *pre, *ch[2];
    int sz, v;
    void up ();
    void setc (nod *c, int d){
        ch[d] = c;
        c->pre = this;
        up ();
    }
}Tnull, *null=&Tnull, mem[N], *bat=mem, mem2[N<<1], *stp=mem2;
void nod::up (){
    if (this != null){
        sz = 1 + ch[0]->sz + ch[1]->sz;
    }
}
//c = 0 left, c = 1 right
void rotate (nod *x, int c){
    nod *y = x->pre;

    y->ch[!c] = x->ch[c];
    if (x->ch[c] != null) x->ch[c]->pre = y;
    x->pre = y->pre;
    if (y->pre != null) y->pre->ch[y->pre->ch[1]==y] = x;
    x->ch[c] = y; y->pre = x;

    y->up();
}

//旋转到go节点下面，如果旋转到根go = null
void splay (nod *x, nod *go = null){
    while (x->pre != go){
        if (x->pre->pre == go) rotate (x, x->pre->ch[0] == x);
        else{
            nod *y = x->pre, *z = y->pre;
            int f = z->ch[1] == y;
            if (y->ch[f] == x) rotate (y, !f);
            else rotate (x, f);
            rotate (x, !f);
        }
    }
    x->up();
}

//把第k大的数旋转到go, idx from 0
//返回操作以后Splay的根
nod *rto(int k, nod *go, nod *r){
    nod *x = r;
    while (x->ch[0]->sz != k){
        if (x->ch[0]->sz > k) x = x->ch[0];
        else{
            k -= x->ch[0]->sz + 1;
            x = x->ch[1];
        }
    }
    splay (x, go);
    return x;
}
nod* newnod (int v, bool fg = 0){
    nod *x = fg ? bat++ : stp++;
    x->v = v; x->sz = 1;
    x->ch[0] = x->ch[1] = null;
    return x;
}
void init (int v){
    nod *r = newnod (-inf); r->pre = null;
    r->setc (newnod (inf), 1);
    r->ch[1]->setc (newnod (v, 1), 0);
    r->up ();
}
void insert (nod *&r, nod *x){
    nod *last, *t = r;
    while (t != null){
        last = t;
        if (x->v >= t->v) t = t->ch[1];
        else t = t->ch[0];
    }
    x->ch[0] = x->ch[1] = null;
    x->sz = 1;
    last->setc (x, x->v >= last->v);
    splay (x, null);
    r = x;
}
void dfs_merge (nod *x, nod *&y){
    if (x == null) return;
    nod *t1 = x->ch[0], *t2 = x->ch[1];
    dfs_merge (t1, y);
    if (x->v != inf && x->v != -inf){
        insert (y, x);
    }
    dfs_merge (t2, y);
}
void merge (int t1, int t2){
    nod *x = &mem[t1], *y = &mem[t2], *t;
    splay (x);
    splay (y);
    if (x->sz > y->sz){ t = x; x = y; y = t;}
    dfs_merge (x, y);
}
int find_kth (nod *r, int k){
    splay (r);
    if (k > r->sz - 2) return -1;
    return rto (k, null, r) - mem + 1;
}

int fa[N];
int find (int x){
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}
int main(){
    null->ch[0] = null->ch[1] = null;

    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0, t; i < n; ++i){
        scanf ("%d", &t);
        fa[i] = i;
        init (t);
    }
    for (int i = 0, t1, t2, u, v; i < m; ++i){
        scanf ("%d%d", &u, &v);
        t1 = find (--u); t2 = find (--v);
        if (t1 != t2){
            merge (t1, t2);
            fa[t1] = t2;
        }
    }
    int q, u, v, t1, t2;
    scanf ("%d", &q);
    for (char op[10]; q--; ){
        scanf ("%s%d%d", op, &u, &v); 
        //printf ("%d %d\n", u, v);
        if (op[0] == 'Q'){
            t1 = find (--u);
            printf ("%d\n", find_kth (&mem[t1], v));
        } else{
            t1 = find (--u); t2 = find (--v);
            if (t1 != t2){
                merge (t1, t2);
                fa[t1] = t2;
            }
        }
    }
    return 0;
}
