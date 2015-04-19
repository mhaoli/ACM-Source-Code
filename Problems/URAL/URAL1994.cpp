/*
 * Author:  Plumrain
 * Created Time:  2014/8/13 16:42:28
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

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
//#define out(x) cout<<#x<<":"<<(x)<<endl
//#define tst(a) cout<<a<<" "
//#define tst1(a) cout<<#a<<endl

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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

double d[555][55];
double fac[555];

double calc (int i, int j, int n, int m){
    double ret = fac[m] - fac[j] - fac[m-j];
    ret += fac[n] - fac[i-j] - fac[n-i+j];
    ret -= (fac[n+m] - fac[i] - fac[n+m-i]);
    return exp (ret);
}

double dfs (int n, int k){
    if (!n) return 0;
    if (!k) return n;
    if (n <= k) return 0;

    double &ret = d[n][k];
    if (ret > -0.5) return ret;
    n -= k;
    ret = 0;
    repf (i, 0, n+k){
        double sum = 0;
        repf (j, 0, k){
            if (j > i || i - j > n) continue;
            double tmp = dfs (n - i + j, k - j);
            double tt = calc (i, j, n, k);
            sum += tt * tmp;
        }
        chmax (ret, sum);
    }
    return ret;
}

void init(int n){
    fac[0] = 0;
    repf (i, 2, n) fac[i] = fac[i-1] + log (i * 1.0);
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init (205);
    int n, k; scanf ("%d%d", &n, &k);
    repf (i, 0, n) repf (j, 0, k) d[i][j] = -1.0;
    if (n <= 2*k) puts ("0.0000000");
    else printf ("%.7f\n", dfs (n-k, k));
    return 0;
}
