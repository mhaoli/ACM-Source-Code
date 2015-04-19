/*
 * Author:  Plumrain
 * Created Time:  2013-11-19 23:47
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

int a[100005];

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &a[i]);
        if (n < 3){
            printf ("%d\n", n);
            continue;
        }

        int ans = 2, tmp = 2;
        for (int i = 2; i < n; ++ i){
            if (a[i] == a[i-1] + a[i-2]) ++ tmp;
            else{
                ans = max(ans, tmp);
                tmp = 2;
            }
        }
        ans = max(ans, tmp);
        printf ("%d\n", ans);
    }
    return 0;
}
