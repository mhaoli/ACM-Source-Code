/*
 * Author:  Plumrain
 * Created Time:  2014/8/28 23:13:31
 * File Name: HDU3709.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
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
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

int mid;
int dig_x[22], dig_y[22];
int64 f[22][5555];

int64 dfs (int p, int s, int e1, int e2){
    if (s < 0) return 0;
    if (p == -1) return s == 0;
    bool saf = !(e1 || e2);
    if (saf && ~f[p][s]) return f[p][s];
    int64 res = 0;
    for (int d = 0; d < 10; ++ d){
        if (e1 && d < dig_x[p]) continue;
        if (e2 && d > dig_y[p]) continue;
        res += dfs (p-1, s + d * (p - mid), e1&&d==dig_x[p], e2&&d==dig_y[p]);
    }
    return saf ? f[p][s] = res : res;
}

int calc_len (int64 x, int *d){
    int ret = 0;
    while (x) d[ret++] = x % 10, x /= 10;
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int64 x, y, ans = 0;
        scanf ("%I64d%I64d", &x, &y);
        if (!x) ++ ans, ++ x;

        int lx = calc_len (x, dig_x), ly = calc_len (y, dig_y);
        while (lx < ly) dig_x[lx++] = 0;
        for (mid = 0; mid < ly; ++ mid)
            clr (f, -1), ans += dfs (ly-1, 0, 1, 1);
        printf ("%I64d\n", ans);
    }
    return 0;
}
