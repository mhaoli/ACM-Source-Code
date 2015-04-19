/*
 * Author:  Plumrain
 * Created Time:  2013-12-02 19:55
 * File Name: G-HDU-1102.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Pat{
    int s, e, w;
};

int f[110];
Pat p[10005];

bool cmp(Pat a, Pat b){ return a.w < b.w;}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void init(int n, int& all)
{
    for (int i = 0; i < n; ++ i)
        f[i] = i;

    int t;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j){
            scanf ("%d", &t);
            p[all].s = i; p[all].e = j;
            p[all++].w = t;
        }
    
    int a, b, q;
    scanf ("%d", &q);
    for (int i = 0; i < q; ++ i){
        scanf ("%d%d", &a, &b);
        -- a; -- b;
        int t1 = find(a), t2 = find(b);
        if (t1 != t2) f[t1] = t2;
    }
}

int kruskal(int n, int m)
{
    sort(p, p+m, cmp);

    int cost = 0;
    for (int i = 0; i < m; ++ i){
        int t1 = find(p[i].s), t2 = find(p[i].e);
        if (t1 != t2){
            cost += p[i].w;
            f[t1] = t2;
        }
    }
    
    int tmp;
    for (int i = 0; i < n; ++ i){
        if (!i) tmp = find(i);
        else if (tmp != find(i)) return -1;
    }
    return cost;
}

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF){
        int all = 0;
        init(n, all);
        int ans = kruskal(n, all);
        printf ("%d\n", ans);
    }
    return 0;
}
