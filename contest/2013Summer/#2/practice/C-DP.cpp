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

#define clr(x) memset( x , 0 , sizeof(x) )
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repf(i, a, b) for (long long i = (a); i <= (b); ++i)
#define repd(i, a, b) for (long long i = (a); i >= (b); --i)
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

VI son[N];
VI ans(N);
int an[N];
int dp[N][2];
int n;

void DP()
{
	repd (i,n,1){
		int size = son[i].size();
		if (!size){
			dp[i][1] = 1;
			dp[i][0] = 0;
			continue;
		}
		int mon = 0, cnt = 0, flag = 0; 
		rep (j,size){
			int k = son[i][j]; 
			mon += dp[k][0];
			if (dp[k][1] - dp[k][0] > cnt){
				cnt = dp[k][1] - dp[k][0];
				flag = k;
			}
		}
		dp[i][1] = mon + 1;
		dp[i][0] = mon;
		if ( flag ){
			dp[i][0] += cnt;
			ans.push_back(flag);
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T;
	scanf ("%d", &T);
	while ( T -- ){
		ans.clear();
		clr(son);
		scanf ("%d", &n);
		int x;
		repf (i,2,n){
			scanf ("%d", &x);
			son[x].push_back(i);
		}
		DP();
		printf ("%d000\n", dp[1][0]);
		int size = ans.size();
		rep (i, size)
			an[i] = ans[i];	
		sort (an, an+size);
		printf ("%d", an[0]);
		repf (i, 1, size-1)
			printf (" %d", an[i]);
		printf ("\n");
		if (T > 0)
			printf ("\n");
	}	
	return 0;
}
