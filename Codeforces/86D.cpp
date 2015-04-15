/*
 * Author:  Plumrain
 * Created Time:  2014/7/21 12:15:37
 * File Name: CF-86D.cpp
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 200005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

piii q[maxn];
int64 res;
int an[maxn], cnt[1000005], L, R, m;
int64 ans[maxn];

bool cmp (piii a, piii b){
    int t1 = a.x.x / m, t2 = b.x.x / m;
    return t1 < t2 || (t1 == t2 && a.x.y < b.x.y);
}

int64 calc (int x, int y, bool u){
    if (!u){
        repf (i, x, y) res += 1LL * ((cnt[an[i]]<<1)+1) * an[i], ++ cnt[an[i]];
    }
    else{
        repf (i, x, L-1) res += 1LL * ((cnt[an[i]]<<1)+1) * an[i], ++ cnt[an[i]];
        repf (i, L, x-1) res -= 1LL * ((cnt[an[i]]<<1)-1) * an[i], -- cnt[an[i]];
        repf (i, R+1, y) res += 1LL * ((cnt[an[i]]<<1)+1) * an[i], ++ cnt[an[i]];
        repf (i, y+1, R) res -= 1LL * ((cnt[an[i]]<<1)-1) * an[i], -- cnt[an[i]];
    }
    L = x; R = y;
    return res;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, t; scanf ("%d%d", &n, &t);
    m = sqrt (n + 0.5);
    repf (i, 0, n-1) scanf ("%d", &an[i]);
    repf (i, 0, t-1){
        scanf ("%d%d", &q[i].x.x, &q[i].x.y), q[i].y = i;
        -- q[i].x.x; -- q[i].x.y;
    }
    sort (q, q+t, cmp);

    //repf (i, 0, t-1) tst (q[i].x.x), tst (q[i].x.y), out (q[i].y);
//
    res = 0; clr (cnt, 0);
    repf (i, 0, t-1) ans[q[i].y] = calc (q[i].x.x, q[i].x.y, i);
    repf (i, 0, t-1) printf ("%I64d\n", ans[i]);
    return 0;
}
