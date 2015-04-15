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
const int C = 1000;

int n,t;
int Ln[25] , Lnn[25] , Vn[25] , Vnn[25] , pos[25] , dev[25]; 
int all1 , all2;
int ans[25] , anss[25];

int Meet( int d , int v )
{
	int ans = 0 , s = v * t;
	if( d < 0 ){
		d = C + d;
	}
	while( s >= d ){
		ans ++;
		d += C;
	}
	return ans;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf( "%d%d" , &n , &t );
	all1 = 0;
	all2 = 0;
	int ln[25] , vn[25];
	for( int i = 0 ; i < n ; i ++ ){
		scanf( "%d" , &ln[i] );
	}
	for( int i = 0 ; i < n ; i ++ ){
		scanf( "%d" , &vn[i] );
	}
	for( int i = 0 ; i < n ; i ++ ){
		int l = ln[i] , v = vn[i];
		if( v > 0 ){
			dev[i] = 1;
			pos[i] = all1;
			Ln[all1] = l;
			Vn[all1++] = v;
		}
		else{
			dev[i] = -1;
			pos[i] = all2;
			Lnn[all2] = l;
			Vnn[all2++] = 0 - v; 
		}
	}
	memset( ans , 0 , sizeof(ans) );
	memset( anss , 0 , sizeof(anss) );
	for( int i = 0 ; i < all1 ; i ++ ){
		for( int j = 0 ; j < all2 ; j ++ ){
			int d = Lnn[j] - Ln[i] , v = Vn[i] + Vnn[j];
			int a = Meet(d,v);
			ans[i] += a;
			anss[j] += a;
		}
	}
	if( dev[0] == 1 ){
		printf( "%d" , ans[pos[0]] );
	}
	else{
		printf( "%d" , anss[pos[0]] );
	}
	for( int i = 1 ; i < n ; i ++ ){
		if( dev[i] == 1 )
			printf( " %d" , ans[pos[i]] );
		else
			printf( " %d" , anss[pos[i]] );
	}	
	return 0;
}
