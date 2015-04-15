/*
 * Author:  Plumrain
 * Created Time:  2014/8/3 13:29:06
 * File Name: J.cpp
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
//const int inf = 2139062143;
const int maxn = (int)1e6 + 5;
const int mod = 1000000007;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int d[maxn][5], f[maxn];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

void init(int n){
    d[1][1] = 1; d[1][0] = 0; f[1] = 0;
    repf (i, 2, n){
        d[i][1] = d[i-1][0];
        d[i][0] = 1LL * (i-1) * d[i-1][1] % mod;
        add (d[i][0], (int)(1LL * (i-2) * d[i-1][0] % mod));
        add (d[i][0], f[i-1]);

        f[i] = d[i-1][0]; add (f[i], d[i-1][1]);
        f[i] = (int)(1LL * f[i] * (i-1) % mod);
    }
//
    //repf (i, 3, 5) tst (f[i]), tst (d[i][0]), out (d[i][1]);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init (maxn - 5);
    repcase{
        int n; scanf ("%d", &n);
        int ans = d[n][0]; add (ans, d[n][1]);
        printf ("Case %d: %d\n", ++ cas, ans);
    }
    return 0;
}
