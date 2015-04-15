#include<bits/stdc++.h>
char str[222], s[40][40];
bool c[155][155], vis[155][155];
bool d[155][155][33][22];
int ans[222];
int len[40], n, m;
void dp (int l, int r){
    if (vis[l][r]) return;
    vis[l][r] = 1;
    for (int i = l; i < r; ++ i){
        dp (l, i); dp (i+1, r);
    }
    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < len[i]; ++ j) if (str[l] == s[i][j]){
            if (l == r && j == len[i]-1 || d[l+1][r][i][j+1])
                d[l][r][i][j] = 1;
        }
    for (int i = l; i < r; ++ i) if (c[l][i])
        for (int j = 0; j < m; ++ j)
            for (int k = 0; k < len[j]; ++ k)
                if (d[i+1][r][j][k]) d[l][r][j][k] = 1;
    for (int i = 0; i < m; ++ i)
        if (d[l][r][i][0]) c[l][r] = 1;
}
int main(){
    scanf ("%s%d", str, &m);
    n = strlen (str);
    for (int i = 0; i < m; ++ i){
        scanf ("%s", s[i]);
        len[i] = strlen (s[i]);
    }
    dp (0, n-1);
    ans[0] = !c[0][0];
    for (int i = 1; i < n; ++ i){
        ans[i] = ans[i-1] + 1;
        for (int j = 0; j <= i; ++ j)
            if (c[j][i]) ans[i] = std::min (ans[i], j ? ans[j-1] : 0);
    }
    printf ("%d\n", ans[n-1]);
    return 0;
}
