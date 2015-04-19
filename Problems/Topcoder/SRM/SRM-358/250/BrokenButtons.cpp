// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BrokenButtons.cpp"
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

#define clr0(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<":"<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class BrokenButtons
{
	public:
        int ans, len, p;
        bool v[20];
        void dfs(int x, int num)
        {
            if (num) ans = min(ans, abs(p-x) + num);
            if (num <= len)
                for (int i = 0; i < 10; ++ i) if (!v[i]) dfs (x*10+i, num+1);
        }
        int minPresses(int pag, vector <int> bro){
            clr0 (v);
            for (int i = 0; i < sz(bro); ++ i) v[bro[i]] = 1;
            ans = abs(pag-100); p = pag; len = 0;
            while (pag) pag /= 10, len ++;
            dfs (0, 0);
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5457; int Arr1[] = { 6, 7, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = { 1, 0, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 14124; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 80000; int Arr1[] = { 8, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2228; verify_case(4, Arg2, minPresses(Arg0, Arg1)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	BrokenButtons ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
