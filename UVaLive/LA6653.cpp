#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
const int N = (int)1e4 + 9;
const long long mod = 10000000000007;
//int fac[N];
int main(){
    //fac[0] = 1;
    //for (int i = 1; i < N-5; ++ i) fac[i] = fac[i-1] * i % mod;

    int T, cas = 0; scanf ("%d", &T);
    while (T--){
        int n, l, r;
        scanf ("%d%d%d", &n, &l, &r);
        long long a = n*n, t = n*n-1, sum = 0;
        int i = 1;
        while (i < l){ 
            (a *= (t--)) %= mod, ++ i;
        }
        sum = a;
        while ((++i) <= r){
            (a *= (t--)) %= mod;
            (sum += a) %= mod;
        }
        printf ("Case %d: %lld\n", ++ cas, sum);
    }
    return 0;
}
