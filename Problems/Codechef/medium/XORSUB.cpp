#include<bits/stdc++.h>
int d[1005][(1<<10)], a[1005];
int main() {
        int _; scanf("%d", &_);
        for(int n, t; _--; ) {
                scanf("%d%d", &n, &t);
                for(int i = 0; i < n; ++i) scanf("%d", a + i);
                memset(d, 0, sizeof d);
                d[0][0] = d[0][a[0]] = 1;
                for(int i = 1, j; i < n; ++i)
                        for(j = 0; j < (1<<10); ++j) if(d[i-1][j])
                                d[i][j] = d[i][j^a[i]] = 1;
                int ans = t;
                for(int i = 0; i < (1<<10); ++i) if(d[n-1][i]) ans = std::max(ans, i^t);
                printf("%d\n", ans);
        }
        return 0;
}
