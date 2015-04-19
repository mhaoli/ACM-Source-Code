/*
 * Author:  Plumrain
 * Created Time:  2013-10-29 16:18
 * File Name: math-POJ-2096.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int N = 1000;

int n, s;
double d[N+5][N+5];

int main()
{
    while (scanf ("%d%d", &n, &s) != EOF){
        CLR (d);
        d[n][s] = 0;
        int ns = n * s;
        for (int i = n; i >= 0; -- i)
            for (int j = s; j >= 0; -- j){
                if (i == n && j == s) continue;
                d[i][j] = (d[i+1][j] * (n-i)*j + d[i][j+1] * i*(s-j) + d[i+1][j+1] * (n-i)*(s-j) + ns) / (ns-i*j + 0.0);
            }
        printf ("%.4f\n", d[0][0]);
    }
    return 0;
}
