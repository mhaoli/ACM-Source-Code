/*
 * Author:  Plumrain
 * Created Time:  2013-11-20 11:21
 * File Name: DP-POJ-2486.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define out(x) cout<<#x<<":"<<(x)<<endl

int n, k;
bool vis[105];
vector<int> pat[105], v[105];
int c[105], d[105][205][2];

void init()
{
    CLR (vis);
    for (int i = 0; i < n; ++ i){
        pat[i].clear();
        v[i].clear();
    }
    
    for (int i = 0; i < n; ++ i)
        scanf ("%d", &c[i]);
    int t1, t2;
    for (int i = 0; i < n-1; ++ i){
        scanf ("%d%d", &t1, &t2);
        -- t1; -- t2; 
        pat[t1].PB (t2);
        pat[t2].PB (t1);
    }
}

void dfs1(int x)
{
    vis[x] = 1;
    int sz = pat[x].size();
    if (!sz) return;

    for (int i = 0; i < sz; ++ i){
        int y = pat[x][i];
        if (vis[y]) continue;
        v[x].PB (y);
        dfs1(y);
    }
}

void dfs2(int x, int p)
{
    for (int i = 0; i <= k; ++ i) 
        d[x][i][0] = d[x][i][1] = c[x];
    if (!k) return;

    int sz = v[x].size();
    for (int i = 0; i < sz; ++ i){
        int y = v[x][i];
        dfs2(y, k-1);

        for (int j = p; j >= 0; -- j){
            for (int k = 0; k <= j - 2; ++ k){
                d[x][j][0] = max(d[x][j][0], d[x][j-k-2][0] + d[y][k][0]);
                d[x][j][1] = max(d[x][j][1], d[x][j-k-2][1] + d[y][k][0]);
                d[x][j][1] = max(d[x][j][1], d[x][j-k-1][0] + d[y][k][1]);
            }
            d[x][j][1] = max(d[x][j][1], d[x][0][0] + d[y][j-1][1]);
        }
    }
}

int main()
{
    while (scanf ("%d%d", &n, &k) != EOF){
        init();

        dfs1(0);

        CLR (d);
        dfs2(0, k);
        
        printf ("%d\n", d[0][k][1]);
    }
    return 0; 
}
