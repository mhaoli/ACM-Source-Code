/*
 * Author:  Plumrain
 * Created Time:  2013-12-02 01:43
 * File Name: G-HDU-1233.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define CLR1(x) memset(x, -1, sizeof(x))
#define PB push_back
typedef pair<int, int> pii;

int n, m, d[110];
bool v[110];
vector<pii> pat[110];

struct cmp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

void init()
{
    for (int i = 0; i < n; ++ i)
        pat[i].clear();

    m = n * (n-1) / 2;
    int a, b, w;
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &a, &b, &w);
        -- a; -- b;
        pat[a].PB (make_pair(b, w));
        pat[b].PB (make_pair(a, w));
    }
}

int Prim(int n, int m)
{
    priority_queue<pii, vector<pii>, cmp> q;
    while (!q.empty()) q.pop();

    int cost = 0;
    CLR1 (d);
    CLR (v); v[0] = 1; d[0] = 0;
    int t_sz = pat[0].size();
    for (int i = 0; i < t_sz; ++ i){
        pii tmp = pat[0][i];
        d[tmp.first] = tmp.second;
        q.push (tmp);
    }

    for (int i = 0; i < n-1; ++ i){
        if (q.empty()) break;
        pii tmp = q.top(); q.pop();
        while (v[tmp.first] && !q.empty()){
            tmp = q.top(); q.pop();
        }
        if (v[tmp.first]) break;

        int t1 = tmp.first, t2 = tmp.second;
        cost += t2; v[t1] = 1; d[t1] = 0;
        int sz = pat[t1].size();
        for (int j = 0; j < sz; ++ j) if (!v[pat[t1][j].first]){
            pii tt = pat[t1][j];
            if (d[tt.first] > tt.second){
                q.push (make_pair(tt.first, tt.second));
                d[tt.first] = tt.second;
            }
        }
    }

    for (int i = 0; i < n; ++ i)
        if (!v[i]) return -1;
    return cost;
}

int main()
{
    while (scanf ("%d", &n) != EOF && n){
        init();
        int ans = Prim(n, m);
        printf ("%d\n", ans);
    }
    return 0;
}
