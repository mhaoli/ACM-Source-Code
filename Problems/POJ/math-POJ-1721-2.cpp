/*
 * Author:  Plumrain
 * Created Time:  2013-10-21 15:26
 * File Name: math-POJ-1721-2.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 1000;

int a[N+5], cir[N+5], ans[N+5], tmp[N+5];

int pow_mod(int p, int n, int mod)
{
    p %= mod;
    int ret = 1;
    while (n > 0){
        if (n & 1) ret = (ret * p) % mod;
        n >>= 1;
        p = (p * p) % mod;
    }
    return ret;
}

void gao(int n, int m)
{
    int pos = 0;
    while (a[pos])
        pos = a[pos];
    cir[0] = pos = 0; 
    int idx = 1;
    while (a[pos]){
        cir[idx++] = a[pos];
        pos = a[pos]; 
    }
    int k = pow_mod(2, m, n);
    for (int i = 0; i < n; ++ i)
        tmp[(i*k)%n] = cir[i];
    for (int i = 0; i < n-1; ++ i)
        ans[tmp[i]] = tmp[i+1];
    ans[tmp[n-1]] = tmp[0];
}

int main()
{
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &a[i]);
            -- a[i];
        }
        gao(n, m);
        for (int i = 0; i < n; ++ i)
            printf ("%d\n", ans[i] + 1);
    }
    return 0;
}
