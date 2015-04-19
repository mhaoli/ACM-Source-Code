/*
 * Author:  Plumrain
 * Created Time:  2013-11-11 15:38
 * File Name: DP-CF-148D.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

double p[1005][1005];

void DP()
{
    CLR (p);
    for (int i = 0; i <= 1001; ++ i){
        p[i][0] = 1.0;
        p[0][i] = 0.0;
        p[i][1] = (double)i / (i + 1);
    }
    for (int i = 1; i <= 1001; ++ i)
        for (int j = 2; j <= 1001; ++ j){
            p[i][j] = (double)i / (i + j);
            double tmp = (double)j * (j-1) / (i + j) / (i + j - 1);
            if (j > 2)
                p[i][j] += tmp * (double)(j-2)/(i+j-2) * p[i][j-3];
            p[i][j] += tmp * (double)i/(i+j-2) * p[i-1][j-2];
        }
}

int main()
{
    DP();
    int w, b;
    while (scanf ("%d%d", &w, &b) != EOF)
        printf ("%.10f\n", p[w][b]);
    return 0;
}
