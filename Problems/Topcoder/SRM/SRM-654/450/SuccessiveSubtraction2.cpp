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

class SuccessiveSubtraction2 {
        public:
                vector<int> calc(vector<int> a, vector<int> p, vector<int> v);
};

vector<int> an, pos, change;

int dp[2222][3][3];

int solve() {
        if(SZ(an) == 1) return an[0];
        else if(SZ(an) == 2) return an[0] - an[1];

        int n = SZ(an);
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < 3; ++j) {
                        for(int k = 0; k < 3; ++k) dp[i][j][k] = -inf;
                }
        }

        //dp[0][1][0] = dp[0][0][0] = an[0];
        dp[0][0][0] = an[0];
        for(int i = 0; i < n-1; ++i) {
                for(int j = 0; j < 3; ++j) {
                        for(int k = 0; k < 3; ++k) if(dp[i][j][k] > -inf){
                                if(k) {
                                        chmax(dp[i+1][j][0], dp[i][j][k] + an[i+1]);
                                        chmax(dp[i+1][j][1], dp[i][j][k] + an[i+1]);
                                } else {
                                        chmax(dp[i+1][j][0], dp[i][j][k] - an[i+1]);
                                        if(j != 2) chmax(dp[i+1][j+1][1], dp[i][j][k] - an[i+1]);
                                }
                        }
                }
        }
        return max(dp[n-1][0][0], max(dp[n-1][1][0], dp[n-1][2][0]));
}

vector<int> SuccessiveSubtraction2::calc(vector<int> a, vector<int> p, vector<int> v){
        //string yes = "Possible", no = "Impossible";
        an = a; pos = p; change = v;
        vector<int> ans;
        for(int i = 0; i < SZ(p); ++i) {
                an[p[i]] = v[i];
                ans.push_back(solve());
        }
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(vector<int> a, vector<int> p, vector<int> v, vector<int> __expected, int caseNo) {

    time_t startClock = clock();
    SuccessiveSubtraction2 *instance = new SuccessiveSubtraction2();
    vector<int> __result = instance->calc(a, p, v);
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
            int a[] = {
                1, 2, 3, 4, 5
            };
            int p[] = {
                1, 2, 0, 4, 3
            };
            int v[] = {
                3, 9, -10, 5, 1
            };
            int __expected[] = {
                10, 16, 5, 5, 2
            };
            return do_test(to_vector(a), to_vector(p), to_vector(v), to_vector(__expected), __no);
        }
        case 1: {
            int a[] = {
                -100, -100, -100, -100, -100
            };
            int p[] = {
                0, 1, 2, 3, 4
            };
            int v[] = {
                0, 0, 0, 0, 0
            };
            int __expected[] = {
                400, 300, 200, 100, 0
            };
            return do_test(to_vector(a), to_vector(p), to_vector(v), to_vector(__expected), __no);
        }
        case 2: {
            int a[] = {
                83, 0, 25, 21
            };
            int p[] = {
                0, 3, 2, 1, 3, 1, 2
            };
            int v[] = {
                10, -90, 33, 52, -100, 0, 45
            };
            int __expected[] = {
                56, 125, 133, 81, 91, 143, 155
            };
            return do_test(to_vector(a), to_vector(p), to_vector(v), to_vector(__expected), __no);
        }
        case 3: {
            int a[] = {
                1
            };
            int p[] = {
                0, 0, 0, 0
            };
            int v[] = {
                10, -10, 100, -100
            };
            int __expected[] = {
                10, -10, 100, -100
            };
            return do_test(to_vector(a), to_vector(p), to_vector(v), to_vector(__expected), __no);
        }
        case 4: {
            int a[] = {
                -11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63
            };
            int p[] = {
                19, 5, 3, 10, 4, 18, 5, 2, 0, 15
            };
            int v[] = {
                -19, 21, 7, -66, 38, -39, -22, 24, -32, 13
            };
            int __expected[] = {
                451, 443, 412, 440, 457, 467, 468, 464, 443, 458
            };
            return do_test(to_vector(a), to_vector(p), to_vector(v), to_vector(__expected), __no);
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
    cout << "SuccessiveSubtraction2 (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430455708;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
