//by PlumRain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define clr(a) memset(a,0,sizeof(a)) 
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;

typedef vector<int> VI;  
typedef vector<string> VS;  
typedef vector<double> VD;  
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 500005;

int chief[N];
int ans[N];
int hash[N];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int test;
	scanf( "%d" , &test );
	int ma = test - 1;
	while( test -- ){
		clr(ans);
		clr(hash);
		int n;
		scanf( "%d" , &n );
		for( int i = 2 ; i <= n ; i ++ )
			scanf( "%d" , &chief[i] );
		int tot = 0;
		for( int i = n ; i > 1 ; i -- )
			if( !hash[i] && !hash[chief[i]] ){
				ans[tot++] = i;
				hash[chief[i]] = true;
			}	
		if( test != ma )
			printf( "\n" );
		printf( "%d000\n" , tot );
		printf( "%d" , ans[tot-1] );
		for( int i = tot - 2 ; i >= 0 ; i -- )
			printf( " %d" , ans[i] );
		printf( "\n" );
	}
	return 0;
}
