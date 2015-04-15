//by iforgot
#include <iostream>
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
const int M = 12500000;

int an[5];
short hash[25000005];
int xn[105];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	memset( hash , 0 , sizeof(hash) );
	for( int i = 0 ; i < 5 ; i ++ )
		scanf( "%d" , &an[i] );
	for( int i = -50 , j = 0 ; i < 51 ; i ++ , j ++ )
		xn[j] = i * i * i;
	for( int i = 0 ; i < 101 ; i ++ ){
		if( i == 50 )
			continue;
		for( int j = 0 ; j < 101 ; j ++ ){
			if( j == 50 )
				continue;
			int x = M + an[3] * xn[i] + an[4] * xn[j];
			hash[x] ++;	
		}
	}
	int ans = 0;
	for( int i = 0 ; i <= 100 ; i ++ ){
		if( i == 50 )
			continue;
		for( int j = 0 ; j <= 100 ; j ++ ){
			if( j == 50 )
				continue;
			for( int k = 0 ; k <= 100 ; k ++ ){
				if( k == 50 )
					continue;
				int sum = an[0] * xn[i] + an[1] * xn[j] + an[2] * xn[k] + M;
				if( sum != M && sum >= 0 && sum <= 2*M ){
					ans += hash[sum];
				}
				/*if( sum == M ){
					if( an[3] && !an[4] || !an[3] && an[4] )
						ans += 100;
					if( !an[3] && !an[4] )
						ans += 10000;
				}*/
			}
		}
	}
	printf( "%d\n" , ans );
	return 0;
}
