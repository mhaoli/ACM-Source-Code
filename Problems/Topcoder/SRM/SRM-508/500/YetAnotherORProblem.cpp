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

int d[70][1100], opt[15];

class YetAnotherORProblem {
    public:
    int countSequences(vector<long long> an){
        int n = sz(an);
        clr (d, 0); d[62][0] = 1;
        repd (i, 62, 1) repf (j, 0, (1<<n)-1) if (d[i][j]){
            int sta = j;
            repf (k, 0, n-1) 
                if (an[k] & (1LL<<(i-1))) opt[k] = 1 << k, sta |= opt[k];
                else opt[k] = 0;
            d[i-1][sta] += d[i][j];
            if (d[i-1][sta] >= mod) d[i-1][sta] -= mod;

            repf (k, 0, n-1){
                if ((1LL<<(i-1)) > an[k]) continue;
                int64 tmp = (an[k] & (1LL<<(i-1))) > 0;
                if (!(j & (1<<k)) && !tmp) continue;

                sta = j;
                repf (tk, 0, n-1) if (k != tk) sta |= opt[tk];
                d[i-1][sta] += d[i][j];
                if (d[i-1][sta] >= mod) d[i-1][sta] -= mod;
            }
        }
        int ans = 0;
        repf (i, 0, (1<<n)-1){
            ans += d[0][i];
            if (ans >= mod) ans -= mod;
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<long long> R, int __expected, int caseNo) {

    time_t startClock = clock();
    YetAnotherORProblem *instance = new YetAnotherORProblem();
    int __result = instance->countSequences(R);
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
            long long R[] = {
                3LL, 5LL
            };
            int __expected = 15;
            return do_test(to_vector(R), __expected, __no);
        }
        case 1: {
            long long R[] = {
                3LL, 3LL, 3LL
            };
            int __expected = 16;
            return do_test(to_vector(R), __expected, __no);
        }
        case 2: {
            long long R[] = {
                1LL, 128LL
            };
            int __expected = 194;
            return do_test(to_vector(R), __expected, __no);
        }
        case 3: {
            long long R[] = {
                26LL, 74LL, 25LL, 30LL
            };
            int __expected = 8409;
            return do_test(to_vector(R), __expected, __no);
        }
        case 4: {
            long long R[] = {
                1000000000LL, 1000000000LL
            };
            int __expected = 420352509;
            return do_test(to_vector(R), __expected, __no);
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
    cout << "YetAnotherORProblem (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405344104;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
