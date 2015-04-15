#include<bits/stdc++.h>
const int inf = ~0u>>2;
int n, m, M, d[44][333][333], i, j, k;
void dfs (int p, int x, int y){
        if (p >= m){
                d[i][x][y] = std::min (__builtin_popcount (y) + d[i-1][j][k], d[i][x][y]);
                return;
        }
        if (k & (1<<p)) dfs (p+1, x, y);
        else{
                if (p) dfs (p+1, x, y|(1<<p-1));
                if (p < m-1) dfs (p+1, x, y|(1<<p+1));
                dfs (p+1, x, y|(1<<p));
                dfs (p+1, x|(1<<p), y);
        }
}
int main(){
        scanf ("%d%d", &n, &m);
        if (n < m) std::swap (n, m);
        memset (d, 127, sizeof d);
        d[0][0][0] = 0;
        M = 1 << m;
        for (i = 1; i <= n; ++i)
                for (j = 0; j < M; ++j)
                        for (k = 0; k < M; ++k)
                                if (d[i-1][j][k] < inf) dfs (0, 0, j);
        int ans = n * m;
        for (i = 0; i < M; ++i) ans = std::min (ans, d[n][0][i]);
        printf ("%d\n", n * m - ans);
        return 0;
}
