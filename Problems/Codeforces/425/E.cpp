/*
 * Author:  Plumrain
 * Created Time:  2014/9/29 18:35:41
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

const ll mod = int(1e9) + 7;
ll two[500001];
int d[505][505];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n, K;
    scanf ("%d%d", &n, &K);
    if (!K) return puts("1"), 0;

    two[0] = 1;
    rep (i, 1, n*n) two[i] = (two[i-1]<<1) % mod;

    d[0][0] = 1;
    rep (i, 1, n) rep (j, 0, min (i,K)){
        rep (k, 0, i-1){
            ll t = (two[i-k] - 1) * two[(i-k)*k] % mod;
            add (d[i][j+1], t * d[k][j] % mod);
        }
    }

    //rep (i, 0, n){
        //rep (j, 0, n) tst (d[i][j]);
        //cout << endl;
    //}
//
    int res = 0;
    rep (i, 1, n){
        add (res, d[i][K] * two[i*(n-i)] % mod);
    }
    cout << res << endl;
    return 0;
}
