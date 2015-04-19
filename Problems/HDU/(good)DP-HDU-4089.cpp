/*
 * Author:  Plumrain
 * Created Time:  2013-10-31 19:59
 * File Name: DP-HDU-4089.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const double eps = 1e-8;
#define CLR(x) memset(x, 0, sizeof(x))
#define zero(x) (((x)>0?(x):-(x))<eps)

double d[2005][2005], c[2005];

int main()
{
    int n, m, k;
    double p1, p2, p3, p4;
    double p21, p31, p41;
    while (scanf ("%d%d%d", &n, &m, &k) != EOF){
        scanf ("%lf%lf%lf%lf", &p1, &p2, &p3, &p4);

        if (zero(p4)){
            printf ("0.00000\n");
            continue;
        }

        p21 = p2 / (1 - p1);
        p31 = p3 / (1 - p1);
        p41 = p4 / (1 - p1);

        CLR (d); d[1][1] = p4 / (1 - p1 - p2);
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= i; ++ j){ 
                if (j == 1) c[j] = p41;
                else if (j <= k) c[j] = d[i-1][j-1] * p31 + p41;
                else c[j] = d[i-1][j-1] * p31;
            }

            double sum = 0.0, cnt = 1.0;
            for (int j = i; j >= 1; -- j){
                sum += c[j] * cnt;
                cnt *= p21;
            }
            if (i > 1) d[i][i] = sum / (1 - cnt);
             
            for (int j = 0; j <= i; ++ j){
                if (j == 1)
                    d[i][j] = d[i][i]*p21 + p41;
                else if (j <= k)
                    d[i][j] = d[i][j-1]*p21 + d[i-1][j-1]*p31 + p41;
                else 
                    d[i][j] = d[i][j-1]*p21 + d[i-1][j-1]*p31;
            }
        }

        printf ("%.5f\n", d[n][m]);
    }
    return 0;
}
