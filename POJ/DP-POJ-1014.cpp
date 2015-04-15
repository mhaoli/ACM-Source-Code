//by iforgot
#include <iostream>
#include <cstdio>
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
int pri[120005],a,all,sum,v;
bool dp[60005];

void ZeroOnePack()
{
	memset( dp , false , sizeof(dp) );
	dp[0] = true;
	for( int i = 1 ; i < all ; i ++ ){
		for( int j = v ; j >= pri[i] ; j -- ){
			dp[j] = dp[j] || dp[j-pri[i]];
		}
		/*out(i);
		for( int k = 0 ; k <= v ; k ++ ){
			printf( "%d " , dp[k] );
		}
		cout << endl;*/	
	}
}

void Change( int b )
{
	int x = 0, xx = 1;
	while( 1 ){
		if( xx <= a )
			x ++;
		else
			break;
		xx <<= 1;
	}
	x --;
	if( x < 0 )
		x = 0;
	for( int i = 0 ; i < x ; i ++ ){
		pri[all++] = b * pow(2,i);
	}
	pri[all++] = b * ( a - (int)pow(2,x) + 1 );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int aa[7] , cas = 0;
	while( cin>>aa[1]>>aa[2]>>aa[3]>>aa[4]>>aa[5]>>aa[6] ){
		if( !aa[1] && !aa[2] && !aa[3] && !aa[4] && !aa[5] && !aa[6] )
			break;
		all = 1;
		sum = 0;
		for( int i = 1 ; i < 7 ; i ++ ){
			a = aa[i];
			if( a )
				Change(i);
			sum += i*aa[i];
		}
		v = sum / 2;
		if( cas != 0 )
			cout << endl;
		cout << "Collection #" << ++cas << ":" << endl;
		if( sum%2 != 0 ){
			cout << "Can't be divided." << endl;
			continue;	
		}
		ZeroOnePack();
		if( dp[v] )
			cout << "Can be divided." << endl;
		else
			cout << "Can't be divided." << endl;
	}
	return 0;
}
