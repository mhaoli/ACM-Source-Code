/*
 * Author:  Plumrain
 * Created Time:  2013-11-07 23:13
 * File Name: DP-HDU-3853.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const double eps = 1e-8;
struct grd{
    double p[3], x[3];
};

int r, c;
grd a[1005][1005];
double d[1005][1005];

void init()
{
    for (int i = 0; i < r; ++ i)
        for (int j = 0; j < c; ++ j)
            for (int k = 0; k < 3; ++ k)
                scanf ("%lf", &a[i][j].p[k]);
}

double DP()
{
    CLR (d);
    for (int i = r-1; i >= 0; -- i)
        for (int j = c-1; j >= 0; -- j)
            if (!(i == r-1 && j == c-1)){
                if (fabs(a[i][j].p[0] - 1) < eps) continue;
                d[i][j] = (d[i][j+1]*a[i][j].p[1] + d[i+1][j]*a[i][j].p[2] + 2) / (1 - a[i][j].p[0]);
            }
    return d[0][0];
}

int main()
{
    while (scanf ("%d%d", &r, &c) != EOF){
        init();
        printf ("%.3lf\n", DP());
    }
    return 0;
}
