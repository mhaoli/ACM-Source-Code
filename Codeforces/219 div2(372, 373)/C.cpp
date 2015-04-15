/*
 * Author:  Plumrain
 * Created Time:  2013-12-14 12:58
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxx = 500005;
int n, a[maxx];

bool ok(int num)
{
    ++ num;
    if (num*2 > n) return 0;
    int i = 0, j = n-num;
    while (i < num){
        if (a[i]*2 > a[j]) return 0;
        ++ i; ++ j;
    }
    return 1;
}

int main()
{
    while (scanf ("%d", &n) != EOF){
        for (int i = 0; i < n; ++ i)
            scanf ("%d", &a[i]);
        sort(a, a+n);

        int l = 0, r = n/2 + 1;
        while (l <= r){
            int mid = (l+r) >> 1;
            if (ok(mid)) l = mid + 1;
            else r = mid - 1;
        }
        printf ("%d\n", n - l);
    }
    return 0;
}
