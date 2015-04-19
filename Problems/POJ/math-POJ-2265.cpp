/*
 * Author:  Plumrain
 * Created Time:  2013-10-16 13:01
 * File Name: math-POJ-2265.cpp
 */
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define zero(x) (((x)>0?(x):-(x))<eps)
const double eps = 1e-8;
int dir[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};

void cha(int x, int& xx, int& yy)
{
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

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF){
        if (n == 1){
            printf ("0 0\n");
            continue;
        }

        int x, y;
        cha(n, x, y);
        printf ("%d %d\n", x, y);
    }
    return 0;
}
