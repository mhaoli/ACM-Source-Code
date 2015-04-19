// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "RoundOfEleven.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <string>
#include <utility>
#include <map>
#include <ctime>
#include <stack>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int64 d[20][11][505];
int dit[20];

class RoundOfEleven
{
	public:
        long long maxIncome(int n, int mon){
            int len = 0;
            while (n){
                dit[len++] = n % 10;
                n /= 10;
            }

            clr (d);
            for (int i = 0; i <= 9; ++ i) ++ d[0][i][abs(i-dit[len-1])];
            for (int i = 1, j = len-2; i < len; ++ i, -- j)
                for (int k = 0; k < 11; ++ k)
                    for (int u = 0; u <= mon; ++ u)
                        for (int t = 0; t <= 9; ++ t){
                            if (abs(t-dit[j]) + u > mon) continue;
                            d[i][(k*10+t)%11][abs(t-dit[j])+u] += d[i-1][k][u];
                        }

            int64 ans = 0;
            for (int i = 0; i < mon; ++ i) ans += d[len-1][0][i] * (mon - i);
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 31; int Arg1 = 4; long long Arg2 = 6LL; verify_case(0, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 31; int Arg1 = 5; long long Arg2 = 11LL; verify_case(1, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 110; int Arg1 = 3; long long Arg2 = 7LL; verify_case(2, Arg2, maxIncome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19759; int Arg1 = 435; long long Arg2 = 3788217LL; verify_case(3, Arg2, maxIncome(Arg0, Arg1)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	RoundOfEleven ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
