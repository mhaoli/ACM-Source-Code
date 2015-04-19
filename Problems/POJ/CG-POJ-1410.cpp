//by plum rain
/*Memory 204k
 *Time   0ms
 *trick: 题目中给出的矩形左上角坐标(x1, y1)和右下角坐标(x2, y2)不一定真的是左上角和右下角
 *比如有可能给(1, 1)和(11, 11)或者(11,1)和(1,11)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <ctime>
#include <stack>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<':'<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)
#define ZERO(x) (((x)>0?(x):(-x))<eps)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}
struct point{double x, y;};
struct line{point a, b;};
//a b
//c d
point a, b, c, d;
line lin;

double xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool dot_online_in(point p, line l)
{
	return ZERO (xmult (p, l.a, l.b)) && (l.a.x - p.x) * (l.b.x - p.x) < eps && (l.a.y - p.y) * (l.b.y - p.y) < eps;
}

bool same_side(point p1, point p2, line l)
{
	return xmult (l.a, p1, l.b) * xmult (l.a, p2, l.b) > eps;
}

bool dots_inline(point p1, point p2, point p3)
{
	return ZERO (xmult (p1, p2, p3));
}

bool intersect_in(line u, line v)
{
	if (!dots_inline (u.a, u.b, v.a))
		return !same_side (u.a, u.b, v) && !same_side (v.a, v.b, u);
	return dot_online_in (u.a, v) || dot_online_in (u.b, v) || dot_online_in (v.a, u) || dot_online_in (v.b, u);
}

bool in_retangle(point p)
{
	return (p.x >= a.x && p.x <= d.x && p.y <= a.y && p.y >= d.y);
}

bool solve()
{
	if (in_retangle(lin.a) || in_retangle(lin.b))
		return 1;
	line tmp;
	tmp.a = a; tmp.b = b;
	if (intersect_in(lin, tmp))
		return 1;
	tmp.a = a; tmp.b = c;
	if (intersect_in(lin, tmp))
		return 1;
	tmp.a = c; tmp.b = d;
	if (intersect_in(lin, tmp))
		return 1;
	tmp.a = b; tmp.b = d;
	if (intersect_in(lin, tmp))
		return 1;
	return 0;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf ("%d", &T);
	while (T--){
		scanf ("%lf%lf%lf%lf", &lin.a.x, &lin.a.y, &lin.b.x, &lin.b.y);
		scanf ("%lf%lf%lf%lf", &a.x, &a.y, &d.x, &d.y);
		double xma = max (a.x, d.x), xmi = min (a.x, d.x);
		double yma = max (a.y, d.y), ymi = min (a.y, d.y);
		a.x = xmi; a.y = yma; d.x = xma; d.y = ymi;
		b.x = d.x; b.y = a.y; c.x = a.x; c.y = d.y;
		if (solve())
			printf ("T\n");
		else
			printf ("F\n");
	}	
	return 0;
}
