#include<bits/stdc++.h>
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int N = 9 + (int)3e5;
const long long mod = 7 + (int)1e9;
int lef[N], right[N], dfs_clock;
long long dep[N];
std::vector<int> son[N];
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}
void dfs (int u, int pre){
    lef[u] = ++dfs_clock;
    foreach (it, son[u]) if (*it != pre){
        dep[*it] = dep[u] + 1;
        dfs (*it, u);
    }
    right[u] = dfs_clock;
}
#define lowbit(x) ((x)&(-x))
int c[2][N];
int query (int *c, int p){
    int ret = 0;
    for (; p <= dfs_clock; p += lowbit(p)) add (ret, c[p]);
    return ret;
}
void modify (int *c, int p, int v){
    for (; p; p -= lowbit (p)) add (c[p], v);
}
void modify (int *c, int ql, int qr, int v){
    modify (c, qr, v); modify (c, ql-1, mod-v);
}
int main(){
    int n; scanf ("%d", &n);
    for (int i = 1, t; i < n; ++i){
        scanf ("%d", &t);
        son[--t].push_back (i);
    }

    dfs (0, -1);
    
    int m; scanf ("%d", &m);
    for (int ans, op, t, t1, t2; m--; ){
        scanf ("%d%d", &op, &t); --t;
        if (op == 1){
            scanf ("%d%d", &t1, &t2);
            add (t1, dep[t] * t2 % mod);
            modify (c[0], lef[t], right[t], t1);
            modify (c[1], lef[t], right[t], t2); 
        } else{
            ans = query (c[0], lef[t]);
            add (ans, mod - (query (c[1], lef[t]) * dep[t] % mod));
            printf ("%d\n", ans);
        }
    }
    return 0;
}
