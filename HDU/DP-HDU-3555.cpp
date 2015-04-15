/*
 * Author:  Plumrain
 * Created Time:  2013-12-14 15:05
 * File Name: DP-HDU-3555.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;
int64 d[25][3], dit[20];

int64 gao(int64 x)
{
    int64 len = 0, ret = 0;
    bool xxx = 0;
    CLR (dit);
    while (x){
        dit[len++] = x % 10;
        x /= 10;
        if (len > 1 && dit[len-1] == 4 && dit[len-2] == 9)
            xxx = 1;
    }
    if (xxx) ++ ret;
    dit[len] = 0;

    bool flag = 0;
    for (int i = len-1; i >= 0; -- i){
        ret += dit[i] * d[i][2];
        if (flag) ret += dit[i] * (d[i][0] + d[i][1]);
        else if (dit[i] > 4) ret += d[i][1];

        if (dit[i+1] == 4 && dit[i] == 9) flag = 1;
    }
    return ret;
}

int main()
{
    CLR (d);
    d[0][0] = 1;
    for (int i = 1; i < 20; ++ i){
        d[i][0] = 9 * (d[i-1][0] + d[i-1][1]) - d[i-1][1];
        d[i][1] = d[i-1][0] + d[i-1][1];
        d[i][2] = 10 * d[i-1][2] + d[i-1][1];
    }
    
    int T;
    int64 n;
    scanf ("%d", &T);
    while (T--){
        cin >> n;
        cout << gao(n) << endl;
    }
    return 0;
}
