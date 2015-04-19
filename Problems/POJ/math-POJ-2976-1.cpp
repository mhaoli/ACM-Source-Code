/*
 * Author:  Plumrain
 * Created Time:  2013-10-13 10:18
 * File Name: math-POJ-2976.cpp
 * 二分法
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0.0, sizeof(x))

const double eps = 1e-4;
const int N = 1000;

int n, m;
int a[N+5], b[N+5];
double c[N+5];

bool cmp(double x, double y)
{
    return x > y;
}

double gao()
{
    double l = 0.0, r = 1.0;
    while (l + eps < r){
        double mid = (l+r) / 2.0;
        CLR (c);
        for (int i = 0; i < n; ++ i)
            c[i] = a[i] - mid * b[i];
        sort(c, c+n, cmp);
        double tmp = 0.0;
        for (int i = 0; i < n-m; ++ i)
            tmp += c[i];
        if (tmp >= eps) l = mid;
        else r = mid;
    }
    return l;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n){    
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &a[i]);
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &b[i]);
        
        printf ("%d\n", (int)(gao()*100.0 + 0.5));
    }
    return 0;
}

