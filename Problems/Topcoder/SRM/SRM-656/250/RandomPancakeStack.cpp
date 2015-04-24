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
#include <complex>

using namespace std;

#define x first
#define y second
#define sqr(x) ((x)*(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/***head***/

class RandomPancakeStack {
        public:
                double expectedDeliciousness(vector<int> d);
};

double fac[1111];

double C(int n, int m) {
        return fac[n] - fac[m] - fac[n - m];
}

double RandomPancakeStack::expectedDeliciousness(vector<int> d){
        //string yes = "Possible", no = "Impossible";
        fac[0] = 0;
        for(int i = 1; i <= 300; ++i) fac[i] = fac[i-1] + log(i + 0.0);
        double sum = 0, tmp;
        int n = d.size();
        for(int i = 0; i < n; ++i) {
                tmp = 0;
                for(int t = 0; t <= i; ++t) {
                        tmp += exp(C(i, t) + fac[n - t - 1] - fac[n]);
                }
                sum += tmp * d[n - i - 1];
        }
        return sum;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<int> d, double __expected, int caseNo) {

    time_t startClock = clock();
    RandomPancakeStack *instance = new RandomPancakeStack();
    double __result = instance->expectedDeliciousness(d);
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
            int d[] = {
                1, 1, 1
            };
            double __expected = 1.6666666666666667;
            return do_test(to_vector(d), __expected, __no);
        }
        case 1: {
            int d[] = {
                3, 6, 10, 9, 2
            };
            double __expected = 9.891666666666667;
            return do_test(to_vector(d), __expected, __no);
        }
        case 2: {
            int d[] = {
                10, 9, 8, 7, 6, 5, 4, 3, 2, 1
            };
            double __expected = 10.999999724426809;
            return do_test(to_vector(d), __expected, __no);
        }
        case 3: {
            int d[] = {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10
            };
            double __expected = 7.901100088183421;
            return do_test(to_vector(d), __expected, __no);
        }
        case 4: {
            int d[] = {
                2, 7, 1, 8, 2, 8, 1, 8, 2, 8, 4, 5, 90, 4, 5, 2, 3, 5, 60, 2, 8, 74, 7, 1
            };
            double __expected = 19.368705050402465;
            return do_test(to_vector(d), __expected, __no);
        }
        case 5: {
            int d[] = {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            double __expected = 1.718281828459045;
            return do_test(to_vector(d), __expected, __no);
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
    cout << "RandomPancakeStack (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1429269516;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
