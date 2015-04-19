//by iforgot
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int T = 1005;
const int M = 35;

int m , n , t;
double an[T][M] , dp[T][M];

void DP()
{
	memset( dp , 0 , sizeof(dp) );
	for( int i = 0 ; i < t ; i ++ )
		dp[i][0] = 1;
	for( int i = 0 ; i < m ; i ++ )
		for( int j = 0 ; j < t ; j ++ )
			for( int k = m ; k >= 0 ; k -- ){
				//dp[j][k] = max( dp[j][k-1]*an[j][i] , dp[j][k]*(1-an[j][i]) );
				dp[j][k] = dp[j][k-1]*an[j][i] + dp[j][k]*(1-an[j][i]); 
			}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	while( scanf( "%d%d%d" , &m , &t , &n ) != EOF ){
		if( !m && !n && !t )
		   break;	
		memset( an , 0 , sizeof(an) );
		for( int i =  0 ; i < t ; i ++ )
			for( int j = 0 ; j < m ; j ++ ){
				//scanf( "%lf" , &an[i][j] );
				cin >> an[i][j];
			}	
		/*for( int i = 0 ; i < t ; i ++ ){
			for( int j = 0 ; j < m ; j ++ )
				cout << an[i][j] << " ";
			cout << endl;
		}*/
		DP();
		/*for( int i = 0 ; i < t ; i ++ ){
			for( int j = 0 ; j <= m ; j ++ )
				cout << dp[i][j] << " ";
			cout << endl;
		}*/
		double xxx = 1 , x = 1;
		for( int i = 0 ; i < t ; i ++ ){
			xxx *= 1 - dp[i][0];
			double xx = 0;
			for( int j = 1 ; j < n ; j ++ )
				xx += dp[i][j];
			x *= xx;
		}
		printf( "%.3lf\n" , xxx - x );
		//cout << setprecision(4) << xxx-x << endl;
	}
	return 0;
}

