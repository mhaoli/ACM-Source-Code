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
#define INF 999999999999
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
const int N = 55;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct point{int x, y; int num; bool flag;};

point an[N], bn[N];


int xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double Distance(point a, point b)
{
	return sqrt ((a.x - b.x + 0.0) * (a.x - b.x + 0.0) + (a.y - b.y + 0.0) * (a.y - b.y + 0.0));
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf ("%d", &T);
	while (T--){
		int xmin = maxint, ymin = maxint;
		int n, tmp;
		scanf ("%d", &n);
		rep (i, n){
			scanf ("%d%d%d", &an[i].num, &an[i].x, &an[i].y);
			if (ymin > an[i].y || (ymin == an[i].y && xmin > an[i].x)){
				ymin = an[i].y;
				xmin = an[i].x;
				tmp = i;
			}
			an[i].flag = false;
		}
		bn[1] = an[tmp];
		bn[0].x = 0; bn[0].y = bn[1].y;
		an[tmp].flag = true;
		int ans = 1;
		while (ans != n){
			bool x = false;
			rep (i, n)
				if (!an[i].flag && xmult (an[i], bn[ans], bn[ans-1]) < 0){
					x = true;
					tmp = i;
					break;
				}
			if (!x)
				break;
			rep (i, n){
				if (i == tmp || an[i].flag)
					continue;
				int xmt = xmult (an[i], an[tmp], bn[ans]);
				double disi = Distance (an[i], bn[ans]), dist = Distance (an[tmp], bn[ans]);
				if (xmt > 0 || (xmt == 0 && disi <= dist - eps)){
					tmp = i;
				}
			}
			bn[++ans] = an[tmp];
			an[tmp].flag = 1;
		}
		printf ("%d", ans);
		repf (i, 1, ans)
			printf (" %d", bn[i].num);
		printf ("\n");
	}	
	return 0;
}
