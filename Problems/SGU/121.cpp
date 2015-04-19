/*
 * Author:  Plumrain
 * Created Time:  2014/7/17 10:34:18
 * File Name: 121.cpp
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
const int maxn = 105;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int idx[maxn][maxn], num[maxn], col[maxn][5];
vector<pii > pat[maxn];

void dfs (int u, int c){
    repf (i, 0, sz(pat[u])-1) if (!pat[u][i].y){
        int v = pat[u][i].x;
        pat[v][idx[v][u]].y = pat[u][i].y = c; 
        col[v][c] = col[u][c] = 1;
        -- num[u]; -- num[v];
        dfs (v, 3 - c);
        break;
    }
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n;
    cin >> n;
    repf (i, 0, n-1) pat[i].clear();
    repf (i, 0, n-1){
        int t;
        while (cin >> t && t) pat[i].pb (mp (--t, 0));
    }

    repf (i, 0, n-1){
        num[i] = sz(pat[i]);
        repf (j, 0, sz(pat[i])-1) idx[i][pat[i][j].x] = j;
    }

    clr (col, 0);
    while (1){
        int pos = -1;
        repf (i, 0, n-1) if (num[i] & 1){
            pos = i; break;
        }
        if (pos == -1) break;
        dfs (pos, 1);
    }

    repf (i, 0, n-1) if (num[i] && (col[i][2] || col[i][1])){
        if (col[i][1]) dfs (i, 2);
        else dfs (i, 1);
    }

    while (1){
        int ma = 0;
        repf (i, 0, n-1) chmax (ma, num[i]);
        if (ma == 0) break;
        repf (i, 0, n-1) if (num[i] == ma) dfs (i, 1);
    }

    repf (i, 0, n-1) if (sz(pat[i]) > 1 && (!col[i][1] || !col[i][2])){
        puts ("No solution"); return 0;
    }

    repf (i, 0, n-1){
        repf (j, 0, sz(pat[i])-1) printf ("%d ", pat[i][j].y);
        puts ("0");
    }
    return 0;
}
