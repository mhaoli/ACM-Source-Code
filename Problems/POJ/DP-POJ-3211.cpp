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
int m,n;
char ann[15][15];
int dp[100005];

class cloth{
	public:
		int time[105];
		int all ;
}clo[15];

int ZeroOnePack( int x )
{
	memset(dp,0,sizeof(dp));
	int sum = 0;
	for( int i = 0 ; i < clo[x].all ; i ++ )
		sum += clo[x].time[i];
	int v = sum / 2;
	for( int i = 0 ; i < clo[x].all ; i ++ )
		for( int j = v ; j >= 0 ; j -- ){
			if( j+clo[x].time[i] <= v )
				dp[(int)(j+clo[x].time[i])] = max( dp[j]+clo[x].time[i] , dp[(int)(j+clo[x].time[i])] );
		}
	int ans = 0;
	for( int i = v ; i >= 0 ; i -- )
		ans = max( dp[i] , ans );
	return sum - ans;
}

int main()
{
	//freopen("a.in","r",stdin);
	while( cin>>m>>n ){
		if( m == 0 && n == 0 )
			break;
		memset(ann,0,sizeof(ann));
		for( int i = 0 ; i < 15 ; i ++ )
			clo[i].all = 0;
		for( int i = 0 ; i < m ; i ++ )
			cin>>ann[i];
		int tim;
		char xxx[15];
		for( int i = 0 ; i < n ; i ++ ){
			cin>>tim>>xxx;
			for( int j = 0 ; j < m ; j ++ )
				if( strcmp(ann[j],xxx) == 0 )
					clo[j].time[clo[j].all ++] = tim;
		}
		int ans = 0;
		for( int i = 0 ; i < m ; i ++ )
			ans += ZeroOnePack(i);
		cout<<ans<<endl;
	}
	return 0;
}
