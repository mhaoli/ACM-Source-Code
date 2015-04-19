//BZOJ 3224
#include<bits/stdc++.h>
const int N = 9 + (int)1e5;
struct nod{
    nod *ch[2];
    int v, pro, sz, num;
    int q (int x){
        return x == v ? -1 : (x < v ? 0 : 1);
    }
    void up (){
        sz = num + ch[0]->sz + ch[1]->sz;
    }
}memo[N<<1], *bat, *rt, Tnull, *null=&Tnull;
nod* newnod (int c){
    nod *x = bat++;
    if (bat - memo == 1) rt = x;
    x->ch[0] = x->ch[1] = null;
    x->v = c; x->pro = rand (); 
    x->num = x->sz = 1;
    return x;
}
void rotate (nod *&x, int d){
    nod *k = x->ch[d^1];
    x->ch[d^1] = k->ch[d];
    k->ch[d] = x;
    x->up (); k->up ();
    if (rt == x) rt = k;
    x = k;
}
void init (){
    null->ch[0] = null->ch[1] = null;
    null->num = null->sz = null->v = 0;
    bat = memo;
    rt = null;
}
void insert (nod *&r, int x){
    if (r == null){
        r = newnod (x);
    } else{
        int d = r->q(x);
        if (d == -1) r->num++, r->up ();
        else{
            insert (r->ch[d], x);
            if (r->pro < r->ch[d]->pro) rotate (r, d^1);
            else r->up ();
        }
    }
}
void del (nod *&r, int x){
    int d = r->q (x);
    if (d == -1){
        if (r->num > 1){
            r->num--, r->up ();
            return;
        } else{
            if (r->ch[0] == null) r = r->ch[1];
            else if (r->ch[1] == null) r = r->ch[0];
            else{
                int d2 = r->ch[0]->pro > r->ch[1]->pro ? 1 : 0;
                rotate (r, d2); del (r->ch[d2], x);
            }
        }
    } else del (r->ch[d], x);
    if (r != null) r->up ();
}

int ans;
int find_key (nod *r, int x){
    int d = r->q (x);
    if (d == -1) return r->ch[0]->sz + 1;
    else return find_key (r->ch[d], x) + (d ? r->ch[0]->sz + r->num : 0);
}
int find_kth (nod *r, int x){
    if (x <= r->ch[0]->sz) return find_kth (r->ch[0], x);
    else if (x <= r->ch[0]->sz + r->num) return r->v;
    else return find_kth (r->ch[1], x - r->ch[0]->sz - r->num);
}
void find_pre (nod *r, int x){
    if (r == null) return;
    if (r->q(x) == 1){
        if (ans < r->v) ans = r->v;
        find_pre (r->ch[1], x);
    } else find_pre (r->ch[0], x);
}
void find_suf (nod *r, int x){
    if (r == null) return;
    if (r->q(x) == 0){
        if (ans > r->v) ans = r->v;
        find_suf (r->ch[0], x);
    } else find_suf (r->ch[1], x);
}
int main(){
    srand (192737);
    init ();
    int _; scanf ("%d", &_);
    for (int op, t; _; --_){
        scanf ("%d%d", &op, &t);
        if (op == 1) insert (rt, t);
        else if (op == 2) del (rt, t);
        else if (op == 3) printf ("%d\n", find_key (rt, t));
        else if (op == 4) printf ("%d\n", find_kth (rt, t));
        else if (op == 5){
            ans = -(~0u>>1);
            printf ("%d\n", (find_pre (rt, t), ans));
        } else{
            ans = ~0u>>1;
            printf ("%d\n", (find_suf (rt, t), ans));
        }
    }
    return 0;
}
