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
const int N = 3005;

int an[N];
short int dp[N][N];
short int ma[N];
short int ans[N];
//VI ans;

inline short int maxs( short int a , short int b )
{
	if( a > b )
		return a;
	else
		return b;
}

void DP( int n )
{
	//memset( dp , 1 , sizeof(dp) );
	//memset( ma , 1 , sizeof(ma) );
	repf( i , 1 , n ){
		repf( j , 1 , i )
			dp[i][j] = 1;
		repf( j , i+1 , n )
			dp[i][j] = 2;
	}
	//rep( i , n+1 )
	//	ma[i] = 0;
	clr(ma);
	repf( k , 1 , n ){
		ma[k] = 1;
		int len = 1;
		repf( i , 1 , k-1 ){
			repf( j , i+1 , k-1 ){
				if( an[i] + an[j] == an[k] ){
					dp[j][k] = maxs( dp[i][j] + 1 , dp[j][k] ); 
					if( dp[j][k] > len ){
						ma[k] = j;
						len = dp[j][k];
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	bool xxxxx = false;
	while( scanf( "%d" , &n ) != EOF ){
		if( xxxxx )
			printf( "\n" );
		else
			xxxxx = true;
		rep( i , n )
			scanf( "%d" , &an[i+1] );
		DP(n);
		int xxx = 1 , flag;
		repf( i , 1 , n){
			if( xxx < dp[ma[i]][i] ){
				flag = i;
				xxx = dp[ma[i]][i];
			}
		}
		printf( "%d\n" , xxx );
		//ans.push_back(an[flag]);
		int pos = 0;
		ans[pos++] = an[flag];
		flag = ma[flag];
		//ans.push_back(an[flag]);
		ans[pos++] = an[flag];
		repf( i , 3 , xxx ){
			//int size = ans.size();
			//ans.push_back(ans[size-2]-ans[size-1]);
			ans[pos++] = ans[pos-2] - ans[pos-1];
		}
		//int size = ans.size();
		int size = pos;
		printf( "%d" , ans[size-1] );
		repd( i , size-2 , 0 )
			printf( " %d" , ans[i] );
	}
	return 0;
}
