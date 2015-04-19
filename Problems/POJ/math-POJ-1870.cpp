/*
 * Author:  Plumrain
 * Created Time:  2013-10-16 14:00
 * File Name: math-POJ-1870.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define zero(x) (((x)>0?(x):-(x))<eps)
const double eps = 1e-8;
const int maxint = 2147483647;

int dir[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
int change[6][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, 1}};
int x[2], y[2], ans;

void cha(int x, int& xx, int& yy)
{
    if (x == 1){xx = 0; yy = 0; return;}

    double n = (sqrt(12.0*x - 3) - 3.0) / 6.0;
    int p = zero(n - ceil(n)) ? (int)n : ceil(n);
    int t = x - 3 * p * p + 3 * p - 1;
    xx = p - 1; yy = 0;
    while (1){
        if (!t) return;
        xx += dir[0][0]; yy += dir[0][1];
        -- t;
        if (!t) return;
        for (int i = 0; i < p-1; ++ i){
            xx += dir[1][0]; yy += dir[1][1];
            -- t;
            if (!t) return;
        }

        for (int i = 2; i <= 6; ++ i)
            for (int j = 1; j <= p; ++ j){
                xx += dir[i%6][0]; yy += dir[i%6][1];
                -- t;
                if (!t) return;
            }
    }
}

int gao()
{
    if (x[0] == x[1] || y[0] == y[1]) 
        return abs(x[0]-x[1] + y[0]-y[1]);
    
    int tmp1 = x[0] - x[1], tmp2 = y[0] - y[1];
    if (tmp1 * tmp2 < 0)
        return max(abs(tmp1), abs(tmp2));
    return abs(tmp1) + abs(tmp2);
}

int main()
{
    int a, b;
    while (scanf ("%d%d", &a, &b) != EOF && (a || b)){
        cha(a, x[0], y[0]); cha(b, x[1], y[1]);
        
        int ans = gao();
        printf ("The distance between cells %d and %d is %d.\n", a, b, ans);
    }
    return 0;
}
