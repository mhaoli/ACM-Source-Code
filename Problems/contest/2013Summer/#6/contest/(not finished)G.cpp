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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
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
const int N = 55;
const int maxx = 150;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int an[N][2*N];
int l1[N] , r1[N] , l2[N] , r2[N];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int n;
	int T = 0;
	while( scanf( "%d" , &n ) != EOF && n ){
		CLR(an) ; CLR(l1) ; CLR(l2) ; CLR(r1) ; CLR(r2);
		string s;
		rep( i , n ){
		    s.clear();
			cin >> s;
			int le1 = maxx , le2 = maxx , re1 = 0 , re2 = 0;
			rep( j , 2*i+1 ){
				if( s[j] == '0' ){
					le1 = min( le1 , j+1 );
					re1 = max( re1 , j+1 );
					an[i+1][j+1] = 1;
				}
				else{
					le2 = min( le2 , j+1 );
					re2 = max( re2 , j+1 );
					an[i+1][j+1] = 2;
				}
			}
			l1[i+1] = le1 ; r1[i+1] = re1 ; l2[i+1] = le2 ; r2[i+1] = re2;
		}
		/*out(n);
		repf( i , 1 , n ){
			repf( j , 1 , 2*i-1 )
				cout << an[i][j];
			cout << endl;
		}
		repf( i , 1 , n )
			cout << l1[i] << " " << r1[i] << " " << l2[i] << " " << r2[i] << endl;*/
		bool left = true , leftup = true , leftdown = true , right = true , rightup = true , rightdown = true;
		rep( i , n ){
			if( r1[i] > l2[i] && !( l2[i] == 0 && r2[i] == maxx ) )
				left = false;
			if( l1[i] < r2[i] && !( l2[i] == 0 && r2[i] == maxx ))
				right = false;
			if( i > 0 ){
				if( l2[i-1] % 2 && l2[i-1]+1 <= r1[i] && !( l2[i-1] == 0 && r2[i-1] == maxx ) )
					leftup = false;
				if( !(l2[i-1] % 2) && l2[i-1]+2 <= r1[i] && !( l2[i-1] == 0 && r2[i-1] == maxx ) )
					leftup = false;
				if( r2[i-1] % 2 && r2[i-1]+1 >= l1[i] &&  !( l2[i-1] == 0 && r2[i-1] == maxx ) )
					
			}
		}
	}
	return 0;
}
