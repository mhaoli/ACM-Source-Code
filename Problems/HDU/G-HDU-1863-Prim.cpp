/*
 * Author:  Plumrain
 * Created Time:  2013-11-30 10:51
 * File Name: G-HDU-1863.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const int maxint = 2147483647;
typedef pair<int, int> pii;

int n, m;
bool v[110];
int c[110];
vector<pii> p[110];

struct cmp{
    bool operator() (pii a, pii b){
        return a.second > b.second;
    }
};

void init()
{
    for (int i = 0; i < n; ++ i)
        p[i].clear();

    int a, b, w;
    for (int i = 0; i < m; ++ i){
        scanf ("%d%d%d", &a, &b, &w);
        -- a; -- b;
        p[a].PB (make_pair(b, w));
        p[b].PB (make_pair(a, w));
    }
}

int prim(int n, int m)
{
    int cost = 0;
    CLR (v);
    priority_queue<pii, vector<pii>, cmp> q;
    while (!q.empty()) q.pop();

    for (int i = 1; i < n; ++ i)
        c[i] = maxint - 1000;
    c[0] = 0;
    v[0] = 1;
    for (int i = 0; i < (int)p[0].size(); ++ i){
        pii tmp = p[0][i];
        c[tmp.first] = tmp.second;
        q.push (make_pair(tmp.first, tmp.second));
    }

    for (int i = 0; i < n-1; ++ i){
        if (q.empty()) break;
        pii tmp = q.top(); q.pop();
        while (v[tmp.first] && !q.empty()){
            tmp = q.top(); q.pop();
        }
        if (v[tmp.first]) break;

        int t1 = tmp.first, t2 = tmp.second;
        cost += t2;
        v[t1] = 1;
        c[t1] = 0;
        for (int j = 0; j < (int)p[t1].size(); ++ j) if (!v[p[t1][j].first]){
            pii t = p[t1][j];
            if (c[t.first] > t.second){
                q.push (make_pair(t.first, t.second));
                c[t.first] = t.second;
            }
        }
    }

    for (int i = 0; i < n; ++ i)
        if (!v[i]) return -1;
    return cost;
}

int main()
{
    while (scanf ("%d%d", &m, &n) != EOF && m){
        init();
        int ans = prim(n, m);
        if (ans == -1) printf ("?\n");
        else printf ("%d\n", ans);
    }
    return 0;
}
