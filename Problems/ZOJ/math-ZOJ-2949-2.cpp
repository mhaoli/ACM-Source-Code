/*
 * Author:  Plumrain
 * Created Time:  2013-10-26 01:08
 * File Name: math-HDU-4465.cpp
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl
const int N = 2000;

double fac[N+5];

void init(int n)
{
    fac[1] = 0;
    for (int i = 2; i <= n; ++ i)
        fac[i] = fac[i-1] + log(i+0.0);
}

double C(int n, int m)
{
    return fac[n] - fac[n-m] - fac[m];
}

int main()
{
    freopen("tst.out","w",stdout);
    init(N);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);
        double ans = 0.0, p = log(0.5); 
        double q = log(0.5);
        double nq = n * q, np = n * p;
        for (int i = 0; i < n; ++ i)
            ans += (n+i) * (exp(C(n+i-1, i) + np + i*q) + exp(C(n+i-1, i) + nq + i*p));
        printf ("%.2f\n", ans);
    }
    return 0;
}
