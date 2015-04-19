/*
 * Author:  Plumrain
 * Created Time:  2013-10-24 16:35
 * File Name: math-POJ-2689.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int maxint = 2147483647;
const int N = 50000;
typedef long long int64;

bool vis[N+5], v[1000005];
int64 prm[N+5];
int all;

int64 max(int64 a, int64 b)
{
    return a < b ? b : a;
}

void sieve(int n)
{
    CLR (vis);
    for (int64 i = 2; i <= n; ++ i) if (!vis[i])
        for (int64 j = i*i; j <= n; j += i) vis[j] = 1;
}

int primes(int n)
{
    sieve(n);
    int ret = 0;
    for (int i = 2; i <= n; ++ i)
        if (!vis[i]) prm[ret++] = i;
    return ret;
}

int main()
{
    all = primes(N);
    int64 m, n;
    while (scanf ("%lld%lld", &m ,&n) != EOF){
        m = max((int64)2, m);
        CLR (v);
        for (int i = 0; i < all && prm[i]*prm[i] <= n; ++ i){
            int64 t = m / prm[i] * prm[i];
            if (t != m) t += prm[i];
            while (t <= n){
                v[t - m] = 1;
                t += prm[i];
            }
            if (prm[i] >= m) v[prm[i]-m] = 0;
        }

        int64 a1 = 0, a2 = 0, b1 = 0, b2 = maxint, tmp = -1;
        for (int64 i = 0; i <= n-m; ++ i) if (!v[i]){
            if (tmp == -1){tmp = i; continue;}
            if (a2 - a1 < i - tmp){
                a1 = tmp;
                a2 = i;
            }
            if (b2 - b1 > i - tmp){
                b2 = i;
                b1 = tmp;
            }
            tmp = i;
        }
        if (!a1 && !a2) printf ("There are no adjacent primes.\n");
        else
            printf ("%lld,%lld are closest, %lld,%lld are most distant.\n", b1+m, b2+m, a1+m, a2+m);
    }
    return 0;
}
