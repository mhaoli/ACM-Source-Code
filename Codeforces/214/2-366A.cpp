/*
 * Author:  Plumrain
 * Created Time:  2013-11-24 23:40
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;


int a[4][4], n;

bool gao(int x, int& t1, int& t2)
{
    for (int i = 0; i < 2; ++ i)
        for (int j = 0; j < 2; ++ j)
            if (a[x][i] + a[x][j+2] <= n){
                t1 = a[x][i];
                t2 = n - a[x][i];
                return 1;
            }

    return 0;
}

int main()
{
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < 4; ++ i)
            for (int j = 0; j < 4; ++ j)
                scanf ("%d", &a[i][j]);

        int ans = -2, t1, t2;
        for (int i = 0; i < 4; ++ i)
            if (gao(i,t1,t2)) ans = i;

        printf ("%d", ans+1);
        if (ans > -1)
            printf (" %d %d\n", t1, t2);
        else printf ("\n");
    }
    return 0;
}
