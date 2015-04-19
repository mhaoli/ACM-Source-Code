#include<bits/stdc++.h>
const int N = 9 + (int)1e4;
const int M = 9 + (int)2e4;
struct DS{
#define lowbit(x) ((x)&(-x))
    struct nod{
        nod *ls, *rs;
        int v;
    }memo[N*20 + M*400], *bat, *rt0[N], *rt[N], *null, Tnull;
    bool FG;
    int n, up, top1, top2; //up = max_a[i]
    nod *Ql[N], *Qr[N];
    void init (){
        bat = memo;
        null = &Tnull;
        null->ls = null->rs = null;
        null->v = 0;
        for (int i = 0; i <= n; ++ i) rt[i] = null;
        rt0[0] = null;
    }
    void build (int _n, int _up, int *a){
        n = _n; up = _up;
        init ();
        FG = 1;
        for (int i = 1; i <= n; ++ i){
            insert (a[i], 1, 0, up, rt0[i] = rt0[i-1]);
        }
        FG = 0;
    }
    void insert (int v, int t, int l, int r, nod *&x){
        if (FG || x == null){
            *bat = *x; x = bat++;
        }
        x->v += t;
        if (l == r) return;
        int m = l + r >> 1;
        if (v <= m) insert (v, t, l, m, x->ls);
        else insert (v, t, m+1, r, x->rs);
    }
    void modify (int p, int v1, int v2){
        for (int i = p; i <= n; i += lowbit(i)){
            insert (v1, -1, 0, up, rt[i]);
            insert (v2, 1, 0, up, rt[i]);
        }
    }
    int query (int l, int r, int k){
        if (l == r) return l;
        int c = 0;
        for (int i = 0; i < top1; ++ i) c -= Ql[i]->ls->v;
        for (int i = 0; i < top2; ++ i) c += Qr[i]->ls->v;

        for (int i = 0; i < top1; ++ i) Ql[i] = c >= k ? Ql[i]->ls : Ql[i]->rs;
        for (int i = 0; i < top2; ++ i) Qr[i] = c >= k ? Qr[i]->ls : Qr[i]->rs;
        int m = l + r >> 1;
        if (k <= c) return query (l, m, k);
        else return query (m+1, r, k-c);
    }
    int solve (int l, int r, int k){
        top1 = top2 = 0;
        Ql[top1++] = rt0[l-1];
        Qr[top2++] = rt0[r];
        for (int i = l-1; i; i -= lowbit (i)) Ql[top1++] = rt[i];
        for (int i = r; i; i -= lowbit (i)) Qr[top2++] = rt[i];
        return query (0, up, k);
    }
}T;
char op[N][2];
int a[N], s[N<<1], rank[N<<1], l[N], r[N], k[N];
int main(){
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) 
        scanf ("%d", a + i), s[i] = a[i];
    int tot = n + 1;
    for (int i = 0; i < m; ++ i){
        scanf ("%s", op[i]);
        if (op[i][0] == 'Q'){
            scanf ("%d%d%d", l+i, r+i, k+i);
        } else{
            scanf ("%d%d", l + i, k + i);
            s[tot++] = k[i];
        }
    }
    std::sort (s + 1, s + tot);
    for (int i = 1, t; i <= n; ++ i){
        t = std::lower_bound (s+1, s+tot, a[i]) - s;
        rank[t] = a[i]; a[i] = t;
    }
    for (int i = 0, t; i < m; ++ i) if (op[i][0] == 'C'){
        t = std::lower_bound (s+1, s+tot, k[i]) - s;
        rank[t] = k[i]; k[i] = t;
    }

    T.build (n, tot, a);
    for (int i = 0; i < m; ++ i){
        if (op[i][0] == 'Q'){
            printf ("%d\n", rank[T.solve (l[i], r[i], k[i])]);
        } else{
            T.modify (l[i], a[l[i]], k[i]);
            a[l[i]] = k[i];
        }
    }
    return 0;
}
