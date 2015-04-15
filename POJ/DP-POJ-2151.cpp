/*
 * Author:  Plumrain
 * Created Time:  2013-11-14 23:07
 * File Name: DP-POJ-2151.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

double p[1005][100], d[1005][40][40];

int main()
{
    int m, t, n;
    while (scanf ("%d%d%d", &m, &t, &n) != EOF && m){
        for (int i = 0; i < t; ++ i)
            for (int j = 1; j <= m; ++ j)
                scanf ("%lf", &p[i][j]);

        CLR (d);
        for (int i = 0; i < t; ++ i){
            d[i][0][0] = 1;
            for (int j = 1; j <= m; ++ j)
                for (int k = 0; k <= m; ++ k){
                    d[i][j][k] = d[i][j-1][k] * (1 - p[i][j]);
                    if (!k) continue;
                    d[i][j][k] += d[i][j-1][k-1] * p[i][j];
                }
        }

        double ans = 1.0;
        for (int i = 0; i < t; ++ i)
            ans *= (1 - d[i][m][0]);
        double tmp = 1.0;
        for (int i = 0; i < t; ++ i){
            double sum = 0.0;
            for (int j = 1; j < n; ++ j)
                sum += d[i][m][j];
            tmp *= sum;
        }
        ans -= tmp;
        printf ("%.3f\n", ans);
    }
    return 0;
}
