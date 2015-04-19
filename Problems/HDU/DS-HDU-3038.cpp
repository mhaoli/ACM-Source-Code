/*
 * Author:  Plumrain
 * Created Time:  2013-11-28 08:32
 * File Name: DS-HDU-3038.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

struct node{
    int f, r;
};

int n, m, ans;
node a[200005];

int find(int x)
{
    if (x != a[x].f){
        int y = a[x].f;
        a[x].f = find(a[x].f);
        a[x].r = a[x].r + a[y].r;
    }
    return a[x].f;
}

void merge(int ta, int tb, int s, int fa, int fb)
{
    a[fa].f = fb;
    a[fa].r = a[tb].r - a[ta].r - s;
}

bool ok(int ta, int tb, int s, int fa, int fb)
{
    return s == (a[tb].r - a[ta].r); 
}

void init()
{
    ans = 0;
    for (int i = 0; i <= n; ++ i){
        a[i].f = i;
        a[i].r = 0;
    }

    int ta, tb, s;
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &ta, &tb, &s);
        -- ta;
        
        int t1 = find(ta), t2 = find(tb);
        if (t1 != t2)
            merge(ta, tb, s, t1, t2);
        else
            if (!ok(ta, tb, s, t1, t2)) ++ ans;
    }
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF){
        init();
        printf ("%d\n", ans);
    }
    return 0;
}
