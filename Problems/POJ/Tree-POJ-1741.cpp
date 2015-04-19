/*
 * Author:  Plumrain
 * Created Time:  2014/5/13 12:05:13
 * File Name: Tree-POJ-1741.cpp
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
#define end eend
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999LL
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
const int maxn = 10005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int e, cost, nxt;
}pat[2 * maxn];
int up;
bool vis[maxn];
int bgn[maxn], end[maxn], tot;
int head[maxn], siz[maxn], len[maxn];

struct get_root{
    edge *pat;
    int *head;
    bool *vis;
    int num[maxn], d[maxn], n, ret;
    int get (edge *pat, int *head, bool *vis, int u){
        this -> pat = pat; this -> head = head; this -> vis = vis;
        clr (d, 0); clr (num, 0); n = 0;
        dfs (u, -1);

        ret = u;
        dfs_ret (u, -1);
        return ret;
    }
    void dfs (int u, int fa){
        num[u] = 1; ++ n;
        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e;
            if (v == fa || vis[v]) continue;
            dfs (v, u);
            chmax (d[u], num[v]); num[u] += num[v];
        }
    }
    void dfs_ret (int u, int fa){
        chmax (d[u], n - num[u]);
        if (d[ret] > d[u]) ret = u;
        for (int i = head[u]; i != -1; i = pat[i].nxt){
            int v = pat[i].e;
            if (v == fa || vis[v]) continue;
            dfs_ret (v, u);
        }
    }
}root;

void addedge (int u, int v, int cost){
    pat[tot].e = v; pat[tot].cost = cost;
    pat[tot].nxt = head[u]; head[u] = tot ++; siz[u] ++;
}

void dfs (int u, int fa, int &dfs_cnt, int cost){
    bgn[u] = ++dfs_cnt; len[dfs_cnt] = cost;
    for (int i = head[u]; i != -1; i = pat[i].nxt){
        int v = pat[i].e;
        if (vis[v] || v == fa) continue;
        dfs (v, u, dfs_cnt, cost+pat[i].cost);
    }
    end[u] = dfs_cnt;
}

int ask_num (int sta, int tar){
    sort (len+sta, len+tar+1);
    int ret = 0;
    for (int i = sta, j = tar; len[i] < up && i <= tar; ++ i){
        while (j > i && len[i] + len[j] > up) -- j;
        if (j <= i) break;
        ret += j - i;
    }
    return ret;
}

int solve (int u){
    int ret = 0, r = root.get (pat, head, vis, u);
    vis[r] = 1;
    for (int i = head[r]; i != -1; i = pat[i].nxt)
        if (!vis[pat[i].e]) ret += solve (pat[i].e);
    int dfs_cnt = -1;
    for (int i = head[r]; i != -1; i = pat[i].nxt){
        int v = pat[i].e;
        if (vis[v]) continue;
        dfs (v, r, dfs_cnt, pat[i].cost);
        ret -= ask_num (bgn[v], end[v]);
    }
    if (dfs_cnt > 0) ret += ask_num (0, dfs_cnt);
    repf (i, 0, dfs_cnt) 
        if (len[i] <= up) ++ ret;
    vis[r] = 0;
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d%d", &n, &up) != EOF){
        if (!n && !up) break;
        clr (siz, 0); clr (head, -1); tot = 0;
        int u, v, cost;
        repf (i, 0, n-2){
            scanf ("%d%d%d", &u, &v, &cost);
            addedge (u, v, cost); addedge (v, u, cost);
        }

        clr (vis, 0);
        printf ("%d\n", solve (1));
    }
    return 0;
}
