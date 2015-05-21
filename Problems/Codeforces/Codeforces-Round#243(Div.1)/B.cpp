/*
 * Author:  Plumrain
 * Created Time:  2014/9/30 20:12:28
 * File Name: B.cpp
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

const int N = 111;
int a[N][N], b[N];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, K;
    scanf ("%d%d%d", &n, &m, &K);
    rep (i, 0, n-1) rep (j, 0, m-1) scanf ("%d", &a[i][j]);

    int ans = inf;
    if (n > K){
        rep (i, 0, n-1){
            int res = 0;
            rep (j, 0, n-1){
                int tmp = 0;
                rep (k, 0, m-1) if (a[i][k] != a[j][k]) ++ tmp;
                res += min (tmp, m-tmp);
            }
            chmin (ans, res);
        }
    } else{
        rep (i, 0, n-1) b[i] = a[i][0];
        rep (i, 0, (1<<n)-1){
            int res = 0;
            for (int sta = i, j = 0; j < n; ++ j, sta>>=1){
                a[j][0] = sta & 1;
                if (b[j] != a[j][0]) ++ res;
            }
            rep (j, 1, m-1){
                int cnt = 0;
                rep (k, 0, n-1) if (a[k][j] != a[k][0]) ++ cnt;
                res += min (cnt, n-cnt);
            }
            chmin (ans, res);
        }
    }
    cout << (ans <= K ? ans : -1) << endl;
    return 0;
}
