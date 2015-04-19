//by plum rain
//Memory 	Time
//688k   	16ms
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 110;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class Node{
	public:
		double x,y;
}ln[N], rn[N];

int n;

double dis(Node a, Node b)
{
	return sqrt ((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

double Cro(Node a, Node b, Node c)
{
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}

bool judge(Node a, Node b)
{
	if (dis(a, b) < eps)
		return 0;
	rep (i, n)
		if (Cro(a, b, ln[i]) * Cro(a, b, rn[i]) > eps)
			return false;
	return true;
}

int main ()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf ("%d", &T);
	while (T --){
		scanf ("%d", &n);
		rep (i, n)
			scanf ("%lf%lf%lf%lf", &ln[i].x, &ln[i].y, &rn[i].x, &rn[i].y);
		if (n == 1){
			printf ("Yes!\n");
			continue;
		}
		bool ans = false;	
		rep (i, n)
			repf (j, i+1, n-1){
				if (judge (ln[i], ln[j]))
					ans = true;
				if (judge (ln[i], rn[j]))
					ans = true;
				if (judge (rn[i], ln[j]))
					ans = true;
				if (judge (rn[i], rn[j]))
					ans = true;
				if (ans)
					break;
			}
		if (ans)
			printf ("Yes!\n");
		else
			printf ("No!\n");
	}
	return 0;
}
