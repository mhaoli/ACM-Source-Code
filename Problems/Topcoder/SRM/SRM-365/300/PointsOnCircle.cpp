// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "PointsOnCircle.cpp"
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
#define all(v) (v.begin(), v.end())
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<":"<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int64> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class PointsOnCircle
{
	public:
        long long count(int r){
            vi d, ans; d.clear(); ans.clear();
            for (int64 i = 1; i*i <= r; ++ i) if (r % i == 0){
                d.pb (i); 
                if (i*i != r) d.pb (r/i);
            }
            for (int i = 0; i < sz(d); ++ i)
                for (int j = 0; j < sz(d); ++ j){
                    ans.pb (d[i]*d[j]);
                }
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            //for (int i = 0; i < sz(ans); ++ i) out (ans[i]);
            int64 n1 = 0, n2 = 0;
            for (int i = 0; i < sz(ans); ++ i){
                //if (i && ans[i] == ans[i-1]) continue;
                int tmp = ans[i] % 4;
                if (tmp == 1) n1 ++;
                else if (tmp == 3) n2 ++;
            }
            return 4 * (n1 - n2);
        }
        
// BEGIN CUT HERE
	public:
	//void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_3();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2000000000; long long Arg1 = 76LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 1053; long long Arg1 = 12LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	PointsOnCircle ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
