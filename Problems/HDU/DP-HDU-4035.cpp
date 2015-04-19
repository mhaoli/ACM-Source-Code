/*
 * Author:  Plumrain
 * Created Time:  2013-11-07 16:37
 * File Name: DP-HDU-4035.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
const double eps = 1e-10;
const int N = 10000;
typedef vector<int> VI;

int n;
bool vis[N+5];
double e[N+5], k[N+5];
double A[N+5], B[N+5], C[N+5];
VI pat[N+5], son[N+5];
vector<pair<int, int> > cal;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second || (a.second == b.second && a.first > b.first);
}

void init()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++ i){
        pat[i].clear();
        son[i].clear();
    }
    int t1, t2;
    for (int i = 0; i < n-1; ++ i){
        scanf ("%d%d", &t1, &t2);
        -- t1; -- t2;
        pat[t1].PB(t2); pat[t2].PB(t1);
    }
    for (int i = 0; i < n; ++ i){
        scanf ("%d%d", &t1, &t2);
        k[i] = (double)t1 / 100.0;
        e[i] = (double)t2 / 100.0; 
    }
}

void DFS(int pos, int num)
{
    vis[pos] = 1;
    cal.PB (make_pair(pos, num));

    int sz = pat[pos].size();
    for (int i = 0; i < sz; ++ i) if (!vis[pat[pos][i]]){
        int t = pat[pos][i];
        son[pos].PB (t);
        DFS (t, num+1);
    }
}

void DP()
{
    CLR (A); CLR (B); CLR (C); 
    int sz = cal.size(), tmp = cal[0].second;
    for (int i = 0; i < sz; ++ i){
        int pos = cal[i].first;
        if (cal[i].second == tmp){
            A[pos] = k[pos];
            B[pos] = 1 - k[pos] - e[pos];
            C[pos] = 1 - k[pos] - e[pos];
            continue;
        }

        double sa = 0.0, sb = 0.0, sc = 0.0;
        int ssz = son[pos].size();
        for (int j = 0; j < ssz; ++ j){
            sa += A[son[pos][j]]; 
            sb += B[son[pos][j]]; 
            sc += C[son[pos][j]];
        }

        double x = (1 - k[pos] - e[pos]) / (double)pat[pos].size(); 
        double chu = 1 - x * sb;
        A[pos] = (k[pos] + x * sa) / chu;
        B[pos] = x / chu;
        C[pos] = x * ((int)pat[pos].size() + sc) / chu;
    }
}

int main()
{
    int T, test = 0;
    scanf ("%d", &T);
    while (T--){
        init();

        CLR (vis);
        cal.clear();
        DFS (0, 0);
        sort (cal.begin(), cal.end(), cmp);

        DP ();

        printf ("Case %d: ", ++ test);
        if (n == 1 || fabs(A[0] - 1.0) < eps) printf ("impossible\n");
        else printf ("%.6lf\n", C[0] / (1 - A[0]));
    }
    return 0;
}
