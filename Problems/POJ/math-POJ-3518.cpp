/*
 * Author:  Plumrain
 * Created Time:  2013-10-20 00:16
 * File Name: math-POJ-3518.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 1299709;

bool vis[N+5];
int prm[100005];

void sieve(int n)
{
    int m = (int)sqrt(n+0.5);
    CLR (vis);
    for (int i = 2; i <= m; ++ i) if (!vis[i])
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

int bin_search(int n, int all)
{
    int l = 0, r = all-1;
    while (l <= r){
        int mid = (l+r) >> 1;
        if (prm[mid] < n) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int gao(int x, int num)
{
    if (!vis[x]) return 0;

    int pos = bin_search(x, num);
    return prm[pos] - prm[pos-1];
}

int main()
{
    int num = primes(N);
    int x;
    while (scanf ("%d", &x) != EOF && x)
        printf ("%d\n", gao(x, num));
    return 0;
}
