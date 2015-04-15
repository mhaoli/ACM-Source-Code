#include<bits/stdc++.h>
const int N = 9 + (int)2e5;
struct nod{
    nod *l, *r;
    long long w;
}Tnull, *null=&Tnull, memo[N*20], *bat=memo, *rt[N];
void init (){
    null->l = null->r = null;
    null->w = 0;
}
void insert (int v, int l, int r, nod *&x){
    (*bat) = (*x); x = bat++; x->w ++;
    if (l == r) return;
    int m = l + r >> 1;
    if (v <= m) insert (v, l, m, x->l);
    else insert (v, m+1, r, x->r);
}
long long query (nod *x, nod *y, int ql, int qr, int l, int r){
    if (ql <= l && r <= qr){
        return y->w - x->w;
    }
    int m = l + r >> 1;
    long long ret = 0;
    if (ql <= m) ret = query (x->l, y->l, ql, qr, l, m);
    if (qr > m) ret += query (x->r, y->r, ql, qr, m+1, r);
    return ret;
}
int s[N], a[N];
int main(){
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    init ();
    int n, m; scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf ("%d", a + i); s[i] = a[i];
    }
    std::sort (s + 1, s + n + 1);
    for (int i = 1; i <= n; ++ i)
        a[i] = std::lower_bound (s + 1, s + n + 1, a[i]) - s;

    rt[0] = null;
    long long ans = 0;
    int up = n + 1;
    for (int i = 1; i <= n; ++ i){
        insert (a[i], 0, up, rt[i] = rt[i-1]);
        ans += query (rt[0], rt[i-1], a[i]+1, up, 0, up);
    }
    //printf ("%lld\n", ans);
    long long tmp = ans;
    for (int i, j; m; -- m, tmp = ans){
        scanf ("%d%d", &i, &j);
        if (a[i] == a[j]) printf ("%lld\n", ans);
        else{
            if (i > j) std::swap (i, j);
            tmp += a[i] > a[j] ? -1 : 1;
            tmp += (query (rt[i], rt[j-1], a[i]+1, up, 0, up) - query (rt[i], rt[j-1], 0, a[i]-1, 0, up));
            tmp += (query (rt[i], rt[j-1], 0, a[j] - 1, 0, up) - query (rt[i], rt[j-1], a[j]+1, up, 0, up));
            printf ("%lld\n", tmp);
        }
    }
    return 0;
}
