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
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x)*(x))
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) cout<<#x<<":"<<(x)<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class UnrelatedPaths {
        public:
                int maxUnrelatedPaths(vector<int> parent);
};

vector<int> son[1111];

int dfs(int u, int pre) {
        int ret = 0;
        bool flag = false;
        for(auto i : son[u]) if(i != pre) {
                flag = true;
                ret += dfs(i, u);
        }
        if(!flag) ++ret;
        return ret;
}

int UnrelatedPaths::maxUnrelatedPaths(vector<int> f){
        //string yes = "Possible", no = "Impossible";
        int n = SZ(f) + 1;
        for(int i = 0; i < n; ++i) {
                son[i].clear();
        }
        for(int i = 1; i < n; ++i) {
                son[f[i-1]].push_back(i);
        }
        return dfs(0, -1);
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> parent, int __expected, int caseNo) {

    time_t startClock = clock();
    UnrelatedPaths *instance = new UnrelatedPaths();
    int __result = instance->maxUnrelatedPaths(parent);
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
            int parent[] = {
                0, 1, 1, 2, 3
            };
            int __expected = 2;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 1: {
            int parent[] = {
                0, 0, 1, 1, 2, 2
            };
            int __expected = 4;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 2: {
            int parent[] = {
                0, 1, 2, 3
            };
            int __expected = 1;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 3: {
            int parent[] = {
                0, 1, 1, 2, 2, 2, 4, 6, 5, 0, 10, 5, 12, 12, 10, 4, 16, 12, 5, 3, 20, 12, 11, 21, 9, 5, 1, 20, 15, 24, 6, 8, 15
            };
            int __expected = 17;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 4: {
            int parent[] = {
                0, 1, 1, 1, 1, 0, 2, 5, 1, 6, 7, 10, 5, 10, 8, 5, 16, 14, 8, 14, 4, 14, 15, 21, 0, 24, 11, 1, 9, 18, 13, 20, 6, 28, 19, 28, 14, 11, 38, 26, 25, 10, 23, 43
            };
            int __expected = 19;
            return do_test(to_vector(parent), __expected, __no);
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
    cout << "UnrelatedPaths (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1431187958;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
