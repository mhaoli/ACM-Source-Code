#include<bits/stdc++.h>
const int Max_N = 9 + (int)1e5;
const int mod = 7 + (int)1e9;
int a[Max_N][101], ans[Max_N], C[Max_N][101];
void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}
int main() {
        for(int i = 0, j; i < Max_N; ++i) {
                C[i][0] = 1;
                for(j = 1; j <= std::min(i, 100); ++j)
                        add(C[i][j], C[i-1][j]), add(C[i][j], C[i-1][j-1]);
        }

        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
                scanf("%d", ans + i);
        }
        for(int l, r, t, i; m--; ) {
                scanf("%d%d%d", &l, &r, &t);
                add(a[l-1][t], 1); 
                for(i = t; i >= 0; --i) {
                        add(a[r][i], mod - C[r-l+t-i][t-i]);
                }
        }
        for(int i = 99; i >= 0; --i) {
                add(a[0][i], a[0][i+1]);
                for(int j = 1; j < n; ++j) {
                        add(a[j][i+1], a[j-1][i+1]);
                        add(a[j][i], a[j][i+1]);
                }
        }
        for(int i = 0; i < n; ++i){
                if(i) add(a[i][0], a[i-1][0]);
                add(ans[i], a[i][0]);
                printf("%d%c", ans[i], " \n"[i==n-1]);
        }
        return 0;
}
