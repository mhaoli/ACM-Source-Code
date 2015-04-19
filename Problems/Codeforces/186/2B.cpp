//by iforgot
#include <iostream>
#include <cstdio>
#include <cstdlib>
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

int an[100005];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	string s;
	while( cin >> s ){
		memset( an , 0 , sizeof(an) );
		int len = s.size();
		char x = s[0] , num = 0;
		for( int i = 1 ; i < len ; i ++ ){
			if( x == s[i] ){
				if( i > 1 )
					an[i-1] = an[i-2] + 1;
				else
					an[i-1] = 1;
			}
			else{
				if( i > 1 )
					an[i-1] = an[i-2];
				else
					an[i-1] = 0;
				x = s[i];
			}
		}
		if( len > 1 )
			an[len-1] = an[len-2];
		else
			an[0] = 0;
		int m;
		scanf( "%d" , &m );
		for( int i = 0 ; i < m ; i ++ ){
			int x,y;
			scanf( "%d%d" , &x , &y );
			if( x > 1 )
				printf( "%d\n" , an[y-2] - an[x-2] );
			else
				printf( "%d\n" , an[y-2] );
		}
	}
	return 0;
}
