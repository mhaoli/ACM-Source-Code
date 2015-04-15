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
const int N = 105;

int an[N];

int main()
{
    //freopen("a.in","r",stdin);
	int n;
   	scanf( "%d" , &n );
	for(int i = 0 ; i < n ; i ++ )
		scanf( "%d" , &an[i] );
	sort( an , an + n );
	int num = n , pos = 0 , ans = 0;
	while( num > 1 ){
		int x = an[pos];
		while( x > 1 ){
			num --;
			ans ++;
			x --;
			if( num == 1 )
				break;
		}
		if( x == 1 ){
			if( num == 2 ){
				num --;
				ans ++;
			}
			if( num > 2 ){
				num -= 2;
				ans ++;
			}
		}
	}
	printf( "%d\n" , ans );
    return 0;
}
