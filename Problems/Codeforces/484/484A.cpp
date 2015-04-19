#include<bits/stdc++.h>
int d[111], g[111], cnt;
void calc (long long l, long long r){
    cnt = 0;
    memset (d, 0, sizeof d);
    memset (g, 0, sizeof g);
    while (r){
        d[cnt] = l & 1;
        g[cnt++] = r & 1;
        l >>= 1; r >>= 1;
    }
}
int main(){
    int n; scanf ("%d", &n);
    for (long long l, r; n; --n){
        scanf ("%I64d%I64d", &l, &r);
        calc (l, r);
        long long ans = 0;
        int j, i;
        for (j = cnt-1; j >= 0; --j){
            if (d[j] == g[j]) ans = ans << 1 | d[j];
            else{
                bool u = 0;
                for (i = j-1; i >= 0; --i) if (!g[i]) u = 1;
                if (u){
                    ans <<= 1;
                } else{
                    ans = ans << 1 | 1;
                }
                for (i = j-1; i >= 0; --i) ans = ans << 1 | 1;
                break;
            }
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}
