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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
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
const int L = 105;
const int M = 30;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int l, m;
int an[L], tn[M][M];
int dp[L][M], fla[L][M];

void DP()
{
	CLR(dp);
	repf (i, 2, l){
		repf (j, 1, m){
			int tmp = maxint, flag = -1;
			repf (k, 1, m){
				if (tmp > abs (an[i-1] - tn[k][j]) + dp[i-1][k]){
					tmp = abs (an[i-1] - tn[k][j]) + dp[i-1][k];
					flag = k;
				}	
			}
			dp[i][j] = tmp;
			fla[i][j] = flag;
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	while (scanf ("%d%d", &l, &m) != EOF){
		repf (i, 1, l-1)
			scanf ("%d", &an[i]);
		repf (i, 1, m)
			repf (j, 1, m){
				scanf ("%d", &tn[i][j]);			
			}
		DP();
		/*repf (i, 1, l){
			repf (j, 1, m){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
		repf (i, 1, l){
			repf (j, 1, m)
				cout << fla[i][j] << " ";
			cout << endl;
		}*/
		int tmp = maxint, flag = -1;
		repf (i, 1, m){
			if (tmp > dp[l][i]){
				tmp = dp[l][i];
				flag = i;
			}
		}
		string s;
		s.clear();
		int cnt = l;
		while (cnt > 0){
			char x = flag + 'a' - 1;
			s += x;
			flag = fla[cnt][flag];
			cnt --;
		}
		int size = SZ(s);
		repd (i, size-1, 0)
			printf ("%c", s[i]);
		printf ("\n");	
	}	
	return 0;
}
