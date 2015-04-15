//by plum rain
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
const int N = 100005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct point{double x, y;};
struct line{point a, b;};

line an[N];
bool ans[N];
int n;

double xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool opposite_side(point p1, point p2, line l)
{
	return xmult (l.a, p1, l.b) * xmult (l.a, p2, l.b) < -eps;
}

bool intersect_ex(line u, line v)
{
	return opposite_side (u.a, u.b, v) && opposite_side (v.a, v.b, u);
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);	
	while (scanf ("%d", &n) != EOF && n){
		rep (i, n)
			scanf ("%lf%lf%lf%lf", &an[i].a.x, &an[i].a.y, &an[i].b.x, &an[i].b.y);
		memset (ans, true, sizeof(ans));
		rep (i, n){
			repf (j, i+1, n-1){
				if (intersect_ex (an[i], an[j])){
					ans[i] = false;
					break;
				}
			}
		}
		bool blank = false;
		printf ("Top sticks:");
		rep (i, n){
			if (ans[i]){
				if (blank)
					printf (",");
				else
					blank = true;
				printf (" %d", i+1);
			}
		}
		printf (".\n");
	}
	return 0;
}
