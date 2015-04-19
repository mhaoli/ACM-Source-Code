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
int n;
int an[405][3],bn[1605][2];
bool dp[40005];
int all;

void ZeroOnePack()
{
	memset( dp , false , sizeof(dp) );
	dp[0] = true;
	for( int i = 0 ; i < all ; i ++ )
		for( int j = bn[i][1]-bn[i][0] ; j >= 0 ; j -- )	
			if( dp[j] )
				dp[j+bn[i][0]] = dp[j] || dp[j+bn[i][0]];
	return ;
}

void MultiplePack_change( int a )
{
	int x = 0 , xx = 1;
	while( 1 ){
		if( xx <= an[a][2] )
			x ++;
		else
			break;
		xx <<= 1;
	}
	x --;
	if( x < 0 )
		x = 0;
	for( int i = 0 ; i < x ; i ++ ){
		bn[all][0] = an[a][0] * (int)pow(2.0,i+0.0);
		bn[all++][1] = an[a][1];
	}
	bn[all][0] = an[a][0] * (an[a][2]-(int)pow(2.0,x+0.0)+1);
	bn[all++][1] = an[a][1];
	return ;
}

int main()
{
	//freopen("a.in","r",stdin);
	while( cin >> n ){
		int	sum = 0;
		for( int i = 0 ; i < n ; i ++ ){
			cin >> an[i][0] >>  an[i][1] >>  an[i][2];
			sum = max( sum , an[i][1] );
		}
		for( int i = 0 ; i < n-1 ; i ++ )
			for( int j = 0 ; j < n-i-1 ; j ++ )
				if( an[j][1] > an[j+1][1] ){
					int t = an[j][0];
					an[j][0] = an[j+1][0];
					an[j+1][0] = t;
					t = an[j][1];
					an[j][1] = an[j+1][1];
					an[j+1][1] = t;
					t = an[j][2];
					an[j][2] = an[j+1][2];
					an[j+1][2] = t;
				}
		all = 0;
		for( int i = 0 ; i < n ; i ++ )
			MultiplePack_change(i);
		ZeroOnePack();
		for( int i = sum ; i >= 0 ; i -- )
			if( dp[i] ){
				cout << i;
				break ;
			}
	}
	return 0;
}
