// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "MarriageProblemRevised.cpp"
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

int rm[10000], rw[10000];
class MarriageProblemRevised
{
	public:
        int neededMarriages(vector <string> pre){
            clr (rm); clr (rw);
            int n = sz(pre), m = sz(pre[0]);
            for (int i = 0; i < n; ++ i){
                bool u = 0;
                for (int j = 0; j < m; ++ j) if (pre[i][j] == '1') u = 1;
                if (!u) return -1;
            }
            for (int i = 0; i < m; ++ i){
                bool u = 0; for (int j = 0; j < n; ++ j) if (pre[j][i] == '1') u = 1;
                if (!u) return -1;
            }

            for (int i = 0; i < (1<<n); ++ i){
                for (int j = 0; j < n; ++ j) if (i & (1<<j)){
                    for (int k = 0; k < m; ++ k) rm[i] |= (pre[j][k] == '1' ? 1<<k : 0);
                }
            }
            for (int i = 0; i < (1<<m); ++ i){
                for (int j = 0; j < m; ++ j) if (i & (1<<j))
                    for (int k = 0; k < n; ++ k) rw[i] |= (pre[k][j] == '1' ? 1<<k : 0);
            }

            int ans = inf;
            for (int i = 0; i < (1<<n); ++ i)
                for(int j = 0; j < (1<<m); ++ j) if ((rm[i]|j) == rm[i]){
                    if ((i | rw[((1<<m)-1)^j]) == (1<<n)-1)
                        ans = min(ans, __builtin_popcount(i) + m - __builtin_popcount(j));
                }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, neededMarriages(Arg0)); }
	void test_case_1() { string Arr0[] = {"100", "010", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, neededMarriages(Arg0)); }
	void test_case_2() { string Arr0[] = {"00", "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, neededMarriages(Arg0)); }
	void test_case_3() { string Arr0[] = {"0001", "0001", "0001", "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, neededMarriages(Arg0)); }
	void test_case_4() { string Arr0[] = {"11101011","00011110","11100100","01010000","01000010","10100011","01110110","10111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, neededMarriages(Arg0)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	MarriageProblemRevised ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
