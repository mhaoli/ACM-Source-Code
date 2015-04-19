/*
 * Author:  Plumrain
 * Created Time:  2013-12-03 19:43
 * File Name: math-LA-5990.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;
const int64 mod = 1000000007;
const int N = 100005;

int64 g[N], a[N];
int64 min(int64 a, int64 b) {return a > b ? b : a;}
int64 max(int64 a, int64 b) {return a > b ? a : b;}

int main()
{
    g[0] = 1;
    for (int i = 1; i < N; ++ i)
        g[i] = g[i-1] * 2 % mod;
    
    int T, n;
    scanf ("%d", &T);
    while (T--){
        int64 mi = mod, ma = 1;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++ i){
            scanf ("%lld", &a[i]);
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
        }

        int64 ans1 = 0, ans2 = 0;

        if (mi == ma){
            ans1 = ((int64)(n + 1) * n / 2) % mod;
            ans2 = g[n] - 1;
            printf ("%lld %lld\n", ans1, ans2);
            continue;
        }

        int t1 = -1, t2 = -1, s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++ i){
            if (a[i] == mi){
                ++ s1; t1 = i;
            }
            if (a[i] == ma){
                ++ s2; t2 = i;
            }

            ans1 = (ans1 + min(t1+1, t2+1)) % mod;
        }

        ans2 = (g[n] - g[n-s1] - g[n-s2] + g[n-s1-s2]) % mod;
        if (ans2 < 0) ans2 += mod;
        printf ("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
