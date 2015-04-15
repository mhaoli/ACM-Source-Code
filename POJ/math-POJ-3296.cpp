/*
 * Author:  Plumrain
 * Created Time:  2013-10-16 16:02
 * File Name: math-POJ-3296.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;
int64 tpow[25];

int64 f(int64 x)
{
    if (x < 0) return 0;

    int64 ret = 1, lef = 0;
    for (int64 i = 1;; ++ i){
        if (!x) break;
        int64 tmp = x % 10;
        x /= 10;
        if (tmp)
            ret += x * tpow[i-1];
        else
            ret += (x-1) * tpow[i-1] + (lef+1);
        lef += tpow[i-1] * tmp;
    }
    return ret;
}

int main()
{
    int64 n, m;
    tpow[0] = 1;
    for (int i = 1; i < 25; ++ i)
        tpow[i] = tpow[i-1] * 10;
    while (scanf ("%lld%lld", &n, &m) != EOF && m >= 0)
        printf ("%lld\n", f(m) - f(n-1)); 
    return 0;
}
