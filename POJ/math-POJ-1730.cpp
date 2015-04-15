/*
 * Author:  Plumrain
 * Created Time:  2013-10-23 16:06
 * File Name: math-POJ-1730.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl
typedef long long int64;
int64 an[10000], bn[10000];
int all;

int64 gcd(int64 a, int64 b)
{
    return b ? gcd(b, a%b) : a;
}

void int_dev(int64 x)
{
    all = -1;
    for (int64 i = 2; i*i <= x;){
        if (!(x%i)){
            an[++all] = i;
            bn[all] = 0;
        }
        while (!(x%i)){
            ++ bn[all];
            x /= i;
        }
        if (i == 2) ++ i;
        else i += 2;
    }
    ++ all;
    if (x != 1){
        an[all] = x;
        bn[all++] = 1;
    }
}

int64 pnt(int64 x, bool fla)
{
    if (fla) return x;
    while ((x & 1) == 0)
        x >>= 1;
    return x;
}

int main()
{
    int64 n;
    while (scanf ("%lld", &n) != EOF && n){
        bool fla = 1;
        if (n < 0){
            fla = 0;
            n = 0 - n;
        }
        int_dev(n);

        if (all == 1){
            printf ("%lld\n", pnt(bn[0], fla));
            continue;
        }
        
        int64 ans = gcd(bn[0], bn[1]);
        for (int i = 2; i < all; ++ i)
            ans = gcd(ans, bn[i]);
        printf ("%lld\n", pnt(ans, fla));
    }
    return 0;
}
