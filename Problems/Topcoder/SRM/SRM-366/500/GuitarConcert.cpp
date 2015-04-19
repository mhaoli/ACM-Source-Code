// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "GuitarConcert.cpp"
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

bool cmp(string s, string t)
{
    return s > t;
}
class GuitarConcert
{
	public:
        map<int, string> m2;
        map<string, int> m1;
        vs son;
        int gao(int sta)
        {
            int m = sz(son[0]), n = sz(son), ret = 0;
            for (int i = 0; i < m; ++ i){
                bool u = 0;
                for (int j = 0; j < n; ++ j) if (sta & (1<<j))
                    if (son[j][i] == 'Y') u = 1;
                if (u) ret ++;
            }
            return ret;
        }
        vector <string> buyGuitars(vector <string> nam, vector <string> Son){
            m1.clear(); m2.clear(); son = Son;
            int n = sz(nam);
            for (int i = 0; i < n; ++ i) m1[nam[i]] = i;
            sort(nam.begin(), nam.end(), cmp);
            //for (int i = 0; i < n; ++ i) tst(i), out (nam[i]);
            for (int i = 0; i < n; ++ i) m2[i] = nam[i];

            int cnt = 0;
            vs ans; ans.clear();
            for (int i = (1<<n)-1; i >= 0; -- i){
                int sta = 0;
                for (int j = 0; j < n; ++ j) if (i & (1<<j)) sta |= 1 << m1[m2[j]];
                int tmp = gao(sta);
                if (tmp > cnt || (tmp == cnt && sz(ans) > __builtin_popcount(i))){
                    cnt = tmp;
                    ans.clear();
                    for (int j = n-1; j >= 0; -- j) if (i & (1<<j)) ans.pb (m2[j]);
                }
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"SSEGPRQMTKBGFBCRRKEGJJMOHRBKBYPLTJWLYWMMAB", "GVFCZELUECYETGCEKRMFGNPZBBUZBJJAMQUFNRHSXKPALSB", "OUB", "XDTDCDLJSLXGJBCXQBQWOTXKCYWROBIEJRVBOQQ", "BGFSNQXYKCVQ", "EWSHSDWILYVBWVYALNRFYVXGCVMOSYQRTSCZDFY", "OTEICQWSGSTQHETOFG", "DULXAUA", "PDCRBPDKYNCSRYICZUGJAKGNZQSHNWC", "RDJNNDSUWNIZNPRVCYZWDKY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYNYNY", "YYNNYN", "YNYNNY", "YYNNNN", "NNYYYN", "NNNNYN", "NYNNNY", "NYYNNY", "YYYYYN", "YNYNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"TAYLOR" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GIBSON", "CRAFTER", "FENDER", "TAYLOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYNN", "NNNYY", "YYNNY", "YNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CRAFTER", "GIBSON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AB", "AA", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN", "YN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"FENDER", "GIBSON", "CRAFTER", "EPIPHONE", "BCRICH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYNNYNN", "YYYNYNN", "NNNNNYY", "NNYNNNN", "NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"BCRICH", "CRAFTER", "GIBSON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GIBSON","FENDER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, buyGuitars(Arg0, Arg1)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	GuitarConcert ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
