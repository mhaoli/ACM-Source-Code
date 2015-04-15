/*
 * Author:  Plumrain
 * Created Time:  2014/4/22 12:55:49
 * File Name: graph-POJ-3692.cpp
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
#define INF 999999999999999999
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

vi son[205];
int v[205], match[205];
bool bod[205][205];

bool crosspath (int x){
    repf (i, 0, sz(son[x])-1){
        int p = son[x][i];
        if (!v[p]){
            v[p] = 1;
            if (match[p] == -1 || crosspath (match[p])){
                match[p] = x; return 1;
            }
        }
    }
    return 0;
}

int hungary (int n){
    int ret = 0;
    clr (match, -1);
    repf (i, 0, n-1){
        clr (v, 0);
        if (crosspath(i)) ++ ret;
    }
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m, q, cas = 0;
    while (scanf ("%d%d%d", &n, &m, &q) != EOF && n){
        clr (bod, 0);
        int s, e;
        while (q--) scanf ("%d%d", &s, &e), bod[s-1][e-1] = 1;
        repf (i, 0, n-1) son[i].clear();
        repf (i, 0, n-1) repf (j, 0, m-1) if (!bod[i][j]) son[i].pb (j);
        int ans = n + m - hungary(n);
        printf ("Case %d: %d\n", ++ cas, ans);
    }
    return 0;
}
