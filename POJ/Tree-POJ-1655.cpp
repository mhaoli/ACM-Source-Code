/*
 * Author:  Plumrain
 * Created Time:  2014/5/13 2:38:39
 * File Name: Tree-POJ-1655.cpp
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
const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int d[maxn], n, num[maxn];
vi son[maxn];

void dfs (int x, int fa){
    num[x] = 1;
    repf (i, 0, sz(son[x])-1) if (fa != son[x][i]){
        int v = son[x][i];
        dfs (v, x);
        chmax (d[x], num[v]);
        num[x] += num[v];
    }
    chmax (d[x], n - num[x]);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &n);
        repf (i, 0, n-1) son[i].clear();

        int t1, t2;
        repf (i, 0, n-2){
            scanf ("%d%d", &t1, &t2);
            -- t1, -- t2;
            son[t1].pb (t2); son[t2].pb (t1);
        }

        clr (d, 0); clr (num, 0);
        dfs (0, -1);
        int ans = 0;
        repf (i, 1, n-1) if (d[i] < d[ans]) ans = i;
        printf ("%d %d\n", ans + 1, d[ans]);
    }
    return 0;
}
