#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
const int N = 9 + (int)1e5;
int s[N], t[N], mx, last, n, m;
int c[3][30], low[N], eq[N], nxt[N], ans[N];
void modify (int *c, int x, int y){
    for (; x <= mx; x += lowbit(x)) c[x] += y;
}
int query (int *c, int x){
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += c[x];
    return ret;
}
bool ok (int *c, int *s, int p1, int p2){
    while (last < p2-p1) modify (c, s[last++], -1);
    return p1 != m && query (c, s[p2]-1) == low[p1] && query (c, s[p2]) == eq[p1];
}
int main(){
    scanf ("%d%d%d", &n, &m, &mx);
    for (int i = 0; i < n; ++ i) scanf ("%d", s + i);
    for (int i = 0; i < m; ++ i){
        scanf ("%d", t + i);
        low[i] = query (c[0], t[i]-1);
        eq[i] = query (c[0], t[i]);
        modify (c[0], t[i], 1);
    }
    nxt[0] = nxt[1] = 0;
    modify (c[1], t[0], 1);
    last = 0;
    for (int j = 0, i = 1; i < m; modify (c[1], t[i++], 1)){
        while (j && !ok (c[1], t, j, i)) j = nxt[j];
        nxt[i+1] = ok (c[1], t, j, i) ? ++j : j;
    }
    last = 0;
    int tot = 0;
    for (int i = 0, j = 0; i < n; modify (c[2], s[i++], 1)){
        while (j && !ok (c[2], s, j, i)) j = nxt[j];
        if (ok (c[2], s, j, i)) ++j;
        if (j == m) ans[tot++] = i - j + 2;
    }
    printf ("%d\n", tot);
    for (int i = 0; i < tot; ++ i) printf ("%d\n", ans[i]);
    return 0;
}
