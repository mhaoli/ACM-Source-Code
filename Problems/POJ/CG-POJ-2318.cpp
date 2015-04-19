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

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define rep(i, n) for(int i = 0; i < (n); i ++)
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
const int N = 5010;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class node{
	public:
		int x,y;
}high[N],low[N];

node a, b;
int n, m;
int num[N];

int cal (node aa, node bb, node cc)
{
	return (cc.x - aa.x) * (bb.y - aa.y) - (cc.y - aa.y) * (bb.x - aa.x);
}

int solve (node cc)
{
	int l = 0, r = n, mid;
	while (l <= r){
		mid = (l + r) >> 1;
		if (cal (low[mid], high[mid], cc) > 0)
			l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int main ()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	while (scanf ("%d", &n) != EOF){
		if (n == 0) break;
		scanf ("%d%d%d%d%d", &m, &a.x, &a.y, &b.x, &b.y);
		rep (i, n){
			scanf ("%d%d", &high[i].x, &low[i].x);
			low[i].y = b.y; high[i].y = a.y;
		}
		low[n].x = b.x; low[n].y = b.y;
		high[n].x = b.x; high[n].y = a.y;
		node temp;
		memset (num, 0, sizeof (num));
		while (m --){
			scanf ("%d%d", &temp.x, &temp.y);
			int pos = solve (temp);
			num[pos] ++;
		}
		rep(i, n+1)
			printf("%d: %d\n", i, num[i]);
		printf ("\n");
	}	
	return 0;
}
