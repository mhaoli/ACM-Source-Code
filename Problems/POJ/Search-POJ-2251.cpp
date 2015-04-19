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

bool an[40][40][40],visited[40][40][40];
int change[6][3] = { {0,-1,0} , {0,1,0} , {-1,0,0} , {1,0,0} , {0,0,1} , {0,0,-1} };
int l,n,m;
int Sx,Sy,Sz,Ex,Ey,Ez;
int ans,anss;

class SE{
	public:
		int x,y,z;
		int time;
}pos[50005];

void bfs( int x , int y , int z )
{
	int left = 0 , right = 1;
	pos[0].x = x ; pos[0].y = y ; pos[0].z = z ;
	pos[0].time = 0;
	visited[z][y][x] = true;
	while( left < right ){
		x = pos[left].x ; y = pos[left].y ; z = pos[left].z ;
		anss = pos[left ++].time;
		if( x == Ex && y == Ey && z == Ez ){
			ans = anss;
			return ; 
		}
		for( int i = 0 ; i < 6 ; i ++ ){
			int xx = x+change[i][0] , yy = y+change[i][1] , zz = z+change[i][2];
			if( xx>0 && xx<=m && yy>0 && yy<=n && zz>0 && zz<=l && an[zz][yy][xx] && !visited[zz][yy][xx] ){
				pos[right].x = xx ; pos[right].y = yy ; pos[right].z = zz ;
				pos[right ++].time = anss + 1;
				visited[zz][yy][xx] = true;
			}

		}
	}
	return ;
}

int main()
{
	//	freopen("a.in","r",stdin);
	while( cin>>l>>n>>m ){
		if( l == 0 && n == 0 && m == 0 )
			break;
		char xx[35];
		memset(an,false,sizeof(an));
		memset(visited,false,sizeof(visited));
		memset(xx,0,sizeof(xx));
		for( int i = 1 ; i <= l ; i ++ )
			for( int j = 1 ; j <= n ; j ++ ){ 
				cin>>xx;
				//puts(xx);
				for( int k = 0 ; k < m ; k ++ ){
					if( xx[k] == '.')
						an[i][j][k+1] = true;
					else if( xx[k] == 'S' ){
						an[i][j][k+1] = true;
						Sx = k + 1 ; Sy = j ; Sz = i ;
					}
					else if( xx[k] == 'E' ){
						an[i][j][k+1] = true;
						Ex = k + 1 ; Ey = j ; Ez = i ;
					}	
				}
			}
		ans = 1000; anss = 0;
		bfs( Sx , Sy , Sz );
		if( ans == 1000 )
			cout<<"Trapped!"<<endl;
		else	
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
	}	
	return 0;
}
