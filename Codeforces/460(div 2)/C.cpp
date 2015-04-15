/*
 * Author:  Plumrain
 * Created Time:  2014/8/21 0:04:03
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
typedef vector<int64> vi;
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
const int maxn = (int)1e5 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 num[maxn];
vector<pair<int, int64> > vec;
int w, n;
int a[maxn];

bool ok (int64 m, int64 mi){
    vec.clear();
    pair<int, int64> t;
    rep (i, 0, n-1) if (a[i] < mi){
        t.x = i; t.y = mi - a[i]; vec.pb (t);
    }

    clr (num, 0);
    int i = 0, j = 0, nn = sz (vec);
    int64 tnum = 0;
    while (i < nn){
        while (j < nn && vec[j].x - vec[i].x + 1 <= w) ++ j;
        -- j;

        vec[i].y -= tnum;
        int64 tmp = vec[i].y;
        if (tmp > 0){
            tnum += tmp;
            m -= tmp;
            num[j] += tmp;
        }
        tnum -= num[i];
        ++ i;
        if (j < i) j = i;
    }
    return (m >= 0);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int m;
    while (scanf ("%d%d%d", &n, &m, &w) != EOF){
        rep (i, 0, n-1) scanf ("%d", a+i);
        int64 l = 1, r = (int64)2e9, ans = 1;
        while (l <= r){
            int64 mid = (l + r) >> 1;
            if (ok ((int64)m, mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}
