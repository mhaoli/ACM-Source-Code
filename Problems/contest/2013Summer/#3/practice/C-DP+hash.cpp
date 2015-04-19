//by PlumRain
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define CLR(x) memset(x, 0, sizeof(x))
#define PB push_back
#define SZ(v) ((int)(v).size())
#define rep(i, n) for(long long i = 0; i < (n); i ++)
#define repf(i, a, b) for(long long i = (a); i <= (b); i ++)
#define repd(i, a, b) for(long long i = (a); i >= (b); i --)
#define out(x) cout<<#x<<':'<<x<<endl
#define tst(a) cout<<#a<<endl

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;


const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 3005;
const int mod = 499997;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int an[N];
short int dp[N][N];
int ans[N];
int anx , ansi , ansj;
int HashTable[mod+2][2];

short int maxs( short int a , short int b )
{
	if( a > b )
		return a;
	return b;
}

int Hash( int x )
{
	int ret = x % mod;
	if( ret < 0 )
		ret += mod;
	while( 1 ){
		if( !HashTable[ret][1] ) return ret;
		if( HashTable[ret][1] && HashTable[ret][0] == x ) return ret;
		ret ++;
		if( ret == mod ) ret = 0;
	}
}

void DP( int n )
{
	anx = 1 ; ansi = -1 ; ansj = -1;
	repf( i , 1 , n ){
		repf( j , 1 , i )
			dp[i][j] = 1;
		repf( j , i+1 , n )
			dp[i][j] = 2;
	}
	CLR(HashTable);
	repf( i , 1 , n-1 ){
		if( i > 1 ){
			int a = Hash(an[i-1]);
			HashTable[a][0] = an[i-1];
			HashTable[a][1] = i-1;
		}
		repf( j , i+1 , n ){
			int x = an[j] - an[i];
			int a = Hash(x);
			if( HashTable[a][1] && HashTable[a][0] == x ){
				int flag = HashTable[a][1];
				dp[i][j] = maxs( dp[flag][i] + 1 , dp[i][j] );
			}
			else
				dp[i][j] = 2;
			if( anx < dp[i][j] ){
				anx = dp[i][j];
				ansi = i;
				ansj = j;
			}
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	bool blank = false;
	while( scanf( "%d" , &n ) != EOF ){
		if( blank )
			printf( "\n" );
		else
			blank = true;
		repf( i , 1 , n )
			scanf( "%d" , &an[i] );
		if( n == 1 ){
			printf( "1\n" );
			printf( "%d\n" , an[1] );
			continue;
		}
		DP(n);
		if( anx <= 2 ){
			printf( "2\n" );
			printf( "%d %d\n" , an[1] , an[2] );
		}
		else{
			printf( "%d\n" , anx );
			int len = anx;
			ans[len--] = an[ansj];
			ans[len--] = an[ansi];
			while( len > 0 )
				ans[len--] = ans[len+2] - ans[len+1];
			printf( "%d" , ans[1] );
			repf( i , 2 , anx ){
				printf( " %d" , ans[i] );
			}
			printf( "\n" );
		}	
	}
	return 0;
}
