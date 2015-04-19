/*
 * Author:  Plumrain
 * Created Time:  2013-11-30 10:21
 * File Name: G-HDU-1863.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
struct Pat{
    int s, e, w;
};

int n, m, f[110];
Pat p[10005];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

void init()
{
    for (int i = 0; i < n; ++ i){
        scanf ("%d%d%d", &p[i].s, &p[i].e, &p[i].w);
        -- p[i].s; --p[i].e;
    }
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int kruskal(int n, int m)
{
    sort(p, p+m, cmp);
    for (int i = 0; i < n; ++ i)
        f[i] = i;
    int cost = 0;
    for (int i = 0; i < m; ++ i){
        int s = p[i].s, e = p[i].e;
        int t1 = find(s), t2 = find(e);
        if (t1 != t2){
            f[t1] = t2;
            cost += p[i].w;
        }
    }

    int tmp = find(0);
    for (int i = 1; i < n; ++ i){
        find (i);
        if (f[i] != tmp) return -1;
    }
    return cost;
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF && n){
        init();
        int ans = kruskal(m, n);
        if (ans == -1) printf ("?\n");
        else printf ("%d\n", ans);
    }
    return 0;
}
