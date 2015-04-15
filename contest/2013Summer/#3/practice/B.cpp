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
const int N = 30005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class MTC{
	public:
		// |a b|
		// |c d|
		int a , b , c , d;	
}mtc[N];

class Node{
	public:
		int	l , r , mid;
		MTC x;
}node[3*N];

int mod , n , m;
MTC ans;

MTC Mul( MTC p , MTC q )
{
	MTC x;
	x.a = ( p.a*q.a + p.b*q.c ) % mod;
	x.b = ( p.a*q.b + p.b*q.d ) % mod;
	x.c = ( p.c*q.a + p.d*q.c ) % mod;
	x.d = ( p.c*q.b + p.d*q.d ) % mod;
	return x;
}

void Cal( int num , int l , int r )
{	
	if( l <= node[num].l && r >= node[num].r ){
		ans = Mul( ans , node[num].x );
		return;
	}
	num <<= 1;
	if( l <= node[num].r )
		Cal( num , l , r );
	if( r >= node[num+1].l )
		Cal( num+1 , l , r );
}

void Build( int num , int l , int r )
{
	node[num].l = l;
	node[num].r = r;
	node[num].mid = (l+r) >> 1;
	if( l == r ){
		node[num].x = mtc[r];
		return;
	}
	Build( num<<1 , l , node[num].mid );
	Build( (num<<1)+1 , node[num].mid+1 , r );
	node[num].x = Mul( node[num<<1].x , node[(num<<1)+1].x );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	bool blank = false;
	while( scanf( "%d%d%d" , &mod , &n , &m ) != EOF ){
		repf( i , 1 , n )
			scanf( "%d%d%d%d" , &mtc[i].a , &mtc[i].b , &mtc[i].c , &mtc[i].d );				
		Build( 1 , 1 , n );
		repf( i , 1 , m ){
			if( blank )
				printf( "\n" );
			else
				blank = true;
			int a , b;
			scanf( "%d%d" , &a , &b );
			ans.a = 1 ; ans.b = 0 ; ans.c = 0 ; ans.d = 1;
			Cal( 1 , a , b );
			printf( "%d %d\n%d %d\n" , ans.a , ans.b , ans.c , ans.d );
		}
	}	
	return 0;
}
