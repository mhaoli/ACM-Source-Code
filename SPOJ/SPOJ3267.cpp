#include<bits/stdc++.h>
const int N = 9 + (int)3e4;
struct nod{
    nod *ls, *rs;
    int l, r, v;
}memo[N*40], *bat=memo, *rt[N], Tnull, *null=&Tnull;
void init (){
    null->ls = null->rs = null;
    null->v = null->l = null->r = 0;
}
void insert (int p, int v, int l, int r, nod *&x){
    *bat = *x; x = bat ++;
    x->l = l; x->r = r; x->v += v;
    if (l == r) return;
    int m = l + r >> 1;
    if (p <= m) insert (p, v, l, m, x->ls);
    else insert (p, v, m+1, r, x->rs);
}
int query (int l, nod *x){
    if (l <= x->l) return x->v;
    int m = x->l + x->r >> 1;
    if (l <= m) return query (l, x->ls) + x->rs->v;
    else return query (l, x->rs);
}
int last[9 + (int)1e6], a[N];
int main(){
    init ();
    int n; scanf ("%d", &n);
    for (int i = 1; i <= n; ++ i)
        scanf ("%d", a + i);

    rt[0] = null;
    nod *x;
    for (int i = 1; i <= n; ++ i){
        if (last[a[i]]){
            insert (last[a[i]], -1, 1, n, x = rt[i-1]);
            insert (i, 1, 1, n, rt[i] = x);
        } else insert (i, 1, 1, n, rt[i] = rt[i-1]);
        last[a[i]] = i;
    }
    int m; scanf ("%d", &m);
    for (int t1, t2; m; -- m){
        scanf ("%d%d", &t1, &t2);
        if (t1 > t2) std::swap (t1, t2);
        printf ("%d\n", query (t1, rt[t2]));
    }
    return 0;
}
