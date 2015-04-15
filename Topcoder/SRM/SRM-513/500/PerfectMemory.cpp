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

class PerfectMemory {
    public:
    double d[2600][2600];
    double getExpectation(int N, int M) {
        int n = N * M;
        repf (i, 0, n) repf (j, 0, n) d[i][j] = -1;
        double ans = dfs (n, 0);
        return ans;
    }
    double dfs (int n, int m){
        if (n == 0 && m == 0) return 0;
        if (n == 2 && (!m || m == 1)) return 1;
        if (2*m > n) return 0;
        double &ret = d[n][m];
        if (ret > -0.5) return ret + 1; ret = 0;

        if (m >= 1) ret += dfs (n-2, m-1) * m / (n-m);
        if (n - 2*m >= 1){
            double mul = (n - 2*m + 0.0) / (n - m - 1) / (n - m);
            ret += dfs (n-2, m) * mul;
            if (m >= 1) ret += m * (dfs (n-2, m) + 1) * mul;
            if (n - 2*m >= 4) ret += (n-2*m-2) * dfs (n, m+2) * mul;
        }
        return ret + 1;
    }
    double C2(int n){
        return 1.0 * n * (n-1) / 2;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(int N, int M, double __expected, int caseNo) {

    time_t startClock = clock();
    PerfectMemory *instance = new PerfectMemory();
    double __result = instance->getExpectation(N, M);
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
            int N = 1;
            int M = 2;
            double __expected = 1.0;
            return do_test(N, M, __expected, __no);
        }
        case 1: {
            int N = 2;
            int M = 2;
            double __expected = 2.6666666666666665;
            return do_test(N, M, __expected, __no);
        }
        case 2: {
            int N = 2;
            int M = 3;
            double __expected = 4.333333333333334;
            return do_test(N, M, __expected, __no);
        }
        case 3: {
            int N = 4;
            int M = 4;
            double __expected = 12.392984792984793;
            return do_test(N, M, __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "PerfectMemory (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1406513282;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
