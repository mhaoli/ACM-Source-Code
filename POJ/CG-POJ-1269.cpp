//by plum rain
//Memory 	Time
//700k   	0ms
//注意double输入用lf，输出用f
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

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define rep(i, n) for(long long i = 0; i < (n); i ++)
#define repf(i, a, b) for(long long i = (a); i <= (b); i ++)
#define repd(i, a, b) for(long long i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<':'<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)
#define ZERO(x) (((x)>0?(x):-(x))<eps)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct point{
	double x, y;
}an[4];

double xmult(point a, point b, point c)
{
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

int parallel(point u1, point u2, point v1, point v2)
{
	return ZERO ((u1.x - u2.x) * (v1.y - v2.y) - (v1.x - v2.x) * (u1.y - u2.y));
}

point intersection(point u1, point u2, point v1, point v2){
	point ret = u1;
	double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
	ret.x += (u2.x - u1.x) * t;
	ret.y += (u2.y - u1.y) * t;
	return ret;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf ("%d", &T);
	printf("INTERSECTING LINES OUTPUT\n");
	while (T --){
		rep (i, 4)
			scanf ("%lf%lf", &an[i].x, &an[i].y);
			//cin >> an[i].x >> an[i].y;
		if (ZERO (xmult (an[0], an[1], an[2])) && ZERO (xmult (an[0], an[1], an[3]))){
			printf("LINE\n");
			continue;	
		}
		if (parallel (an[0], an[1], an[2], an[3])){
			printf("NONE\n");
			continue;
		}
		point g = intersection (an[0], an[1], an[2], an[3]);
		printf("POINT %.2f %.2f\n",g.x,g.y);
	}	
	printf("END OF OUTPUT\n");
	return 0;
}
