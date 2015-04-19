/*
 * Author:  Plumrain
 * Created Time:  2014/9/30 15:01:38
 * File Name: D.cpp
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

const int N = int(2e6) + 9;
const int base = int(1e6);
int mx, mi;
vi a[N];

inline bool find (const int &x, const int &y){
    if (x < 0 || x > mx) return 0;
    vi::iterator it = lower_bound (all (a[x]), y);
    return (it != a[x].end() && *it == y);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    mi = inf; mx = -inf;
    rep (i, 0, n-1){
        int t1, t2;
        scanf ("%d%d", &t1, &t2);
        t1 += base; t2 += base;

        a[t1].pb (t2);
        chmax (mx, t1);
        chmin (mi, t1);
    }

    rep (i, 0, mx) sort (all (a[i]));

    int siz = (int)sqrt(n + 0.0), ans = 0, j, k, x;
    rep (i, mi, mx)
        if (sz(a[i]) <= siz){
            rep (tj, 0, sz(a[i])-1) rep (tk, 0, tj-1){
                j = a[i][tj]; k = a[i][tk];
                if (find (i+k-j, j) && find (i+k-j, k)) ++ ans;
            }
        } else{
            rep (j, mi, i-1) rep (k, 0, sz(a[j])-1){
                x = a[j][k];
                if (find (i, x) && find (j, x+i-j) && find (i, x+i-j)) ++ ans;
            }
        }
    cout << ans << endl;
    return 0;
}
