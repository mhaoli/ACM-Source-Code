/*
 * Author:  Plumrain
 * Created Time:  2013-11-24 20:57
 * File Name: G-POJ-1861.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int maxm = 15005 * 2;
const int maxn = 1005;

struct pat{
    int s, t, l;
};

pat p[maxm];
bool v[maxm];
vector<int> ans;
int n, m, all, f[maxn];

bool cmp(pat a, pat b)
{
    return a.l < b.l;
}

void init()
{
    int t1, t2, t3;
    all = 0;
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &t1, &t2, &t3);
        -- t1; -- t2;
        p[all].s = p[all+1].t = t1;
        p[all].t = p[all+1].s = t2;
        p[all++].l = t3;
        p[all++].l = t3;
    }
}

void Kruskal()
{
    sort(p, p+all, cmp);
    for (int i = 0; i < n; ++ i) f[i] = i;
    CLR (v);
    for (int i = 0; i < all; ++ i){
        int t1 = p[i].s, t2 = p[i].t;
        while (t1 != f[t1]) t1 = f[t1];
        while (t2 != f[t2]) t2 = f[t2];
        if (t1 != t2){
            v[i] = 1;
            f[t1] = t2;
        }
    }
}

int main()
{
    while (scanf ("%d%d", &n, &m) != EOF){
        init();
        Kruskal();

        ans.clear();
        int cnt = 0;
        for (int i = 0; i < all; ++ i) if (v[i]){
            cnt = max(i, cnt);
            ans.PB(i);
        }
        int sz = ans.size();
        printf ("%d\n%d\n", p[cnt].l, sz);
        for (int i = 0; i < sz; ++ i)
            printf ("%d %d\n", p[ans[i]].s+1, p[ans[i]].t+1);
    }
    return 0;
}
