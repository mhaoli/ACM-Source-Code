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
const int N = 1005;

int an[N];

int Compare_Double( double x , double y )
{
	if( x < y - eps )
		return -1;
	else if( x > y + eps )
		return 1;
	else
		return 0;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf( "%d" , &T );
	bool blank = false;
	while( T -- ){
		if( blank )
			printf( "\n" );
		else
			blank = true;
		CLR(an);
		int n , m , y;
		scanf( "%d%d%d" , &n , &m , &y);
		int sum = 0;
		bool have = false;
		rep( i , n-1 ){
			int x;
			scanf( "%d" , &x );	
			double flag = 2.0;
			repf( j , 0 , m ){
				double now = fabs( ((double)j) / ((double)m) - ((double)x) /((double)y) );
				int xx = Compare_Double( flag , now );
				if( xx > 0 )
					flag = now;
				else if( xx < 0 ){
					an[i] = j -1;
					sum += an[i];
					break;
				}
				else{
					if( !have ){
						an[i] = j - 1;
						sum += an[i];
						have = true;
						break;
					}
					else{
						an[i] = j;
						sum += an[i];
						have = false;
						break;
					}
				}	

			}
		}
		int x;
		scanf( "%d" , &x );
		an[n-1] = m - sum;
		printf( "%d" , an[0] );
		repf( i , 1 , n-1 )
			printf( " %d" , an[i] );
	}

	return 0;
}
