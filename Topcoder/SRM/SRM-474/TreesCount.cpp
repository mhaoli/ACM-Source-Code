// BEGIN CUT HERE
/*
 * Author:  plum rain
 * score :
 */
/*

 */
// END CUT HERE
#line 11 "TreesCount.cpp"
#include <sstream>
#include <stdexcept>
#include <functional>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <cctype>
#include <iostream>
#include <cstdio>
//#include <vector>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <cstdlib>
//#include <set>
//#include <queue>
//#include <bitset>
//#include <list>
//#include <string>
//#include <utility>
//#include <map>
//#include <ctime>
//#include <stack>

using namespace std;

//#define CLR(x) memset(x, 0, sizeof(x))
//#define PB push_back
//#define SZ(v) ((int)(v).size())
//#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<#a<<endl
//#define CINBEQUICKER std::ios::sync_with_stdio(false)

//typedef vector<int> VI;
//typedef vector<string> VS;
//typedef vector<double> VD;
//typedef long long int64;
//
//const double eps = 1e-8;
//const double PI = atan(1.0)*4;
//const int maxint = 2139062143;
//
//inline int MyMod( int a , int b ) {a = a % b;if (a < 0) a += b; return a;}
//
class TreesCount
{
	public:
        int count(vector <string> graph){
		    return ();
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"021",
 "201",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123",
 "1012",
 "2101",
 "3210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"073542",
 "705141",
 "350721",
 "517031",
 "442304",
 "211140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
//    freopen( "a.out" , "w" , stdout );    
	TreesCount ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
