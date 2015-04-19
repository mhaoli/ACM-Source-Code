/*
 * Author:  Plumrain
 * Created Time:  2014/9/20 11:07:18
 * File Name: ZOJ3747.cpp
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

const int mod = 1000000007;

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

int d[1000001][3][2], s[10000001][3][2];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, M, K;
    while (scanf ("%d%d%d", &n, &M, &K) != EOF){
        //rep (i, 0, n) clr (d[i], 0), clr (s[i], 0);
        rep (i, 0, n) rep (j, 0, 2) rep (k, 0, 1) d[i][j][k] = s[i][j][k] = 0;
        rep (i, 1, n) rep (k, 0, 1){
            rep (t, 1, 2){
                add (d[i][0][k], s[i-1][t][k]);
                if (i >= M && !k) add (d[i][0][k], mod - s[i-M][t][k]);
                if (k && i >= M) add (d[i][0][k], s[i-M][t][0]);
            }
            if (k == (i >= M)) add (d[i][0][k], 1);
            rep (t, 0, 2) if (t != 1){
                add (d[i][1][k], s[i-1][t][k]);
                if (i >= K) add (d[i][1][k], mod - s[i-K][t][k]);
            }
            if (i < K && !k) add (d[i][1][k], 1);
            rep (t, 0, 1){
                add (d[i][2][k], s[i-1][t][k]);
            }
            if (!k) add (d[i][2][k], 1);
            rep (t, 0, 2) add (s[i][t][k], d[i][t][k]);
        }

        //rep (i, 1, n) rep (k, 0, 1){
            //cout << i << " " << k << " : ";
            //tst (d[i][0][k]); 
            //tst (d[i][1][k]); 
            //out (d[i][2][k]); 
        //}

        int ans = d[n][0][1];
        add (ans, d[n][1][1]); 
        add (ans, d[n][2][1]);
        printf ("%d\n", ans);
    }
    return 0;
}
