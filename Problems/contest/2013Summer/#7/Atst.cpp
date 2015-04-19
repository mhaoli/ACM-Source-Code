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

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int64 an[21][501];


int main()
{
	//freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	CLR(an);
	repf( i , 1 , 20 )
		an[i][1] = 2;
	repf( j , 1 , 500 )
		an[1][j] = 2*j;
	repf( i , 2 , 20 ){
		repf( j , 2 , 500 ){
			if( j == 1 ){
				an[i][j] = 2;
				continue;
			}
			if( i == 1 ){
				an[i][j] = 2 * j;
			}
			if( an[i][j-1] < 501 )
				an[i][j] = an[i-1][an[i][j-1]];
		}
	}
	repf( i , 1 , 20 ){
		repf( j , 1 , 500 ){
			cout << an[i][j] << " ";
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}
