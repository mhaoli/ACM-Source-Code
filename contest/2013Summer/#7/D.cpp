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

int ans;

void DFS( int len , int num , int r )
{
	//out(len);
	//out(num);
	if( num > r )
		return;
	if( num == r ){
		ans ++;
		return;
	}
	if( num > 0 )
		DFS( len+1 , num << 1 , r );
	DFS( len+1 , (num << 1)+1 , r );
	DFS( len+1 , (num << 1)+2 , r ); 
}

int main()
{
	//freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	//int r;
	//while( scanf( "%d" , &r ) != EOF && r >= 0 ){
	rep( r , 100 ){ 
		if( r == 0 ){
			out(r);
			cout << "0" << endl;
			continue;
		}
		ans = 0;
		DFS(0,0,r);
		out(r);
		cout << ans << endl;
	//}	
	}
	return 0;
}
