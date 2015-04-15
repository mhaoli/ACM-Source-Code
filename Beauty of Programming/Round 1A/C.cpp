/*
 * Author:  Plumrain
 * Created Time:  2014/4/19 14:20:37
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
#define sqr(x) ((x)*(x))
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
double temp = 1000000.0;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int n;
pii an[maxn];

double dis (double x1, double y1, double x2, double y2){
    return sqrt ( sqr(x1-x2) + sqr(y1-y2) );
}

double calc (double x){
    double ret = 0.0;
    repf (i, 0, n-1) ret += dis (x, 0, an[i].x+0.0, an[i].y+0.0);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &n);
        repf (i, 0, n-1) scanf ("%d%d", &an[i].x, &an[i].y);
        double l = -temp - 1.0, r = temp + 1.0;
        int cnt = 0;
        while (cnt < 200){
            double tmp = (r - l) / 3;
            double m1 = l + tmp, m2 = r - tmp;
            if (calc (m1) < calc (m2)) r = m2;
            else l = m1;
            ++ cnt;
        }
        printf ("Case %d: %.7f\n", ++ cas, l);
    }
    return 0;
}
