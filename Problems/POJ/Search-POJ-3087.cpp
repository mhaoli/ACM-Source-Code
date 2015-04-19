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

class SE{
	public:
		char ann[105],bnn[105];
		int step;
};

SE pos[205],s,e;
char ee[205];
int n;

bool Judge( int a , int x )
{
	if( x == 1 ){
		for( int i = 0 ; i < n ; i ++ ){
			if( pos[a].ann[i] != e.ann[i] || pos[a].bnn[i] != e.bnn[i] )
				return false;
		}	
	}
	if( x == 2 ){
		for( int i = 0 ; i < n ; i ++ ){
			if( pos[a].ann[i] != pos[0].ann[i] || pos[a].bnn[i] != pos[0].bnn[i] )
				return false;
		}
	}
	return true;
}


void BFS()
{
	pos[0] = s;
	int left = 0 , right = 1;
	while( left < right ){
		if( Judge(left,1) && left != 0 ){
			printf( "%d\n" , pos[left].step );
			return ;
		}
		if( Judge(left,2) && left != 0 ){
			printf( "-1\n" );
			return ;
		}
		SE x = pos[left++];
		for( int i = 0 ; i < 2*n ; i ++ ){
			if( i <= n-1 ){
				if( i%2 == 0 )
					pos[right].ann[i] = x.bnn[i/2];
				else
					pos[right].ann[i] = x.ann[i/2];
			}
			else{
				if( i%2 == 0 )
					pos[right].bnn[i-n] = x.bnn[i/2];
				else
					pos[right].bnn[i-n] = x.ann[i/2];
			}
		}
		pos[right++].step = x.step + 1;
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int t , cas = 0;
	cin >> t;
	while( t -- ){
		cin >> n;
		cin >> s.ann >> s.bnn;
		cin >> ee;
		for( int i = 0 ; i < n ; i ++ )
			e.ann[i] = ee[i];
		for( int i = 0 ; i < n ; i ++ )
			e.bnn[i] = ee[i+n];
		s.step = 0;
		printf( "%d " , ++cas );
		BFS();	
	}	
	return 0;
}
