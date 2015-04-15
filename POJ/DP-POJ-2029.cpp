/*
 * Author:  Plumrain
 * Created Time:  2013-11-18 01:05
 * File Name: DP-POJ-2029.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

int n, w, h, s, t;
bool has[200][200];
int d[2][2][105][105];

void init()
{
    scanf ("%d%d", &w, &h);
    int t1, t2;
    CLR (has);
    for (int i = 0; i < n; ++ i){
        scanf ("%d%d", &t1, &t2);
        has[t1][t2] = 1;
    }
    scanf ("%d%d", &s, &t);
}

int DP()
{
    int ret = 0;
    CLR (d);
    ret = d[1][1][1][1] = has[1][1];
    for (int i = 2; i <= w; ++ i)
        d[1][1][i][1] = d[1][1][i-1][1] + has[i][1];
    for (int i = 2; i <= h; ++ i)
        d[1][1][1][i] = d[1][1][1][i-1] + has[1][i];

    for (int i = 2; i <= w; ++ i)
        for (int j = 2; j <= h; ++ j)
            d[1][1][i][j] = has[i][j] + d[1][1][i-1][j] + d[1][1][i][j-1] - d[1][1][i-1][j-1];

    for (int x1 = 1; x1 <= w; ++ x1)
        for (int y1 = 1; y1 <= h; ++ y1)
            for (int x2 = x1; x2 <= min(x1+s-1, w); ++ x2)
                for (int y2 = y1; y2 <= min(y1+t-1, h); ++ y2)
                    ret = max(ret, d[1][1][x2][y2] - d[1][1][x1-1][y2] - d[1][1][x2][y1-1] + d[1][1][x1-1][y1-1]);
    return ret;
}

int main()
{
    while (scanf ("%d", &n) != EOF && n){
        init();
        printf ("%d\n", DP()); 
    }
    return 0;
}
