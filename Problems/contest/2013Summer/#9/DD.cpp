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
#include <stack>

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

int64 prm[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int num[25] = {0};
int64 n;
		int64 ans;
		int64 tmp;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

void DFS(int64 x)
{
	if (x > n)
		return;
	int64 a = 1; 
	rep (i, 25)
		a *= num[i] + 1;
	if (a > tmp || (a == tmp && ans > x)){
		ans = x;
		tmp = a;
	}
	num[0] ++;
	DFS(2 * x);
	num[0] --;
	repf (i, 1, 24){
		if (num[i-1] > num[i]){
			num[i] ++;
			DFS(prm[i] * x);
			num[i] --;
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	while (scanf ("%lld", &n) != EOF){
		if (n == -5)
			break;
		if (n == 1){
			printf ("1\n");
			continue;
		}
		CLR(num);
		tmp = 0;
		DFS (1);
		printf ("%lld\n", ans);
	}
	return 0;
}
