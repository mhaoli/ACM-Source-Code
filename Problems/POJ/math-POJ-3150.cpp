/*
 * Author:  Plumrain
 * Created Time:  2013-10-14 08:21
 * File Name: math-POJ-3150.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 500;
typedef long long int64;

int64 a[N+5], p[N+5], ans[N+5];
int n, mod, k, d;

void init()
{
    scanf ("%d%d%d", &mod, &d, &k); 
    for (int i = 0; i < n; ++ i)
        scanf ("%lld", &a[i]);

    CLR (p);
    int t = 0, tl = 0, tr = 0;
    while (t <= d){
        p[tl] = 1; p[tr] = 1;
        ++ t; ++ tr; -- tl;
        if (tl < 0) tl = n-1;
    }
}

void mtx_mul(int64* a, int64* b)
{
    int x[N+5];
    for (int i = 0; i < n; ++ i){
        x[i] = 0;
        for (int j = 0; j < n; ++ j)
            x[i] = (a[j] * b[(j-i+n)%n] + x[i]) % mod;
        if (x[i] < 0) x[i] += mod;
    }
    for (int i = 0; i < n; ++ i)
        a[i] = x[i];
}

void mtx_pow()
{
    -- k;
    int64 x[N+5];
    for (int i = 0; i < n; ++ i)
        x[i] = p[i];
    while (k > 0){
        if (k & 1) mtx_mul(x, p);
        k >>= 1;
        mtx_mul(p, p);
    }
    for (int i = 0; i < n; ++ i)
        p[i] = x[i];
}

void gao()
{
    mtx_pow();
    for (int i = 0; i < n; ++ i){
        ans[i] = 0;
        for (int j = 0; j < n; ++ j)
            ans[i] = (a[j] * p[(j-i+n)%n] + ans[i]) % mod;
        if (ans[i] < 0) ans[i] += mod;
    }
    for (int i = 0; i < n; ++ i){
        if (i) printf (" ");
        printf ("%lld", ans[i]);
    }
    printf ("\n");
}

int main()
{
    while (scanf ("%d", &n) != EOF && n){ 
        init();
        gao();
    }
    return 0;
}
