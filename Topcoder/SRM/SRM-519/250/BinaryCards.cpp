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
#define two(x) (1<<(x))
#define twol(x) (1LL<<(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

class BinaryCards {
    public:
    long long largestNumber(long long A, long long B){
        if (A == B) return A;
        vi a, b;
        while (A) a.pb (A & 1), A >>= 1;
        while (B) b.pb (B & 1), B >>= 1;

        while (sz (a) < sz (b)) a.pb (0);
        red (i, sz (a)-1, 0) if (a[i] != b[i]){
            red (j, i, 0) a[j] = 1; break;
        }
        
        int64 ret = 0;
        red (i, sz (a)-1, 0) ret = (ret<<1) | a[i];
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long A, long long B, long long __expected, int caseNo) {

    time_t startClock = clock();
    BinaryCards *instance = new BinaryCards();
    long long __result = instance->largestNumber(A, B);
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
            long long A = 6LL;
            long long B = 6LL;
            long long __expected = 6LL;
            return do_test(A, B, __expected, __no);
        }
        case 1: {
            long long A = 6LL;
            long long B = 7LL;
            long long __expected = 7LL;
            return do_test(A, B, __expected, __no);
        }
        case 2: {
            long long A = 6LL;
            long long B = 8LL;
            long long __expected = 15LL;
            return do_test(A, B, __expected, __no);
        }
        case 3: {
            long long A = 1LL;
            long long B = 11LL;
            long long __expected = 15LL;
            return do_test(A, B, __expected, __no);
        }
        case 4: {
            long long A = 35LL;
            long long B = 38LL;
            long long __expected = 39LL;
            return do_test(A, B, __expected, __no);
        }
        case 5: {
            long long A = 1125899906842630LL;
            long long B = 1125899906842632LL;
            long long __expected = 1125899906842639LL;
            return do_test(A, B, __expected, __no);
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
    cout << "BinaryCards (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408711624;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
