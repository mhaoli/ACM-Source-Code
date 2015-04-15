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

int64 C[5005][5005];

class LongWordsDiv1 {
    public:
    int64 fac[5005], d[5005];
    int count(int n){
        //string no = "Impossible", yes = "Possible";
        fac[1] = 1; fac[2] = 2;
        repf (i, 3, n) fac[i] = fac[i-1] * i % mod;

        C[1][1] = C[1][0] = 1;
        repf (i, 2, n){
            C[i][0] = C[i][i] = 1;
            repf (j, 1, i-1) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }

        clr (d, 0);
        d[1] = 1; d[2] = 2;
        repf (i, 3, n){
            for (int j = 2; j < 2*i-2; j += 2) d[i] = (d[i] + ((C[i-1][j/2] * d[j/2]) % mod) * d[(2*i-j-2)/2]) % mod;
            d[i] = (d[i] * i + d[i-1] * i) % mod;
        }
        return d[n];
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int __expected, int caseNo) {

    time_t startClock = clock();
    LongWordsDiv1 *instance = new LongWordsDiv1();
    int __result = instance->count(n);
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
            int n = 1;
            int __expected = 1;
            return do_test(n, __expected, __no);
        }
        case 1: {
            int n = 2;
            int __expected = 2;
            return do_test(n, __expected, __no);
        }
        case 2: {
            int n = 5;
            int __expected = 1080;
            return do_test(n, __expected, __no);
        }
        case 3: {
            int n = 100;
            int __expected = 486425238;
            return do_test(n, __expected, __no);
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
    cout << "LongWordsDiv1 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1398388859;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
