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
const int maxx = 50005;
int cost[maxx];
int n,m;
int dp[maxx][4];
int DP()
{
	memset(dp,0,sizeof(dp));
	for( int i = 1 ; i <= n ; i ++ ){
		int x = i - m;
		if( x < 0 )
			x = 0;
		dp[i][1] = max( dp[i-1][1] , cost[i]-cost[x] );
		for( int j = 2 ; j <= 3 ; j ++ ){
			if( dp[x][j-1] != 0 )
				dp[i][j] = max( dp[i-1][j] , dp[x][j-1]+cost[i]-cost[x]);
		}
	}
	/*for( int i = 0 ; i <= n ; i ++ ){
		for( int j = 0 ; j <= 3 ; j ++ )
			printf( "%d " , dp[i][j] );
		puts("");
	}*/
	return dp[n][3];
}

int main()
{
	//freopen("a.in","r",stdin);
	int t;
	scanf( "%d" , &t );
	while( t -- ){
		memset(cost,0,sizeof(cost));
		scanf( "%d" , &n );
		for( int i = 1 ; i <= n ; i ++ ){
			scanf( "%d" , &cost[i] );
			cost[i] += cost[i-1];
		}
		scanf( "%d" , &m );
		cout<<DP()<<endl;
	}
	return 0;
}
