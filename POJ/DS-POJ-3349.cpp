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
const int maxx = 100005;
const int prime = 99991;

vector<int64> hash[prime+1];

class HashTable{
	public:
		int64 an[6];
}pos[maxx];

bool Snow_same( HashTable x , HashTable y )
{
	for( int i = 0 ; i < 6 ; i ++ )
		if( x.an[i] != y.an[i] )
			return false;
	return true;
}

bool If_same( int x , int key )
{
	/*if( hash[key].size() == 0 ){
		hash[key].push_back(x);
		return false;
	}
	else{*/
		for( int i = 0 ; i < hash[key].size() ; i ++ ){
			int temp = hash[key][i];
			int cnt = 0;
			while( cnt < 6 ){
				HashTable current1, current2;
				for( int i = 0 ; i < 6 ; i ++ ){
					current1.an[i] = pos[x].an[(i+6-cnt)%6];
					current2.an[i] = pos[x].an[(11-i-cnt)%6];
				}
				if( Snow_same(current1, pos[temp]) || Snow_same(current2, pos[temp]) )
					return true;
				cnt++;
			}
		}
		hash[key].push_back(x);
		return false;
	//}
}

int main()
{
	//freopen("a.in","r",stdin);
	//for( int i = 1 ; i <= prime+1 ; i ++ )
	//	hash[i].clear();
	int n;
	scanf( "%d" , &n );
	bool ans = false;
	for(int i = 0 ; i < n ; i ++ ){
		int key = 0;
		for( int j = 0 ; j < 6 ; j ++ ){
			scanf( "%lld" , &pos[i+1].an[j] );
			key += pos[i+1].an[j];
			key %= prime;
		}
		key++;
		if( !ans )
			ans = If_same(i+1,key);
	}	
	if( ans )
		printf( "Twin snowflakes found.\n" );
	else
		printf( "No two snowflakes are alike.\n" );
	return 0;
}
