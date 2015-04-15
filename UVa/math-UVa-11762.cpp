/*
 * Author:  Plumrain
 * Created Time:  2013-09-06 19:39
 * File Name: math-UVa-11762.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

const double eps = 1e-8;
const int N = 1000000;

double f[N+1];
bool vis[N+501];
int prm[N+1];
int all;

void sieve(int n)
{
    int m = (int)sqrt(n+0.5);
    CLR (vis);
    for (int i = 2; i <= m; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

int primes(int n)
{
    sieve (n);
    int ret = 0;
    for (int i = 2; i <= n; ++ i) 
        if (!vis[i]) prm[ret++] = i;
    return ret;
}

int bin_search(int n)
{
    int l = 0, r = all - 1;
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (prm[mid] < n) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

double gao(int n)
{
    if (n == 1) return 0.0;
    if (f[n] > eps) return f[n];
    if (!vis[n]) return 1 + bin_search (n);

    double ret = 0.0;
    int cnt = 0, num;
    for (int i = 0; ; ++ i){
        if (prm[i] > n){
            num = i;
            break;
        }

        if (n % prm[i]){
            ++ cnt;
            continue;
        }
        ret += (1 + gao(n/prm[i]));
    }
    ret = (ret + cnt + 0.0) / (num - cnt);
    return ret;
}

int main()
{
    all = primes (N+500);
    CLR (f);
    
    int T;
    scanf ("%d", &T);
    int test = 0;
    while (T--){
        int n;
        scanf ("%d", &n);
        printf ("Case %d: %.8lf\n", ++test, gao(n));
    }
    return 0;
}
