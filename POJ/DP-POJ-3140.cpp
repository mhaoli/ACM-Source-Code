/*
 * Author:  Plumrain
 * Created Time:  2013-11-21 13:58
 * File Name: DP-POJ-3140.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
typedef long long int64;
const int maxn = 100005;

int n, m;
bool vis[maxn];
int64 c[maxn], tot[maxn];
vector<int> pat[maxn];

void init()
{
    CLR (vis); CLR (tot);
    for (int i = 0; i < n; ++ i)
        pat[i].clear();
    
    for (int i = 0; i < n; ++ i)
        scanf ("%lld", &c[i]);
    int t1, t2;
    for (int i = 0; i < n-1; ++ i){
        scanf ("%d%d", &t1, &t2);
        -- t1; -- t2;
        pat[t1].PB(t2);
        pat[t2].PB(t1);
    }
}

void dfs(int x)
{
    vis[x] = 1;
    tot[x] = c[x];
    int sz = pat[x].size();
    for (int i = 0; i < sz; ++ i){
        int y = pat[x][i];
        if (vis[y]) continue;

        dfs(y);
        tot[x] += tot[y];
    }
}

int64 abs64(int64 x)
{
    return x > 0 ? x : -x;
}

int main()
{
    int test = 0;
    while (scanf ("%d%d", &n, &m) != EOF && n){
        init();
        dfs(0);

        int64 sum = tot[0], ans = 1LL<<60;
        for (int i = 0; i < n; ++ i)
            if (abs64(sum-2*tot[i]) < ans)
                ans = abs64(sum-2*tot[i]);
        printf ("Case %d: %lld\n", ++ test, ans);
    }
    return 0;
}
