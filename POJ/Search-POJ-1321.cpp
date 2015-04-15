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

int n,k;
int ans;
bool an[9][9],visit_col[9];

void dfs( int x , int num )
{
	if( num == k ){
		ans ++;
		return ;
	}
	if( x > n )
		return ;
	for( int i = 1 ; i <= n ; i ++ ){
		if( an[x][i] && !visit_col[i] ){
			visit_col[i] = true;
			num ++;
			dfs( x+1 , num );
			num --;
			visit_col[i] = false;
		}
	}
	dfs( x+1 , num );
}

int main()
{
	//freopen("a.in","r",stdin);
	while( cin>>n>>k ){
		memset(visit_col,false,sizeof(visit_col));
		if( n == -1 && k == -1 )
			break;
		int sum = 0;
		char xn[10];
		for( int i = 1 ; i <= n ; i ++ ){
			memset(xn,0,sizeof(xn));
			cin>>xn;
			for( int j = 0 ; j < n ; j ++ ){
				if( xn[j] == '#' ){
					an[i][j+1] = true;
					sum ++;
				}
				else
					an[i][j+1] = false;
			}
		}
	/*	for( int i = 1 ; i <= n ; i ++ ){
			for( int j = 1 ; j <= n ; j ++ ){
				printf( "%d" , an[i][j] );	
			}
			printf( "\n" );
		}*/
		if( sum < k )
			cout<<0<<endl;
		else{
			ans = 0;
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
