//by plum rain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <ctime>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define rep(i, n) for(long long i = 0; i < (n); i ++)
#define repf(i, a, b) for(long long i = (a); i <= (b); i ++)
#define repd(i, a, b) for(long long i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
#define out(x) cout<<#x<<':'<<(x)<<endl
#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 200005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int an[N];
bool hash[N];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf( "%d" , &T);
	while( T -- ){
		int n;
		scanf( "%d" , &n );
		memset( hash , true , sizeof(hash) );
		int num , flag;
		repf( i , 1 , n ){
			scanf( "%d" , &an[i] );	
			if( an[i] == -1 ){
				hash[i] = false;
				num = 1;
				flag = i;
				while( num > 0 ){
					flag --;
					if( flag == i )
						break;
					if( flag == 0 )
						flag = n;
					if( an[flag] == -1 )
						num ++;
					else{
						hash[flag] = false;
						num --;
					}
				}
			}	
		}
		int ans = 0;
		repf( i , 1 , n ){
			if( hash[i] )
				ans ++;
		}
		printf( "%d\n" , ans ); 
	}	
	return 0;
}
