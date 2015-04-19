/*
 * Author:  Plumrain
 * Created Time:  2014-04-10 16:12
 * File Name: Tarjan-POJ-2186.cpp
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
const int maxn = 100050;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

vi g[maxn], scc_fa[maxn];
stack<int> stk;
int dfs_clock, scc_cnt;
int sccno[maxn], low[maxn], pre[maxn], num[maxn], ans[maxn], in[maxn], v[maxn];
bool ismax[maxn];

void dfs (int u){
    low[u] = pre[u] = ++ dfs_clock;
    stk.push (u);
    repf (i, 0, sz(g[u])-1){
        int v = g[u][i];
        if (!pre[v]) dfs (v), chmin (low[u], low[v]);
        else if (!sccno[v]) chmin (low[u], pre[v]);
    }

    if (low[u] != pre[u]) return;
    ++ scc_cnt;
    while (sz(stk)){
        int x = stk.top(); stk.pop();
        sccno[x] = scc_cnt;
        if (x == u) break;
    }
}

void find_scc (int n){
    dfs_clock = scc_cnt = 0;
    clr (low, 0); clr (pre, 0); clr (sccno, 0);
    repf (i, 0, n-1) if (!pre[i]) dfs (i);
}

void dfs2 (int u){
    v[u] = 1;
    repf (i, 0, sz(scc_fa[u])-1) if (!v[scc_fa[u][i]]) dfs2 (scc_fa[u][i]);
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        repf (i, 0, n-1) g[i].clear();

        int s, e;
        while (m --) scanf ("%d%d", &s, &e), g[s-1].pb (e-1);

        repf (i, 1, n-1){
            sort (all(g[i]));
            g[i].erase (unique (all(g[i])), g[i].end());
        }

        find_scc (n);

        clr (num, 0);
        repf (i, 0, n-1) ++ num[sccno[i]];
        repf (i, 1, scc_cnt) scc_fa[i].clear();
        repf (i, 0, n-1) repf (j, 0, sz(g[i])-1) 
            if (sccno[i] != sccno[g[i][j]]) scc_fa[sccno[g[i][j]]].pb (sccno[i]), ++ in[sccno[i]];

        repf (i, 1, scc_cnt){
            sort (all(scc_fa[i]));
            scc_fa[i].erase (unique (all(scc_fa[i])), scc_fa[i].end());
        }

        clr (ans, 0);
        repf (i, 1, scc_cnt) if (in[i] == 0) {
            clr (v, 0); v[i] = 1;
            dfs2 (i);
            repf (j, 1, scc_cnt) if (v[j]) ans[i] += num[j];
        }


        int ma = 0, ans_num = 0;
        repf (i, 1, scc_cnt) chmax (ma, ans[i]);
        repf (i, 0, n-1) if (ans[sccno[i]] == ma) ++ ans_num;
        if (ma < n) ans_num = 0;
        printf ("%d\n", ans_num);
    }
    return 0;
}
