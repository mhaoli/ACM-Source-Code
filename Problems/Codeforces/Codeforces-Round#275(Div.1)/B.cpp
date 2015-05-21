#include<bits/stdc++.h>
using namespace std;
const int N = 9 + (int)1e5;
struct nod{
    int u, v, c;
    bool operator<(const nod &o)const{
        if (c == o.c) return u == o.u ? v < o.v : u < o.u;
        return c > o.c;
    }
}a[N];
int cnt[N];
int fr[N], to[N], val[N], ans[N], n, m, nxt[N];
int solve (int t2){
    for (int i = 0; i < m; ++ i){
        a[i].u = fr[i], a[i].v = to[i], a[i].c = (val[i]&t2) > 0;
    }
    std::sort (a, a + m);
    memset (cnt, 0, sizeof cnt);
    for (int i = 0; i < m && a[i].c; ++ i){
        ++cnt[a[i].u]; --cnt[a[i].v+1];
    }
    //for (int i = 0; i < m; ++ i)
        //printf ("%d %d %d\n", a[i].u, a[i].v, a[i].c);
    for (int i = 0, num = 0; i < n; ++ i){
        num += cnt[i];
        if (num) ans[i] |= t2;
    }
    for (int i = n-1, last = n; i >= 0; -- i) {
        if ((ans[i] & t2) == 0) last = i;
        nxt[i] = last;
    }
    for (int i = m-1; i >= 0 && !a[i].c; -- i) 
        if (nxt[a[i].u] > a[i].v) return 1;
    return 0;
}
int main(){
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", fr+i, to+i, val+i);
        -- fr[i]; -- to[i];
    }
    bool u = 0;
    for (int i = 0, j = 1; i < 30 && !u; ++i, j<<=1) u |= solve (j);
    puts (!u ? "YES" : "NO");
    if (!u) for (int i = 0; i < n; ++i) printf ("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
