#include<bits/stdc++.h>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N = 9 + (int)1e5;
const int maxx = (1<<30)-1;
int a[N<<2], cov[N<<2];
void Up (int rt){
    a[rt] = a[rt<<1] & a[rt<<1|1];
}
void Down (int rt){
        cov[rt<<1] |= cov[rt];
        cov[rt<<1|1] |= cov[rt];
        a[rt<<1] |= cov[rt];
        a[rt<<1|1] |= cov[rt];
        cov[rt] = 0;
}
void insert (int ql, int qr, int v, int l, int r, int rt){
    if (ql <= l && r <= qr){
        cov[rt] |= v; a[rt] |= v; return;
    }
    int m = l + r >> 1;
    Down (rt);
    if (ql <= m) insert (ql, qr, v, lson);
    if (qr > m) insert (ql, qr, v, rson);
    Up (rt);
}
int query (int ql, int qr, int l, int r, int rt){
    if (ql <= l && r <= qr) return a[rt];
    int m = l + r >> 1, ret = maxx;
    Down (rt);
    if (ql <= m) ret &= query (ql, qr, lson);
    if (qr > m) ret &= query (ql, qr, rson);
    Up (rt);
    return ret;
}
int n, m, fr[N], to[N], val[N];
int main(){
    scanf ("%d%d", &n, &m);
    for (int i = 0, u, v, t; i < m; ++ i){
        scanf ("%d%d%d", &u, &v, &t); -- u; -- v;
        fr[i] = u; to[i] = v; val[i] = t;
        insert (u, v, t, 0, n-1, 1);
    }
    for (int i = 0; i < m; ++ i)
        if (query (fr[i], to[i], 0, n-1, 1) != val[i]) return puts ("NO"), 0;
    puts ("YES");
    for (int i = 0; i < n; ++ i) printf ("%d%c", query (i, i, 0, n-1, 1), " \n"[i==n-1]);
    return 0;
}
