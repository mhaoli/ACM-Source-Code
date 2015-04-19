/*
 * Author:  Plumrain
 * Created Time:  2013-10-18 10:45
 * File Name: math-POJ-2154.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 1000000;

int phi[N+5];
int vis[50005], prm[50005];
int mod, nprm;

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

void phi_table(int n)
{ 
    CLR (phi);
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i) if (!phi[i]){
        for (int j = i; j <= n; j += i){
            if (!phi[j]) phi[j] = j;
            phi[j] -= phi[j]/i;
        }
    }
}

int euler_phi(int n)
{ 
    if (n <= N) return phi[n] % mod;

    int m = (int)sqrt(n + 0.5);
    int ans = n;
    for (int i = 0; i<nprm && prm[i] <= m; ++ i)
        if (!(n % prm[i])){
            ans -= ans/prm[i];
            while (!(n % prm[i])) n /= prm[i];
        }
    if (n > 1) ans -= ans/n;
    return ans % mod;
}

int pow_mod(int p, int n)
{
    int ret = 1;
    p %= mod;
    while (n > 0){
        if (n & 1) ret = (ret * p) % mod;
        n >>= 1;
        p = (p * p) % mod;
    }
    return ret;
}

int Polya(int n)
{
    int ret = 0;
    for (int i = 1; i*i <= n; ++ i) if (n % i == 0){
        ret = (ret + pow_mod(n, n/i-1) * euler_phi(i)) % mod;
        if (i*i < n)
            ret = (ret + (pow_mod(n, i-1) % mod) * (euler_phi(n/i) % mod)) % mod;
    }
    if (ret < 0) ret += mod;
    return ret;
}

int main()
{
    phi_table(N);
    nprm = primes(50000);
    int T, n;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d%d", &n, &mod);
        printf ("%d\n", Polya(n));
    }
    return 0;
}






