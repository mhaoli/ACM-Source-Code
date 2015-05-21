/*
 * Author:  Plumrain
 * Created Time:  2014/10/6 10:23:19
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

const int N = 9 + (int)1e5;
int a[N], f[N];
map<int, ll> has;

int find (int x){
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    rep (i, 0, n-1) scanf ("%d", a + i);
    rep (i, 0, n-1) f[i] = i;
    ++ has[a[0]];
    rep (i, 1, n-1){
        //out (i);
        //if (a[i-1] % a[i] == 0) f[i] = f[i-1];
        for (int p = i, t = a[i], tt; ;){
            int tp = find(p);
            //tst (p), tst (tp), out (t);
            if (t == 1){
                f[p] = 0;
                has[1] += p + 1; break;
            }
            has[t] += p - tp + 1;
            if (tp <= 0) break;
            tt = t;
            t = __gcd (t, a[tp-1]);
            if (tt == t) f[tp] = f[tp-1];
            p = tp - 1;
        }
        //out (has[1]);
    }

    int m, x; scanf ("%d", &m);
    while (m--){
        scanf ("%d", &x);
        printf ("%I64d\n", has[x]);
    }
    return 0;
}
