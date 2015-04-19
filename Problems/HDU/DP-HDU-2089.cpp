/*
 * Author:  Plumrain
 * Created Time:  2013-12-14 13:40
 * File Name: DP-HDU-2089.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

int s[20], d[10][3];

int gao(int x)
{
    int ret = x + 1;
    CLR (s);
    int len = 0;
    while (x){
        s[len++] = x % 10;
        x /= 10;
    }
    s[len] = 0;
    
    bool flag = 0;
    for (int i = len-1; i >= 0; -- i){
        ret -= s[i] * d[i][2];
        if (flag) ret -= s[i] * (d[i][0] + d[i][1]);
        else{
            if (s[i] > 6) ret -= d[i][1];
            if (s[i] > 4) ret -= d[i][0] + d[i][1];
            if (s[i+1] == 6 && s[i] > 2) ret -= d[i][0] + d[i][1];
        }

        if ((s[i+1] == 6 && s[i] == 2) || s[i] == 4) flag = 1;
    }
    return ret;
}

int main()
{
    CLR (d);
    d[0][0] = 1;
    for (int i = 1; i < 10; ++ i){
        d[i][0] = 8 * (d[i-1][0] + d[i-1][1]) - d[i-1][1];
        d[i][1] = d[i-1][1] + d[i-1][0];
        d[i][2] = d[i-1][0] + 2*d[i-1][1] + 10*d[i-1][2];
    }

    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        if (!n && !m) break;
        printf ("%d\n", gao(m+1) - gao(n));
    }
    return 0;
}
