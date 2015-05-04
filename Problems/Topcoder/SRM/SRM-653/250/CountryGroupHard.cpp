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

class CountryGroupHard {
        public:
                string solve(vector<int> a);
};

int dp[1111];

string CountryGroupHard::solve(vector<int> an){
        string yes = "Sufficient", no = "Insufficient";
        int n = SZ(an);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 0; i < n; ++i) if(dp[i]) {
                for(int j = i; j < n; ++j) {
                        if(an[j]) {
                                if(i + an[j] - 1 >= j) {
                                        bool flag = 1;
                                        for(int k = j+1; k < i + an[j]; ++k) {
                                                if(an[k] && an[k] != an[j]) {
                                                        flag = 0; break;
                                                }
                                        }
                                        if(flag) dp[i+an[j]] += dp[i];
                                }
                                break;
                        } else {
                                dp[j+1] += dp[i];
                        }
                }
        }
        OUT(dp[n]);
        return dp[n] == 1 ? yes : no;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> a, string __expected, int caseNo) {

    time_t startClock = clock();
    CountryGroupHard *instance = new CountryGroupHard();
    string __result = instance->solve(a);
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
                    1
                //0, 2, 3, 0, 0
            };
            string __expected = "Sufficient";
            return do_test(to_vector(a), __expected, __no);
        }
        case 1: {
            int a[] = {
                0, 2, 0
            };
            string __expected = "Insufficient";
            return do_test(to_vector(a), __expected, __no);
        }
        case 2: {
            int a[] = {
                0, 3, 0, 0, 3, 0
            };
            string __expected = "Sufficient";
            return do_test(to_vector(a), __expected, __no);
        }
        case 3: {
            int a[] = {
                0, 0, 3, 3, 0, 0
            };
            string __expected = "Insufficient";
            return do_test(to_vector(a), __expected, __no);
        }
        case 4: {
            int a[] = {
                2, 2, 0, 2, 2
            };
            string __expected = "Sufficient";
            return do_test(to_vector(a), __expected, __no);
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
    cout << "CountryGroupHard (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430563141;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
