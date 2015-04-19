/*
 * Author:  Plumrain
 * Created Time:  2013-12-01 02:52
 * File Name: G-HDU-1879.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Pat{
    int s, e, w;
};

int n, all, f[110];
Pat p[10005];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

int find (int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void init()
{
    all = 0;
    for (int i = 0; i < n; ++ i)
        f[i] = i;

    int s, e, w, x;
    for (int i = 0; i < n*(n-1)/2; ++ i){
        scanf ("%d%d%d%d", &s, &e, &w, &x);
        -- s; -- e;
        if (x == 1){
            int t1 = find(s), t2 = find(e);
            if (t1 != t2) f[t1] = t2;
        }
        else{
            p[all].s = s; p[all].e = e;
            p[all++].w = w;
        }
    }
}

int kruskal()
{
    int cost = 0;
    sort(p, p+all, cmp);
    for (int i = 0; i < all; ++ i){
        int s = p[i].s, e = p[i].e, w = p[i].w;
        int t1 = find(s), t2 = find(e);
        if (t1 != t2){
            f[t1] = t2; cost += w;
        }
    }
    return cost;
}

int main()
{
    while (scanf ("%d", &n) != EOF && n){ 
        init();
        int ans = kruskal();
        printf ("%d\n", ans);
    }
    return 0;
}
