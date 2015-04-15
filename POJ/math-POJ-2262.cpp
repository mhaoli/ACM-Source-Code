/*
 * Author:  Plumrain
 * Created Time:  2013-10-23 16:33
 * File Name: math-POJ-2262.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 1000000;
typedef long long int64;

bool vis[N+5];
int prm[N+5], all;

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
    int n;
    while (scanf ("%d", &n) != EOF && n){
        int ans = -1;
        for (int i = 1; i < all && prm[i] < n; ++ i)
            if (!vis[n-prm[i]]){
                ans = prm[i];
                break;
            }
        if (ans == -1) printf ("Goldbach's conjecture is wrong.\n");
        else printf ("%d = %d + %d\n", n, ans, n-ans); 
    }
    return 0;
}
