/*
 * Author:  Plumrain
 * Created Time:  2013-09-09 00:02
 * File Name: math-UVa-11077.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

typedef unsigned long long int64;

const int N = 21;
int64 f[N+1][N+1];

int64 gao(int64 n, int64 k)
{
    int64& x = f[n][k];
    if (x != -1) return x; 
    if (n == 1 && k == 1) return 0;
    if (k == 0) return 1;
    if (n == 1) return 0;
    
    x = gao(n-1, k-1) * (n-1) + gao(n-1, k);
    return x;
}

int main()
{
    int n, k;
    for (int i = 0; i <= N; ++ i)
        for (int j = 0; j <= N; ++ j)
            f[i][j] = -1;
    while (scanf ("%d%d", &n, &k) != EOF && !(!n && !k)){
        printf ("%llu\n", gao(n, k));
    }
    return 0;
}
