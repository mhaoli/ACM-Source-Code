/*
 * Author:  Plumrain
 * Created Time:  2014/9/15 23:55:52
 * File Name: ZOJ3801.cpp
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

const int64 mod = 1<<30;
int an[15][15];
int64 b[15][15];

long long calc(long long a[15][15], int n){
    long long ans = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = i+1; j < n; ++ j){
            while (a[j][i] != 0){
                long long t = a[i][i] / a[j][i];
                for (int k = 0; k < n; ++ k){
                    a[i][k] -= a[j][k] * t;
                }
                for (int k = 0; k < n; ++ k){
                    swap (a[i][k], a[j][k]);
                }
                ans = -ans;
            }
        }
        ans *= a[i][i];
    }
    return ans;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    repcase{
        int n; scanf ("%d", &n);
        rep (i, 0, n-1) rep (j, 0, n-1) scanf ("%d", &an[i][j]);
        rep (i, 0, n-1) rep (j, 0, n-1) b[i][j] = an[i][j] - 1;
        int64 ans = abs (calc (b, n));
        rep (i, 0, n-1) rep (j, 0, n-1) b[i][j] = an[i][j] + 1;
        ans ^= abs (calc (b, n));
        if (n == 1){
            rep (i, 0, n-1) rep (j, 0, n-1) b[i][j] = an[i][j];
            ans ^= abs (calc (b, n));
        }
        printf ("%d\n", int(ans % mod));
    }
    return 0;
}
