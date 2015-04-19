#include<bits/stdc++.h>
const int N = 2002;
int n;
char str[N][N];
bool diag[N], col[2][N], row[2][N];
int solve (bool *col, bool *row, bool *diag){
        int ret = 0;
        bool rev = 0;
        for (int i = n-1, j; i; --i){
                rev = 0;
                for (j = 0; j < i; ++j){
                        if ((rev ^ row[j]) != (str[j][i] == '1')){
                                rev ^= 1;
                                ++ret;
                                row[j] ^= 1;
                                diag[i] ^= 1; diag[j] ^= 1;
                        }
                }
        }
        return ret;
}
int main(){
        scanf ("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf ("%s", str[i]);
        }
        int ans = solve (col[0], row[0], diag);
        for (int i = 0, j; i < n; ++i)
                for (j = 0; j < i; ++j) std::swap (str[i][j], str[j][i]);
        ans += solve (col[1], row[1], diag);
        for (int i = 0; i < n; ++i) if (diag[i] != (str[i][i] == '1')) ++ans;
        printf ("%d\n", ans);
        return 0;
}
