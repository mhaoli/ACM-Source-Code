/*
 * Author:  Plumrain
 * Created Time:  2014/8/15 11:18:27
 * File Name: C.cpp
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
const int maxn = 1e6 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

double fac[maxn];

void init (int n){
    fac[0] = 0;
    repf (i, 1, n) fac[i] = fac[i-1] + log(i + 0.0);
}

double C(int m, int n){
    if (n > m) return 0;
    return fac[m] - fac[n] - fac[m-n];
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init(maxn - 5);
    int n, m;
    while (cin >> n >> m){
        double ans = 0;
        int up = min (n, m);
        repf (i, 1, up){
            double t = C(m, i) + C(n*m-m, n-i) - C(n*m, n);
            t = exp(t) * (double)i * i / n / n;
            ans += t;
        }
        ans *= n;
        printf ("%.7f\n", ans);
    }
    return 0;
}
