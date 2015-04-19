/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 15.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl

typedef long long int64;
int64 d[25][25];
int main()
{
    clr0 (d);
    d[0][0] = 0;
    for (int i = 0; i <= 20; ++ i) d[i][0] = d[0][i] = 1;
    for (int i = 1; i <= 20; ++ i) for (int j = 1; j <= 20; ++ j) d[i][j] = d[i-1][j] + d[i][j-1];
    out (d[20][20]);
    return 0;
}
