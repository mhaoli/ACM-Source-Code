/*
 * Author:  Plumrain
 * Created Time:  2013-10-24 10:35
 * File Name: math-POJ-2909.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 40000;

bool vis[N+5];
int all, prm[N+5];

void sieve(int n)
{
    CLR (vis);
    for (int i = 2; i <= n; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
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
    int n;
    while (scanf ("%d", &n) != EOF && n){
        int ans = 0;
        for (int i = 0; prm[i] <= n/2; ++ i)
            if (!vis[n-prm[i]]) ++ ans;
        printf ("%d\n", ans);
    }
    return 0;
}
