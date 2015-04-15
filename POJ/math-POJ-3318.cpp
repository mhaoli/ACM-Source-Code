/*
 * Author:  Plumrain
 * Created Time:  2013-10-14 19:06
 * File Name: math-POJ-3318.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;
typedef long long matrix[505][505];
int n;
matrix a, b, c, d;

void init()
{ 
    scanf ("%d", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            scanf ("%lld", &a[i][j]);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            scanf ("%lld", &b[i][j]);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            scanf ("%lld", &c[i][j]);
}

void mtx_mul(int64* a, matrix b)
{
    int64 ret[505];
    for (int i = 0; i < n; ++ i){
        ret[i] = 0;
        for (int j = 0; j < n; ++ j)
            ret[i] += a[j] * b[j][i];
    }

    for (int i = 0; i < n; ++ i)
        a[i] = ret[i];
}

bool gao(int64* a, int64* b)
{
    for (int i = 0; i < n; ++ i)
        if (a[i] != b[i]) return false;
    return true;
}

int main()
{
    init();

    int64 x[505], y[505];
    for (int i = 0; i < n; ++ i){
        x[i] = 10 * i + i*i+1;
        y[i] = 10 * i + i*i+1;
    }
    mtx_mul(x, a);
    mtx_mul(x, b);
    mtx_mul(y, c); 

    if (gao(x, y)) printf ("YES\n");
    else printf ("NO\n");
    return 0;
}


