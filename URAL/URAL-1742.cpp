/*
 * Author:  Plumrain
 * Created Time:  2014/7/23 13:11:52
 * File Name: A.cpp
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

int nxt[maxn], num[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;

void dfs (int u){
    pre[u] = lowlink[u] = ++ dfs_clock;
    S.push (u);
    int v = nxt[u];
    if (!pre[v]){
        dfs (v);
        chmin (lowlink[u], lowlink[v]);
    }
    else if (sccno[v] == -1) chmin (lowlink[u], pre[v]);
    
    if (lowlink[u] == pre[u]){
        scc_cnt ++;
        for (;;){
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

void find_scc (int n){
    dfs_clock = 0; scc_cnt = -1;
    clr (sccno, -1); clr (pre, 0);
    repf (i, 0, n-1) if (!pre[i]) dfs (i);
    ++ scc_cnt;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n; scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d", &nxt[i]), -- nxt[i];
    find_scc (n);
    int ans_ma = scc_cnt;
    
    clr (num, 0);
    repf (i, 0, n-1){
        int v = sccno[nxt[i]];
        if (v != sccno[i]) ++ num[v];
    }
    int ans_mi = 0;
    repf (i, 0, scc_cnt-1) if (!num[i]) ++ ans_mi;
    printf ("%d %d\n", ans_mi, ans_ma);
    return 0;
}
