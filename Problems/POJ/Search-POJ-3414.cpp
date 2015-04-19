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
#define left lef
#define right rig

using namespace std;
const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

class SE{
	public:
		int v1,v2;
		int change;
		int s;
		int step;
}pos[2000000];

int A,B,C;
bool ann[5000][5000];
int ans;
int left,right,yy;
SE x,xx;

void Data_output( int a )
{
	if( a == 1 )
		printf( "FILL(1)\n" );
	if( a == 2 )
		printf( "FILL(2)\n" );
	if( a == 3 )
		printf( "DROP(1)\n" );
	if( a == 4 )
		printf( "DROP(2)\n" );
	if( a == 5 )
		printf( "POUR(2,1)\n" );
	if( a == 6 )
		printf( "POUR(1,2)\n" );	
}

void Change( int a )
{
	if( a == 1 ){
		xx.v1 = A;
	}
	if( a == 2 )
		xx.v2 = B;
	if( a == 3 )
		xx.v1 = 0;
	if( a == 4 )
		xx.v2 = 0;
	if( a == 5 ){
		if( xx.v1+xx.v2 <= A ){
			xx.v1 = xx.v1 + xx.v2;
			xx.v2 = 0;
		}
		else{
			xx.v2 = xx.v1 + xx.v2 - A;
			xx.v1 = A;
		}
	}
	if( a == 6 ){
		if( xx.v1+xx.v2 <= B ){
			xx.v2 = xx.v1 + xx.v2;
			xx.v1 = 0;
		}
		else{
			xx.v1 = xx.v1 + xx.v2 - B;
			xx.v2 = B;
		}
	}	
}

bool BFS()
{
	left = 0 ; right = 1;
	while( left < right ){
		x = pos[left++];
		/*out(x.v1);
		  out(x.v2);
		  out(x.s);
		  out(x.change);
		  out(left);
		  out(right);*/
		/*if( ann[x.v1][x.v2] && left != 1 ){
		  return false;
		  }*/
		ann[x.v1][x.v2] = true;
		for( int i = 1 ; i < 7 ; i ++ ){
			xx = x;
			Change(i);
			if( xx.v1 == C || xx.v2 == C ){
				ans = x.step + 1;
				yy = i;
				return true;
			}
			if( !ann[xx.v1][xx.v2] ){
				pos[right].v1 = xx.v1;
				pos[right].v2 = xx.v2;
				pos[right].s = left - 1;
				pos[right].change = i;
				pos[right++].step = xx.step + 1;
				ann[xx.v1][xx.v2] = true;
			}
		}	
	}	
	return false;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//while( cin>>A>>B>>C ){
		//if( A == -2 )
		//	break;
		cin >> A >> B >> C;
		memset( ann , false , sizeof(ann) );
		ann[0][0] = true;
		pos[0].v1 = 0 ; pos[0].v2 = 0 ; pos[0].step = 0 ; pos[0].change = -1 ; pos[0].s = -1 ;
		if( !BFS() )
			printf( "impossible\n" );
		else{
			printf( "%d\n" , ans );
			left --;
			int bn[2000000];	
			int all = 0;
			bn[all++] = yy;
			while(1){
				bn[all++] = pos[left].change;
				left = pos[left].s;
				if( left <= 0 )
					break;
			}
			for( int i = all-1 ; i >= 0 ; i -- )
				Data_output(bn[i]);
		}
//	}
	return 0;
}
