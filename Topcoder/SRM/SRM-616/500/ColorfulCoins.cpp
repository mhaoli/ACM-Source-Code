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
typedef vector<int64> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class ColorfulCoins {
    public:
    vi an;
    int minQueries(vector<long long> v) {
        an.clear();
        repf (i, 1, sz(v)-1) an.pb (v[i] / v[i-1]);
        sort (all(an));
        int ret = 1;
        repf (i, 0, sz(an)-1) chmax (ret, (int)(ceil(log(i+2) / log(an[i]))));
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<long long> values, int __expected, int caseNo) {

    time_t startClock = clock();
    ColorfulCoins *instance = new ColorfulCoins();
    int __result = instance->minQueries(values);
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
            long long values[] = {
                1LL
            };
            int __expected = 1;
            return do_test(to_vector(values), __expected, __no);
        }
        case 1: {
            long long values[] = {
                1LL, 3LL
            };
            int __expected = 1;
            return do_test(to_vector(values), __expected, __no);
        }
        case 2: {
            long long values[] = {
                1LL, 2LL, 4LL
            };
            int __expected = 2;
            return do_test(to_vector(values), __expected, __no);
        }
        case 3: {
            long long values[] = {
                1LL, 2LL, 4LL, 8LL, 16LL
            };
            int __expected = 3;
            return do_test(to_vector(values), __expected, __no);
        }
        case 4: {
            long long values[] = {
                1LL, 2LL, 6LL, 30LL, 90LL, 270LL, 810LL, 2430LL, 7290LL, 29160LL, 87480LL, 262440LL, 787320LL, 3149280LL, 9447840LL, 28343520LL, 56687040LL, 170061120LL, 510183360LL, 1530550080LL, 3061100160LL, 9183300480LL, 27549901440LL, 82649704320LL, 247949112960LL, 1239745564800LL, 3719236694400LL, 14876946777600LL, 44630840332800LL, 223154201664000LL, 669462604992000LL, 2008387814976000LL, 6025163444928000LL, 12050326889856000LL, 24100653779712000LL, 72301961339136000LL, 289207845356544000LL, 867623536069632000LL
            };
            int __expected = 4;
            return do_test(to_vector(values), __expected, __no);
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
    cout << "ColorfulCoins (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1398097601;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
