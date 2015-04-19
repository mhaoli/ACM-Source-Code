/*
 * Author:  Plumrain
 * Created Time:  2014/7/25 13:56:29
 * File Name: 515.cpp
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int spe[maxn], d[maxn], cnt, dp[maxn], nxt[maxn];
vector<piii > pat[maxn];

struct cmp{
    bool operator() (pii a, pii b){
        return a.x > b.x;
    }
};

void dijskra (int x){
    clr (d, 127); d[x] = 0;
    priority_queue<pii, vector<pii >, cmp> q; q.push (mp (0, x));
    while (sz (q)){
        pii u = q.top(); q.pop();
        if (u.x > d[u.y]) continue;
        repf (i, 0, sz(pat[u.y])-1){
            piii v = pat[u.y][i];
            if (d[v.x.x] > d[u.y] + v.x.y){
                d[v.x.x] = d[u.y] + v.x.y;
                q.push (mp (d[v.x.x], v.x.x));
            }
        }
    }
}

int dfs (int x){
    int &ret = dp[x];
    if (ret != -1) return ret;
    ret = 0;

    repf (i, 0, sz(pat[x])-1){
        int v = pat[x][i].x.x, dis = pat[x][i].x.y;
        if (d[x] + dis != d[v]) continue;
        int tmp = dfs (v);
        if (ret < tmp) ret = tmp, nxt[x] = i;
    }

    ret += (spe[x] ? 1 : 0);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    scanf ("%d%d", &n, &m);
    repf (i, 0, n-1) pat[i].clear();
    repf (i, 0, m-1){
        int t1, t2, c;
        scanf ("%d%d%d", &t1, &t2, &c); -- t1; -- t2;
        pat[t1].pb (mp (mp (t2, c), i)); pat[t2].pb (mp (mp (t1, c), i));
    }
    int q, t; scanf ("%d", &q);
    clr (spe, 0);
    repf (i, 0, q-1) scanf ("%d", &t), spe[--t] = 1;

    dijskra (t);
    repf (i, 0, n-1) if (spe[i] && d[i] > d[t]) t = i;
    dijskra (t);

    clr (dp, -1); clr (nxt, -1); dfs (t);
    int pos = t;
    vi ans;
    while (nxt[pos] != -1){
        ans.pb (pat[pos][nxt[pos]].y);
        pos = pat[pos][nxt[pos]].x.x;
    }

    cout << sz(ans) << endl;
    repf (i, 0, sz(ans)-1){
        if (i) printf (" ");
        printf ("%d", ans[i] + 1);
    }
    puts ("");
    return 0;
}
