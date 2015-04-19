#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
const int N = 9 + (int)3e7;
int ans[N];
void init (int x){
    memset (ans, 0, sizeof ans);
    for (int i = 2; i < x; i += 2){
        int t = i + 1, j, ti;
        for (j = t, ti = i; j <= x; j += t<<1, ti += i<<1)
            if (std::__gcd(ti, j) == (ti^j)){
                for (int k = 1; k*j <= x; k <<= 1) ++ans[j*k];
            } 
    }
    for (int i = 1; i <= x; ++ i) ans[i] += ans[i-1];
}
int main(){
    init (N-9);
    int T, cas = 0; scanf ("%d", &T);
    while (T--){
        int n; scanf ("%d", &n);
        printf ("Case %d: %d\n", ++ cas, ans[n]);
    }
    return 0;
}
