//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int64 long long
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int d = 100;
int n,k;
int an[10005];
bool dp[10005][205];

bool ANS()
{
	memset(dp,0,sizeof(dp));
	dp[1][an[1]%k+d] = 1;
	for( int i = 2 ; i <= n ; i ++ )
		for( int j = 0 ; j <= 202 ; j ++ ){
			if(dp[i-1][j]){
				dp[i][(j-d+an[i])%k+d] = 1;
				dp[i][(j-d-an[i])%k+d] = 1;
			}
		}
/*	for( int i = 0 ; i <= n ; i ++ ){
		for( int j = d-k-1 ; j <= d+k+1 ; j ++ ){
			if(dp[i][j])
				printf( "1 " );
			else
				printf( "0 " );
		}
		printf( "\n" );
	}*/
	return dp[n][d];
}

int main()
{
	//freopen("a.in","r",stdin);
	while( cin>>n>>k ){
//		if( n == -2 )
//			break;
		int x;
		for( int i = 1 ; i <= n ; i ++ ){
			cin>>x;
			an[i] = x%k;
		}
		if( ANS() )
			printf( "Divisible\n" );
		else
			printf( "Not divisible\n" );
	}	
	return 0;
}
