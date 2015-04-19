// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "AverageProblem.cpp"
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

class AverageProblem
{
	public:
        int all;
        int num[1000];
        bool ok(int x)
        {
            for (int i = 0; i < all; ++ i){
                if (num[i]*x % 1000 == 0) continue;

                int t1 = (num[i]*x + x) / 1000, t2 = num[i]*x / 1000;
                if ((num[i]*x+x) % 1000 == 0) -- t1;
                if (t1 <= t2) return 0;
            }
            return 1;
        }
        int numberOfParticipants(vector <string> m){
            string s;
            for (int i = 0; i < sz(m); ++ i) s += m[i] + " ";
            all = 0;
            int tmp = 0;
            for (int i = 0; i < sz(s); ++ i){
                if (s[i] == ' ') num[all++] = tmp, tmp = 0;
                else if (s[i] != '.'){
                    tmp = tmp * 10 + s[i] - '0';
                }
            }
            //for (int i = 0; i < all; ++ i) out (num[i]);
            for(int i = 1; i <= 1000; ++ i)
                if (ok(i)) return i;
            return 1000;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"9.663 2.638 4.111 6.332 3.725 6.188", "4.840 0.358 4.164 7.103 1.215", "4.248 6.902 9.060 2.105 0.224", "8.454 3.136 9.211 9.647 3.844 8.798", "1.888 1.236 8.843 6.688", "0.621 2.253 5.515 7.040 6.935", "9.947 0.298", "4.653", "9.782 3.830 8.356 8.332", "0.322 2.954"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(0, Arg1, numberOfParticipants(Arg0)); }
	void test_case_1() { string Arr0[] = {"0.500 0.250", "0.125"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, numberOfParticipants(Arg0)); }
	void test_case_2() { string Arr0[] = {"0.500","0.300"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, numberOfParticipants(Arg0)); }
	void test_case_3() { string Arr0[] = {"0.500","0.301"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 106; verify_case(3, Arg1, numberOfParticipants(Arg0)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	AverageProblem ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
