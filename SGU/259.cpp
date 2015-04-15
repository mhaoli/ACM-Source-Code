/*
 * Author:  Plumrain
 * Created Time:  2014/7/12 23:02:23
 * File Name: 259.cpp
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

int tim[maxn];
pii an[maxn];

bool cmp (pii a, pii b){
    int t1 = a.x + max (a.y, b.x+b.y);
    int t2 = b.x + max (b.y, a.x+a.y);
    return t1 < t2;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d", &an[i].x);
    repf (i, 0, n-1) scanf ("%d", &an[i].y);
    sort (an, an+n, cmp);

    tim[0] = an[0].x;
    repf (i, 1, n-1) tim[i] = tim[i-1] + an[i].x;
    int ans = 0;
    repf (i, 0, n-1) chmax (ans, tim[i] + an[i].y);
    cout << ans << endl;
    return 0;
}
