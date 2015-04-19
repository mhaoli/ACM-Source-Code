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
const int N = 500005;

class POS{
	public:
		int64 pri;
		int len;
		int lchild;
		int rchild;
}aaa;
vector<POS> v(N);
POS bn[2*N];
int ans;
int now;

bool cmp2( POS a , POS b )
{
	return a.pri > b.pri;
}
bool cmp( POS a , POS b )
{
	return a.pri < b.pri;
}

void Build_Tree( int n )
{
	make_heap(v.begin(),v.end(),cmp2);
	int num = 1 , me = n;
	now = 0;
	while( SZ(v) > 1 ){
		POS x = v.front();
		pop_heap(v.begin(),v.end(),cmp2);
		v.pop_back();
		push_heap(v.begin(),v.end(),cmp2);
		POS y = v.front();
		pop_heap(v.begin(),v.end(),cmp2);
		v.pop_back();
		POS z;
		z.pri = x.pri + y.pri;
		z.lchild = now;
		z.rchild = now + 1;
		bn[now++] = x;
		bn[now++] = y;
		v.PB(z);
		push_heap(v.begin(),v.end(),cmp2);
	}
	bn[now++] = v.front();
}

void Add_Len( int a , int len )
{
	bn[a].len = len;
	if( bn[a].lchild != -1)
		Add_Len( bn[a].lchild , len + 1 );
	if( bn[a].rchild != -1 )
		Add_Len( bn[a].rchild , len + 1 );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf( "%d" , &T );
	bool blank = false;
	while( T -- ){
		if( blank )
			printf( "\n" );
		else
			blank = true;
		v.clear();
		CLR(bn);
		int n;
		scanf( "%d" , &n );
		aaa.len = 0;
		aaa.lchild = -1;
		aaa.rchild = -1;
		rep( i , n ){
			scanf( "%d" , &aaa.pri );
		   	v.PB(aaa);	
		}
		Build_Tree(n);
		now-- ;
		Add_Len(now,0);
		ans = 0;
		rep( i , now )
			if( bn[i].lchild == -1 && bn[i].rchild == -1 )
				ans += bn[i].pri * bn[i].len;
		printf( "%d\n" , ans );
	}
	return 0;
}
