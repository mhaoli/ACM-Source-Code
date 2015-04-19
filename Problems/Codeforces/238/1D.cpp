#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 9 + (int)1e5;
int f[Max_N][20], dep[Max_N], lg2[Max_N];
std::vector<int> son[Max_N];
void dfs(int x) {
        for(int i = 1; i <= lg2[dep[x]]; ++i) {
                f[x][i] = f[f[x][i-1]][i-1];
        }
        snuke(it, son[x]) {
                dep[*it] = dep[x] + 1;
                f[*it][0] = x;
                dfs(*it);
        }
}
int Up(int x, int l) {
        for(; l > 0; l -= 1<<lg2[l]) x = f[x][lg2[l]];
        return x;
}
int lca(int x, int y) {
        if(dep[x] < dep[y]) std::swap(x, y);
        if((x = Up(x, dep[x] - dep[y])) == y) return y;
        for(int i = lg2[dep[x]]; i >= 0; --i) if(f[x][i] != f[y][i]){
                x = f[x][i]; y = f[y][i];
        }
        return f[x][0];
}
int x[Max_N], stk[Max_N], top;
long long h[Max_N];
double calcK(int t1, int t2) {
        return (h[t2] - h[t1]) / (x[t2] - x[t1] + 0.0);
}
int main() {
        lg2[1] = 0;
        for(int i = 2; i < Max_N; ++i) lg2[i] = lg2[i>>1] + 1;

        int n; scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
                scanf("%d%I64d", x + i, h + i);
        }
        stk[top++] = n-1;
        for(int i = n-2; i >= 0; --i) {
                while(top > 1 && calcK(i, stk[top-1]) < calcK(stk[top-1], stk[top-2])) --top;
                son[stk[top-1]].push_back(i);
                stk[top++] = i;
        }
        f[n-1][dep[n-1] = 0] = -1;
        dfs(n - 1);

        int nq; scanf("%d", &nq);
        for(int u, v; nq--; ) {
                scanf("%d%d", &u, &v);
                printf("%d%c", lca(--u, --v) + 1, " \n"[!nq]);
        }
        return 0;
}
