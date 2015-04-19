//by PlumRain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

using namespace std;

typedef vector<int> VI;  
typedef vector<string> VS;  
typedef vector<double> VD;  
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 10005;
const int M = 100005;

int an[2*M];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int test;
	scanf( "%d" , &test );
	int ma = test;
	while( test -- ){
		int n,m;
		scanf( "%d%d" , &n , &m );
		int pos = 0;
		for( int i = 0 ; i < m ; i ++ ){
			scanf( "%d" , &an[pos++] );
				scanf( "%d" , &an[pos++] );
		}
		sort(an,an+pos);
		int cnt = 1 , ans = 0 , flag = an[0];
		for( int i = 1 ; i < pos ; i ++ ){
			if( flag == an[i] )
				cnt ++;
			else{
				ans += cnt * cnt;
				cnt = 1;
				flag = an[i];
			}
		}
		ans += cnt * cnt;
		if( test != ( ma-1 ) )
			printf( "\n" );
		printf( "%d\n" , ans );
	}
	return 0;
}
