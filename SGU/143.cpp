/*
 * Author:  Plumrain
 * Created Time:  2014/6/30 14:02:12
 * File Name: 143.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 16000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int d[maxn+5][2], cost[maxn+5];
vi pat[maxn+5];

void dfs (int x, int pre){
    d[x][0] = 0; d[x][1] = cost[x];
    if (!sz(pat[x])) return;
    repf (i, 0, sz(pat[x])-1) if (pat[x][i] != pre){ 
        int v = pat[x][i];
        dfs (v, x);
        chmax (d[x][0], max(d[v][0], d[v][1]));
        if (d[v][1] > 0) d[x][1] += d[v][1];
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    repf (i, 0, n-1) pat[i].clear();
    repf (i, 0, n-1) scanf ("%d", &cost[i]);
    int t1, t2;
    repf (i, 0, n-2){
        scanf ("%d%d", &t1, &t2); -- t2; -- t1;
        pat[t1].pb (t2); pat[t2].pb (t1);
    }

    clr (d, 0); dfs (0, -1);
    sort (cost, cost+n);
    if (cost[n-1] < 0) printf ("%d", cost[n-1]);
    else printf ("%d\n", max (d[0][0], d[0][1]));
    return 0;
}
