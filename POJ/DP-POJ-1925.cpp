/*
 * Author:  Plumrain
 * Created Time:  2013-11-18 19:22
 * File Name: DP-POJ-1925.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int maxint = 2147483647 - 10;
typedef long long int64;

int n;
int x[5005], y[5005], d[1010005];
int64 a[5005];

void init()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf ("%d%d", &x[i], &y[i]);
        a[i] = (int64)y[i]*y[i] - (int64)(y[i]-y[0]) * (y[i]-y[0]);
    }
}

int DP()
{
    for (int i = 0; i <= x[n-1]+10000; ++ i)
        d[i] = maxint;
    d[x[0]] = 0;

    for (int i = 1; i < n; ++ i){
        for (int j = x[i]-1; j >= x[0]; -- j){
            if ((int64)(x[i]-j)*(x[i]-j) > a[i]) break;

            int tmp = 2*x[i] - j;
            if (tmp >= x[n-1])
                tmp = x[n-1];
            d[tmp] = min(d[tmp], d[j] + 1);
        }
    }
    
    return d[x[n-1]] == maxint ? -1 : d[x[n-1]];
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init();
        printf ("%d\n", DP());
    }
    return 0;
}
