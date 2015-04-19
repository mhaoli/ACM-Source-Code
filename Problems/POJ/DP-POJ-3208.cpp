/*
 * Author:  Plumrain
 * Created Time:  2013-12-14 20:55
 * File Name: DP-POJ-3208.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;
int64 d1[20][10][10], d2[20][10][10];

int64 get_num(int64 x)
{
    int len = 0, dit[30];
    bool xxx = 0;
    while (x){
        dit[len++] = x % 10;
        x /= 10;
        if (len > 2 && dit[len-1] == 6 && dit[len-2] == 6 && dit[len-3] == 6)
            xxx = 1;
    }
    dit[len] = 0; dit[len+1] = 0;
    
    int64 ret = 0;
    if (xxx) ret = 1;
    bool flag = 0;
    for (int i = len-1; i >= 0; -- i){
        for (int j = 0; j < 10; ++ j)
            for (int k = 0; k < 10; ++ k)
                ret += dit[i] * d2[i][j][k];

        if (flag){
            for (int j = 0; j < 10; ++ j)
                for (int k = 0; k < 10; ++ k)
                    ret += dit[i] * d1[i][j][k];
        }
        else {
            if (dit[i+2] == 6  && dit[i+1] == 6 && dit[i] > 6){
                for (int j = 0; j < 10; ++ j)
                    for (int k = 0; k < 10; ++ k)
                        ret += d1[i][j][k];
            }
            else if (dit[i+1] == 6 && dit[i] > 6){
                for (int j = 0; j < 10; ++ j)
                    ret += d1[i][6][j];
            }
            else if (dit[i] > 6) ret += d1[i][6][6];
        }

        if (dit[i] == 6 && dit[i+1] == 6 && dit[i+2] == 6)
            flag = 1;
    }
    return ret;
}

int64 gao(int64 n)
{
    int64 l = 0, r = 100000000000000;
    while (l <= r){
        int64 mid = (l + r) >> 1;
        if (get_num(mid) < n) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    CLR (d1); CLR (d2);
    d1[0][0][0] = 1;
    for (int i = 0; i < 10; ++ i){
        d1[1][i][0] = 1;
        for (int j = 0; j < 10; ++ j)
            d1[2][i][j] = 1;
    }

    for (int i = 3; i < 15; ++ i){
        d2[i][6][6] += d1[i-1][6][6];
        d1[i][6][6] -= d1[i-1][6][6];
        for (int j = 0; j < 10; ++ j)
            for (int k = 0; k < 10; ++ k)
                for (int l = 0; l < 10; ++ l){
                    d2[i][j][k] += d2[i-1][k][l];
                    d1[i][j][k] += d1[i-1][k][l];
                }
    }

    int T;
    scanf ("%d", &T);
    while (T--){
        int64 n;
        cin >> n;
        cout << gao(n) << endl;
    }
    return 0;
}
