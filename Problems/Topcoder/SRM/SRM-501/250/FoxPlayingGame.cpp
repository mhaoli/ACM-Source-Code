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

class FoxPlayingGame {
    public:
    double theMax(int nA, int nB, int pa, int pb) {
        double sa = pa * nA / 1000.0, sb = pb / 1000.0;
        double ans = -inf;
        repf (i, 1, nB+1) chmax (ans, solve (i, sa, sb, nB+1));
        return ans;
    }
    double solve (int p, double sa, double sb, int n){
        double ret = 0;
        repf (i, 1, n){
            if (p == i) ret += sa;
            else ret *= sb;
        }
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(int nA, int nB, int paramA, int paramB, double __expected, int caseNo) {

    time_t startClock = clock();
    FoxPlayingGame *instance = new FoxPlayingGame();
    double __result = instance->theMax(nA, nB, paramA, paramB);
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
            int nA = 5;
            int nB = 4;
            int paramA = 3000;
            int paramB = 2000;
            double __expected = 240.0;
            return do_test(nA, nB, paramA, paramB, __expected, __no);
        }
        case 1: {
            int nA = 3;
            int nB = 3;
            int paramA = 2000;
            int paramB = 100;
            double __expected = 6.0;
            return do_test(nA, nB, paramA, paramB, __expected, __no);
        }
        case 2: {
            int nA = 4;
            int nB = 3;
            int paramA = -2000;
            int paramB = 2000;
            double __expected = -8.0;
            return do_test(nA, nB, paramA, paramB, __expected, __no);
        }
        case 3: {
            int nA = 5;
            int nB = 5;
            int paramA = 2000;
            int paramB = -2000;
            double __expected = 160.0;
            return do_test(nA, nB, paramA, paramB, __expected, __no);
        }
        case 4: {
            int nA = 50;
            int nB = 50;
            int paramA = 10000;
            int paramB = 2000;
            double __expected = 5.62949953421312E17;
            return do_test(nA, nB, paramA, paramB, __expected, __no);
        }
        case 5: {
            int nA = 41;
            int nB = 34;
            int paramA = 9876;
            int paramB = -1234;
            double __expected = 515323.9982341775;
            return do_test(nA, nB, paramA, paramB, __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxPlayingGame (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402406454;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
