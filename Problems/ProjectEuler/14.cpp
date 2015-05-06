/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: 14.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define clr1(x) memset(x, -1, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl

typedef long long int64;
const int64 N = 10000000;
int64 d[N+5];
int64 gao(int64 x)
{
    if (x <= N && d[x] != -1) return d[x];

    int64 ret = 0;
    if (x & 1) ret = 1 + gao(3*x+1);
    else ret = 1 + gao(x/2);
    if (x <= N) d[x] = ret;
    return ret;
}
int main()
{
    clr1 (d); d[1] = 0;
    int64 ans = 1;
    for (int64 i = 2; i < 1000000; ++ i) ans = d[ans] > gao(i) ? ans : i;
    out (ans);
    return 0;
}
