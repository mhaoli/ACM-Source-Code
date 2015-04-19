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
const int maxx = 3410;
int wn[maxx],dn[maxx],dp[12885];

int ZeroOnePack( int n , int m )
{
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for ( int j = m ; j >= 0 ; j -- ){
			if( j + wn[i] <= m && dp[j] != -1 )
				dp[j+wn[i]] = max( dp[j] + dn[i] , dp[j+wn[i]] );
		}
	}
	int ans = 0;
	for( int i = 1 ; i <= m ; i ++ )
		ans = max( ans , dp[i] );
	return ans;
}

int main()
{
	//freopen("a.in","r",stdin);
	int n,m;
	while( cin>>n>>m ){
		if( n == -2 )
			break;
		for( int i = 1 ; i <= n ; i ++ )
			cin>>wn[i]>>dn[i];
		cout<<ZeroOnePack(n,m)<<endl;
	}	
	return 0;
}
