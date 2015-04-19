/*
 * Author:  Plumrain
 * Created Time:  2013-12-02 20:18
 * File Name: G-POJ-1251.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Pat{
    int s, e, w;
};

int f[110];
Pat p[1005];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

int find (int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void init(int n, int& all)
{
    char s1[10];
    int num, s, e, w;
    for (int i = 0; i < n-1; ++ i){
        scanf ("%s%d", s1, &num);
        s = s1[0] - 'A';
        for (int j = 0; j < num; ++ j){ 
            scanf ("%s%d", s1, &w);
            e = s1[0] - 'A';
            p[all].s = s; p[all].e = e;
            p[all++].w = w;
        }
    }
}

int kruskal(int n, int m)
{
    sort (p, p+m, cmp);
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
    int n;
    while (scanf ("%d", &n) != EOF && n){
        int all = 0;
        init(n, all);
        int ans = kruskal(n, all);
        printf ("%d\n", ans);
    }
    return 0;
}
