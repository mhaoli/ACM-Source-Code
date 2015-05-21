#include<bits/stdc++.h>
const int N = 9 + (int)2e5;
int a[N];
int main(){
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; ++ i) scanf ("%d", a + i);
    std::sort (a, a + n);
    int ans = 0, mx = a[n-1];
    for (int j, p, i = n-2, t; i >= 0 && a[i] > ans+1; --i){
        if (a[i] == a[i+1]) continue;
        //printf ("%d:\n", a[i]);
        for (j = a[i] << 1; ; j += a[i]){
            p = std::lower_bound (a, a + n, j) - a - 1;
            //printf ("%d %d\n", j, p);
            if (p > i){
                t = a[p] % a[i]; 
                ans = std::max (ans, t);
            }
            if (j > mx) break;
        }
    }
    printf ("%d\n", ans);
    return 0;
}
