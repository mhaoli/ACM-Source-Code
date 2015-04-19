// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BalanceScale.cpp"
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

int d[55][1<<9];
vi divv;

class BalanceScale
{
	public:
        int gao(int sta, int x)
        {
            int m = sz(divv), ret = 0;
            for (int i = 0; i < m; ++ i) if (sta & (1<<i)){
                if (x % divv[i] == 0) ret |= 1 << i;
            }
            return ret;
        }
        int takeWeights(vector <int> w){
            sort(all(w));
            int gd = w[0], n = sz(w);
            for (int i = 1; i < n; ++ i) gd = __gcd(gd, w[i]);
            for (int i = 0; i < n; ++ i){
                w[i] /= gd;
                if (w[i] == 1) return 1;
            }
            int ans = n;
            for (int i = 0; i < n; ++ i){
                int tmp = w[i];
                divv.clear();
                for (int64 j = 2; j*j <= tmp; ++ j) if (tmp % j == 0){
                    divv.pb (j);
                    while (tmp % j == 0) tmp /= j;
                }
                if (tmp != 1) divv.pb (tmp);

                int m = sz(divv);
                clr (d); d[0][(1<<m)-1] = 1;
                for (int j = 0; j < n; ++ j){
                    for (int k = 0; k <= j; ++ k)
                        for (int t = 0; t < (1<<m); ++ t) 
                            if (d[k][t]) d[k+1][gao(t, w[j])] = 1;
                }

                for (int j = 1; j < n; ++ j) if (d[j][0]) ans = min(ans, j+1);
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arr0[] = { 5, 4, 1, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, takeWeights(Arg0)); }
	void test_case_0() { int Arr0[] = {3828825, 2159850, 4594590, 22, 1939392}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, takeWeights(Arg0)); }
	void test_case_1() { int Arr0[] = { 2, 3, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, takeWeights(Arg0)); }
	void test_case_2() { int Arr0[] = { 60, 105, 490, 42 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, takeWeights(Arg0)); }
	void test_case_3() { int Arr0[] = { 15, 25, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, takeWeights(Arg0)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	BalanceScale ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
