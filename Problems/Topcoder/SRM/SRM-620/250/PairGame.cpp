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

class PairGame {
    public:
    int maxSum(int a, int b, int c, int d) {
        if (__gcd (a, b) != __gcd (c, d)) return -1;

        set<pii > st; 
        st.insert (mp (a, b));
        while (a > 0 && b > 0){
            if (a < b) b -= a;
            else a -= b;
            if (a > 0 && b > 0) st.insert (mp (a, b));
        }

        if (st.count (mp (c, d))) return c + d;
        while (c > 0 && d > 0){
            if (c < d) d -= c;
            else c -= d;
            if (st.count (mp (c, d))) return c + d;
        }
        return -1;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int a, int b, int c, int d, int __expected, int caseNo) {

    time_t startClock = clock();
    PairGame *instance = new PairGame();
    int __result = instance->maxSum(a, b, c, d);
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
            int b = 2;
            int c = 2;
            int d = 1;
            int __expected = 2;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 1: {
            int a = 15;
            int b = 4;
            int c = 10;
            int d = 7;
            int __expected = 7;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 2: {
            int a = 1;
            int b = 1;
            int c = 10;
            int d = 10;
            int __expected = -1;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 3: {
            int a = 1000;
            int b = 1001;
            int c = 2000;
            int d = 2001;
            int __expected = 1001;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 4: {
            int a = 10944;
            int b = 17928;
            int c = 7704;
            int d = 21888;
            int __expected = 144;
            return do_test(a, b, c, d, __expected, __no);
        }
        case 5: {
            int a = 1;
            int b = 1;
            int c = 1;
            int d = 1;
            int __expected = 2;
            return do_test(a, b, c, d, __expected, __no);
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
    cout << "PairGame (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1399737761;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
