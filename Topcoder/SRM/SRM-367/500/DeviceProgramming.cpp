// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "DeviceProgramming.cpp"
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
typedef pair<int64, int64> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int64 d[55];
vector<pii > pat;
class DeviceProgramming
{
	public:
        long long minBytes(vector <int> sta, vector <int> len, int ma, int hed){
            pat.clear();
            for (int i = 0; i < sz(sta); ++ i) pat.pb (make_pair(sta[i], sta[i]+len[i]-1));
            sort(all(pat));
            d[0] = 0;
            int64 l = ma - hed;
            for (int i = 1; i <= sz(pat); ++ i){
                d[i] = 1LL<<60;
                for (int j = 0; j < i; ++ j){
                    int64 cnt = pat[i-1].second - pat[j].first + 1;
                    int64 num = ceil((double)cnt/l);
                    d[i] = min(d[i], d[j] + cnt + num*hed);
                }
            }
            return d[sz(pat)];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 42, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 15, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 6; long long Arg4 = 78LL; verify_case(0, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 42, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 15, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 6; long long Arg4 = 92LL; verify_case(1, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0, 2, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 5; long long Arg4 = 26LL; verify_case(2, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10264, 111, 357, 100066, 714}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {117, 134, 235, 2395, 23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 10; long long Arg4 = 3254LL; verify_case(3, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 100000000, 450000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99999999, 315000000, 500000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 30; long long Arg4 = 943298999LL; verify_case(4, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0, 1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 999; long long Arg4 = 2000000000000LL; verify_case(5, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	DeviceProgramming ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
