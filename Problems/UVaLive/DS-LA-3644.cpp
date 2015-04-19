/*
 * Author:  Plumrain
 * Created Time:  2013-11-29 14:14
 * File Name: DS-LA-3644.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;

int f[maxn];

int find(int x)
{
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

int main()
{
    int a, b;
    while (scanf ("%d", &a) != EOF){
        for (int i = 0; i < maxn; ++ i)
            f[i] = i;
        int ans = 0;
        while (a >= 0){
            scanf ("%d", &b);
            int t1 = find(a), t2 = find(b);
            if (t1 != t2) f[t1] = t2;
            else ++ ans;
            scanf ("%d", &a);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
