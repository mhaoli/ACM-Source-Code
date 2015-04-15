/*
 * Author:  Plumrain
 * Created Time:  2014/7/1 17:43:43
 * File Name: 149.cpp
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
typedef pair<int, int64> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 10005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int idx[maxn];
int64 up[maxn], dis[maxn];
pii down_fir[maxn], down_sec[maxn], fa[maxn];
vector<pii > pat[maxn];

void dfs (int x, int pre){
    down_sec[x] = down_fir[x] = mp (0, 0LL);
    repf (i, 0, sz(pat[x])-1){
        pii v = pat[x][i];
        if (v.x == pre) continue;
        dis[v.x] = dis[x] + v.y;

        dfs (v.x, x);
        
        int64 t1 = down_fir[v.x].y + v.y;
        if (t1 > down_fir[x].y) down_sec[x] = down_fir[x], down_fir[x].y = t1, down_fir[x].x = v.x;
        else if (t1 > down_sec[x].y) down_sec[x].y = t1, down_sec[x].x = v.x;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n; scanf ("%d", &n);
    repf (i, 0, n-1) pat[i].clear();
    int t2;
    repf (i, 1, n-1){
        scanf ("%d%d", &fa[i].x, &t2); fa[i].y = (int64)t2;
        pat[--fa[i].x].pb (mp (i, fa[i].y));
    }

    dis[0] = 0; dfs (0, -1);
    up[0] = 0; cout << down_fir[0].y << endl;
    repf (i, 1, n-1){
        if (down_fir[fa[i].x].x != i) up[i] = down_fir[fa[i].x].y + fa[i].y;
        else up[i] = down_sec[fa[i].x].y + fa[i].y;
        chmax (up[i], fa[i].y + up[fa[i].x]);
        
        int64 ans = up[i];
        chmax (ans, down_fir[i].y);
        cout << ans << endl;
    }
    return 0;
}
