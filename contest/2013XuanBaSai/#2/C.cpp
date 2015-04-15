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
const int N = 500005;
int all,an[N],bn[N];
int all2,cn[N],dn[N];

void inte_devide( int x ){
	all = -1;
	for( int i = 2 ; i*i <= x ; ){
		if( !(x%i) ){
			an[++all] = i;
			bn[all] = 0;
		}
		//out(all);
		//out(i);
		//out(x);
		while( !(x%i) ){
			bn[all] ++;
			x /= i;
		}
		//out(x);
		if( i == 2 )
			i ++;
		else
			i += 2;
	}
	all ++;
	if( x != 1 ){
		an[all] = x;
		bn[all ++] = 1;
	}	
}

int main()
{
	//freopen("a.in","r",stdin);
	int a,b;
	int test = 0;
	while( scanf( "%d%d" , &a , &b ) != EOF ){
		if( !a && !b )
			break;
		inte_devide(a);
		all2 = all;
		for( int i = 0 ; i < all2 ; i ++ ){
			cn[i] = an[i];
			dn[i] = bn[i];
		}	
		inte_devide(b);
		/*for( int i = 0 ; i < all2 ; i ++ ){
			printf( "%d %d" , cn[i] , dn[i] );
			printf( "\n" );
		}
		tst(a);
		for( int i = 0 ; i < all ; i ++ ){
			printf( "%d %d" , an[i] , bn[i] );
			printf( "\n" );
		}*/
		int a1 = 0 , a2 = 0 , ans = 0 , xxx = 0;
		while( a2 < all2 || a1 < all ){
			if( a2 >= all2 ){
				ans += bn[a1];
				a1 ++;
				xxx ++;
			}
			else if( a1 >= all ){
				ans += dn[a2];
				a2 ++;
				xxx ++;
			}
			else{
				if( cn[a2] == an[a1] ){
					ans += abs(dn[a2] - bn[a1]);
					a2 ++;
					a1 ++;
					xxx ++;
				}
				else if( cn[a2] > an[a1] ){
					ans += bn[a1];
					a1 ++;
					xxx ++;
				}
				else{
					ans += dn[a2];
					a2 ++;
					xxx ++;
				}
			}
		}
		printf("%d. %d:%d\n" , ++ test , xxx , ans );
	}
	return 0;
}
