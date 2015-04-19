//by plum rain
/*Memory 200k
 *Time   16ms
 *trick: n = 0 
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 35;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct point{ double x, y;};
struct line{ point a, b;};

point an[N], p;
line bn[N];

double xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool opposite_side(point p1, point p2, point l1, point l2)
{
	return xmult (l1, p1, l2) * xmult (l1, p2, l2) < -eps;
}

bool intersect_ex(point u1, point u2, point v1, point v2)
{
	return opposite_side (u1, u2, v1, v2) && opposite_side (v1, v2, u1, u2);
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int n;
	while (scanf ("%d", &n) != EOF){
		if (n == -5)
			break;
		int num = 0;
		rep (i, n){
			scanf ("%lf%lf%lf%lf", &bn[i].a.x, &bn[i].a.y, &bn[i].b.x, &bn[i].b.y);
			an[num++] = bn[i].a; an[num++] = bn[i].b;
		}
		scanf ("%lf%lf", &p.x, &p.y);
		int ans = maxint, tmp;
		rep (i, num){
			tmp = 0;
			rep (j, n){
				if ((an[i].x == bn[j].a.x && an[i].y == bn[j].a.y) || (an[i].x == bn[j].b.x && an[i].y == bn[j].b.y))
					continue;
				if (intersect_ex (p, an[i], bn[j].a, bn[j].b))
					tmp ++;
			}
			if (tmp < ans)
				ans = tmp;
		}
		//if (!ans) printf ("Number of door = 1\n"); 
		if (!n) printf ("Number of doors = 1\n");
		else printf ("Number of doors = %d\n", ans + 1);
	}	
	return 0;
}
