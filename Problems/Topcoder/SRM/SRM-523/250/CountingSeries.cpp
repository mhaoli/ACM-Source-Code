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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

class CountingSeries {
    public:
    long long countThem(long long up_a, long long b, long long c, long long d, long long up){
        //string no = "Impossible", yes = "Possible";
        int64 t = c, res = 0, a = up_a % b;
        while (t <= up){
            ++ res;
            if ((t % b) == a && t >= up_a) -- res;
            if (d == 1) break;
            t *= d;
        }
        if (up_a > up) return res;
        res += calc (up, b, a) - calc (up_a-1, b, a);
        return res;
    }
    int64 calc (int64 up, int64 b, int64 a){
        int64 t = up / b, res = t;
        if (t * b + a <= up) ++ res;
        return res;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long a, long long b, long long c, long long d, long long upperBound, long long __expected, int caseNo) {

    time_t startClock = clock();
    CountingSeries *instance = new CountingSeries();
    long long __result = instance->countThem(a, b, c, d, upperBound);
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
            //long long a = 1LL;
            //long long b = 1LL;
            //long long c = 1LL;
            //long long d = 2LL;
            //long long upperBound = 1000LL;
            //long long __expected = 1000LL;
            long long a = 801992493102LL;
            long long b = 165925373974LL;
            long long c = 292778598713LL;
            long long d = 58875LL;
            long long upperBound = 438429892615LL;
            long long __expected = 1LL;

            return do_test(a, b, c, d, upperBound, __expected, __no);
        }
        case 1: {
            long long a = 3LL;
            long long b = 3LL;
            long long c = 1LL;
            long long d = 2LL;
            long long upperBound = 1000LL;
            long long __expected = 343LL;
            return do_test(a, b, c, d, upperBound, __expected, __no);
        }
        case 2: {
            long long a = 40LL;
            long long b = 77LL;
            long long c = 40LL;
            long long d = 100000LL;
            long long upperBound = 40LL;
            long long __expected = 1LL;
            return do_test(a, b, c, d, upperBound, __expected, __no);
        }
        case 3: {
            long long a = 452LL;
            long long b = 24LL;
            long long c = 4LL;
            long long d = 5LL;
            long long upperBound = 600LL;
            long long __expected = 10LL;
            return do_test(a, b, c, d, upperBound, __expected, __no);
        }
        case 4: {
            long long a = 234LL;
            long long b = 24LL;
            long long c = 377LL;
            long long d = 1LL;
            long long upperBound = 10000LL;
            long long __expected = 408LL;
            return do_test(a, b, c, d, upperBound, __expected, __no);
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
    cout << "CountingSeries (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409019702;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
