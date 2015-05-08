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
const int inf = ~0u>>2;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class Mutalisk {
        public:
                int minimalAttacks(vector<int> x);
};

vector<int> an;
int dp[22][150][150];

bool check(int K) {
        int n = SZ(an);
        memset(dp, 127, sizeof dp);
        dp[n][0][0] = 0;
        for(int i = n-1; i >= 0; --i) {
                for(int t1 = 0; t1 <= K; ++t1) {
                        for(int t2 = 0; t2 <= K; ++t2) if(dp[i+1][t1][t2] < inf) {
                                for(int j = 0; j <= K - t1 && (!j || (j - 1) * 9 < an[i]); ++j) {
                                        for(int k = 0; k <= K - t2 && (!k || (k - 1) * 3 + j * 9 < an[i]); ++k) {
                                                //if(K == 4 && i == n-1 && j == 1 && k == 0) puts("bb");
                                                int t = an[i] - 9 * j - 3 * k;
                                                if(t < 0) t = 0;
                                                if(t + j + k > K) continue;
                                                chmin(dp[i][j + t1][k + t2], dp[i+1][t1][t2] + t);
                                        }
                                }
                        }
                }
        }
        for(int i = 0; i <= K; ++i) {
                for(int j = 0; j <= K; ++j) {
                        if(dp[0][i][j] <= K) return 1;
                }
        }
        return 0;
}

int Mutalisk::minimalAttacks(vector<int> x){
        //string yes = "Possible", no = "Impossible";
        an = x;
        int res = 140;
        for(int l = 0, r = 140, mid; l <= r; ) {
                mid = l + r >> 1;
                if(check(mid)) {
                        res = mid;
                        r = mid - 1;
                } else {
                        l = mid + 1;
                }
        }
        return res;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, int __expected, int caseNo) {

    time_t startClock = clock();
    Mutalisk *instance = new Mutalisk();
    int __result = instance->minimalAttacks(x);
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
            int x[] = {
                12, 10, 4
            };
            int __expected = 2;
            return do_test(to_vector(x), __expected, __no);
        }
        case 1: {
            int x[] = {
                54, 18, 6
            };
            int __expected = 6;
            return do_test(to_vector(x), __expected, __no);
        }
        case 2: {
            int x[] = {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            int __expected = 4;
            return do_test(to_vector(x), __expected, __no);
        }
        case 3: {
            int x[] = {
                55, 60, 53
            };
            int __expected = 13;
            return do_test(to_vector(x), __expected, __no);
        }
        case 4: {
            int x[] = {
                60
            };
            int __expected = 7;
            return do_test(to_vector(x), __expected, __no);
        }
        case 5: {
            int x[] = {
                60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60
            };
            int __expected = 93;
            return do_test(to_vector(x), __expected, __no);
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
    cout << "Mutalisk (650 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430920844;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 650 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
