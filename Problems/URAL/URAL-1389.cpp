/*
 * Author:  Plumrain
 * Created Time:  2014/7/21 14:12:48
 * File Name: J.cpp
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi pat[maxn];
pii ans[maxn];
int d[maxn][2], sum[maxn], ans_cnt;

void dfs (int u, int pre){
    //tst (u), out (pre);
    sum[u] = d[u][1] = d[u][0] = 0;
    int t0 = 0, t1 = 0;
    repf (i, 0, sz(pat[u])-1){
        int v = pat[u][i];
        if (v == pre) continue;
        dfs (v, u);
        chmax (d[u][0], t0 + max (d[v][0], d[v][1]));
        chmax (d[u][1], t0 + d[v][0] + 1);
        chmax (d[u][1], t1 + max (d[v][0], d[v][1]));
        sum[u] += d[v][1];
        t0 = d[u][0]; t1 = d[u][1];
    }
}

void dfs_out (int u, int pre, int t, bool flag){
    if (!t || (t && flag)){
        repf (i, 0, sz(pat[u])-1){
            int v = pat[u][i];
            if (v == pre) continue;
            dfs_out (v, u, d[v][0]>=d[v][1]?0:1, 0);
        }
    }
    else{
        int idx = 0;
        repf (i, 0, sz(pat[u])-1){
            int v = pat[u][i];
            if (v == pre) continue;
            if (sum[u] - d[v][1] + d[v][0] + 1 == d[u][1]) idx = v;
        }
        ans[ans_cnt].x = u; ans[ans_cnt++].y = idx;
        repf (i, 0, sz(pat[u])-1){
            int v = pat[u][i];
            if (v == pre) continue;
            if (v == idx) dfs_out (v, u, 1, 1);
            else dfs_out (v, u, d[v][0]>=d[v][1]?0:1, 0);
        }
    }
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m; scanf ("%d%d", &n, &m);
    repf (i, 0, n-1) pat[i].clear();
    int t1, t2;
    repf (i, 0, m-1){
        scanf ("%d%d", &t1, &t2); -- t1; -- t2;
        pat[t1].pb (t2); pat[t2].pb (t1);
    }

    dfs (0, -1);

    printf ("%d\n", max (d[0][1], d[0][0]));
    ans_cnt = 0;
    dfs_out (0, -1, d[0][0]>d[0][1] ? 0 : 1, 0);
    repf (i, 0, ans_cnt-1) printf ("%d %d\n", ans[i].x+1, ans[i].y+1);
    return 0;
}
