/*
 * Author:  Plumrain
 * Created Time:  2014/9/28 17:13:37
 * File Name: B.cpp
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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int N = 1005;

int a[N][N];
ll d[2][N][N], g[2][N][N];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m; scanf ("%d%d", &n, &m);
    rep (i, 0, n-1) rep (j, 0, m-1) scanf ("%d", &a[i][j]);

    clr (d, 0); clr (g, 0);
    rep (i, 0, n-1) rep (j, 0, m-1){
        d[0][i][j] += a[i][j];
        chmax (d[0][i+1][j], d[0][i][j]);
        chmax (d[0][i][j+1], d[0][i][j]);
    }
    red (i, n-1, 0) red (j, m-1, 0){
        d[1][i][j] += a[i][j];
        if (i) chmax (d[1][i-1][j], d[1][i][j]);
        if (j) chmax (d[1][i][j-1], d[1][i][j]);
    }
    red (i, n-1, 0) rep (j, 0, m-1){
        g[0][i][j] += a[i][j];
        if (i) chmax (g[0][i-1][j], g[0][i][j]);
        chmax (g[0][i][j+1], g[0][i][j]);
    }
    rep (i, 0, n-1) red (j, m-1, 0){
        g[1][i][j] += a[i][j];
        chmax (g[1][i+1][j], g[1][i][j]);
        if (j) chmax (g[1][i][j-1], g[1][i][j]);
    }

    ll ans = 0;
    rep (i, 1, n-2) rep (j, 1, m-2){
        chmax (ans, d[0][i-1][j] + d[1][i+1][j] + g[0][i][j-1] + g[1][i][j+1]);
        chmax (ans, d[0][i][j-1] + d[1][i][j+1] + g[0][i+1][j] + g[1][i-1][j]);
    }
    printf ("%I64d\n", ans);
    return 0;
}
