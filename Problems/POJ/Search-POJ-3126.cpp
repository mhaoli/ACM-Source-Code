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
int ans,prime[9005],all;
int e;
bool if_prime[10000],visited[10000];

class SE{
public:
	int s; 
	int time;
}pos[9005];

void If_prime()
{
	all = 1;
	prime[all++] = 2;
	if_prime[2] = 1;
	for( int i = 3 ; i < 9999 ; i += 2 ){
		bool if_pri = true;
		for( int j = 1 ; prime[j]*prime[j] <= i ; j ++ ){
			if( i%prime[j] == 0 ){
				if_pri = false;
				break;
			}
		}
		if( if_pri ){
			prime[all++] = i;
			if_prime[i] = true;
		}
	}
}

bool BFS()
{
	int left = 0,right = 1;
	if( pos[left].s == e ){
		ans = 0;
		return true;
	}
	while( left < right ){
		int xx,xxtime;
		xxtime = pos[left].time;
		xx = pos[left++].s;
		if( xx == e ){
			ans = xxtime;
			return true;
		}
		for( int i = 0 ; i < 4 ; i ++ ){
			for( int j = 0 ; j < 10 ; j ++ ){
				int yy = 0;
				int xn[4],xi = 0,xxx = xx;
				while( xi < 4 ){
					xn[xi++] = xxx % 10;
					xxx /= 10;	
				}
				for( int k = 0 ; k < 4 ; k ++ ){
					if( k == i )
						yy += j*pow(10,i);
					else
						yy += xn[k] * pow(10,k);
				}
				/*if( yy == e ){
					ans = xxtime + 1;
					return true;
				}*/
				if( if_prime[yy] && !visited[yy] ){
					//out(i);
					//out(j);
					//out(yy);
					pos[right].s = yy;
					pos[right++].time = xxtime + 1;
					visited[yy] = true;	
					//out(pos[right-1].time);
				}
					
			}
		}
	}
	return false;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	memset(if_prime,false,sizeof(if_prime));
	If_prime();
	/*for( int i = 1 ; i <= 30 ; i ++ ){
		out(i);
		out(prime[i]);
		out(if_prime[i]);
	}*/
	int t;
	scanf( "%d" , &t );
	while( t -- ){
		memset(visited,false,sizeof(visited));
		cin>>pos[0].s>>e;
		visited[pos[0].s] = true;
		pos[0].time = 0;
		if( BFS() )
			cout<<ans<<endl;
		else
			cout<<"Impossible"<<endl;
	}	
	return 0;
}
