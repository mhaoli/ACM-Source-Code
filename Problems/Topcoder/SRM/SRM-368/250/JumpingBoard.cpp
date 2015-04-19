// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "JumpingBoard.cpp"
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

int temp[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class JumpingBoard
{
	public:
        vs bod;
        bool v[55][55];
        int cnt[55][55];
        int n, m;
        int dfs(int x, int y)
        {
            if (x < 0 || x >= n || y < 0 || y >= m || bod[x][y] == 'H') return 0;

            if (v[x][y]){
                cnt[x][y] = inf; return inf;
            }

            int &ret = cnt[x][y];
            if (ret != -1) return ret;
            v[x][y] = 1; ret = 0;

            for (int i = 0; i < 4; ++ i){
                int xx = x + (bod[x][y]-'0')*temp[i][0], yy = y + (bod[x][y]-'0')*temp[i][1];
                ret = max(ret, dfs (xx, yy) + 1);
            }
            v[x][y] = 0;
            return ret;
        }
        int maxJumps(vector <string> board){
            bod = board;
            n = sz(bod); m = sz(bod[0]);
            clr (v);
            clrs (cnt, -1);
            int ans = dfs (0, 0);
            return ans >= inf ? -1 : ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3942178",
 "1234567",
 "9123532"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxJumps(Arg0)); }
	void test_case_1() { string Arr0[] = {"2H3HH4HHH5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxJumps(Arg0)); }
	void test_case_2() { string Arr0[] = {"3994",
 "9999",
 "9999",
 "2924"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, maxJumps(Arg0)); }
	void test_case_3() { string Arr0[] = {"123456",
 "234567",
 "345678",
 "456789"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, maxJumps(Arg0)); }
	void test_case_4() { string Arr0[] = {"9"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, maxJumps(Arg0)); }
	void test_case_5() { string Arr0[] = {"2H9HH11",
 "HHHHH11",
 "9HHHH11"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, maxJumps(Arg0)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	JumpingBoard ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
