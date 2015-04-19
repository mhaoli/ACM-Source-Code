/*
 * Author:  Plumrain
 * Created Time:  2013-10-01 14:05
 * File Name: math-POJ-2409.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

typedef long long int64;

int64 pow[40];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    int64 c, n;
    while (scanf ("%lld%lld", &c, &n) != EOF && n){
        CLR (pow);
        pow[0] = 1;
        for (int i = 1; i <= n; ++ i)
            pow[i] = pow[i-1] * c;
        int64 ans = 0;
        for (int i = 0; i < n; ++ i)
            ans += pow[gcd(i, n)];
        if (n & 1)
            ans += n * pow[n/2+1];
        else
            ans += (pow[n/2] + pow[n/2+1]) * (n/2);
        ans = ans / 2 / n;
        printf ("%lld\n", ans);
    }
    return 0;
}
