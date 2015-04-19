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

char ann[105];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int t;
	scanf( "%d" , &t );
	while( t-- ){
		memset( ann , 0 , sizeof(ann) );
		gets(ann);
		while(!((ann[0] >= 'a' && ann[0] <= 'z') || (ann[0] >= 'A' && ann[0] <= 'Z') || ann[0] == '_' || ann[0] == ',' || ann[0] == '.' || ann[0] == ' ' ))
			gets(ann);
		//puts(ann);
		int ans = 0 , len = strlen(ann);
		if( len >= 5 ){
			if( ann[0] == 'm' && ann[1] == 'i' && ann[2] =='a' && ann[3] == 'o' && ann[4] == '.' )
				ans += 1;
			if( ann[len-1] == '.' && ann[len-2] == 'a' && ann[len-3] == 'l' && ann[len-4] == 'a' && ann[len-5] == 'l' )
				ans += 2;
		}
		//out(ans);
		if( ans == 0 || ans == 3 )
			printf( "OMG>.< I don't know!\n" );
		if( ans == 1 )
			printf( "Rainbow's\n" );
		if( ans == 2 )
			printf( "Freda's\n" );	
	}	
	return 0;
}
