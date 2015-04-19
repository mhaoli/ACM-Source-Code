/*
 * Author:  Plumrain
 * Created Time:  2013-11-19 01:01
 * File Name: DP-POJ-2411.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
typedef long long int64;

int n, m;
int64 d[20][1<<12];
vector<int> pat[1<<12];

bool gao1(int sta)
{
    int x = 0, time = 0;
    while (sta > 0){
        x = sta & 1;
        sta >>= 1;
        if (!x){
            if (time & 1) return 0;
            time = 0;
        }
        else ++ time;
    }
    return !(time & 1);
}

bool gao2(int s1, int s2)
{
    for (int i = 0; i < m; ++ i){
        int t1 = s1 & (1<<i), t2 = s2 & (1<<i);
        if (!t1 && !t2) return 0;

        if (!t1) s2 ^= (1 << i);
    }
    return gao1(s2);
}

void init()
{
    for (int i = 0; i < (1<<m); ++ i)
        pat[i].clear();
    for (int i = 0; i < (1<<m); ++ i)
        for (int j = 0; j < (1<<m); ++ j)
            if (gao2(j, i)) pat[i].PB(j);
}

int64 DP()
{
    CLR (d);
    for (int i = 0; i < (1<<m); ++ i)
        d[0][i] = gao1(i);

    for (int i = 1; i < n; ++ i)
        for (int j = 0; j < (1<<m); ++ j){
            d[i][j] = 0;
            for (int k = 0; k < (int)pat[j].size(); ++ k)
                d[i][j] += d[i-1][pat[j][k]]; 
        }

    return d[n-1][(1<<m)-1];
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n){
        init();
        printf ("%lld\n", DP());
    }
    return 0;
}
