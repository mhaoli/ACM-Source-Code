/*
 * Author:  Plumrain
 * Created Time:  2013-12-14 15:50
 * File Name: DP-HDU-4734.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR1(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))

int dit_b[20], d[20][10000];

int Mypow(int p, int n)
{
    int ret = 1;
    while (n){
        if (n & 1) ret *= p;
        n >>= 1;
        p *= p;
    }
    return ret;
}

int dit_dev(int x, int* dit)
{
    int ret = 0;
    while (x){
        dit[ret++] = x % 10;
        x /= 10;
    }
    return ret;
}

int cal(int x)
{
    int ret = 0, dit[20];
    CLR (dit);
    int len = dit_dev(x, dit);
    for (int i = 0; i < len; ++ i)
        ret += dit[i] * Mypow(2, i);
    return ret;
}

int rec(int len, int cost, bool flag)
{
    if (len < 0) return 1;

    if (flag){
        int &ret = d[len][cost];
        if (ret != -1) return ret;
        ret = 0;

        for (int i = 0; i < 10; ++ i){
            int tmp = i * Mypow(2, len);
            if (tmp <= cost) ret += rec(len-1, cost-tmp, 1);
        }
        return ret;
    }
    else{
        int ret = 0;
        for (int i = 0; i < dit_b[len]; ++ i){
            int tmp = i * Mypow(2, len);
            if (tmp <= cost) ret += rec(len-1, cost-tmp, 1);
        }
        int tmp = dit_b[len] * Mypow(2, len);
        if (tmp <= cost) ret += rec(len-1, cost-tmp, 0);
        return ret;
    }
}

int main()
{
    int a, b, T, test = 0;
    CLR1 (d);
    scanf ("%d", &T);
    while (T--){
        scanf ("%d%d", &a, &b);
        CLR (dit_b);
        int tmp = cal(a), len_b = dit_dev(b, dit_b);
        printf ("Case #%d: %d\n", ++test, rec(len_b-1, tmp, 0));
    }
    return 0;
}
