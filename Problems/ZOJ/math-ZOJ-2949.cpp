/*
 * Author:  Plumrain
 * Created Time:  2013-10-26 00:03
 * File Name: math-ZOJ-2949.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

double d[1005][1005], ans[1005];

void DP(int n)
{
    CLR (d); d[0][0] = 1.0;
    for (int i = 1; i <= n; ++ i)
        d[i][0] = d[0][i] = d[i-1][0] * 0.5;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            d[i][j] = (d[i-1][j] + d[i][j-1]) / 2.0;

    for (int i = 1; i <= n; ++ i){
        double sum = d[i][0] * i;
        for (int j = 1; j < i; ++ j)
            sum += (i+j) * (d[i][j] - d[i][j-1]*0.5);
        ans[i] = sum * 2.0; 
    }
}

int main()
{
    DP(1000);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);
        printf ("%.2f\n", ans[n]);
    }
    return 0;
}
