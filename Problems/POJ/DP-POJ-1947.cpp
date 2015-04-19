/*
 * Author:  Plumrain
 * Created Time:  2013-11-19 16:11
 * File Name: DP-POJ-1947.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int maxint = 2147483647 / 10;

int n, p, f;
int d[200][200];
bool vis[200];
vector<int> son[200];

void init()
{
    for (int i = 1; i <= n; ++ i)
        son[i].clear();
    
    CLR (vis);
    int t1, t2;
    for (int i = 0; i < n-1; ++ i){
        scanf ("%d%d", &t1, &t2);
        vis[t2] = 1; 
        son[t1].PB (t2);
    }
        
    for (int i = 1; i <= n; ++ i)
        if (!vis[i]){
            f = i; break;
        }
}

void dfs(int x)
{
    int sz = son[x].size();
    for (int i = 1; i <= p; ++ i)
        d[x][i] = maxint;
    d[x][1] = 0;

    for (int t = 0; t < sz; ++ t){
        int v = son[x][t];
        dfs(v);
        for (int i = p; i >= 1; -- i){
            d[x][i] += 1;
            for (int j = 1; j < i; ++ j)
                d[x][i] = min(d[x][i], d[x][i-j] + d[v][j]);
        }
    }
}

int main()
{
    while (scanf ("%d%d", &n, &p) != EOF){    
        init();
        
        dfs(f);
        
        d[f][p] -= 1;
        int ans = maxint;
        for (int i = 1; i <= n; ++ i)
            ans = min(ans, d[i][p]);
        printf ("%d\n", ans + 1);
    }
    return 0;
}
