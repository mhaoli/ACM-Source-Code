/*
 * Author:  Plumrain
 * Created Time:  2013-12-04 19:35
 * File Name: G-POJ-1679-2.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define CLR1(x) memset(x, -1, sizeof(x))
#define PB push_back

struct Pat{
    int s, e, w;
};

int n, m;
Pat p[10005];
bool vis[105][105];
int d[105][105], f[105];
int cnt[105];
vector<int> nod[105];

bool cmp(Pat a, Pat b)
{
    return a.w < b.w;
}

void init()
{ 
    CLR (vis);
    CLR1 (d);

    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &p[i].s, &p[i].e, &p[i].w);
        -- p[i].s; -- p[i].e;
        d[p[i].s][p[i].e] = p[i].w;
        d[p[i].e][p[i].s] = p[i].w;
    }
    sort (p, p+m, cmp);

    for (int i = 0; i < n; ++ i)
        nod[i].clear();
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int kruskal()
{
    for (int i = 0; i < n; ++ i)
        f[i] = i;
    
    int cost = 0;
    for (int i = 0; i < m; ++ i){
        int s = p[i].s, e = p[i].e, w = p[i].w;
        int t1 = find(s), t2 = find(e);
        if (t1 != t2){
            f[t1] = t2;
            cost += w;
            nod[s].PB (e);
            nod[e].PB (s);
            vis[e][s] = vis[s][e] = 1;
        }
    }

    int tmp;
    for (int i = 0; i < n; ++ i){
        if (!i) tmp = find(i);
        else if (tmp != find(i)) return -1;
    }
    return cost;
}

void dfs(int x, int ma)
{
    if (cnt[x] != -1) return;

    cnt[x] = ma;
    int sz = nod[x].size();
    for (int i = 0; i < sz; ++ i)
        if (cnt[nod[x][i]] == -1) 
            dfs (nod[x][i], max(d[x][nod[x][i]], ma));
}
    
int main()
{
    int T;
    scanf ("%d", &T);
    while (T--){
        init();
        int ans = kruskal();
        if (ans == -1){
            printf ("0\n");
            continue;
        }
        bool ok = 0;
        for (int i = 0; i < n; ++ i){
            CLR1 (cnt);
            dfs (i, 0);

            for (int j = 0; j < n; ++ j) if (i != j && !vis[i][j])
                if (cnt[j] == d[i][j]) ok = 1;
        }
        if (!ok) printf ("%d\n", ans);
        else printf ("Not Unique!\n");
    }
    return 0;
}
