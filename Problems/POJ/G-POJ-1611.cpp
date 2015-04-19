/*
 * Author:  Plumrain
 * Created Time:  2013-11-25 02:04
 * File Name: G-POJ-1611.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

int n, m, f[30005];

void init()
{
    for (int i = 0; i < n; ++ i) 
        f[i] = i;

    int t, t1, t2;
    for (int i = 0; i < m; ++ i){
        scanf ("%d", &t);
        if (!t) continue;

        scanf ("%d", &t1);
        while (t1 != f[t1]) t1 = f[t1];

        for (int i = 1; i < t; ++ i){
            scanf ("%d", &t2);
            while (t2 != f[t2]) t2 = f[t2];
            f[t2] = t1;
        }
    }
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n){
        init();

        int x = 0;
        while (x != f[x]) x = f[x];
        int ans = 0;
        for (int i = 0; i < n; ++ i){
            int tmp = i;
            while (tmp != f[tmp]) tmp = f[tmp];
            if (tmp == x) ++ ans;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
