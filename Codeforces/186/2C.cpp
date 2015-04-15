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

int an[2000005];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	scanf( "%d" , &n );
	for( int i = 0 ; i < n ; i ++ )
		scanf( "%d" , &an[i] );
	sort( an , an + n );
	int x = ( log10(n+0.0) / log10(4+0.0) ); 
	int64 sum = 0;
	for( int i = 1 ; i <= n ; i *= 4 ){
		int a = n , b = 0;
		while( b < i ){
			sum += an[--a];
			b ++;
		}
	}
	cout << sum << endl;
	return 0;
}
