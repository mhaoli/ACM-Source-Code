//by iforgot
#include <iostream>
#include <cstdio>
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
const int N = 45;

class SE{
	public:
		bool have;
		int x , y;
}chess[N][N];

int removed;
int n , p;
bool ans;
int xxn[N*N] , yyn[N*N] , xnn[N*N] , ynn[N*N];

void DFS( int x , int y )
{
	if( ans )
		return ; 
	if( removed == n*n ){
		ans = true;
		return ;
	}
	if( x == n+1 && y == n ){
		return ;
	}
	if( x == n+1 ){
		x = 1;
		y ++;
	}
	if( chess[y][x].have && !ans ){
		if( x < n && chess[y][x+1].have && !ans ){
			chess[y][x].x = x + 1;
			chess[y][x].y = y;
			chess[y][x].have = false;
			chess[y][x+1].x = x;
			chess[y][x+1].y = y;
			chess[y][x+1].have = false;
			removed += 2 ;
			DFS(x+2,y);
			chess[y][x].have = true;
			chess[y][x+1].have = true;
			removed -= 2;
		}
		if( y < n && chess[y+1][x].have && !ans ){
			chess[y][x].x = x;
			chess[y][x].y = y + 1;
			chess[y][x].have = false;
			chess[y+1][x].x = x;
			chess[y+1][x].y = y;
			chess[y+1][x].have = false;
			removed += 2;
			DFS(x+1,y);
			chess[y][x].have = true;
			chess[y+1][x].have = true;
			removed -= 2;
		}
	}
	if( !ans )
		DFS(x+1,y);
}

int main()
{
	//freopen("a.in","r",stdin);
	scanf( "%d%d" , &n , &p );
	removed = p;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ; j ++ ){
			chess[i][j].have = true;	
			chess[i][j].x = -1;
			chess[i][j].y = -1;
		}
	for( int i = 0 ; i < p ; i ++ ){
		int x , y;
		scanf( "%d%d" , &x , &y );
		chess[y][x].have = false;	
	}
	if( (n*n - removed) % 2 == 0 ){
		ans = false;
		DFS(1,1);
		if( !ans )
			printf( "No\n" );
		else{
			memset( xxn , 0 , sizeof(xxn) );
			memset( yyn , 0 , sizeof(yyn) );
			memset( xnn , 0 , sizeof(xnn) );
			memset( ynn , 0 , sizeof(ynn) );
			printf( "Yes\n" );
			int a1 = 0 , a2 = 0;
			for( int i = 1 ; i <= n ; i ++ ){
				for( int j = 1 ; j <= n ; j ++ ){
					if( chess[i][j].x == j + 1 ){
						xxn[a1] = j;
						yyn[a1++] = i; 
					}
					if( chess[i][j].y == i + 1 ){
						xnn[a2] = j;
						ynn[a2++] = i;
					}
				}	
			}
			printf( "%d\n" , a1 );
			for( int i = 0 ; i < a1 ; i ++ )
				printf( "%d %d\n" , xxn[i] , yyn[i] );
			printf( "%d\n" , a2 );
			for( int i = 0 ; i < a2 ; i ++ )
				printf( "%d %d\n" , xnn[i] , ynn[i] );

		}
	}
	else{
		printf( "No\n" );
	}
	return 0;
}

