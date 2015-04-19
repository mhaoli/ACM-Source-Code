#include<bits/stdc++.h>
const int N = 9 + (int)1e5;
char s[N];
int cnt[10][N];
int main(){
    int n, q, m;
    scanf ("%d%d%d%s", &n, &m, &q, s);
    for (int i = 0; i < n; ++i){
        cnt[i%m][i] = i < m ? 0 : cnt[i%m][i-m];
        if (s[i] == '1') ++cnt[i%m][i];
    }
    for (int l, r, ans, i, j; q--;){
        scanf ("%d%d", &l, &r);
        ans = 0;
        for (i = --l, j = --r - m + 1; i < l + m - 1; ++i, ++j){
            ans += cnt[i%m][j] - cnt[i%m][i] + (s[i] == '1');
        }
        ans += (r - l + 1) / m - (cnt[r%m][r] - cnt[r%m][l+m-1] + (s[l+m-1] == '1'));
        printf ("%d\n", ans);
    }
    return 0;
}
