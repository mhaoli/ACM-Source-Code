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

class IncrementingSequence {
    public:
    bool v[105];
    string canItBeDone(int k, vector<int> an) {
        string no = "IMPOSSIBLE", yes = "POSSIBLE";
        int n = sz(an);
        sort (all(an));
        clr (v, 0);
        repf (i, 0, n-1){
            bool ans = 0;
            int t = an[i];
            while (t < 60){
                bool u = 0;
                repf (j, 1, n) if (j == t && !v[j]){
                    v[j] = 1; u = 1; break;
                }
                if (u){
                    ans = 1; break;
                }
                t += k;
            }
            if (!ans) return no;
        }
        return yes;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int k, vector<int> A, string __expected, int caseNo) {

    time_t startClock = clock();
    IncrementingSequence *instance = new IncrementingSequence();
    string __result = instance->canItBeDone(k, A);
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
            int k = 3;
            int A[] = {
                1, 2, 4, 3
            };
            string __expected = "POSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
        }
        case 1: {
            int k = 5;
            int A[] = {
                2, 2
            };
            string __expected = "IMPOSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
        }
        case 2: {
            int k = 1;
            int A[] = {
                1, 1, 1, 1, 1, 1, 1, 1
            };
            string __expected = "POSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
        }
        case 3: {
            int k = 2;
            int A[] = {
                5, 3, 3, 2, 1
            };
            string __expected = "IMPOSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
        }
        case 4: {
            int k = 9;
            int A[] = {
                1, 2, 3, 1, 4, 5, 6, 7, 9, 8
            };
            string __expected = "POSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
        }
        case 5: {
            int k = 2;
            int A[] = {
                1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2
            };
            string __expected = "POSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
        }
        case 6: {
            int k = 1;
            int A[] = {
                1
            };
            string __expected = "POSSIBLE";
            return do_test(k, to_vector(A), __expected, __no);
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
    cout << "IncrementingSequence (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403970453;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
