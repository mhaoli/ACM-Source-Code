/*
 * Author:  Plumrain
 * Created Time:  2013-11-18 23:37
 * File Name: DP-POJ-3254.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
const int mod = 100000000;

int n, m, a[20][20];
int d[20][1<<13];

void init()
{
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            scanf ("%d", &a[i][j]);
}

bool gao1(int sta)
{
    int x = 0;
    while (sta > 0){
        if (x == 1 && (sta&1))
            return 0;
        x = sta & 1;
        sta >>= 1;
    }
    return 1; 
}

bool gao2(int sta, int k)
{
    for (int i = 0; i < m; ++ i)
        if (!a[k][i] && (sta & (1<<i))) return 0;
    return 1;
}

bool gao3(int s1, int s2)
{
    for (int i = 0; i < (1<<m); ++ i){
        int t1 = s1 & (1<<i), t2 = s2 & (1<<i);
        if (t1 && t2) return 0;
    }
    return 1;
}

int DP()
{
    CLR (d);
    for (int i = 0; i < (1<<m); ++ i) 
        if (gao1(i) && gao2(i, 0)) d[0][i] = 1;

    for (int i = 1; i < n; ++ i)
        for (int j = 0; j < (1<<m); ++ j){
            d[i][j] = 0;
            if (gao1(j) && gao2(j, i))
                for (int k = 0; k < (1<<m); ++ k)
                    if (gao3(j, k)) d[i][j] = (d[i][j] + d[i-1][k]) % mod;
        }

    int ret = 0;
    for (int i = 0; i < (1<<m); ++ i)
        if (gao1(i) && gao2(i, n-1)) ret = (d[n-1][i] + ret) % mod;
    return (int)ret;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF){    
        init();
        printf ("%d\n", DP());
    }
    return 0;
}
