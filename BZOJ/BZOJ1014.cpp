/*
 * Author:  Plumrain
 * Created Time:  2014/10/15 11:41:16
 * File Name: BZOJ1014.cpp
 */
#include<bits/stdc++.h>
typedef unsigned long long UL;
const int N = 9 + (int)1e5;
const UL seed = 257;
UL pp[N];
int n;
struct nod{
    nod *ch[2], *pre;
    int s;
    UL key, v;
    void up (){
        UL &t = key;
        t = ch[0]->key * seed + v;
        t = t * pp[ch[1]->s] + ch[1]->key;
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down (){
    }
    bool q(){
        return this == pre->ch[1];
    }
    void setc (nod *c, int d){
        ch[d] = c; c->pre = this; up ();
    }
}Tnull, *null=&Tnull, memo[N], *bat = memo, *rt;
void rotate (nod*x, int c){
    nod *y = x->pre;
    y->down (); x->down ();
    
    y->ch[!c] = x->ch[c];
    if (x->ch[c] != null) x->ch[c]->pre = y;
    x->pre = y->pre;
    if (y->pre != null) y->pre->ch[y->pre->ch[1]==y] = x;
    x->ch[c] = y; y->pre = x;
    
    y->up ();
}
void splay (nod *x, nod *go, nod*&r){
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
    x->up ();
    if (go == null) r = x;
}
void rto (int k, nod *go, nod *&r){
    nod *x = r;
    x->down ();
    while (x->ch[0]->s != k){
        if (x->ch[0]->s > k) x = x->ch[0];
        else{
            k -= x->ch[0]->s + 1;
            x = x->ch[1];
        }
        x->down ();
    }
    splay (x, go, r);
}

/*
void Debug (nod *x){
    if (x != null){
        printf ("id:%2d pre:%2d lson:%2d rson:%2d size:%2d v:%2d, key:%2d\n", x->id, x->pre->id, x->ch[0]->id, x->ch[1]->id, x->s, x->v, (int)x->key);
        x->down ();
        Debug (x->ch[0]); Debug (x->ch[1]);
    }
}
*/

nod*newnod (UL v){
    nod *x = bat++;
    x->s = 1; x->v = v;
    x->ch[0] = x->ch[1] = null;
    x->up ();
    return x;
}
void splay_init (nod *&r){
    r = newnod (0); r->pre = null;
    r->setc (newnod (0), 1);
}

char s[N], op[10];

nod *build (int l, int r){
    int m = (l + r) >> 1;
    nod *x = newnod (s[m]-'a'+1);
    if (m > l) x->setc (build (l, m-1), 0);
    if (m < r) x->setc (build (m+1, r), 1);
    return x;
}
UL Hash (int p, int l){
    rto (p, null, rt);
    rto (p+l+1, rt, rt);
    return rt->ch[1]->ch[0]->key;
}

void init (){
    n = strlen (s);
    for (int i = 0; i < N; ++ i){
        pp[i] = i ? pp[i-1]*seed : 1;
    }
    null->s = 0;
    null->key = null->v = 0;
    splay_init (rt);
    rt->ch[1]->setc (build (0, n-1), 0);
    rt->up ();
}
int calc (int t1, int t2){
    int res = 0;
    if (t1 > t2) std::swap (t1, t2);
    for (int l = 0, r = n, m; m = (l+r)>>1, l <= r; ){
        if (t2 + m <= n && Hash(t1,m) == Hash(t2, m)) res = m, l = m + 1;
        else r = m - 1;
    }
    return res;
}
void modify (int t1, char d){
    rto (t1, null, rt);
    rto (t1+2, rt, rt);
    rt->ch[1]->ch[0]->v = d-'a'+1;
    rt->ch[1]->ch[0]->up ();
    rt->ch[1]->up (); rt->up ();
}
void insert (int t1, char d){
    ++ n;
    rto (t1+1, null, rt);
    rto (t1+2, rt, rt);
    rt->ch[1]->setc (newnod (d-'a'+1), 0);
    rt->up ();
}

int main(){
    scanf ("%s", s);
    init ();
    int m, t1, t2;
    scanf ("%d", &m);
    while (m--){
        scanf ("%s%d", op, &t1); -- t1;
        if (op[0] == 'Q'){
            scanf ("%d", &t2); -- t2;
            printf ("%d\n", calc (t1, t2));
        } else if (op[0] == 'R'){
            scanf ("%s", op);
            modify (t1, op[0]);
        } else{
            scanf ("%s", op);
            insert (t1, op[0]);
        }
    }
    return 0;
}
