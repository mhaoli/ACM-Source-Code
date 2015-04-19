/*
 * Author:  Plumrain
 * Created Time:  2013-12-15 23:53
 * fILE nAME: dp-fzU-2113.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;
int64 d[25][20];
int dit[25];

int64 mypow(int64 p, int64 n)
{
    int64 ret = 1;
    while (n){
        if (n & 1) ret *= p;
        n >>= 1;
        p *= p;
    }
    return ret;
}

void d_init()
{
    CLR (d);
    d[1][1] = 1;
    for (int i = 2; i < 25; ++ i){
        d[i][1] = mypow(10, i-1);
        for (int j = 0; j < 10; ++ j)
            for (int k = 0; k < 10; ++ k)
                d[i][j] += d[i-1][k];
    }
}

int64 gao(int64 x)
{
    int len = 0;
    while (x){
        dit[len++] = x % 10;
        x /= 10;
    }
    dit[len] = 0;
    
    int64 ret = 0;
    int flag = 0;
    for (int i = len-1; i >= 0; -- i){
        ret += dit[i] * mypow(10, i) * flag;
        for (int j = 0; j < dit[i]; ++ j)
            ret += d[i+1][j];
        if (dit[i] == 1) ++ flag;
    }
    return ret;
}

int main()
{
    d_init();
    int64 a, b;
    while (cin >> a >> b)
        cout << gao(b+1) - gao(a) << endl;
    return 0;
}
