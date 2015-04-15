/*
 * Author:  Plumrain
 * Created Time:  2014/9/13 0:16:13
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = 2099;
const int64 mod = 1000000007;
void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

int d[maxn][maxn], a[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, h;
    while (scanf ("%d%d", &n, &h) != EOF){
        rep (i, 1, n) scanf ("%d", a + i);
        clr (d, 0); d[0][0] = 1;
        rep (i, 1, n) rep (j, 0, n) if (d[i-1][j]){
            int t = a[i] + j;
            if (t == h){
                add (d[i][j], d[i-1][j]);
                if (i > 1 && j > 0) add (d[i][j], (int64)d[i-1][j] * j % mod);
            } else if (t + 1 == h){
                add (d[i][j+1], d[i-1][j]);
            } else if (t - 1 == h){
                if (i > 1 && j > 0) add (d[i][j-1], (int64)d[i-1][j] * j % mod);
            }
        }

        int ans = d[n][0]; add (ans, d[n][1]);
        printf ("%d\n", ans);
    }
    return 0;
}
