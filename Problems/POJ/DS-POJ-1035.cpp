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

class word{
	public:
		int len;
		char ann[20];
}words[10005];

int all;
char xx[10005][20] , bn[20];
int num;

bool Similiar3( int a )
{
	bool x;
	for( int i = 0 ; i < words[a].len+1 ; i ++ ){
		x = true;
		for( int j = 0 ; j < i ; j ++ )
			if( bn[j] != words[a].ann[j] )
				x = false;
		for( int j = i+1 ; j < words[a].len+1 ; j ++ )
			if( bn[j] != words[a].ann[j-1] )
				x = false;
		if( x )
			return true;
	}
	return false;
}

bool Similiar2( int a )
{
	bool x;
	for( int i = 0 ; i < words[a].len ; i ++ ){
		x = true;
		for( int j = 0 ; j < i ; j ++ ){
			if( bn[j] != words[a].ann[j] )
				x = false;	
		}
		for( int j = 1+i ; j < words[a].len ; j ++ ){
			if( bn[j-1] != words[a].ann[j] )
				x = false;	
		}
		if( x )
			return true;
	}	
	return false;
}

bool Similiar1( int a )
{
	bool x = true;
	for( int i = 0 ; i < words[a].len ; i ++ ){
		if( bn[i] != words[a].ann[i] ){
			if( !x )
				return false;
			else
				x = false;
		}
	}
	return true;
}

bool Is_correct( int a )
{
	for( int i = 0 ; i < words[a].len ; i ++ )
		if( bn[i] != words[a].ann[i] )
			return false;
	return true;	
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	all = 0;
	while( cin >> words[all].ann && words[all].ann[0] != '#' ){
		words[all].len = strlen(words[all].ann);
		all ++;
	}
	/*for( int i = 0 ; i < all ; i ++ ){
	  puts(words[i].ann);
	  out(words[i].len);
	  }*/
	while( cin >> bn && bn[0] != '#' ){
		memset( xx , 0 , sizeof(xx) );
		num = 0;
		bool ans = false;
		int len = strlen(bn);
		for( int i = 0 ; i < all ; i ++ ){
			if( len == words[i].len ){
				if( Is_correct(i) ){
					ans = true;
					break;
				}
				else if( Similiar1(i) ){
					for( int j = 0 ; j < len ; j ++ )
						xx[num][j] = words[i].ann[j];
					num ++;
				}
			}
			if( len+1 == words[i].len ){
				if( Similiar2(i) ){
					for( int j = 0 ; j < words[i].len ; j ++ )
						xx[num][j] = words[i].ann[j];
					num ++;
				}
			}
			if( len-1 == words[i].len ){
				if( Similiar3(i) ){
					for( int j = 0 ; j < words[i].len ; j ++ )
						xx[num][j] = words[i].ann[j];
					num ++;
				}
			}
		}
		for( int i = 0 ; i < len ; i ++ )
			printf( "%c" , bn[i] );
		if( ans ){
			printf( " is correct\n" );
		}
		else{
			printf( ":" );
			for( int i = 0 ; i < num ; i ++ ){
				printf( " " );
				for( int j = 0 ; j < strlen(xx[i]) ; j ++ )
					printf( "%c" , xx[i][j] );
			}
			printf( "\n" ); 
		}
	}
	return 0;
}
