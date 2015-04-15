#include<bits/stdc++.h>
const int N = 9 + (int)1e5;
struct Edge{
    int v; Edge *nxt;
    void add (int _v, Edge*n){ v = _v; nxt = n; }
}memo[N<<1], *bat=memo, *head[N];
int dep[N], mx;
void adde (int u, int v){
    bat->add (v, head[u]); head[u] = bat++;
}
void dfs (int u, int pre){
    mx = std::max (dep[u], mx);
    for (Edge* p = head[u]; p; p = p->nxt) if (p->v != pre){
        dep[p->v] = dep[u] + 1;
        dfs (p->v, u);
    }
}
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int add[N<<2];
long long sum[N<<2];
void Up (int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Down (int rt, int l, int r){
    int m = l + r >> 1;
    if (add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += (long long)add[rt] * (m - l + 1);
        sum[rt<<1|1] += (long long)add[rt] * (r - m);
        add[rt] = 0;
    }
}
void addIt (int ql, int qr, int v, int l, int r, int rt){
    if (ql <= l && r <= qr){
        add[rt] += v; sum[rt] += (long long)v * (r - l + 1);
        return;
    }
    int m = l + r >> 1;
    Down (rt, l, r);
    if (ql <= m) addIt (ql, qr, v, lson);
    if (qr > m) addIt (ql, qr, v, rson);
    Up (rt);
}
long long query (int ql, int qr, int l, int r, int rt){
    if (ql <= l && r <= qr) return sum[rt];
    int m = l + r >> 1;
    Down (rt, l, r);
    long long ret = 0;
    if (ql <= m) ret = query (ql, qr, lson);
    if (qr > m) ret += query (ql, qr, rson);
    Up (rt);
    return ret;
}
int main(){
    int n, k, up;
    scanf ("%d%d%d", &n, &k, &up);
    for (int i = 0, u, v; i < n-1; ++i){
        scanf ("%d%d", &u, &v);
        adde (--u, --v); adde (v, u);
    }
    mx = 0;
    dfs (0, -1);
    std::sort (dep, dep + n);
    for (int i = 1; i < n; ++i)
        addIt (i, i, mx-dep[i], 1, n-1, 1);
    int ans = 0;
    for (int i = n-1, l, r, m, res; i && ans < k;){
        l = std::max (1, i - k + 1); r = i; res = i + 1;
        while (l <= r){
            m = l + r >> 1;
            if (query (m, i, 1, n-1, 1) <= up) r = (res=m) - 1;
            else l = m + 1;
        }
        ans = std::max (ans, i - res + 1);
        addIt (1, i, -1, 1, n-1, 1);
        --i;
        while (i && dep[i] == dep[i+1]) --i;
    }
    printf ("%d\n", ans);
    return 0;
}
