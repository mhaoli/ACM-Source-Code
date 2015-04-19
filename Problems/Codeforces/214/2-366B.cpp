/*
 * Author:  Plumrain
 * Created Time:  2013-11-25 00:02
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))

int n, k;
int a[100005];

int main()
{
    while (scanf ("%d%d", &n, &k) != EOF){    
        CLR (a);
        int t;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &t);
            a[i%k] += t;
        }
        int ans = 0;
        for (int i = 1; i < k; ++ i)
            if (a[i] < a[ans]) ans = i;
        printf ("%d\n", ans+1);
    }
    return 0;
}
