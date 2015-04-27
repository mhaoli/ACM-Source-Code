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

class TheNicePair {
        public:
                int solve(vector<int> A);
};

int n;
vector<int> A;

bool check(int t1, int t2) {
        int limit = (t2 - t1 + 2) >> 1;
        for(int t = 2, i, j, cnt; t <= 1000; ++t) {
                cnt = 0;
                for(i = t1; i <= t2; ++i) if(A[i] % t == 0) {
                        if(++cnt >= limit) return 1;
                }
        }
        return 0;
}

int TheNicePair::solve(vector<int> AA){
        //string yes = "Possible", no = "Impossible";
        A = AA;
        n = A.size();
        for(int l = n, i, j, k; l; --l) {
                for(i = 0, j = l-1; j < n; ++j, ++i) {
                        if(check(i, j)) return l - 1;
                }
        }
        return -1;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> A, int __expected, int caseNo) {

    time_t startClock = clock();
    TheNicePair *instance = new TheNicePair();
    int __result = instance->solve(A);
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
            int A[] = {
                5, 5, 5, 5, 5
            };
            int __expected = 4;
            return do_test(to_vector(A), __expected, __no);
        }
        case 1: {
            int A[] = {
                1, 1, 1, 1
            };
            int __expected = -1;
            return do_test(to_vector(A), __expected, __no);
        }
        case 2: {
            int A[] = {
                2, 3, 5, 7
            };
            int __expected = 1;
            return do_test(to_vector(A), __expected, __no);
        }
        case 3: {
            int A[] = {
                8, 8, 5, 5, 5
            };
            int __expected = 4;
            return do_test(to_vector(A), __expected, __no);
        }
        case 4: {
            int A[] = {
                1, 1000, 1000, 1, 1000, 1, 999
            };
            int __expected = 5;
            return do_test(to_vector(A), __expected, __no);
        }
        case 5: {
            int A[] = {
                1000, 1, 1, 1000
            };
            int __expected = 3;
            return do_test(to_vector(A), __expected, __no);
        }
        case 6: {
            int A[] = {
                1, 1, 953, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 953, 1, 953, 953, 1, 1, 1, 1, 1, 1, 1, 953, 953, 953, 1, 1, 1, 1, 1, 953, 953, 1, 1, 1, 953, 953, 953, 1
            };
            int __expected = 15;
            return do_test(to_vector(A), __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "TheNicePair (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430114948;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
