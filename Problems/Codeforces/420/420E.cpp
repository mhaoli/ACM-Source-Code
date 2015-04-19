/*
 * Author:  Plumrain
 * Created Time:  2014/10/1 20:27:35
 * File Name: E.cpp
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

typedef pair<double, int> pdi;
vector<pdi > vec;
int cnt;

void add (double l, double r){
    while (l <= -PI) l += 2*PI;
    while (l > PI) l -= 2*PI;
    while (r <= -PI) r += 2*PI;
    while (r > PI) r -= 2*PI;
    vec.pb (pdi (l, -1));
    vec.pb (pdi (r, 1));
    if (l > r) ++ cnt;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, d; scanf ("%d%d", &n, &d);
    int x, y, r;
    rep (i, 0, n-1){
        scanf ("%d%d%d", &x, &y, &r);
        double dis = sqrt(x*x + y*y + 0.0);
        int tl = max ((int)ceil((dis-r) / d), 1), tr = floor((dis+r) / d);
        double th = atan2 (y, x);
        rep (j, tl, tr){
            double th2 = acos (((double)j*j*d*d + dis*dis - r*r) / j / d / dis / 2);
            add (th - th2, th + th2);
        }
    }
    sort (all (vec));
    int ans = cnt;
    rep (i, 0, sz(vec)-1) chmax (ans, cnt-=(vec[i].y));
    cout << ans << endl;
    return 0;
}
