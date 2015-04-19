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
const int maxx = 5005;
char ann[maxx],bnn[maxx];
int dp[2][maxx];

int LCS(int n)
{
	memset(dp,0,sizeof(dp));
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ;j ++){
			if( ann[i] == bnn[j] )
				dp[i%2][j] = dp[abs(i%2-1)][j-1] + 1;
			else
				dp[i%2][j] = max( dp[abs(i%2-1)][j] , dp[i%2][j-1] );
		}
	return dp[n%2][n];
}

int main()
{
	//freopen("a.in","r",stdin);
	int n;
	while( cin>>n>>ann ){
		for( int i = n , j = 1 ; i > 0 ; i -- , j ++ ){
			ann[i] = ann[i-1];
			bnn[j] = ann[i];
		}
		cout<<(n-LCS(n))<<endl;
	}
	return 0;
}
