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
int n,ans,anss;

class SE{
	public:
		int s;
		int e[27];
		int all;
}pos[27];

void DFS( int a )
{
	//char x = a + 'A' - 1;
	if( a == n+1 ){
		/*ans = 0;
		  for( int i = 1 ; i <= n ; i ++ )
		  ans = max(ans,pos[i].s);*/
		anss = min(anss,ans);
		return ;
	}
	bool an[27];
	memset( an , false , sizeof(an) );
	for( int j = 1 ; j <= pos[a].all ; j ++ )
		an[pos[pos[a].e[j]].s] = true;
	for( int i = 1 ; i <= ans ; i ++ ){
		if( !an[i] ){
			pos[a].s = i;
			DFS( a+1 );
			pos[a].s = 0;
		}
	}
	ans ++;
	pos[a].s = ans;
	DFS( a+1 );
	pos[a].s = 0;
	ans --;
	return ;
}

int main()
{
	//freopen("a.in","r",stdin);
	while( cin >> n ){
		if( !n )
			break;
		for( int i = 1 ; i < 27 ; i ++ )
			pos[i].s = 0;
		char xx[30];
		for( int i = 1 ; i <= n ; i ++ ){
			cin >> xx;
			int len = strlen(xx);
			pos[i].all = len - 2;
			for( int j = 2 ; j < len ; j ++ )
				pos[i].e[j-1] = xx[j] - 'A' + 1;
		}
		ans = 0;
		anss = maxint;
		DFS(1);
		if( anss == 1 )
			cout << "1 channel needed." << endl;
		else
			cout << anss << " channels needed." << endl;
	}		
	return 0;
}



