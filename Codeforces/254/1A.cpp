/*
 * Author:  Plumrain
 * Created Time:  2014/9/1 22:57:13
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

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
const int inf = ~0U >> 1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/
const int maxn = 505;
int v[maxn], g[maxn][maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    scanf ("%d%d", &n, &m);
    rep (i, 0, n-1) scanf ("%d", v + i);
    clr (g, -1);
    rep (i, 0, m-1){
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w); -- u; -- v;
        g[u][v] = g[v][u] = w;
    }

    double ans = 0;
    rep (i, 0, n-1) rep (j, 0, n-1) if (i != j && ~g[i][j]){
        chmax (ans, (v[i] + v[j] + 0.0) / g[i][j]);
    }
    printf ("%.10f\n", ans);
    return 0;
}
