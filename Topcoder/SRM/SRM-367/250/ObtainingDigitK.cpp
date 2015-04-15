// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ObtainingDigitK.cpp"
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

class ObtainingDigitK
{
	public:
        string gao(string s)
        {
            string ret; ret.clear();
            int n = sz(s);
            if (s[n-1] != '9'){
                s[n-1] ++;
                return s;
            }
            bool u = 1;
            ret.pb ('0');
            for (int i = n-2; i >= 0; -- i){
                if (u){
                    if (s[i] != '9') s[i] ++, u = 0;
                    else s[i] = '0', u = 1;
                }
                ret.pb (s[i]);
            }
            if (u) ret.pb ('1');
            string ans; ans.clear();
            for (int i = sz(ret)-1; i >= 0; -- i) ans.pb (ret[i]);
            return ans;
        }
        int minNumberToAdd(string s, int k){
            int num = 0;
            while (1){
                for (int i = 0; i < sz(s); ++ i) if (s[i] == k + '0') return num;
                ++ num;
                s = gao(s);
                if (num > 20) break;
            }
            return 9;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "153"; int Arg1 = 7; int Arg2 = 4; verify_case(0, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "158"; int Arg1 = 7; int Arg2 = 9; verify_case(1, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "7853192"; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999999999999999999999999999999999999999999999"; int Arg1 = 0; int Arg2 = 1; verify_case(3, Arg2, minNumberToAdd(Arg0, Arg1)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	ObtainingDigitK ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
