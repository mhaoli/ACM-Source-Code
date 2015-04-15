/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 7.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl

const int N = 1000005;
bool v[N];
int prm[N];
void sieve (int n)
{
    int m = (int)sqrt(n+0.5);
    clr0 (v); v[0] = v[1] = 1;
    for (int i = 2; i <= m; ++ i) if (!v[i])
        for (int j = i*i; j <= n; j += i) v[j] = 1;
}
int primes(int n)
{
    sieve(n);
    int ret = 0;
    for (int i = 2; i <= n; ++ i) if (!v[i]) prm[ret++] = i;
    return ret;
}
int main()
{
    int all = primes(N);
    out (all); 
    out (prm[0]); out (prm[10000]);
    return 0;
}
