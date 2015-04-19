#include<bits/stdc++.h>
const int N = 3111;
int a[N], mx[N], last, d[N][N], n;
void dfs (int k, int x, int y){
        if (d[x][y] >= k) return;
        d[x][y] = k;
        if (!k || (!a[x] && !mx[y]) || y >= n || (y == n-1 && x == y)) return;
        if (x == y){
                if (a[x] && mx[x+1]) dfs (k-1, x + 2, y + 2);
                if (a[x] != 100 && mx[x+1]) dfs (k-1, x+1, y+1);
                if (a[x] && last <= x) dfs (k-1, x, y+2);
        } else{
                if (a[x] && mx[y]) dfs (k-1, y+1, y+1);
                if (a[x] != 100 && mx[y]) dfs (k-1, y, y);
                if (a[x] && last < y) dfs (k-1, x, y+1);
        }
}
int main(){
        int K;
        scanf ("%d%d", &n, &K);
        last = -1;
        for (int i = 0; i < n; ++i){
                scanf ("%d", a + i);
                if (a[i] == 100) last = i;
        }
        mx[n-1] = a[n-1];
        for (int i = n-2; i >= 0; --i){
                mx[i] = std::max (mx[i+1], a[i]);
        }
        memset (d, -1, sizeof d);
        dfs (K, 0, 0);
        int ans = 0;
        for (int i = 0, j; i <= n; ++i) for (j = 0; j <= n; ++j) if (d[i][j] != -1) ++ans;
        printf ("%d\n", ans);
        return 0;
}
