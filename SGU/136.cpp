/*
 * Author:  Plumrain
 * Created Time:  2014/6/23 23:44:34
 * File Name: 136.cpp
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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 10005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

pdd an[maxn+5];

void solve (double &x, double &y, double t1, double t2){
    x = 2 * t1 - x; y = 2 * t2 - y;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    repf (i, 0, n-1) cin >> an[i].x >> an[i].y;
    if (n & 1){
        double t1 = 0, t2 = 0;
        repf (i, 0, n-1)
            if (i & 1) t1 -= an[i].x, t2 -= an[i].y;
            else t1 += an[i].x, t2 += an[i].y;
        double x = t1, y = t2;
        if (sgn(x-an[0].x) == 0 && sgn(y-an[0].y) == 0) puts ("NO");
        else if (sgn(x-an[n-1].x) == 0 || sgn(y-an[n-1].y) == 0) puts ("NO");
        else{
            puts ("YES");
            repf (i, 0, n-1){
                printf ("%.3f %.3f\n", x, y);
                solve (x, y, an[i].x, an[i].y);
            }
        }
    }
    else{
        double t1 = 0, t2 = 0;
        repf (i, 0, n-1)
            if (i & 1) t1 += an[i].x, t2 += an[i].y;
            else t1 -= an[i].x, t2 -= an[i].y;
        if (sgn(t1) == 0 && sgn(t2) == 0){
            puts ("YES");
            double x = 1.55, y = 2.63;
            while ((sgn(x-an[0].x)==0 && sgn(y-an[0].y)==0) || (sgn(an[n-1].x-x)==0 && sgn(an[n-1].y-y)==0))
                x += 1.5, y += 1.5;
            repf (i, 0, n-1){
                printf ("%.3f %.3f\n", x, y);
                solve (x, y, an[i].x, an[i].y);
            }
        }
        else puts ("NO");
    }
    return 0;
}
