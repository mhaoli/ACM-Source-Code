#include<bits/stdc++.h>
const long long mod = 7 + (int)1e9;
const int N = 5003;
int d[2][N], s[2][N];
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}
int main(){
    int n, i, j, now = 1, nxt = 0; scanf ("%d", &n);
    for (i = 1; i <= n; ++ i){
        d[1][i] = 1;
        s[1][i] = i == 1 ? 0 : s[1][i-1] + d[1][i];
    }
    for (i = 2; i <= n; ++ i){
        for (j = i; j <= n; ++ j){
            d[nxt][j] = s[now][j-1];
            add (d[nxt][j], (long long)j * d[now][j] % mod);
            i == j ? s[nxt][j] = 0 : (s[nxt][j] = s[nxt][j-1], add (s[nxt][j], d[nxt][j]), 0);
        }
        std::swap (now, nxt);
    }
    printf ("%d\n", d[now][n]);
    return 0;
}
