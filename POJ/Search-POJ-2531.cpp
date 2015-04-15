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
int an[21][21];
int n;
bool bn[21];
int all;
int cn[21],dn[21];
int cn_num,dn_num;

int Fn()
{
	int ans = 0;
	for( int i = 1 ; i < cn_num ; i ++ )
		for( int j = 1 ; j < dn_num ; j ++ ){
			ans += an[cn[i]][dn[j]];
		}	
	return ans;
}

void Bn_change( int x )
{
	all = 0;
	while( x > 0 ){
		bn[all++] = x & 1;
		x = x >> 1;
	}
	cn_num = 1 ; dn_num = 1 ; 
	for( int i = 1 ; i <= n ; i ++ ){
		if( bn[i] )
			cn[cn_num++] = i;
		else
			dn[dn_num++] = i;
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	while( cin >> n ){
		for( int i = 1 ; i <= n ; i ++ )
			for( int j = 1 ; j <= n ; j ++ )
				cin >> an[i][j];
		int	ans = 0;
		for( int i = 1 ; i < 1<<n ; i ++ ){
			memset( bn , false , sizeof(bn) );
			Bn_change(i);
			ans = max( ans , Fn() );
		}
		cout << ans << endl;
	}
	return 0;
}
