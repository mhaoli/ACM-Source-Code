/*
 * Author:  Plumrain
 * Created Time:  2013-09-30 21:18
 * File Name: math-POJ-1286.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

typedef long long int64;

int64 pow3[30];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int64 gao(int64 n)
{
    int64 ret = 0;
    for (int i = 0; i < n; ++ i)
        ret += pow3[gcd(i, n)];

    if (n&1)
        ret += n * pow3[n/2+1];
    else
        ret += (pow3[n/2] + pow3[n/2+1]) * (n/2);
    ret /= 2 * n;
    return ret;
}

int main()
{
    int n;
    CLR (pow3);
    pow3[0] = 1;
    for (int i = 1; i < 24; ++ i)
        pow3[i] = pow3[i-1] * 3;

    while (scanf ("%d", &n) != EOF && n != -1){
        if (!n) printf ("0\n");
        else printf ("%lld\n", gao((int64)n));     
    }
    return 0;
}
