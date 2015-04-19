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

#define clr(x) memset(x, 0, sizeof(x))
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
const int N = 500005;

const int MaxValue = maxint;
//const int MaxBit = ;
const int MaxN = 500005;
int an[N];
int ans;

struct HaffNode{
	int weight;
	int flag;
	int len;
	int parent;
	int leftchild;
	int rightchild;
}node[2*N];

void Haffman( int weight[] , int n , HaffNode haffTree[] )
{
	int j , m1 , m2 , x1 , x2;
	for( int i = 0 ; i < 2 * n - 1 ; i ++ ){
		if( i < n )
			haffTree[i].weight = weight[i];
		else
			haffTree[i].weight = 0;
		haffTree[i].parent = 0;
		haffTree[i].flag = 0;
		haffTree[i].leftchild = -1;
		haffTree[i].rightchild = -1;
	}
	for( int i = 0 ; i < n - 1 ; i ++ ){
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		for(j = 0 ; j < n + i ; j ++ ){
			if( haffTree[j].weight < m1 && haffTree[j].flag == 0 ){
				m2 = m1;
				x2 = x1;
				m1 = haffTree[j].weight;
				x1 = j;
			}
			else if( haffTree[j].weight < m2 && haffTree[j].flag == 0 ){
				m2 = haffTree[j].weight;
				x2 = j;
			}
		}
		haffTree[x1].parent = n + i;
		haffTree[x2].parent = n + i;
		haffTree[x1].flag = 1;
		haffTree[x2].flag = 1;
		haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight;
		haffTree[n + i].leftchild = x1;
		haffTree[n + i].rightchild = x2;
	}
}

void Add_Len( int a , int len )
{
	node[a].len = len;
	if( node[a].leftchild != -1 )
		Add_Len( node[a].leftchild , len + 1 );
	if( node[a].rightchild != -1 )
		Add_Len( node[a].rightchild , len + 1 );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T;
	scanf( "%d" , &T );
	bool blank = false;
	while( T -- ){
		if( blank )
			printf( "\n" );
		else
			blank;
		int n;
		scanf( "%d" , &n );
		rep(i,n)
			scanf( "%d" , &an[i] );
		sort(an,an+n);
		Haffman( an , n , node );
		ans = 0;
		Add_Len(2*n-2,0);
		for( int i = 0 ; i < n ; i ++ )
			ans += node[i].weight * node[i].len;
		cout << ans << endl;
	}
	return 0;
}

