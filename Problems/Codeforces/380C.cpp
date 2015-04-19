#include<bits/stdc++.h>
const int N = 9 + (int)1e6;
char s[N];
struct nod{
    int l, r, res;
    void add (const nod &t){
        int cnt = std::min (l, t.r);
        res += cnt + t.res;
        l += -cnt + t.l;
        r += t.r - cnt;
    }
    nod(){ l = r = res = 0; }
}a[N<<2];
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
nod build (int l, int r, int rt){
    if (l != r){
        int m = l + r >> 1;
        a[rt] = build (lson);
        a[rt].add (build (rson));
    } else s[l] == ')' ? a[rt].r = 1 : a[rt].l = 1;
    return a[rt];
}
nod query (int ql, int qr, int l, int r, int rt){
    if (ql <= l && r <= qr) return a[rt];
    int m = l + r >> 1;
    nod ret;
    if (ql <= m) ret = query (ql, qr, lson);
    if (qr > m) ret.add (query (ql, qr, rson));
    return ret;
}
int main(){
    scanf ("%s", s);
    int n = strlen (s), q, l, r;
    build (0, n-1, 1);
    for (scanf ("%d", &q); q--; ){
        scanf ("%d%d", &l, &r);
        printf ("%d\n", query (--l, --r, 0, n-1, 1).res << 1);
    }
    return 0;
}
