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
	char an[2005];
	while( cin >> an ){
		if( an[0] == '-' )
			break;
		int num_a = 0 , num_b = 0; 
		int ans = 0;
		int len = strlen(an);
		for( int i = 0 ; i < len ; i ++ ){
			if( an[i] == '{' )
				num_a ++;
			else{
				if( num_a > 0 )
					num_a --;
				else{
					ans ++;
					num_a ++;
				}
			}
		}
		if( num_a != 0 )
			ans += ( num_a / 2 );
		printf( "%d. %d\n" , ++ test , ans );
	}
    return 0;
}
