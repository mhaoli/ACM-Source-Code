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
int mod[524286];

int main()
{
	//freopen("a.in","r",stdin);
	int n;
	while( cin>>n ){
		if( n == 0 )
			break;
		mod[1] = 1;
		int ans;
		for( int i = 2 ; ; i ++ ){
			mod[i] = (mod[i/2]*10 + i%2) % n;
			if( mod[i] == 0 ){
				ans = i;
				break;
			}
		}
		int cnt = 0 , an[205];
		while( ans > 0 ){	
			an[cnt++] = ans%2;
			ans = ans >> 1;
		}
		while(cnt)
			printf( "%d" , an[--cnt] );
		printf( "\n" );
	}
	return 0;
}
