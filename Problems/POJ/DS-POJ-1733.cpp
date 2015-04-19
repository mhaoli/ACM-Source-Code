/*
 * Author:  Plumrain
 * Created Time:  2013-11-27 17:53
 * File Name: DS-POJ-1733.cpp
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define PB push_back

struct temp{
    int a, b;
    bool x;
    char s[10];
};

struct node{
    int f, r;
};

int n, m, all;
vector<int> ttt;
map<int, int> mp;
node a[10005];
temp tt[5005];

void init()
{
    mp.clear();
    ttt.clear();

    scanf ("%d", &m);

    if (!m)
        return;
    
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%s", &tt[i].a, &tt[i].b, tt[i].s);

        if (tt[i].a > tt[i].b)
            swap(tt[i].a, tt[i].b);

        -- tt[i].a;
        if (tt[i].s[0] == 'e') tt[i].x = 0;
        else tt[i].x = 1; 
        ttt.PB (tt[i].a); ttt.PB (tt[i].b);
    }
    
    sort(ttt.begin(), ttt.end()); 
    int tmp = ttt[0], sz = ttt.size();
    all = 0;
    mp[tmp] = all++;
    for (int i = 1; i < sz; ++ i) if (ttt[i] != tmp){
        tmp = ttt[i];
        mp[tmp] = all++;
    }

    for (int i = 0; i < all; ++ i){
        a[i].f = i;
        a[i].r = 0;
    }
}

int find(int x)
{
    if (x != a[x].f){
        int y = a[x].f;
        a[x].f = find(a[x].f);
        a[x].r = (a[x].r + a[y].r) % 2;
    }
    return a[x].f;
}

void merge(int ta, int tb, bool x, int fa, int fb)
{
    a[fb].f = fa;
    a[fb].r = (a[ta].r + a[tb].r + x) % 2;
}

bool ok(int ta, int tb, bool x, int fa, int fb)
{
    return x == ((a[ta].r + a[tb].r) % 2);
}

int gao()
{
    bool x;
    int ta, tb, fa, fb;
    for (int i = 0; i < m; ++ i){
        ta = mp[tt[i].a]; tb = mp[tt[i].b]; x = tt[i].x;
        fa = find(ta); fb = find(tb);

        if (fa != fb)
            merge(ta, tb, x, fa, fb);
        else
            if (!ok(ta, tb, x, fa, fb)) return i;
    }
    return m;
}

int main()
{
    int n;
    while (scanf ("%d", &n) != EOF){
        init();
        if (!m) printf ("0\n");
        else printf ("%d\n", gao());
    }
    return 0;
}


