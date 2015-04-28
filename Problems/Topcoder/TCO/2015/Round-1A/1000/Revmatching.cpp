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

class Revmatching {
        public:
                int smallest(vector<string> A);
};

int cost[1<<21][22], idx[1<<21];

int Revmatching::smallest(vector<string> A){
        //string yes = "Possible", no = "Impossible";
        int n = A.size(), ans = ~0u>>1;
        for(int i = 0; i < n; ++i) idx[1<<i] = i;
        memset(cost, 0, sizeof cost);
        for(int i = 0, j, k, t; i < n; ++i) {
                for(j = 0; j < (1<<n); ++j) {
                        for(k = j; k; k ^= t) {
                                t = k & (-k);
                                cost[j][i] += A[i][idx[t]] - '0';
                        }
                }
        }
        for(int i = 1, j, t, tmp; i < (1<<n); ++i) {
                sort(cost[i], cost[i] + n);
                t = n - __builtin_popcount(i) + 1;
                tmp = 0;
                for(j = 0; j < t; ++j) tmp += cost[i][j];
                //if(n <= 5) out(i), out(t), out(tmp), out(cost[1][0]);
                chmin(ans, tmp);
        }
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> A, int __expected, int caseNo) {

    time_t startClock = clock();
    Revmatching *instance = new Revmatching();
    int __result = instance->smallest(A);
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
            string A[] = {
                "1"
            };
            int __expected = 1;
            return do_test(to_vector(A), __expected, __no);
        }
        case 1: {
            string A[] = {
                "0"
            };
            int __expected = 0;
            return do_test(to_vector(A), __expected, __no);
        }
        case 2: {
            string A[] = {
                "44",
                "44"
            };
            int __expected = 8;
            return do_test(to_vector(A), __expected, __no);
        }
        case 3: {
            string A[] = {
                "861",
                "870",
                "245"
            };
            int __expected = 6;
            return do_test(to_vector(A), __expected, __no);
        }
        case 4: {
            string A[] = {
                "01000",
                "30200",
                "11102",
                "10001",
                "11001"
            };
            int __expected = 0;
            return do_test(to_vector(A), __expected, __no);
        }
        case 5: {
            string A[] = {
                "0111101100",
                "0001101001",
                "1001001000",
                "1000100001",
                "0110011111",
                "0011110100",
                "1000001100",
                "0001100000",
                "1000100001",
                "0101110010"
            };
            int __expected = 1;
            return do_test(to_vector(A), __expected, __no);
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
    cout << "Revmatching (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430233444;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
