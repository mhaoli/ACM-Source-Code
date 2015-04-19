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
const int mod = 1000000007;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

/*3 1
  4 2*/

class AlgridTwo {
    public:
    int n, m, d[55][55][2];
    int makeProgram(vector<string> an) {
        n = sz(an); m = sz(an[0]);
        int64 ans = 1;
        clr (d, 0);
        repf (i, 1, n-1) {
            d[i][0][0] = d[i][0][1] = 1;

            repf (j, 1, m-1){
                if (an[i-1][j-1] == 'W'){
                    if (an[i-1][j] == 'W') d[i][j][1] = d[i][j][0] = d[i][j-1][idx(an[i][j-1])];
                    else if (an[i][j-1] == 'W') d[i][j][0] = 2 * ((d[i][j-1][0] + d[i][j-1][1]) % mod) % mod;
                }
                else{
                    if (an[i-1][j] == 'B') d[i][j][0] = d[i][j-1][0], d[i][j][1] = d[i][j-1][1];
                    else if (an[i][j-1] == 'B') d[i][j][1] = 2 * ((d[i][j-1][0] + d[i][j-1][1]) % mod) % mod;
                }
            }
            ans = ans * d[i][m-1][idx(an[i][m-1])] % mod;
        }
        return (int)ans;
    }
    int idx(char c){
        return c == 'W' ? 0 : 1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> output, int __expected, int caseNo) {

    time_t startClock = clock();
    AlgridTwo *instance = new AlgridTwo();
    int __result = instance->makeProgram(output);
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
            string output[] = {
                "BB",
                "WB"
            };
            int __expected = 1;
            return do_test(to_vector(output), __expected, __no);
        }
        case 1: {
            string output[] = {
                "BBWBBB",
                "WBWBBW"
            };
            int __expected = 8;
            return do_test(to_vector(output), __expected, __no);
        }
        case 2: {
            string output[] = {
                "BWBWBW",
                "WWWWWW",
                "WBBWBW"
            };
            int __expected = 0;
            return do_test(to_vector(output), __expected, __no);
        }
        case 3: {
            string output[] = {
                "WWBWBWBWBWBWBWBW",
                "BWBWBWBWBWBWBWBB",
                "BWBWBWBWBWBWBWBW"
            };
            int __expected = 73741817;
            return do_test(to_vector(output), __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "AlgridTwo (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403006523;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
