/*
 * Author:  Plumrain
 * Created Time:  2013-12-16 12:19
 * File Name: DP-HDU-4389.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
typedef long long int64;
int dit[20];
int64 ten[15];
int d[11][85][85][85];

void init()
{
    ten[0] = 1;
    for (int i = 1; i < 15; ++ i)
        ten[i] = ten[i-1] * 10;
    
    CLR (d);
    for (int i = 0; i < 10; ++ i)
        for (int j = 1; j < 85; ++ j)
            ++ d[1][i][j][i%j];

    for (int i = 2; i < 10; ++ i)
        for (int j = 0; j < 85; ++ j)
            for (int k = 1; k < 85; ++ k)
                for (int l = 0; l < k; ++ l)
                    for (int t = 0; t < 10; ++ t) if (j+t < 85)
                        d[i][j+t][k][(l+t*ten[i-1])%k] += d[i-1][j][k][l];
}

int gao(int x)
{
    if (x < 10) return x-1;
    int64 ret = 0, len = 0;
    while (x){
        dit[len++] = x % 10;
        x /= 10;
    }
    dit[len] = 0;

    int64 flag = 0, dt_sum = 0;
    for (int i = len-1; i > 0; -- i){
        for (int t = 0; t < dit[i]; ++ t)
            for (int j = 0; j < 82; ++ j)
                for (int l = 0; l < 82; ++ l){
                    int k = j + t + dt_sum;
                    if (!k || (flag + t*ten[i] + l) % k != 0) continue;
                    ret += d[i][j][k][l];
                }

        flag += dit[i] * ten[i]; 
        dt_sum += dit[i];
    }

    for (int i = 0; i < dit[0]; ++ i)
        if ((flag+i) % (dt_sum+i) == 0) ++ ret;
    return (int)ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("my.out","w",stdout);
    init();
    int T, test = 0;
    scanf ("%d", &T);
    while (T--){
        int a, b;
        scanf ("%d%d", &a, &b);
        printf ("Case %d: %d\n", ++test, gao(b+1) - gao(a));
    }
    return 0;
}
