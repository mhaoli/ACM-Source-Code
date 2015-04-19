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

int64 mm[13];
int p,m;

int64 MyPow( int64 x , int64 n)
{
	int64 sq = 1;
	while( n > 0 ){
		if( n % 2 )
			sq = ( sq * x ) % mm[m];
		n /= 2;
		x = x * x % mm[m];
	}
	return sq;
}

void Data_Output()
{
	if( p > mm[m] ){
		printf( "%lld\n" , p % mm[m] );
		return ;
	}
	int64 an = p , time = 0;
	while( time <= 4 && an < mm[m] ){
		an = MyPow(p,an);
		time ++;
	}
	printf( "%lld\n" , an % mm[m] );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	repf( i , 1 , 12 ){
		int a = i ; mm[i] = i;
		while( a > 1 )
			mm[i] *= -- a;
	}
	bool xxx = false;
	while( scanf( "%d%d" , &p , &m ) != EOF ){
		if( xxx )
			printf( "\n" );
		else
			xxx = true;
		Data_Output();
	}
	return 0;
}

