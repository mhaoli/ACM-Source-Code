/*
 * Author:  Plumrain
 * Created Time:  2014-04-09 16:01
 * File Name: graph-POJ-2553.cpp
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
const int maxn = 5005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

vector<int> g[maxn];
stack<int> stk;
int scc_cnt, dfs_clock;
int pre[maxn], low[maxn], sccno[maxn], num[maxn], du[maxn];

void dfs (int u){
    pre[u] = low[u] = ++ dfs_clock;
    stk.push (u);
    repf (i, 0, sz(g[u])-1){
        int v = g[u][i];
        if (!pre[v]) dfs (v), chmin (low[u], low[v]);
        else if (!sccno[v]) chmin (low[u], pre[v]);
    }

    if (pre[u] != low[u]) return;
    ++ scc_cnt;
    while (!stk.empty()){
        int x = stk.top(); stk.pop();
        sccno[x] = scc_cnt;
        if (x == u) break;
    }
}

void find_scc(int n){
    dfs_clock = scc_cnt = 0;
    clr (sccno, 0); clr (pre, 0);
    repf (i, 0, n-1) if (!pre[i]) dfs (i);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d", &n) != EOF && n){
        repf (i, 0, n-1) g[i].clear();

        scanf ("%d", &m);
        int s, e;
        while (m--) scanf ("%d%d", &s, &e), g[s-1].pb (e-1);

        find_scc(n);

        clr (du, 0);
        repf (i, 0, n-1) repf (j, 0, sz(g[i])-1) if (sccno[i] != sccno[g[i][j]]) ++ du[sccno[i]];
        bool u = 0;
        repf (i, 0, n-1) if (!du[sccno[i]]){
            if (u) printf (" "); u = 1;
            printf ("%d", i + 1);
        }
        printf ("\n");
    }
    return 0;
}
