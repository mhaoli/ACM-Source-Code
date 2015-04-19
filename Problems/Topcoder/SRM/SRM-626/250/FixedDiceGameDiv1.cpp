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
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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

class FixedDiceGameDiv1 {
    public:
        double num[10][3000], bn[55][3000];
        double getExpectation(int a, int b, int c, int d) {
            if (a * b <= c) return -1.0;
            solve (a, b, num[1]); solve (c, d, num[2]);

            double ans = 0;
            double sum = 0;
            repf (i, a, a*b) repf (j, c, c*d) if (i > j){
                ans += i * num[1][i] * num[2][j];
                sum += num[1][i] * num[2][j];
            }
            return ans / sum;
        }
        void solve (int a, int b, double *an){
            repf (i, 0, a) repf (j, 0, a*b) bn[i][j] = 0;
            bn[0][0] = 1;
            repf (i, 1, a) repf (j, 0, a*b) repf (k, 1, b) bn[i][j+k] += bn[i-1][j];
            repf (i, a, a*b) an[i] = bn[a][i];
        }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(int a, int b, int c, int d, double __expected, int caseNo) {

    time_t startClock = clock();
    FixedDiceGameDiv1 *instance = new FixedDiceGameDiv1();
    double __result = instance->getExpectation(a, b, c, d);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            int b = 2;
            int c = 1;
            int d = 5;
            double __expected = 2.0;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 1: {
            int a = 3;
            int b = 1;
            int c = 1;
            int d = 3;
            double __expected = 3.0;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 2: {
            int a = 1;
            int b = 5;
            int c = 1;
            int d = 1;
            double __expected = 3.4999999999999996;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 3: {
            int a = 2;
            int b = 6;
            int c = 50;
            int d = 30;
            double __expected = -1.0;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 4: {
            int a = 50;
            int b = 11;
            int c = 50;
            int d = 50;
            double __expected = 369.8865999182022;
            return do_test(a, b, c, d, __expected, __no);
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
    cout << "FixedDiceGameDiv1 (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403971332;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
