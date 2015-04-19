/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 11.cpp
 */
#include<iostream>
#include<cstdio>

using namespace std;

#define out(x) cout<<#x<<":"<<(x)<<endl

int a[20][20];
int ok(int x, int y, int u)
{
    int ret = a[x][y], tx = x, ty = y;
    for (int i = 0; i < 3; ++ i){
        if (u == 1) ++ tx; 
        else if (u == 2) ++ ty;
        else if (u == 3) -- tx, ++ ty;
        else ++ tx, ++ ty;

        if (tx >= 20 || ty >= 20 || tx < 0 || ty < 0) return -1;
        ret *= a[tx][ty]; 
    }
    return ret;
}
int main()
{
    for (int i = 0; i < 20; ++ i) for (int j = 0; j < 20; ++ j) scanf ("%d", &a[i][j]);
    int ans = 0;
    for (int i = 0; i < 20; ++ i) for (int j = 0; j < 20; ++ j) for (int t = 0; t < 4; ++ t) ans = max(ans, ok(i, j, t));
    out (ans);
    return 0;
}
