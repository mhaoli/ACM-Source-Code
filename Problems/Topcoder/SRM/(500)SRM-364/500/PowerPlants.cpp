// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "PowerPlants.cpp"
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

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int d[100000];

class PowerPlants
{
	public:
        int gao(char x)
        {
            if (x >= '0' && x <= '9') return x - '0';
            return x - 'A' + 10;
        }
        int minCost(vector <string> con, string v, int nump){
            int sta = 0, n = sz(con);
            for (int i = 0; i < sz(v); ++ i) if (v[i] == 'Y') sta |= 1 << i;
            clrs(d, 10);
            d[sta] = 0;
            int ans = inf;
            for (int i = 0; i < (1<<n); ++ i){
                for (int j = 0; j < n; ++ j) if (i & (1<<j))
                    for (int k = 0; k < n; ++ k) if (k != j && (i & (1<<k))){
                        //int tmp = d[i];
                        d[i] = min(d[i], d[i^(1<<j)] + gao(con[k][j]));
                        //if (i == 3 && tmp != d[i]) out (d[i]), out (i), out (j), out (k);
                    }

                if (__builtin_popcount(i) >= nump) ans = min(ans, d[i]);
            }
            //for (int i = 0; i < (1<<n); ++ i) tst(i), out (d[i]);
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"024",
 "203",
 "430"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNN"; int Arg2 = 3; int Arg3 = 5; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0AB",
 "A0C",
 "CD0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNN"; int Arg2 = 3; int Arg3 = 21; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1ABCD",
 "35HF8",
 "FDM31",
 "AME93",
 "01390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NYNNN"; int Arg2 = 5; int Arg3 = 14; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"012",
 "123",
 "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NNY"; int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"1309328",
 "DS2389U",
 "92EJFAN",
 "928FJNS",
 "FJS0DJF",
 "9FWJW0E",
 "23JFNFS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YYNYYNY"; int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"01","20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YN"; int Arg2 = 2; int Arg3 = 1; verify_case(5, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	PowerPlants ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
