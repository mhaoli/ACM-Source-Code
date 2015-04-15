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

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

inline void clear( string &a )
{
	while( a.length() > 0 && a[0] == '0' )
		a.erase(0,1);
	if( a == "" )
		a = "0";
}

bool isBigger( string a , string b )
{
	clear(a);
	clear(b);
	if( a.length() > b.length() )
		return true;
	if( a.length() == b.length() && a >= b )
		return true;
	return false;
}

string stringSubString( string a , string b )
{
	bool aBigger = true;
	while( a.length() < b.length() )
		a = '0' + a;
	while( a.length() > b.length() )
		b = '0' + b;
	if( a < b )
	{
		aBigger = false;
		string buf = b;
		b = a;
		a = buf;
	}
	repd( i , a.length()-1 , 0 ){
		if( a[i] >= b[i] )
			a[i] = a[i] - ( b[i] - '0' );
		else{
			a[i] = a[i] + 10;
			a[i-1] -= 1;
			a[i] = a[i] - ( b[i] - '0' );
		}	
	}
	clear(a);
	if( !aBigger )
		a = '-' + a;
	return a;
}

string  stringModString( string a , string b )
{
	clear(a);
	clear(b);
	if( b == "0" )
		return "Error!";
	string result = "";
	string remainder = "";
	for( int i = 0 ; i < a.length() ; i ++ ){
		remainder = remainder + a[i];
		result = result + '0';
		while( isBigger( remainder , b ) ){
			result[result.length()-1] ++;
			remainder = stringSubString( remainder , b );
		}
	}
	clear(remainder);
	return remainder;
}

string stringGcd( string a , string b )
{
	clear(a);
	clear(b);
	if( !isBigger(a,b) ){
		string buf = a;
		a = b;
		b = buf;
	}
	if( b == "0" )
		return a;
	else
		return stringGcd( b , stringModString(a,b) );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	string  a , b , s; 
	a.clear();
	b.clear();
	bool blank = false;
	while( cin >> a >> b ){
		if( blank )
			printf( "\n" );
		else
			blank = true;
		string s;
		s.clear();
		s = stringGcd(a,b);
		cout << s << endl;
		a.clear();
		b.clear();
	}
	return 0;
}
