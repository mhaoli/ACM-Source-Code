/*
 * Author:  Plumrain
 * Created Time:  2013-11-20 10:39
 * File Name: (good)DP-POJ-2057.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back

int n;
bool w[1005];
vector<int> v[1005];
int le[1005], fail[1005], su[1005];

bool cmp(int x, int y)
{
    return (fail[x]+2)*le[y] < (fail[y]+2)*le[x];
}

void init()
{
    CLR (le); CLR (fail); CLR (su); CLR (w);
    for (int i = 0; i < n; ++ i)
        v[i].clear();

    int t1;
    char s[10];
    for (int i = 0; i < n; ++ i){
        scanf ("%d%s", &t1, s);
        if (s[0] == 'Y') w[i] = 1;
        if (t1 != -1) v[t1-1].PB(i);
    }
}

void dfs(int x)
{
    if (!v[x].size()){
        le[x] = 1;
        su[x] = 0;
        fail[x] = 0;
        return;
    }

    for (int i = 0; i < (int)v[x].size(); ++ i){
        dfs(v[x][i]);
        le[x] += le[v[x][i]];
    }

    sort (v[x].begin(), v[x].end(), cmp);
    for (int i = 0; i < (int)v[x].size(); ++ i){
        int y = v[x][i];
        su[x] += (fail[x]+1)*le[y] + su[y];
        fail[x] += fail[y] + 2; 
    }
    if (w[x]) fail[x] = 0;
}

int main()
{
    while (scanf("%d", &n) != EOF && n){    
        init(); 
        dfs(0);
        printf ("%.4f\n", (double)su[0] / le[0]);
    }
    return 0;
}
