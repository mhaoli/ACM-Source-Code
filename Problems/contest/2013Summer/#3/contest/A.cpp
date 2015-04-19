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


int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	while( scanf( "%d" , &n ) != EOF ){
		//if( n == -5 )
		//	break;
		printf( "0" );
		for( int i = 0 ; i < n ; i ++ ){
			if( i == 0 )
				for( int j = 1 ; j < n ; j ++ ){ 
					printf( " 1" );
				}
			else{
				printf( "90" );
				for( int j = 1 ; j < n ; j ++ ) 
					printf( " 1" );
			}
			printf( "\n" );
		}
		printf( "\n" );
	}
	return 0;
}
