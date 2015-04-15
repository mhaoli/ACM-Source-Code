/*
 * Author:  Plumrain
 * Created Time:  2013-12-02 20:52
 * File Name: G-POJ-1287.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Pat{
    int s, e, w;
};

int f[110];
Pat p[100005];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void init(int n, int m)
{
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &p[i].s, &p[i].e, &p[i].w);
        -- p[i].s; -- p[i].e;
    }
}

int kruskal(int n, int m)
{
    sort(p, p+m, cmp);
    for (int i = 0; i < n; ++ i)
        f[i] = i;

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
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF && n){
        init(n, m);
        int ans = kruskal(n, m);
        printf ("%d\n", ans);
    }
    return 0;
}
