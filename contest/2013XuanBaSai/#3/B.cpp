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

int main()
{
    //freopen("a.in","r",stdin);
	int a[7] , x = 1;
	while( x < 7 ){
		scanf( "%d" , &a[x++] );
	}
	int ans = 100000;
	for( int i = 1 ; i < 4 ; i ++ ){
		int m = a[i] / a[i+3];
		ans = min(ans,m);
	}
	printf("%d\n" , ans );
    return 0;
}
