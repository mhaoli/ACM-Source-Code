/*
 * Author:  Plumrain
 * Created Time:  2013-11-17 19:22
 * File Name: DP-POJ-1191.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int maxint = 2147483647;

int n;
double sum;
int d[20][10][10][10][10];
int a[10][10], ss[10][10][10][10], s[10][10][10][10];

void init()
{
    sum = 0.0;
    for (int i = 1; i <= 8; ++ i)
        for (int j = 1; j <= 8; ++ j){
            scanf ("%d", &a[i][j]);
            sum += a[i][j];
        }

    CLR (ss);
    for (int i = 1; i <= 8; ++ i)
        for (int j = 1; j <= 8; ++ j)
            for (int k = i; k <= 8; ++ k)
                for (int l = j; l <= 8; ++ l){
                    if (i == k && j == l) 
                        ss[i][j][k][l] = a[i][j];
                    else if (j == l)
                        ss[i][j][k][l] = ss[i][j][k-1][l] + a[k][l];
                    else{
                        ss[i][j][k][l] = ss[i][j][k][l-1];
                        for (int ii = i; ii <= k; ++ ii)
                            ss[i][j][k][l] += a[ii][l];
                    }
                }

    CLR (s);
    for (int i = 1; i <= 8; ++ i)
        for (int j = 1; j <= 8; ++ j)
            for (int k = i; k <= 8; ++ k)
                for (int l = j; l <= 8; ++ l)
                    s[i][j][k][l] = ss[i][j][k][l]*ss[i][j][k][l];
}

double gao()
{
    for (int i = 1; i <= 8; ++ i)
        for (int j = 1; j <= 8; ++ j)
            for (int k = i; k <= 8; ++ k)
                for (int l = j; l <= 8; ++ l)
                    d[1][i][j][k][l] = s[i][j][k][l];

    for (int t = 2; t <= n; ++ t)
        for (int i = 1; i <= 8; ++ i)
            for (int j = 1; j <= 8; ++ j)
                for (int k = i; k <= 8; ++ k)
                    for (int l = j; l <= 8; ++ l){
                        if (i == k && j == l){
                            d[t][i][j][k][l] = s[i][j][k][l];
                            continue;
                        }
                        int tmp = maxint;
                        for (int a = i; a < k; ++ a){
                            tmp = min(tmp, d[t-1][i][j][a][l] + s[a+1][j][k][l]);
                            tmp = min(tmp, d[t-1][a+1][j][k][l] + s[i][j][a][l]);
                        }
                        for (int a = j; a < l; ++ a){
                            tmp = min(tmp, d[t-1][i][j][k][a] + s[i][a+1][k][l]);
                            tmp = min(tmp, d[t-1][i][a+1][k][l] + s[i][j][k][a]);
                        }
                        d[t][i][j][k][l] = tmp;
                    }

    double ret = (double)d[n][1][1][8][8] / n - (sum*sum/n/n);
    ret = sqrt(ret);
    return ret;
}

int main()
{
    while (scanf ("%d", &n) != EOF){
        init();
        printf ("%.3f\n", gao());
    }
    return 0;
}
