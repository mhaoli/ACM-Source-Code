/*
 * Author:  Plumrain
 * Created Time:  2014/6/1 17:03:17
 * File Name: graph-POJ-2230.cpp
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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

bool vis[200005];
int top, stk[200005];
vector<pii > pat[200005];

void add (int t1, int t2, int t3){
    pat[t1].pb (mp (t2, 2*t3));
    pat[t2].pb (mp (t1, 2*t3+1));
}

void dfs (int x){
    repf (i, 0, sz(pat[x])-1) if (!vis[pat[x][i].y]){
        vis[pat[x][i].y] = 1;
        dfs (pat[x][i].x);
        stk[ top++ ] = pat[x][i].x;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    repf (i, 0, n-1) pat[i].clear();
    int t1, t2;
    repf (i, 0, m-1) scanf ("%d%d", &t1, &t2), add (t1-1, t2-1, i);

    top = 0; clr (vis, 0);
    dfs (0);
    printf ("1\n");
    repd (i, top-1, 0) printf ("%d\n", stk[i]+1);
    return 0;
}
