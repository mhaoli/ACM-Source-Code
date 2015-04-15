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
const int N = 500005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class Node{
	public:
		int64 pri;
		int l,r;
}an[2*N];

struct cmp{
	bool operator()( Node x , Node y ){
		return x.pri > y.pri;
	}
};

priority_queue<Node,vector<Node>,cmp> q;
int64 ans;

int Build()
{
	int pos = 0;
	while( SZ(q) != 1 ){
		Node x = q.top();
		q.pop();
		Node y = q.top();
		q.pop();
		Node sum;
		sum.pri = x.pri + y.pri;
		sum.l = pos;
		sum.r = pos + 1;
		an[pos++] = x;
		an[pos++] = y;
		q.push(sum);
	}
	an[pos] = q.top();
	return pos;
}

void Query( int num , int len )
{
	if( an[num].l == -1 ){
		ans += an[num].pri * len;
		return;
	}
	Query( an[num].l , len + 1 );
	Query( an[num].r , len + 1 );
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int T;
	scanf( "%d" , &T );
	Node x;
	x.l = -1 ; x.r = -1;
	bool blank = false;
	while( T -- ){
		if( blank )
			printf( "\n" );
		else
			blank = true;
		while( SZ(q) ){
			q.pop();
		}
		int n;
		scanf( "%d" , &n );
		int a;
		repf( i , 1 , n ){
			scanf( "%d" , &a );
			x.pri = a;
			q.push(x);
		}
		int pos = Build();
		ans = 0;
		Query(pos,0);
		cout << ans << endl;
	}	
	return 0;
}
