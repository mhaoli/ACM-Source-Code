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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define repf(i, a, b) for(int64 i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class CorrectMultiplication {
    public:
    long long getMinimum(int a, int b, int c){
        int64 ans = a - 3LL + b + c;
        if (a > b) swap (a, b);
        repf (i, 1, 40000){
            repf (j, c/i-1, c/i+2){
                if (j <= 0) continue;
                chmin (ans, llabs (i-a) + llabs (j-b) + llabs (i*j-c));
            }
        }

        repf (i, 1, 40000){
            repf (j, c/i-1, c/i+2){
                if (j <= 0) continue;
                chmin (ans, llabs (i-b) + llabs (j-a) + llabs (i*j-c));
            }
        }
        return ans;
    }
    int64 llabs (int x){
        return x < 0 ? -x : x;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int a, int b, int c, long long __expected, int caseNo) {

    time_t startClock = clock();
    CorrectMultiplication *instance = new CorrectMultiplication();
    long long __result = instance->getMinimum(a, b, c);
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

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int a = 1;
            int b = 1;
            int c = 1000000000;
            long long __expected = 2LL;
            return do_test(a, b, c, __expected, __no);
        }
        case 1: {
            int a = 10;
            int b = 30;
            int c = 500;
            long long __expected = 11LL;
            return do_test(a, b, c, __expected, __no);
        }
        case 2: {
            int a = 11111;
            int b = 11111;
            int c = 123454321;
            long long __expected = 0LL;
            return do_test(a, b, c, __expected, __no);
        }
        case 3: {
            int a = 1000;
            int b = 100;
            int c = 10;
            long long __expected = 1089LL;
            return do_test(a, b, c, __expected, __no);
        }
        case 4: {
            int a = 399;
            int b = 522;
            int c = 199999;
            long long __expected = 24LL;
            return do_test(a, b, c, __expected, __no);
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
    cout << "CorrectMultiplication (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1401928118;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
