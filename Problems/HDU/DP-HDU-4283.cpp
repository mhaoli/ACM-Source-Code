/*
 * Author:  Plumrain
 * Created Time:  2014-01-30 14:41
 * File Name: DP-HDU-4283.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
int d[105][105][105];
int an[105], n;
int dp(int num, int s, int e)
{
    if (s == e) return num * an[s];
    if (s > e) return 0;
    int &ret = d[num][s][e];
    if (ret != -1) return ret;
    ret = num*an[s] + dp(num+1, s+1, e);
    for (int i = s+1; i <= e; ++ i)
        ret = min(ret, dp(num, s+1, i) + (num+i-s)*an[s] + dp(num+i-s+1, i+1, e));
    return ret;
}
int main()
{
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        clrs (d, -1);
        scanf ("%d", &n);
        for (int i = 0; i < n; ++ i) scanf ("%d", &an[i]);
        printf ("Case #%d: %d\n", ++ cas, dp(0, 0, n-1));
    }
    return 0;
}
