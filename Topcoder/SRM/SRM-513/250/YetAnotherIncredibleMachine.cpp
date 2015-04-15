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
const int mod = 1000000009;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class YetAnotherIncredibleMachine {
    public:
    int countWays(vector<int> xn, vector<int> ln, vector<int> an){
        int n = sz(xn), m = sz(an);
        int64 ans = 1;
        repf (i, 0, n-1){
            int cnt = 0;
            repf (j, xn[i]-ln[i], xn[i]){
                int k = j + ln[i];
                bool u = 1;
                repf (t, 0, m-1) if (an[t] >= j && an[t] <= k) u = 0;
                if (u) ++ cnt;
            }
            ans = ans * cnt % mod;
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> platformMount, vector<int> platformLength, vector<int> balls, int __expected, int caseNo) {

    time_t startClock = clock();
    YetAnotherIncredibleMachine *instance = new YetAnotherIncredibleMachine();
    int __result = instance->countWays(platformMount, platformLength, balls);
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
            int platformMount[] = {
                7
            };
            int platformLength[] = {
                10
            };
            int balls[] = {
                3, 4
            };
            int __expected = 3;
            return do_test(to_vector(platformMount), to_vector(platformLength), to_vector(balls), __expected, __no);
        }
        case 1: {
            int platformMount[] = {
                1, 4
            };
            int platformLength[] = {
                3, 3
            };
            int balls[] = {
                2, 7
            };
            int __expected = 1;
            return do_test(to_vector(platformMount), to_vector(platformLength), to_vector(balls), __expected, __no);
        }
        case 2: {
            int platformMount[] = {
                4, 4, 4
            };
            int platformLength[] = {
                10, 9, 8
            };
            int balls[] = {
                1, 100
            };
            int __expected = 27;
            return do_test(to_vector(platformMount), to_vector(platformLength), to_vector(balls), __expected, __no);
        }
        case 3: {
            int platformMount[] = {
                0
            };
            int platformLength[] = {
                1
            };
            int balls[] = {
                0
            };
            int __expected = 0;
            return do_test(to_vector(platformMount), to_vector(platformLength), to_vector(balls), __expected, __no);
        }
        case 4: {
            int platformMount[] = {
                100, -4215, 251
            };
            int platformLength[] = {
                400, 10000, 2121
            };
            int balls[] = {
                5000, 2270, 8512, 6122
            };
            int __expected = 250379170;
            return do_test(to_vector(platformMount), to_vector(platformLength), to_vector(balls), __expected, __no);
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
    cout << "YetAnotherIncredibleMachine (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1406513780;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
