/*
 * Author:  Plumrain
 * Created Time:  2013-12-03 21:27
 * File Name: G-POJ-1679.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
struct Pat{
    int s, e, w;
};

int n, m, f[10005];
bool v[10005];
Pat p[10005];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

void init()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i)
        scanf ("%d%d%d", &p[i].s, &p[i].e, &p[i].w);
    sort (p, p+m, cmp);
    CLR (v);
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int kruskal(int x)
{
    for (int i = 0; i < n; ++ i)
        f[i] = i;

    int cost = 0;
    for (int i = 0; i < m; ++ i) if (i != x){
        int t1 = find(p[i].s), t2 = find(p[i].e);
        if (t1 != t2){
            cost += p[i].w;
            f[t1] = t2;
            if (x == -1) v[i] = 1;
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
    int T;
    scanf ("%d", &T);
    while (T--){
        init();
        int ans = kruskal(-1);
        bool ok = 1;
        for (int i = 0; i < m; ++ i) if (v[i]){
            int tmp = kruskal(i);
            if (tmp == ans){
                ok = 0;
                break;
            }
        }
        if (ok) printf ("%d\n", max(ans, 0));
        else printf ("Not Unique!\n");
    }
    return 0;
}
