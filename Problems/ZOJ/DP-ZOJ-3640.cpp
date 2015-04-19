/*
 * Author:  Plumrain
 * Created Time:  2013-11-16 19:38
 * File Name: DP-ZOJ-3640.cpp
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, f;
int c[10005];
double x;

double DP(int f)
{
    double ret = 0.0;
    for (int i = 1; i <= n; ++ i){
        if (f > c[i]) ret += (int)(x * c[i] * c[i]);
        else ret += 1 + DP(f+c[i]);
    }
    ret /= (double)n;
    return ret;
}

int main()
{
    x = (1 + sqrt(5)) / (double)2;
    while (scanf ("%d%d", &n, &f) != EOF && n){
        for (int i = 1; i <= n; ++ i)
            scanf ("%d", &c[i]);
        printf ("%.3f\n", DP(f));
    }
    return 0;
}
