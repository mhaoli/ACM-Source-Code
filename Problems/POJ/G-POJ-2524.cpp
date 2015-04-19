/*
 * Author:  Plumrain
 * Created Time:  2013-11-25 01:26
 * File Name: G-POJ-2524.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;


int f[50005];

int main()
{
    int test = 0, n, m;
    while (scanf ("%d%d", &n, &m) != EOF && n){    
        for (int i = 0; i < n; ++ i) f[i] = i;

        int t1, t2;
        for (int i = 0; i < m; ++ i){
            scanf ("%d%d", &t1, &t2);
            while (t1 != f[t1]) t1 = f[t1];
            while (t2 != f[t2]) t2 = f[t2];
            if (t1 != t2) f[t1] = t2;
        }

        int ans = 0;
        for (int i = 0; i < n; ++ i)
            if (f[i] == i) ++ ans;
        printf ("Case %d: %d\n", ++ test, ans);
    }
    return 0;
}
