// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ChangingSounds.cpp"
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
#define mp make_pair
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

class ChangingSounds
{
	public:
        int d[55][1005];
        int maxFinal(vector <int> cha, int s, int ma){
            clr (d);
            if (s + cha[0] <= ma) d[0][s+cha[0]] = 1;
            if (s >= cha[0]) d[0][s-cha[0]] = 1;
            int n = sz(cha);
            for (int i = 1; i < n; ++ i){
                for (int j = 0; j <= ma; ++ j) if (d[i-1][j]){
                    if (j + cha[i] <= ma) d[i][j+cha[i]] = 1;
                    if (j - cha[i] >= 0) d[i][j-cha[i]] = 1;
                }
            }
            for (int i = ma; i >= 0; -- i) if (d[n-1][i]) return i;
            return -1;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; int Arg3 = 10; verify_case(0, Arg3, maxFinal(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {15, 2, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 20; int Arg3 = -1; verify_case(1, Arg3, maxFinal(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 243; int Arg3 = 238; verify_case(2, Arg3, maxFinal(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	ChangingSounds ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
