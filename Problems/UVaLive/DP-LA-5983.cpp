/*
 * Author:  Plumrain
 * Created Time:  2013-12-03 20:25
 * File Name: DP-LA-5983.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define CLR1(x) memset(x, -1, sizeof(x))

int n, m;
int d[505][505];
int s[505][505];

void init()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            scanf ("%d", &s[i][j]);
}

bool dp(int x)
{
    CLR1 (d);
    d[0][0] = x + s[0][0];
    for (int i = 1; i < n; ++ i)
        if (d[i-1][0] > 0)
            d[i][0] = d[i-1][0] + s[i][0];
    for (int i = 0; i < m; ++ i)
        if (d[0][i-1] > 0)
            d[0][i] = d[0][i-1] + s[0][i];

    for (int i = 1; i < n; ++ i)
        for (int j = 1; j < m; ++ j){
            if (d[i][j-1] > 0)
                d[i][j] = max(d[i][j], d[i][j-1] + s[i][j]);
            if (d[i-1][j] > 0)
                d[i][j] = max(d[i][j], d[i-1][j] + s[i][j]);
        }
    if (d[n-1][m-1] <= 0) return 0;
    return 1;
}

int bin_search()
{
    int l = 1, r = 1e7;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (!dp(mid)) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init();
        int ans = bin_search();
        printf ("%d\n", ans);
    }
    return 0;
}
