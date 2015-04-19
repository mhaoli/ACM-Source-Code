//by iforgot
#include <iostream>
#include <cstdio>
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

int main()
{
    //freopen("a.in","r",stdin);
	int test = 0;
	int n;
	while( scanf( "%d" , &n ) != EOF ){
		if( !n )
			break;
		int ans1 , ans2;
		if( n % 2 == 0 ){
			ans1 = 0;
			ans2 = n / 2;
		}
		else{ 
			ans1 = 1;
			ans2 = n / 2;
		}
		printf( "%d. " , ++ test );
		if( ans1 == 0 )
			printf( "even " );
		else
			printf( "odd " );
		printf( "%d\n" , ans2 );
	}
    return 0;
}
