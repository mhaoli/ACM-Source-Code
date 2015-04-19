/*
 * Author:  Plumrain
 * Created Time:  2014/8/17 13:12:38
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

double d[110][210];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, p;
    while (scanf ("%d%d", &n, &p) != EOF){
        if (!n && !p) break;
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        int sum = a + b + c, lef = 34 - sum;
        n = min (lef, n); 
        double pa = (a + 0.0) / sum, pb = (b + 0.0) / sum, pc = (c + 0.0) / sum;
        clr (d, 0); d[0][0] = 1;
        rep (i, 1, n) rep (j, 0, 200){
            d[i][j] = d[i-1][j] * pc;
            if (j >= 1) d[i][j] += d[i-1][j-1] * pb;
            if (j >= 3) d[i][j] += d[i-1][j-3] * pa;
        }

        double ans = 0;
        rep (j, p, 200) ans += d[n][j];
        ans *= 100.0;
        //printf ("%.5f\n", ans);
        printf ("%.1f\n", ans);
    }
    return 0;
}
