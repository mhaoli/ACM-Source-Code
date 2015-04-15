// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Hotel.cpp"
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
#define tst(x) cout<<#x<<":"<<(x)<<" "
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

int temp[20], d[220][1005];
class Hotel
{
	public:
        int marketCost(int m, vector <int> cus, vector <int> c){
            temp[0] = 1; for (int i = 1; i < 11; ++ i) temp[i] = temp[i-1] * 2;
            int n = sz(c), ans = inf; 
            vi num, cost;
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < 11; ++ j){
                    num.pb (temp[j]*cus[i]); cost.pb (temp[j]*c[i]);
                    if (temp[j] * cus[i] > m) break;
                }
            }

            //for (int i = 0; i < sz(num); ++ i) tst(num[i]), out (cost[i]);

            clr1 (d); 
            for (int i = 0; i < m; ++ i) d[0][i] = inf;
            d[0][0] = 0;
            if (num[0] < m) d[0][num[0]] =  cost[0];
            else ans = cost[0];
            for (int i = 1; i < sz(num); ++ i){
                for (int j = 0; j < m; ++ j){
                    if (d[i][j] == -1) d[i][j] = inf;
                    d[i][j] = min(d[i][j], d[i-1][j]);
                    if (j + num[i] >= m) ans = min(ans, d[i-1][j]+cost[i]);
                    else{
                        if (d[i][j+num[i]] == -1) d[i][j+num[i]] = inf; 
                        d[i][j+num[i]] = min(d[i][j+num[i]], d[i-1][j] + cost[i]);
                    }
                }
                //tst(i), out (d[i][99]);
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	//void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_3();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, marketCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, marketCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; int Arr1[] = {5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(2, Arg3, marketCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {9, 11, 4, 7, 2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 9, 3, 8, 1, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 45; verify_case(3, Arg3, marketCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	Hotel ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
