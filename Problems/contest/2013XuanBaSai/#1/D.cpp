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
const int N = 50005;

int an[N];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	while( scanf( "%d" , &n ) != EOF ){
		int ans_ma , ans_idx;
		for( int i = 0 ; i < n ; i ++ ){
			scanf( "%d" , &an[i] );
			an[i] -= i;
		}	
		sort(an,an+n);
		/*for( int i = 0 ; i < n ; i ++ ){
			printf( "%d " , an[i] );
		}*/
		int ma = 1 , idx = an[0] ; 
		ans_ma  = 1 ; ans_idx = an[0];
		for(int i = 1 ; i < n ; i ++ ){
			if( idx == an[i] ){
				ma ++;
			}
			else{
				if( ma > ans_ma ){
					ans_idx = idx;
					ans_ma = ma;
				}
				idx = an[i];
				ma = 1;
			}
		}
		if( ma > ans_ma ){
			ans_idx = idx;
			ans_ma = ma;
		}
		//out(ans_ma);
		//out(ans_idx);
		printf( "%d\n" , n - ans_ma );
		printf( "%d" , ans_idx ++ );
		for( int i = 1 ; i < n ; i ++ ){
			printf( " %d" , ans_idx ++ );
		}
		printf( "\n" );
	}
	return 0;
}
