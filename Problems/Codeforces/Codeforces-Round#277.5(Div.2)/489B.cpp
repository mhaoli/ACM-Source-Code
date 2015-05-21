#include<bits/stdc++.h>
int a[111], b[111];
int main(){
        int n, m;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++i) scanf ("%d", a + i);
        scanf ("%d", &m);
        for (int i = 0; i < m; ++i) scanf ("%d", b + i);
        std::sort (a, a + n);
        std::sort (b, b + m);
        int ans = 0;
        for (int i = 0, j = 0; i < n && j < m; ++i){
                if (abs (a[i] - b[j]) <= 1) ++ ans, ++j;
                else if (b[j] < a[i]) ++j, --i;
        }
        printf ("%d\n", ans);
        return 0;
}
