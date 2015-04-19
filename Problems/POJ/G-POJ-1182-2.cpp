/*
 * Author:  Plumrain
 * Created Time:  2013-11-25 20:00
 * File Name: G-POJ-1182-2.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 50005;

struct node{
    int f, r, x;
};

int n, k;
node a[maxn];

int find(int x)
{
    if (x == a[x].f){
        a[x].r = a[x].x = 0;
        return x;
    }

    int y = a[x].f;
    if (y == a[y].f){
        a[x].x = a[x].r;
        return y;
    }

    int ret = find(y);    
    a[x].x = (a[x].r + a[y].x) % 3;
    return ret;
}

void merge(int x, int y, int d, int t1, int t2)
{
    t1 = find(x);
    t2 = find(y);
    a[t1].f = t2;
    a[t1].r = a[t1].x = ((3-a[x].x) + a[y].x + d-1) % 3;
}

bool gao(int d, int x, int y)
{
    if ((d == 2 && x == y) || x >= n || y >= n) 
        return false;
    
    int t1 = find(x), t2 = find(y);
    if (t1 == t2){
        if (d == 1)
            if (a[x].x != a[y].x) return false;
        if (d == 2)
            if ((a[x].x%3) != ((a[y].x+1)%3)) return false;
    }
    else
        merge(x, y, d, t1, t2);
    return true;
}

void init()
{
    for (int i = 0; i < n; ++ i){
        a[i].f = i;
        a[i].r = a[i].x = 0;
    }
}

int main()
{
    scanf ("%d%d", &n, &k);
    init();

    int d, x, y, ans = 0;
    for (int i = 0; i < k; ++ i){
        scanf ("%d%d%d", &d, &x, &y);
        if (!gao(d, x-1, y-1)) ++ ans; 
    }
    printf ("%d\n", ans);
    return 0;
}
