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
const int N = 130005;

int an[N];

int main()
{
    //freopen("a.in","r",stdin);
	int n , m;
	scanf( "%d%d" , &n , &m );
	for( int i = 1 ; i <= n ; i ++ ){
		an[i] = i;
	}
	for( int i =0 ; i < m ; i ++ ){
		int l,r;
		scanf( "%d%d" , &l, &r );
		while( l < r ){
			int t = an[l];
			an[l] = an[r];
			an[r] = t;
			l ++;
			r --;
		}
	}
	printf( "%d" , an[1] );
	for( int i = 2 ; i < n ; i ++ ){
		printf( " %d" , an[i] );
	}
	printf( "\n" );
    return 0;
}
