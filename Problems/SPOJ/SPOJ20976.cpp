#include<bits/stdc++.h>
const int N = 1009;
int a[N][N];
int main(){
    int n; scanf ("%d", &n);
    for (int j, i = 0; i < n; ++i){
        for (j = 0; j < n; ++j) scanf ("%d", &a[i][j]);
    }
    if (n == 2) printf ("1 %d\n", a[0][1]-1);
    else{
        int s = 0, t = n-1;
        for (int i = 1; i < n; ++ i) s += a[0][i];
        for (int i = n-1; i > 0; i -= 2){
            s -= a[i][i-1];
            if (i-1 == 0) -- t;
        }
        int ans = s / t;
        printf ("%d", ans);
        for (int i = 1; i < n; ++ i)
            printf (" %d", a[0][i] - ans);
        puts ("");
    }
    return 0;
}
