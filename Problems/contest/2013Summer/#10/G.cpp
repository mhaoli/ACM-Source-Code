//by plum rain
/*special test data:
 *8
 *1 2 2 2 1 2 3 3
 */
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
#define INF 999999999999
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define flin freopen( "a.in" , "r" , stdin )
#define flout freopen( "a.out" , "w" , stdout )
//#define out(x) cout<<#x<<':'<<(x)<<endl
//#define tst(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int maxint = 2139062143;
const int N = 4005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct POS{
	int r;
	int num;	
};

POS an[N];
int bn[N];
int cn[N][3];

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	int n;
	while (scanf ("%d", &n) != EOF){
		CLR(cn);
		rep (i, n){
			scanf ("%d", &an[i].r);
			an[i].num = i + 1;
		}
		int l = 0, r = 0, ans = 0, time = 1, ma = 0;
		rep (i, n){
			bool xxx = false;
			repf (j, l, r-1)
				if (cn[j][0] == an[i].r && an[i].num > ma && cn[j][1] > ma){
					bn[ans++] = cn[j][1];
					bn[ans++] = an[i].num;
					cn[j][0] = 0;
					xxx = true;
					if (time != 2)
						++time;
					else{
						time = 1;
						ma = max (ma, max (an[i].num, cn[j][1]));
						l = j+1;
					}
					break;
				}
			if (!xxx){
				cn[r][0] = an[i].r;
				cn[r][1] = an[i].num;
				r ++;
			}
		}
		sort (bn, bn+ans);
		printf ("%d\n", ans / 4);
		int cnt = 0;
		rep (i, ans/4){
			printf ("%d", bn[cnt]);
			printf (" %d %d %d\n", bn[cnt+1], bn[cnt+2], bn[cnt+3]);
			cnt += 4;
		}
		printf ("\n");
	}	
	return 0;
}
