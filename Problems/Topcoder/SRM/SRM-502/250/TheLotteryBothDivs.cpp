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

class TheLotteryBothDivs {
    public:
    double find(vector<string> s){
        sort (all (s)); s.erase (unique (all(s)), s.end());
        vs ans;
        repf (i, 0, sz(s)-1) {
            bool u = 1;
            repf (j, 0, sz(s)-1) if (i != j && ok (s[i], s[j])) u = 0;
            if (u) ans.pb (s[i]);
        }
        double ret = 0;
        repf (i, 0, sz(ans)-1){
            double tmp = 1;
            repf (j, 0, sz(ans[i])-1) tmp /= 10;
            ret += tmp;
        }
        return ret;
    }
    bool ok (string a, string b){
        if (sz(a) <= sz(b)) return 0;
        for (int i = sz(b)-1, j = sz(a)-1; i >= 0; -- i, -- j) if (b[i] != a[j]) return 0;
        return 1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<string> goodSuffixes, double __expected, int caseNo) {

    time_t startClock = clock();
    TheLotteryBothDivs *instance = new TheLotteryBothDivs();
    double __result = instance->find(goodSuffixes);
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
            string goodSuffixes[] = {
                "4"
            };
            double __expected = 0.1;
            return do_test(to_vector(goodSuffixes), __expected, __no);
        }
        case 1: {
            string goodSuffixes[] = {
                "4",
                "7"
            };
            double __expected = 0.2;
            return do_test(to_vector(goodSuffixes), __expected, __no);
        }
        case 2: {
            string goodSuffixes[] = {
                "47",
                "47"
            };
            double __expected = 0.01;
            return do_test(to_vector(goodSuffixes), __expected, __no);
        }
        case 3: {
            string goodSuffixes[] = {
                "47",
                "58",
                "4747",
                "502"
            };
            double __expected = 0.021;
            return do_test(to_vector(goodSuffixes), __expected, __no);
        }
        case 4: {
            string goodSuffixes[] = {
                "8542861",
                "1954",
                "6",
                "523",
                "000000000",
                "5426",
                "8"
            };
            double __expected = 0.201100101;
            return do_test(to_vector(goodSuffixes), __expected, __no);
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
    cout << "TheLotteryBothDivs (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402478917;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
