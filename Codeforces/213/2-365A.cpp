/*
 * Author:  Plumrain
 * Created Time:  2013-11-19 23:32
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

int n, k;
bool a[10];

bool gao()
{
    for (int i = 0; i <= k; ++ i)
        if (!a[i]) return 0;
    return 1;
}

int main()
{
    while (scanf ("%d%d", &n, &k) != EOF){
        int ans = 0;
        for (int i = 0; i < n; ++ i){
            int x;
            scanf ("%d", &x);
            CLR (a);
            while (x > 0){
                a[x%10] = 1;
                x /= 10;
            }
            if (gao()) ++ ans;
        }
        printf ("%d\n", ans); 
    }
    return 0;
}
