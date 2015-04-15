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

int n,c1,c2;
int an[15],dp[1<<10+5],once[1<<10+5];
int cnt;

int ZeroOnePack()
{	
	dp[0] = 0;
	for( int i = 1 ; i < 1<<10 ; i ++ )
		dp[i] = 2000;
	for( int i = 0 ; i < cnt ; i ++ )
		for( int j = (1<<n)-1-once[i] ; j >= 0 ; j -- ){
			if( !(j&once[i]) )
				dp[j|once[i]] = min( dp[j]+1 , dp[j|once[i]] );
		}
	return dp[(1<<n)-1];
}

bool judge( int x )
{	
	bool f[105];
	memset(f,0,sizeof(f));
	f[0] = 1;
	int sum = 0;
	for( int i = 0 ; i < n ; i ++ )
		if( (1<<i)&x ){
			sum += an[i];
			for( int j = c1-an[i] ; j >= 0 ; j -- )
				if( f[j] )
					f[j+an[i]] = 1;
		}
	if( sum > c1+c2 )
		return false;
	for( int i = c1 ; i >= 0 ; i -- ){
		if( f[i] && sum-i <= c2 )
			return true;
	}
	return false;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int t,cas = 0;
	scanf( "%d" , &t );
	while( t -- ){
		cin>>n>>c1>>c2;
		if( c1 > c2 )
			swap(c1,c2);
		for( int i = 0 ; i < n ; i ++ )
			scanf( "%d" , &an[i] );
		cnt = 0;
		for( int i = 1 ; i < 1<<n ; i ++ )
			if( judge(i) )
				once[cnt++] = i;	
		printf( "Scenario #%d:\n%d\n\n" , ++cas , ZeroOnePack() );
	}	
	return 0;
}
