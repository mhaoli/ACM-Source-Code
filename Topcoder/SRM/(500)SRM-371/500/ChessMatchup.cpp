// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ChessMatchup.cpp"
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

class ChessMatchup
{
	public:
        int d[55][55];
        int gao(int a, int b)
        {
            if (a > b) return 2;
            if (a == b) return 1;
            return 0;
        }
        int maximumScore(vector <int> an, vector <int> bn){
            sort (all(an)); sort (all(bn));
            int n = sz(an);
            clr (d);
            int ans = 0;
            for (int i = 0; i < n; ++ i){
                if (an[i] == bn[0]) d[0][i] = 1;
                else if (an[i] > bn[0]) d[0][i] = 2;
                ans = max(ans, d[0][i]);
            }
            for (int i = 1; i < n; ++ i)
                for (int j = 0; j < n; ++ j){
                    if (!j) d[i][0] = gao(an[0], bn[i]);
                    else for (int k = 0; k < j; ++ k) d[i][j] = max(d[i][j], d[i-1][k] + gao(an[j], bn[i]));
                    ans = max(ans, d[i][j]);
                }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_0() { int Arr0[] = {3, 3, 4, 4, 5, 5, 6, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 10, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15, 3, 8, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, maximumScore(Arg0, Arg1)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	ChessMatchup ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
