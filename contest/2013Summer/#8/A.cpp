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
const int N = 100005;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

string s;
bool an[N];

bool match(int a, int b)
{
	if (s[a] == '(' && s[b] == ')')
		return true;
	if (s[a] == '[' && s[b] == ']')
		return true;	
	return false;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//std::ios::sync_with_stdio(false);
	s.clear();
	while (cin >> s){
		int len = SZ(s);
		stack<int> stk;
		while (!stk.empty())
			stk.pop();
		CLR(an);
		rep (i, len){
			if (stk.empty()){
				stk.push(i);
				continue;
			}
			if (match(stk.top(),i)){
				an[stk.top()] = true;
				an[i] = true;
				stk.pop();
				continue;
			}
			stk.push(i);
		}
		int tmp = 0, ans = 0, l = -5, r = -5;
		int i = 0, j;
		while (i < len){
			while (i < len && !an[i])
				i ++;
			j = i;
			while (i < len && an[i])
				i ++;
			tmp = i - j;
			if (tmp > ans){
				ans = tmp;
				l = j; r = i;
			}
		}
		if (ans)
		repf (k, l ,r-1)
			printf ("%c", s[k]);
		printf ("\n\n");
		s.clear();
	}	
	return 0;
}
