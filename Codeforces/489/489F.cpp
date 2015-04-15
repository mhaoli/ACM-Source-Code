#include<bits/stdc++.h>
const int N = 555;
long long mod;
int num[N], d[2][N][N];
char str[N];
void add (int &a, int b){
        a += b; if (a >= mod) a -= mod;
}
long long C2 (int m){
        return ((long long)m * (m-1) / 2) % mod;
}
int main(){
        int n, m;
        scanf ("%d%d%I64d", &n, &m, &mod);
        for (int i = 0, j, t; i < m; ++i){
                scanf ("%s", str);
                t = 0;
                for (j = 0; j < n; ++j) str[j] == '1' ? ++num[j], ++t : 0;
                if (t != 2) return puts ("0"), 0;
        }
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; ++i){
                if (num[i] == 1) ++t1;
                else if (num[i] == 2) ++t2;
                else if (num[i] > 2) return puts("0"), 0;
        }
        d[0][t2][t1] = 1;
        int now = 0, nxt = 1;
        for (int i = m, j, k; i < n; ++i){
                memset (d[nxt], 0, sizeof d[nxt]);
                for (j = 0; j <= n; ++j) for (k = 0; k <= n - j; ++k) if (d[now][j][k]){
                        if (k >= 2) add (d[nxt][j+2][k-2], d[now][j][k] * C2(k) % mod);
                        if (k >= 1 && j + k <= n-1) add (d[nxt][j+1][k], (d[now][j][k] * (long long)k % mod) * (n - j - k) % mod);
                        if (j + k <= n-2) add (d[nxt][j][k+2], d[now][j][k] * C2(n - j - k) % mod);
                }
                std::swap (now, nxt);
        }
        printf ("%d\n", d[now][n][0]);
        return 0;
}
