#include<bits/stdc++.h>
typedef unsigned long long UL;
const UL seed = 30007;
const UL delta = 257;
const int N = 9 + (int)2e5;
UL pp[N];
struct nod{
    nod *ch[2];
    int v, pro, sz;
    UL hash, val;
    int q (int x){
        return x == v ? -1 : (v < x ? 1 : 0);
    }
    void up (){
        sz = ch[0]->sz + ch[1]->sz + 1;
        hash = val + delta + ch[0]->hash * seed;
        hash = hash * pp[ch[1]->sz] + ch[1]->hash;
    }
}memo[N], *bat, *rt, Tnull, *null=&Tnull;
nod* newnod (int v, int val){
    nod* x = bat++;
    if (bat - memo == 1) rt = x;
    x->sz = 1; x->v = v; x->val = val;
    x->pro = rand ();
    x->ch[0] = x->ch[1] = null;
    x->up ();
    return x;
}
void rotate (nod* &r, int d){
    nod *t = r->ch[d^1];
    r->ch[d^1] = t->ch[d];
    t->ch[d] = r;
    r->up (); t->up ();
    if (r == rt) rt = t;
    r = t;
}
void init (){
    null->ch[0] = null->ch[1] = null;
    bat = memo;
    rt = null;
}
void insert (nod *&r, int v, int val){
    if (r == null){
        r = newnod (v, val);
    } else{
        int d = r->q (v);
        insert (r->ch[d], v, val);
        if (r->pro < r->ch[d]->pro) rotate (r, d^1);
        else r->up ();
    }
}
void del (nod *&r, int x){
    int d = r->q (x);
    if (d == -1){
        if (r->ch[0] == null) r = r->ch[1];
        else if (r->ch[1] == null) r = r->ch[0];
        else{
            int d2 = r->ch[0]->pro > r->ch[1]->pro ? 1 : 0;
            rotate (r, d2); del (r->ch[d2], x);
        }
    } else del (r->ch[d], x);
    if (r != null) r->up ();
}
int pos[N];
int main(){
    int n, m; 
    scanf ("%d%d", &n, &m);
    UL tmp = 0, val = 0;
    for (int t, i = 0; i < n; ++ i){
        scanf ("%d", &t);
        tmp += (pp[i] = i ? pp[i-1]*seed : 1);
        val = val * seed + delta + --t;
    }
    pp[n] = pp[n-1] * seed;
    for (int c, i = 0; i < m; ++ i){
        scanf ("%d", &c);
        pos[--c] = i;
    }
    init ();
    int ans = 0;
    for (int i = 0; i < m; ++ i){
        insert (rt, pos[i], i);
        if (i >= n){
            del (rt, pos[i-n]);
            val += tmp;
        }
        if (i >= n-1 && rt->hash == val) ++ ans;
    }
    printf ("%d\n", ans);
    return 0;
}
