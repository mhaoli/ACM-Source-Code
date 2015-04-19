// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ArithmeticProgressions.cpp"
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
typedef vector<int64> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int64, int64> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

int64 d[2][500][500];
class ArithmeticProgressions
{
	public:
        vi num;
        int64 sol(int64 x, int64 a, int64 div)
        {
            if (x < 0) return 0;
            a %= div;
            int64 ret = x / div;
            if ((x%div) >= a) ++ ret;
            return ret;
        }
        bool ok(pii a, pii b)
        {
            double x = (double)a.first / a.second;
            double y = (double)b.first / b.second;
            return x < y;
        }
        string gao2(int64 x)
        {
            int len = 0, dit[50];
            while (x){
                dit[len++] = x % 10;
                x /= 10;
            }
            if (!len) return "0";
            string ret; ret.clear();
            for (int i = len-1; i >= 0; -- i) ret.pb (dit[i] + '0');
            return ret;
        }
        vs gao(pii x)
        {
            vs ret; ret.clear();
            ret.pb (gao2(x.first)); ret.pb (gao2(x.second));
            return ret;
        }
        vector <string> maxAptitude(vector <string> ttt){
            num.clear();
            for (int i = 0; i < sz(ttt); ++ i){
                string s = ttt[i] + " ";
                int64 cnt = 0; 
                for (int j = 0; j < sz(s); ++ j){
                    if (s[j] == ' ') num.pb (cnt), cnt = 0;
                    else cnt = cnt * 10 + s[j] - '0';
                }
            }

            sort(all(num));
            //for (int i = 0; i < sz(num); ++ i) tst (num[i]); cout << endl;

            clrs (d, -1);
            int n = sz(num);
            int cur = 0, nxt = 1;
            pii ans; ans.first = 0; ans.second = 1;
            if (n < 3) return gao(ans);
            for (int i = 0; i < n; ++ i) for (int j = i+1; j < n; ++ j){
                d[0][i][j] = num[j] - num[i];
                //pii tmp; tmp.first = 2; tmp.second = sol(num[n-1], num[j], d[nxt][i][j]) - sol(num[0]-1, num[j], d[nxt][i][j]);
                //if (ok(ans, tmp)) ans = tmp;
            }
            //tst(ans.first); tst(ans.second); cout << endl;
            for (int i = 3; i <= n; ++ i){
                nxt = cur ^ 1;
                for (int j = 0; j < n; ++ j){
                    for (int k = j+1; k < n; ++ k){
                        d[nxt][j][k] = -1;
                        for (int l = j; l < k; ++ l){
                            //if (i == 2 && j == 0 && k == 1) tst(l), out (d[nxt][j][k]), out (d[cur][j][l]);
                            d[nxt][j][k] = max(d[nxt][j][k], __gcd(d[cur][j][l], num[k]-num[l]));
                            //if (i == 2 && j == 0 && k == 1) tst(l), out (d[nxt][j][k]);
                        }
                        if (d[nxt][j][k] == -1) continue;
                        pii tmp; 
                        tmp.first = i; tmp.second = sol(num[n-1], num[j], d[nxt][j][k]) - sol(num[0]-1, num[j], d[nxt][j][k]); 
                        //if (i == 3 && j == 1 && k == 9) out (d[nxt][j][k]), out (sol(num[n-1], num[j], d[nxt][j][k]));
                        //if (tmp.first > tmp.second) tst(i), tst(tmp.second), tst(j), tst(k), cout << endl;
                        if (ok(ans, tmp)) ans = tmp;
                    }
                }
                cur ^= 1;
            }
            int64 gd = __gcd(ans.first, ans.second);
            ans.first /= gd; ans.second /= gd;
            return gao(ans);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1", "3", "5", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3", "4" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, maxAptitude(Arg0)); }
	void test_case_1() { string Arr0[] = {"1", "3", "5", "7", "9", "11", "13", "15", "17", "19"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, maxAptitude(Arg0)); }
	void test_case_2() { string Arr0[] = {"1", "999999999999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, maxAptitude(Arg0)); }
	void test_case_3() { string Arr0[] = {"1", "7", "13", "3511", "1053", "10", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3", "391" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, maxAptitude(Arg0)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	ArithmeticProgressions ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
