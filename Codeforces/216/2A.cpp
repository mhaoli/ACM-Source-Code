/*
 * Author:  Plumrain
 * Created Time:  2013-11-29 23:35
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, t1, t2;
    while (scanf ("%d%d%d", &n, &t1, &t2) != EOF){
        int a, one = 0, two = 0;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &a);
            if (a == 1) ++ one;
            else ++ two;
        }

        int ans;
        if (one >= t1) ans = one - t1 + max(two-t2, 0);
        else{
            int tmp = t1 - one;
            ans = max(two - tmp - t2, 0);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
