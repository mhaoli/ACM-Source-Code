/*
 * Author:  Plumrain
 * Created Time:  2013-10-09 20:14
 * File Name: math-POJ-3071.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

const double eps = 1e-8;

double a[150][150], p[150][150];
int two[8];
int n;

void init()
{
    for (int i = 0; i < two[n]; ++ i)
        for (int j = 0; j < two[n]; ++ j)
            scanf ("%lf", &a[i][j]);
}

int gao()
{
    CLR (p);
    for (int i = 0; i < two[n]; ++ i)
        p[0][i] = 1;

    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < two[n]; ++ j)
            for (int k = 0; k < two[n]; ++ k)
                if (((j>>i)^1) == (k>>i))
                    p[i+1][j] += p[i][j] * p[i][k] * a[j][k];

    int ret = 0;
    for (int i = 0; i < two[n]; ++ i)
       if (p[n][i] > p[n][ret] + eps) ret = i; 
    return ret + 1;
}

int main()
{
    CLR (two);
    two[0] = 1;
    for (int i = 1; i < 8; ++ i)
        two[i] = two[i-1] * 2;
    while (scanf ("%d", &n) != EOF && n != -1){
        init();
        printf ("%d\n", gao());
    }
    return 0;
}


