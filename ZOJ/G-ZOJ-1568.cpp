/*
 * Author:  Plumrain
 * Created Time:  
 * File Name: G-ZOJ-1568.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))


struct Pat{
    int s, e, w;
};

int n, all, c[1005], f[1005];
Pat p[1000005];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void init()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++ i)
        scanf ("%d", &c[i]);
    all = 0;
    int t;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j){
            scanf ("%d", &t);
            if (i == j) continue;
            p[all].s = i; p[all].e = j;
            p[all++].w = t + c[i] + c[j];
        }
}

int kruskal(int n, int m)
{
    sort (p, p+m, cmp);
    for (int i = 0; i < n; ++ i)
        f[i] = i;
    
    int cost = 0;
    for (int i = 0; i < m; ++ i){
        int s = p[i].s, e = p[i].e, w = p[i].w;
        int t1 = find(s), t2 = find(e);
        if (t1 != t2){
            cost += w;
            f[t1] = t2;
        }
    }

    int tmp;
    for (int i = 0; i < n; ++ i){
        f[i] = find(i);
        if (!i) tmp = f[i];
        else if (tmp != f[i]) return -1;
    }
    return cost;
}

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init();
        int ans = kruskal(n, all);
        printf ("%d\n", ans);
    }
    return 0;
}
