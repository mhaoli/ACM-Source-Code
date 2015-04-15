/*
 * Author:  Plumrain
 * Created Time:  2013-09-07 15:33
 * File Name: (good)-math-UVa-10294.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;


typedef long long int64;

int64 Mypow(int64 a, int64 n)
{
    int64 ret = 1;
    while (n > 0){
        if (n & 1)
            ret *= a;
        n >>= 1;
        a *= a;
    }
    return ret;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    int n, t;
    while (scanf ("%d%d", &n, &t) != EOF){
        int64 ans1 = 0;
        for (int i = 0; i < n; ++ i)
            ans1 += Mypow (t, gcd(n, i));
        int64 ans2 = ans1;
        if (n & 1) ans2 += n * Mypow (t, (n+1)/2);
        else ans2 += n * (Mypow (t, n/2) + Mypow (t, n/2+1)) / 2;
        printf ("%lld %lld\n", ans1/n, ans2 / (2*n));
    }
    return 0;
}
