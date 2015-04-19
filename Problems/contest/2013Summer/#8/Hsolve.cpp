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

int n;
string dp[200][65][65];

inline void clear(string &a)
{
	while (a.length() > 0 && a[0] == '0')
		a.erase(0, 1);
	if (a == "")
		a = "0";
}

string Add(string a, string b)
{
	while (a.length() < b.length())
		a = '0' + a;
	while (a.length() > b.length())
		b = '0' + b;
	a = '0' + a;
	b = '0' + b;
	for (int i = a.length()-1; i >= 0; i --){
		a[i] = a[i] + b[i] - '0';
		if (a[i] > '9'){
			a[i] = a[i] - 10;
			a[i-1] += 1;
		}
	}
	clear(a);
	return a;
}

void DP()
{
	rep (i, n+1)
		rep (j, n+1){
			dp[1][i][j].clear();
			dp[1][i][j] = "0";
		}
	dp[1][1][0] = "1";
	repf (i, 2, 3*n)
		repf (j, 0, i)
		repf (k, 0, j){
			dp[i][j][k].clear();
			dp[i][j][k] = "0";
			if (i-j-k > k){
				continue;
			}
			if (j > n || k > n || i-j-k > n){
				continue;
			}
			//dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k];
			if (i > k && i > i-j-k)
				dp[i][j][k] = Add (dp[i][j][k], dp[i-1][j-1][k]);
			if (i > j && i > i-j-k)
				dp[i][j][k] = Add (dp[i][j][k], dp[i-1][j][k-1]);
			if (i > j && i > k)
				dp[i][j][k] = Add (dp[i][j][k], dp[i-1][j][k]);
		}
}

int main()
{
	//freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	//while (scanf ("%d", &n) != EOF){
		//if (n == -5)
		//	break;
	for (n = 0; n < 61; n ++){
		DP();
		//string ans;
		//ans.clear();
		/*rep (i, 7){
			out (i);
			out (dp[i][0][0]);
			out (dp[i][1][0]);
			out (dp[i][1][1]);
			out (dp[i][1][2]);
			out (dp[i][2][0]);
			out (dp[i][2][1]);
			out (dp[i][2][2]);
		}*/
		cout << dp[3*n][n][n] << endl;
	}	
	return 0;
}
