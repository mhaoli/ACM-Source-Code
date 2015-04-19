/*
 * Author:  Plumrain
 * Created Time:  2014/10/5 21:23:32
 * File Name: C.cpp
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

const int N = 1005;
#define right rtsts
#define left sdata

int n, m, L, R;
char s[1005][1005], str[1005][1005];
int right[1005][1005], down[N][N];
bool vis[N][N];

void dfs1 (int x, int y){
    str[x][y] = '.';
    rep (t, 0, 3){
        int t1 = x + Dx[t], t2 = y + Dy[t];
        if (posin (t1, t2) && str[t1][t2] == 'X') dfs1 (t1, t2);
    }
}

bool dfs (int x, int y){
    if (right[x][y] < y + R || down[x][y] < x + L) return 0;

    bool u1 = (right[x][y] == y + R), u2 = (down[x][y] == x + L);
    if (u1 && u2) return 1;
    else if (!u1 && !u2) return 0;
    else if (!u1){
        rep (i, x, x+L-1) vis[i][y+R] = 1;
        return dfs (x, y+1);
    } else{
        rep (i, y, y+R-1) vis[x+L][i] = 1;
        return dfs (x+1, y);
    }
}

bool check (const int &l, const int &r, int x, int y){
    L = l; R = r;
    clr (vis, 0);
    rep (i, x, x+L-1) rep (j, y, y+R-1){
        vis[i][j] = 1;
        if (s[i][j] != 'X') return 0;
    }

    if (!dfs (x, y)) return 0;

    //rep (i, 0, n-1){
        //rep (j, 0, m-1) tst (vis[i][j]);
        //cout << endl;
    //}

    rep (i, 0, n-1) rep (j, 0, m-1){
        if (s[i][j] == 'X' && !vis[i][j]) return 0;
        if (s[i][j] == '.' && vis[i][j]) return 0;
    }
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    cin >> n >> m;
    rep (i, 0, n-1) scanf ("%s", s[i]);

    rep (i, 0, n-1) rep (j, 0, m-1) str[i][j] = s[i][j];
    rep (i, 0, n-1) rep (j, 0, m-1) if (str[i][j] == 'X'){
        dfs1 (i, j); break;
    }
    rep (i, 0, n-1) rep (j, 0, m-1) if (str[i][j] == 'X') return puts("-1"), 0;

    rep (i, 0, n-1){
        int t = m;
        red (j, m-1, 0){
            if (s[i][j] == '.') t = j;
            right[i][j] = t;
        }
    }
    rep (i, 0, m-1){
        int t = n;
        red (j, n-1, 0){
            if (s[j][i] == '.') t = j;
            down[j][i] = t;
        }
    }

    //rep (i, 0, n-1){
        //rep (j, 0, m-1) tst (down[i][j]);
        //cout << endl;
    //}
//
    bool ans_u = 1;
    int ans = inf;
    rep (i, 0, n-1) if (ans_u) rep (j, 0, m-1) if (s[i][j] == 'X'){
        //tst (i), out (j);
        int tx = i+1;
        while (tx < n && right[tx][j] == right[i][j]) ++ tx;
        //out (tx);
        if (tx == n || right[tx][j] == j){
            if (check (1, right[i][j]-j, i, j))
                chmin (ans, right[i][j] - j);
        } else if (right[tx][j] > right[i][j]){
            if (check (down[tx][j]-tx, right[i][j]-j, i, j)) 
                chmin (ans, (down[tx][j]-tx) * (right[i][j] - j));
        }

        int ty = j + 1;
        while (ty < m && down[i][ty] == down[i][j]) ++ ty;
        //out (ty);
        if (ty == m || down[i][ty] == i){
            if (check (down[i][j]-i, 1, i, j)) 
                chmin (ans, down[i][j] - i);
        } else if (down[i][ty] > down[i][j]){
            if (check (down[i][j]-i, right[i][ty] - ty, i, j))
                chmin (ans, (down[i][j]-i) * (right[i][ty] - ty));
        }
        ans_u = 0; break;
    }
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}
