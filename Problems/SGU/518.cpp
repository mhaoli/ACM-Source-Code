/*
 * Author:  Plumrain
 * Created Time:  2014/9/1 14:16:16
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[205][205];
int g[205][205];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    rep (i, 0, n-1) rep (j, 0, n-1) scanf ("%d", &g[i][j]);
    int k; scanf ("%d", &k);
    clr (vis, 0);
    vis[0][0] = 1;
    //rep (i, 0, n-1) vis[0][i] = 1;
    rep (cas, 0, k-1){
        int t; scanf ("%d", &t);
        rep (i, 0, n-1) if (vis[cas][i])
            rep (j, 0, n-1) if (g[i][j] == t) vis[cas+1][j] = 1;
    }
    int cnt = 0;
    rep (i, 0, n-1) if (vis[k][i]) ++ cnt;
    printf ("%d\n", cnt);
    rep (i, 0, n-1) if (vis[k][i]){
        printf ("%d", i + 1);
        if (--cnt) printf (" ");
        else puts ("");
    }
    return 0;
}
