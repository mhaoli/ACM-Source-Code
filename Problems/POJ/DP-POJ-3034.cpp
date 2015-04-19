/*
 * Author:  Plumrain
 * Created Time:  2013-11-18 21:00
 * File Name: DP-POJ-3034.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int OO = 10;

int n, r, m, t;
int a[20][40][40];
int d[20][40][40];

int abs(int a)
{
    return a > 0 ? a : -a;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

void init()
{
    n += OO;
    CLR (a);
    t = 0;
    int t1, t2, t3;
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &t1, &t2, &t3);
        a[t3][t1+OO][t2+OO] = 1;
        t = max(t, t3);
    }
}

bool ok(int x1, int y1, int x2, int y2)
{
    int t1 = abs(x1 - x2), t2 = abs(y1 - y2);
    return (t1*t1 + t2*t2 <= r*r);
}

int move(int k, int x1, int y1, int x2, int y2)
{
    int ret = 0;
    if (x1 == x2 || y1 == y2){
        if (x1 == x2 && y1 == y2)
            return a[k][x1][y1];
        if (x1 == x2){
            for (int i = min(y1, y2); i <= max(y1, y2); ++ i)
                ret += a[k][x1][i];
            return ret; 
        }
        for (int i = min(x1, x2); i <= max(x1, x2); ++ i)
            ret += a[k][i][y1];
        return ret;
    }
    
    int xd = x2 - x1, yd = y2 - y1; 
    int dd = gcd(abs(xd), abs(yd));
    xd = xd / dd; yd = yd / dd;
    int time = 0;
    while (time <= dd){
        ret += a[k][x1][y1];
        ++ time;
        x1 += xd; y1 += yd;
    }
    return ret;
}

int DP()
{
    CLR (d); 
    for (int i = 1; i <= t; ++ i)
        for (int x1 = 0; x1 <= n+OO; ++ x1)
            for (int y1 = 0; y1 <= n+OO; ++ y1)
                for (int x2 = max(x1-5, 0); x2 <= min(x1+5, n+OO); ++ x2)
                    for (int y2 = max(y1-5, 0); y2 <= min(y1+5, n+OO); ++ y2) if (ok(x1, y1, x2, y2))
                        d[i][x2][y2] = max(d[i][x2][y2], d[i-1][x1][y1] + move(i, x1, y1, x2, y2));
    
    int ret = 0;
    for (int i = 0; i <= n; ++ i)
        for (int j = 0; j <= n; ++ j)
            ret = max(ret, d[t][i][j]);
    return ret;
}

int main()
{
    while (scanf ("%d%d%d", &n, &r, &m) != EOF && n){
        init();
        printf ("%d\n", DP());
    }
    return 0;
}
