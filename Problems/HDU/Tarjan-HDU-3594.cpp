/*
 * Author:  Plumrain
 * Created Time:  2014-04-09 01:45
 * File Name: Tarjan-HDU-3594.cpp
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
const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

bool ans;
vi g[maxn];
stack<int> stk;
int dfs_clock, scc_cnt;
int sccno[maxn], low[maxn], pre[maxn];

void dfs (int u){
    low[u] = pre[u] = ++ dfs_clock;
    stk.push (u);
    int t1 = 0;
    repf (i, 0, sz(g[u])-1){
        int v = g[u][i];
        if (!pre[v]){ 
            dfs (v);
            if (low[v] > pre[u]){
                ans = 0; return;
            }
            else if (low[v] < pre[u]) chmin (low[u], low[v]), ++ t1;
        }
        else {
            ++ t1;
            if (!sccno[v]) chmin (low[u], pre[v]);
        }
    }

    if (t1 >= 2) ans = 0;
    if (!ans) return;
    if (low[u] != pre[u]) return;
    ++ scc_cnt;
    return;
    while (sz(stk)){
        int x = stk.top(); stk.pop();
        sccno[x] = scc_cnt;
        if (x == u) break;
    }
}

void find_scc (int n){
    dfs_clock = scc_cnt = 0;
    clr (pre, 0); clr (sccno, 0);
    repf (i, 0, n-1) if (ans && !pre[i]) dfs (i);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);
        repf (i, 0, n-1) g[i].clear();
        int s, e;
        while (scanf ("%d%d", &s, &e) != EOF){
            if (!e && !s) break; g[s].pb (e);
        }

        ans = 1;
        find_scc (n);

        if (scc_cnt > 1) ans = 0;
        if (ans) puts ("YES");
        else puts ("NO");
    }
    return 0;
}
