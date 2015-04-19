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
typedef unsigned long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

string gn[55][55][55];
string nn,kk;

int Int( string a )
{
	int len = a.length();
	int ret = 0;
	rep( i , len ){
		ret = ret * 10 + a[i] - '0';
	}
	return ret;
}

void cler( string &a )
{
	while( a.length() > 0 && a[0] == '0' )
		a.erase(0,1);
	if( a == "" )
		a = "0";
}

string Add( string a , string b )
{
	while( a.length() < b.length() )
		a = '0' + a;
	while( a.length() > b.length() )
		b = '0' + b;
	a = '0' + a;
	b = '0' + b;
	for( int i = a.length()-1 ; i >= 0 ; i -- ){
		a[i] = a[i] + b[i] - '0';
		if( a[i] > '9' ){
			a[i] = a[i] - 10;
			a[i-1] += 1;
		}
	}
	cler(a);
	return a;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	rep( i , 51 )
		rep( j , 51 )
			rep( k , 51 )
				gn[i][j][k].clear();
	gn[0][2][2] = "0" ; gn[0][2][1] = "0" ; gn[1][2][1] = "1" ; gn[1][2][2] = "0";
	gn[2][2][1] = "0" ; gn[2][2][2] = "1";
	repf( n , 3 , 51 ){
		rep( x , 51 ){
			rep( k , 51 ){
				if( k > n || x > k ){
					gn[x][n][k] = "0";
					continue;
				}
				if( !x || !k ){
					gn[x][n][k] = "0";
					continue;
				}
				if( k == 1 ){
					if( x != 1 )
						gn[x][n][k] = "0";
					else
						gn[x][n][k] = "1";
					continue;
				}
				if( k == n ){
					if( x == k )
						gn[x][n][k] = "1";
					else
						gn[x][n][k] = "0";
					continue;
				}
				if( x == k ){
					gn[x][n][k] = Add( gn[x-1][n-1][k-1] , gn[x-1][n-1][k] );
					gn[x][n][k] = Add( gn[x][n][k] , gn[x][n-1][k] );
				}
				else{
					gn[x][n][k] = "0";
					repf( i , x-1 , min(k,n-1) ){
						gn[x][n][k] = Add( gn[x][n][k] , gn[i][n-1][k] );
					}
				}
			}
		}
	}
	/*rep( i , 51 ){
		cout << "i:" << i << endl;
		int yy = i;
		string ans = "0";
		repf( j , 1 , yy )
			ans = Add( ans , gn[j][50][yy] );
		//printf( "%lld\n" , ans );
		cout << ans << endl;
	}*/
	//bool blank = false;
	int T = 0;
	while( cin >> nn >> kk  && !( nn == "0" && kk == "0" )){
		if( T )
			printf( "\n" );
		printf( "Case %d: " , ++ T ); 
		if( nn == "1" && kk == "1" ){
			printf( "1\n" );
			continue;
		}
		int intn = Int(nn) , intk = Int(kk);
		string ans = "0";
		repf( i , 1 , intk )
			ans = Add( ans , gn[i][intn][intk] );
		//printf( "%lld\n" , ans );
		cout << ans << endl;
	}
	return 0;
}
