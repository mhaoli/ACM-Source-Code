/*
 * Author:  Plumrain
 * Created Time:  2013-10-20 11:27
 * File Name: math-POJ-2739.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 10000;

bool vis[N+5];
int prm[N+5], all;

void sieve(int n)
{
    CLR (vis);
    for (int i = 2; i <= n; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

int primes(int n)
{
    sieve(N);
    int ret = 0;
    for (int i = 2; i <= n; ++ i) 
        if (!vis[i]) prm[ret++] = i;
    return ret;
}

int gao(int n)
{
    int ret = 0, l = 0, r = 0, sum = 2;
    while (1){
        if (sum < n) sum += prm[++r];
        else if (sum > n) sum -= prm[l++];
        else{
            sum += prm[++r];
            ++ ret;
        }

        if (prm[l] > n) return ret; 
    }
}

int main()
{
    all = primes(N);
    int x;
    while (scanf ("%d", &x) != EOF && x)
        printf ("%d\n", gao(x));
    return 0;
}
