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

class FoxAverageSequence {
    public:
    int d[45][1605][45][2];
    int theCount(vector<int> seq) {
        int n = sz(seq);
        clr (d, 0); d[0][0][40][0] = 1;
        int ma = 0;
        repf (i, 1, n) repf (j, 0, ma) repf (k, 0, 40) repf (t, 0, 1)
            if (d[i-1][j][k][t]) repf (a, 0, i > 1 ? j / (i-1.0) : 40) if (ok (a, seq[i-1])){
                if (a > 40) break;
                if (k > a && t == 1 && i >= 3) continue;
                int tj = j + a, tt = k > a ? 1 : 0;
                chmax (ma, tj);

                int &change = d[i][tj][a][tt];
                change += d[i-1][j][k][t];
                if (change >= mod) change -= mod;
            }

        int ans = 0;
        repf (i, 0, ma) repf (j, 0, 40) repf (k, 0, 1) ans = (ans + d[n][i][j][k]) % mod;
        return ans;
    }
    bool ok (int a, int b){
        if (b == -1) return 1;
        return a == b;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> seq, int __expected, int caseNo) {

    time_t startClock = clock();
    FoxAverageSequence *instance = new FoxAverageSequence();
    int __result = instance->theCount(seq);
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
//    freopen("a.out","w",stdout);

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int seq[] = {
                3, -1
            };
            int __expected = 4;
            return do_test(to_vector(seq), __expected, __no);
        }
        case 1: {
            int seq[] = {
                5, 3, -1
            };
            int __expected = 2;
            return do_test(to_vector(seq), __expected, __no);
        }
        case 2: {
            int seq[] = {
                -1, 0, 40
            };
            int __expected = 0;
            return do_test(to_vector(seq), __expected, __no);
        }
        case 3: {
            int seq[] = {
                -1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1
            };
            int __expected = 579347890;
            return do_test(to_vector(seq), __expected, __no);
        }
        case 4: {
            int seq[] = {
                -1, 12, 25, 0, 18, -1
            };
            int __expected = 58;
            return do_test(to_vector(seq), __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxAverageSequenceEasy (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402407279;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
