/*
 * Author:  Plumrain
 * Created Time:  2013-10-22 10:34
 * File Name: math-POJ-2034.cpp
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int N = 20000;
typedef vector<int> VI;
bool vis[N+5], v[N+5], ans;
int n, m, d;
VI cur;

void sieve(int n)
{
    CLR (vis);
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= n; ++ i) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}

bool ok(int x, int pos)
{
    if (!pos) return 1;

    int sum = x + cur[pos-1];
    if (!vis[sum]) return 0;

    for (int i = 3; i <= d; ++ i){
        if (pos - i + 1 < 0) break; 
        sum += cur[pos-i+1];
        if (!vis[sum]) return 0;
    }
    return 1;
}

void DFS (int pos)
{
    if (pos == m-n+1){ 
        ans = true;
        return;
    }
    
    for (int i = n; i <= m; ++ i) if ((!ans) && (!v[i])){
        if (!ok(i, pos)) continue;
        cur.PB (i); v[i] = 1;
        DFS (pos+1);
        if (!ans) cur.pop_back(); 
        v[i] = 0;
    }
}

int main()
{
    sieve(N); 
    while (scanf ("%d%d%d", &n, &m, &d) != EOF && n){
        CLR (v); cur.clear(); ans = false;
        DFS(0);
        if (!ans) printf ("No anti-prime sequence exists.\n");
        else
            for (int i = 0; i < cur.size(); ++ i)
                printf ("%d%c", cur[i], i == cur.size()-1 ? '\n' : ',');
    }
    return 0;
}


