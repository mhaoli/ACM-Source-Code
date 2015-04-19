//by PlumRain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, n) for(long long i = 0; i < (n); i ++)
#define repf(i, a, b) for(long long i = (a); i <= (b); i ++)
#define repd(i, a, b) for(long long i = (a); i >= (b); i --)
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 100005;

class POS{
	public:
		int s;
		int b;
}an[N];

POS dn[N];

int Compare( POS a , POS b )
{
	if( ( a.s > b.s && a.b < b.b ) || ( a.s < b.s && a.b > b.b ) )
		return -1;
	else 
		return 1;
}

int Binsearch( int l , int r , POS x )
{
	while( l <= r ){
		int mid = (l+r) >> 1;
		if( Compare( dn[mid] , x ) <= 0 )
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

int LIS(int n)
{
	//clr(dn);
	int len = 1;
	dn[1] = an[0];
	repf( i , 1 , n - 1 ){
		int j;
		if( Compare( an[i] , dn[1] ) < 0 )
			j = 1;
		else if( Compare( an[i] , dn[len]) > 0 )
			j = ++ len;
		else 
			j = Binsearch( 1 , len , an[i] );
		dn[j] = an[i];
	} 
	repf( i , 1 , len ){
		out(dn[i].s);
		out(dn[i].b);
	}
	return len;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T;
	scanf( "%d" , &T );
	while( T -- ){
		int n;
		scanf( "%d" , &n );
		rep( i , n )
			scanf( "%d%d" , &an[i].s , &an[i].b );
		int ans = LIS(n);
		printf( "%d\n" , ans );
		if( T > 0 )
			printf( "\n" );
	}
	return 0;
}
