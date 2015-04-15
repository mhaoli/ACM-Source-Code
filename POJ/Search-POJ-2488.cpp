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
#define yn zn

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int maxx = 27;
int p,q,total;
bool all_visited,visited[maxx][maxx];
int xn[maxx],yn[maxx];
int change[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

void dfs( int x , int y )
{
	if(all_visited)
		return ;	
	xn[++total] = x;
	yn[total] = y;
	visited[x][y] = true;
	if( total == p*q ){
		all_visited = true;
		return ;
	}
	for( int i = 0 ; i < 8 ; i ++ ){
		int xx = x + change[i][0] , yy = y + change[i][1];
		if( visited[xx][yy] == 0 && xx > 0 && xx <= q && yy > 0 && yy <= p ){
			dfs(xx,yy);
			total --;
		}
	}
	visited[x][y] = false;
	return ;
}

int main()
{
	//freopen("a.in","r",stdin);
	int t,cas = 0;
	cin>>t;
	while(t --){
		memset(xn,0,sizeof(xn));
		memset(yn,0,sizeof(yn));
		memset(visited,false,sizeof(visited));
		all_visited = false;
		total = 0;
		printf( "Scenario #%d:\n" , ++ cas );
		cin>>p>>q;
		dfs(1,1);
		if( !all_visited )
			printf( "impossible\n\n" );
		else{
			for( int i = 1 ; i <= p*q ; i ++ )
				printf( "%c%d" , xn[i]+'A'-1 , yn[i] );
			printf( "\n\n" );
		}		
	}
	return 0;
}
