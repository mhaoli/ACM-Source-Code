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
const int mod = 200000;

class SE{
	public:
		int f;
		int whi;
		char ann[105];
		int time;
}pos[200005];

int BFS()
{
	int left = 0 , right = 1;
	while( !(left == right) ){
		SE x = pos[left];
		left = (left+1) % mod;
		if( x.time >= 10 )
			return -1;
		int a = 0 , num_whi = 0 , len = strlen(x.ann); 
		while( a < len ){
			if( x.ann[a] == 'W' )
				num_whi ++;
			if( x.ann[a] == 'B' )
				break;
			a ++;
		}
		a = len - 1;
		while( a >= 0 ){
			if( x.ann[a] == 'W' )
				num_whi ++;
			if( x.ann[a] == 'B' )
				break;
			a --;
		}
		if( num_whi >= x.whi ){
			return x.time;
		}
		x.time ++;
		SE y = x;
		if( y.f > 0 ){
			y.ann[y.f] = y.ann[y.f-1];
			y.ann[y.f-1] = 'F';
			y.f -= 1;
			pos[right] = y;
			right = (right+1) % mod;
		}
		y = x;
		if( y.f < len-1 ){
			y.ann[y.f] = y.ann[y.f+1];
			y.ann[y.f+1] = 'F';
			y.f += 1;
			pos[right] = y;
			right = (right + 1 ) % mod;
		}
		y = x;
		if( y.f > 1 ){
			if( y.ann[y.f-2] == 'W' ){
				y.whi --;
				y.ann[y.f] = 'B';
			}
			else{
				y.whi ++;
				y.ann[y.f] = 'W';
			}
			y.ann[y.f-2] = 'F';
			y.f -= 2;
			pos[right] = y;
			right = (right+1) % mod;
		}
		y = x;
		if( y.f < len-2 ){
			if( y.ann[y.f+2] == 'W' ){
				y.ann[y.f] = 'B';
				y.whi --;
			}
			else{
				y.ann[y.f] = 'W';
				y.whi ++;
			}
			y.ann[y.f+2] = 'F';
			y.f += 2;
			pos[right] = y;
			right = (right + 1) % mod;
		}
	}
	return -1;
}

int main()
{
    //freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int test = 0;
	while( cin >> pos[0].ann ){
		if( pos[0].ann[0] == '-' )
			break;
		pos[0].time = 0;
		pos[0].whi = 0;
		int len = strlen(pos[0].ann);
		for( int i = 0 ; i < len ; i ++ ){
			if( pos[0].ann[i] == 'W' )
				pos[0].whi ++;
			if( pos[0].ann[i] == 'F' )
				pos[0].f = i;
		}
		int ans = BFS();
		printf( "%d. %d\n" , ++ test , ans );
	}
    return 0;
}
