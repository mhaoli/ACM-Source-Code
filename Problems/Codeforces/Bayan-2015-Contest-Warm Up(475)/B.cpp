/*
 * Author:  Plumrain
 * Created Time:  2014/10/5 21:06:56
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
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

char s[1111];
bool vis[33][33];
vii pat[33][33];

void add (int x, int y, int t1, int t2, bool u){
    if (u) pat[x][y].pb (mp (t1, t2));
    else pat[t1][t2].pb (mp (x, y));
}

void dfs (int x, int y){
    vis[x][y] = 1;
    for (auto v : pat[x][y]) if (!vis[v.x][v.y]) dfs (v.x, v.y);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (cin >> n >> m){
        scanf ("%s", s);
        rep (i, 0, n-1) rep (j, 0, m-1) pat[i][j].clear ();
        rep (i, 0, n-1){
            rep (j, 0, m-2) add (i, j, i, j+1, s[i]=='>');
        }
        scanf ("%s", s);
        rep (i, 0, m-1){
            rep (j, 0, n-2) add (j, i, j+1, i, s[i]=='v');
        }
        bool ans = 1;
        rep (i, 0, n-1) rep (j, 0, m-1){
            clr (vis, 0);
            dfs (i, j);
            rep (x, 0, n-1) rep (y, 0, m-1) if (!vis[x][y]){
                ans = 0; break;
            }
        }
        if (!ans) puts ("NO");
        else puts ("YES");
    }
    return 0;
}
