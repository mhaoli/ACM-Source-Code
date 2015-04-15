#include<bits/stdc++.h>
int n, up, s;
int a[20], ans[5][5], s1[5], s2[5], s3, s4, idx[1<<16], cnt[1<<16];
bool ans_u, vis[1<<16];
void dfs (int sta){
        if (sta == up){
                if (ans_u) return;
                printf ("%d\n", s);
                for (int i = 0, j; i < n; ++i){
                        for (j = 0; j < n; ++j){
                                if (j) putchar (' ');
                                printf ("%d", ans[i][j]);
                        }
                        puts ("");
                }
                ans_u = 1;
                return ;
        }

        int x = cnt[sta] / n, y = cnt[sta] % n;
        for (int ts = up ^ sta, t, u; ts && !ans_u; ts ^= ts & (-ts)){
                t = a[idx[ts & (-ts)]];
                s1[x] += t; s2[y] += t;
                if (x == y) s3 += t;
                if (x + y == n-1) s4 += t;

                u = 1;
                if (y == n-1 && s1[x] != s) u = 0;
                if (x == n-1 && s2[y] != s) u = 0;
                if (x == n-1 && y == n-1 && s3 != s) u = 0;
                if (x == n-1 && y == 0 && s4 != s) u = 0;
                if (u){
                        ans[x][y] = t, dfs (sta ^ ((ts & (-ts))));
                }

                s1[x] -= t; s2[y] -= t;
                if (x == y) s3 -= t;
                if (x + y == n-1) s4 -= t;
        }
}
int main(){
        scanf("%d", &n);
        for (int i = 0; i < n*n; ++i){
                scanf ("%d", &a[i]);
                s += a[i];
        }
        s /= n;

        up = (1 << (n*n)) - 1;
        idx[1] = 0;
        for (int i = 1, j = 1; i < up; idx[i<<=1] = j++);
        cnt[0] = 0;
        for (int i = 1; i <= up; ++i) cnt[i] = cnt[i>>1] + (i & 1);

        dfs (0);
        return 0;
}
