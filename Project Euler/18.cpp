/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 18.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define clr0(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl

int a[20][20], d[20][20];
int main()
{
    for (int i = 0; i < 15; ++ i) 
        for (int j = 0; j <= i; ++ j) 
            scanf ("%d", &a[i][j]);
    clr0 (d); d[0][0] = a[0][0];
    for (int i = 1; i < 15; ++ i)
        for (int j = 0; j <= i; ++ j){
            d[i][j] = d[i-1][j];
            if (j) d[i][j] = max(d[i][j], d[i-1][j-1]);
            d[i][j] += a[i][j];
        }
    int num = 0;
    for (int i = 0; i < 15; ++ i) num = max(num, d[14][i]);
    out (num);
    return 0;
}
