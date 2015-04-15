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
#include <typeinfo>
#include <stack>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define two(x) (1<<(x))
#define twol(x) (1LL<<(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

set<int64> st;
vi len;
int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

class RangeSquaredSubsets {
    public:
    long long countSubsets(int mi, int ma, vector<int> x, vector<int> y){
        mi *= 2; ma *= 2;
        for (auto &i : x) i *= 2;
        for (auto &i : y) i *= 2;

        st.clear();
        for (int i : x) for (int j : y){
            len.clear();
            len.pb (mi); len.pb (ma);
            for (int x2 : x){
                int t = abs (x2 - i);
                if (t >= mi && t <= ma) len.pb (t);
            }
            for (int y2 : y){
                int t = abs (y2 - j);
                if (t >= mi && t <= ma) len.pb (t);
            }
            unq (len);

            for (int l : len) rep (d, 0, 3) rep (sx, -1, 1) rep (sy, -1, 1){
                int x1 = i + sx, y1 = j + sy, x2 = i + l * dx[d] + sx, y2 = j + l * dy[d] + sy;
                calc (x1, x2); calc (y1, y2);

                int64 res = 0;
                rep (k, 0, sz(x)-1){
                    if (x[k] >= x1 && x[k] <= x2 && y[k] >= y1 && y[k] <= y2) 
                        res |= (1ll << k);
                }
                if (res) st.insert (res);
            }
        }
        return st.size ();
    }
    void calc (int &a, int &b){
        if(a > b) swap (a, b);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int nlow, int nhigh, vector<int> x, vector<int> y, long long __expected, int caseNo) {

    time_t startClock = clock();
    RangeSquaredSubsets *instance = new RangeSquaredSubsets();
    long long __result = instance->countSubsets(nlow, nhigh, x, y);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "  Testcase #" << caseNo << " ... ";
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "  Testcase #" << caseNo << " ... ";
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

/*1999, 1999, 
  {8261, 5119, 2397, 3401, 7402, 6165, 1120, 3369, 5446, 2440, 386, 6279, 8412, 1195, 64, 8388, 185, 1122, 4187, 6144, 5203, 3468, 4325, 5067, 5235, 3283, 7053, 5308, 108, 1194, 8420, 3285, 8122, 117, 183, 6208, 4343, 2174, 2377, 7471}
  {1184, 6054, 7408, 92, 6215, 8191, 1248, 2298, 224, 123, 3056, 6279, 3396, 22, 1276, 6130, 16, 6281, 162, 4304, 1378, 5442, 8184, 4416, 8212, 8169, 5131, 3359, 2013, 4365, 159, 3175, 7258, 4281, 8169, 2063, 6370, 2425, 5243, 4301}*/

bool run_testcase(int __no) {
    switch (__no) {
        //case 0: {
            //int nlow = 5;
            //int nhigh = 5;
            //int x[] = {
                //-5, 0, 5
            //};
            //int y[] = {
                //0, 0, 0
            //};
            //long long __expected = 5LL;
            //return do_test(nlow, nhigh, to_vector(x), to_vector(y), __expected, __no);
        //}
        case 0: {
            int nlow = 1999;
            int nhigh = 1999;
            int x[] = 
            {8261, 5119, 2397, 3401, 7402, 6165, 1120, 3369, 5446, 2440, 386, 6279, 8412, 1195, 64, 8388, 185, 1122, 4187, 6144, 5203, 3468, 4325, 5067, 5235, 3283, 7053, 5308, 108, 1194, 8420, 3285, 8122, 117, 183, 6208, 4343, 2174, 2377, 7471};
            int y[] = 
            {1184, 6054, 7408, 92, 6215, 8191, 1248, 2298, 224, 123, 3056, 6279, 3396, 22, 1276, 6130, 16, 6281, 162, 4304, 1378, 5442, 8184, 4416, 8212, 8169, 5131, 3359, 2013, 4365, 159, 3175, 7258, 4281, 8169, 2063, 6370, 2425, 5243, 4301};
            long long __expected = 5LL;
            return do_test(nlow, nhigh, to_vector(x), to_vector(y), __expected, __no);
        }
        case 1: {
            int nlow = 8;
            int nhigh = 8;
            int x[] = {
                0, 5
            };
            int y[] = {
                0, 5
            };
            long long __expected = 5LL;
            return do_test(nlow, nhigh, to_vector(x), to_vector(y), __expected, __no);
        }
        case 2: {
            int nlow = 1;
            int nhigh = 100;
            int x[] = {
                -5, 0, 5
            };
            int y[] = {
                0, 0, 0
            };
            long long __expected = 6LL;
            return do_test(nlow, nhigh, to_vector(x), to_vector(y), __expected, __no);
        }
        case 3: {
            int nlow = 3;
            int nhigh = 100000000;
            int x[] = {
                -1, -1, -1, 0, 1, 1, 1
            };
            int y[] = {
                -1, 0, 1, 1, -1, 0, 1
            };
            long long __expected = 21LL;
            return do_test(nlow, nhigh, to_vector(x), to_vector(y), __expected, __no);
        }
        case 4: {
            int nlow = 64;
            int nhigh = 108;
            int x[] = {
                -56, -234, 12, 324, -12, 53, 0, 234, 1, 12, 72
            };
            int y[] = {
                6, 34, 2, 235, 234, 234, 342, 324, 234, 234, 234
            };
            long long __expected = 26LL;
            return do_test(nlow, nhigh, to_vector(x), to_vector(y), __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "RangeSquaredSubsets (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408960004;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
