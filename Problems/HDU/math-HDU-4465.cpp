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

const int N = 200000;

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
    init(N);
    int n, test = 0;
    double p;
    while (scanf ("%d%lf", &n, &p) != EOF){
        double q = log(1 - p), ans = 0.0; 
        p = log(p);
        double nq = (n+1) * q, np = (n+1) * p;
        for (int i = 0; i < n; ++ i)
            ans += (n-i) * (exp(C(n+i, i) + np + i*q) + exp(C(n+i, i) + nq + i*p));
        printf ("Case %d: %.6f\n", ++test, ans);
    }
    return 0;
}
