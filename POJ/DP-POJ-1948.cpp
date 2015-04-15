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
int n,an[45];
bool dp[805][805];
int sum;
int ans;

bool judge( int x , int y )
{
	int xx[3];
	xx[0] = x ; xx[1] = y ; xx[2] = sum-x-y ;
	sort(xx,xx+3);
	if( xx[0]+xx[1] > xx[2] )
		return true;
	return false;
}

int area( double x , double y , double z )
{
	double p = (x+y+z) / 2.0;
	return (int)(sqrt(p*(p-x)*(p-y)*(p-z)) * 100.0);
}

void DP()
{
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	int a;
	if( sum%2 == 0 )
		a = sum/2;
	else
		a = (sum+1)/2;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = a ; j >= 0 ; j -- )
			for( int k = a ; k >= 0 ; k -- ){
				if( !dp[j][k] ){
					if( j-an[i] >= 0 && dp[j-an[i]][k] )
						dp[j][k] = 1;
					else if( k-an[i] >= 0 && dp[j][k-an[i]] )
						dp[j][k] = 1;
				}
			}
	}
	ans = -1;
	for( int i = 1 ; i <= a ; i ++ )
		for( int j = 1 ; j <= a ; j ++ ){
			if( dp[i][j] && judge(i,j) )
				ans = max( ans , area(i,j,sum-i-j) );
		}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	while( cin>>n ){
	//	if( n == -2 )
	//		break;
		sum = 0;
		for( int i = 1 ; i <= n ; i ++ ){
			cin>>an[i];
			sum += an[i];
		}
		DP();
		cout<<ans<<endl;	
	}
	return 0;
}
