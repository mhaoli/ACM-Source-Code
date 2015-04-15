/*
 * Author:  Plumrain
 * Created Time:  2013-11-16 21:24
 * File Name: DP-HDU-4336.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

double d[1<<20], p[100];

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF){
        double px = 1.0;
        for (int i = 0; i < n; ++ i){
            scanf ("%lf", &p[i]);
            px -= p[i];
        }

        CLR (d);
        for (int i = (1<<n) - 2; i >= 0; -- i){
            double tmp = px;
            for (int j = 0; j < n; ++ j){
                if (!(i & (1<<j)))
                    d[i] += p[j] * (1 + d[i|(1<<j)]);
                else
                    tmp += p[j];
            }
            d[i] = (d[i] + tmp) / (1 - tmp);
        }
        printf ("%.6f\n", d[0]);
    }
    return 0;
}
