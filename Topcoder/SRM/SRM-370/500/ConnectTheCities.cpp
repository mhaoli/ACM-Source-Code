// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ConnectTheCities.cpp"
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

int d[55][105];
class ConnectTheCities
{
	public:
        vi pos;
        int len;
        int gao(int dis)
        {
            clrs (d, 10);
            int ret = inf;
            for (int i = 0; i <= dis; ++ i) d[0][i] = 0;
            for (int i = 1; i <= sz(pos); ++ i){
                for (int j = 0; j <= len; ++ j){
                    int tmp = d[i-1][j] + abs(pos[i-1] - j);
                    for (int k = j; k <= j + dis; ++ k){
                        if (k >= len){
                            ret = min(ret, tmp); break;
                        }
                        d[i][k] = min(d[i][k], tmp);
                    }
                }
            }
            return ret;
        }
        int minimalRange(int lenn, int tot, vector <int> posi){
            pos = posi; len = lenn;
            sort(all(pos));
            int l = 0, r = len;
            while (l <= r){
                int mid = (l + r) >> 1;
                //out (mid); out (gao(mid));
                if (gao(mid) > tot) l = mid + 1;
                else r = mid - 1;
            }
            return l;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = { 3, 7, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 100; int Arr2[] = { 0, 0, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 63; int Arg1 = 19; int Arr2[] = { 34, 48, 19, 61, 24 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, minimalRange(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	ConnectTheCities ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
