/*
 * Author:  Plumrain
 * Created Time:  2014-04-06 20:42
 * File Name: Tarjan-HDU-1827.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 1005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

vi g[maxn];
stack<int> stk;
int cnt, dfs_clock;
int pre[maxn], low[maxn], cost[maxn], sccno[maxn], num[maxn];
int ru[maxn];

void dfs (int u){
    pre[u] = low[u] = ++ dfs_clock;
    stk.push (u);

    repf (i, 0, sz(g[u])-1){
        int v = g[u][i];
        if (!pre[v]) dfs (v), chmin (low[u], low[v]);
        else if (!sccno[v]) chmin (low[u], pre[v]);
    }

    if (low[u] == pre[u]){
        ++ cnt;
        while (1){
            int x = stk.top(); stk.pop();
            sccno[x] = cnt;
            if (x == u) break;
        }
    }
}

void find_scc (int n){
    dfs_clock = cnt = 0;
    clr (sccno, 0); clr (pre, 0); clr (low, 0);
    repf (i, 0, n-1) if (!pre[i]) dfs (i);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF && n != -5){
        repf (i, 0, n-1) scanf ("%d", cost+i);

        int s, e;
        repf (i, 0, n-1) g[i].clear();
        while (m--) scanf ("%d%d", &s, &e), g[s-1].pb (e-1);

        find_scc(n);
        clr (num, 127);
        repf (i, 0, n-1) chmin (num[sccno[i]], cost[i]);
        
        clr (ru, 0);
        repf (i, 0, n-1) repf (j, 0, sz(g[i])-1) if (sccno[i] != sccno[g[i][j]]) ru[sccno[g[i][j]]] ++;

        int ans_cnt = 0, ans = 0;
        repf (i, 1, cnt) if (!ru[i]) ++ ans_cnt, ans += num[i];
        printf ("%d %d\n", ans_cnt, ans);
    }
    return 0;
}
