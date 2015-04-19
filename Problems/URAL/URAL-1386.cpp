/*
 * Author:  Plumrain
 * Created Time:  2014/7/21 15:20:07
 * File Name: G.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

pii bod[4][105][105];
bool vis[2][105][105];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m; scanf ("%d%d", &n, &m);
    repf (i, 0, 3) repf (j, 0, n-1) repf (k, 0, m-1){
        scanf ("%d%d", &bod[i][j][k].x, &bod[i][j][k].y);
        -- bod[i][j][k].x; -- bod[i][j][k].y;
    }

    clr (vis, 0);
    int now = 0, nxt = 1;
    repf (i, 0, n-1) repf (j, 0, m-1) vis[0][i][j] = 1;

    int Q, q; scanf ("%d", &Q);
    while (Q --){
        scanf ("%d", &q); -- q;
        clr (vis[nxt], 0);
        repf (i, 0, n-1) repf (j, 0, m-1) if (vis[now][i][j]) vis[nxt][bod[q][i][j].x][bod[q][i][j].y] = 1;
        swap (nxt, now);
    }
    int cnt = 0;
    repf (i, 0, n-1) repf (j, 0, m-1) if (vis[now][i][j]) ++ cnt;
    printf ("%d\n", cnt);
    repf (i, 0, n-1) repf (j, 0, m-1) if (vis[now][i][j]) printf ("%d %d\n", i+1, j+1);
    return 0;
}
