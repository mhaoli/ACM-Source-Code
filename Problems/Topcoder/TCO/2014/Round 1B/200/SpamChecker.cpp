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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class SpamChecker {
    public:
    string spamCheck(string s, int g, int b) {
        string no = "SPAM", yes = "NOT SPAM";
        int cnt = 0;
        repf(i, 0, sz(s)-1){
            if (s[i] == 'o') cnt += g;
            else cnt -= b;
            if (cnt < 0) return no;
        }
        return yes;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string judgeLog, int good, int bad, string __expected, int caseNo) {

    time_t startClock = clock();
    SpamChecker *instance = new SpamChecker();
    string __result = instance->spamCheck(judgeLog, good, bad);
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
            string judgeLog = "ooooxxxo";
            int good = 2;
            int bad = 3;
            string __expected = "SPAM";
            return do_test(judgeLog, good, bad, __expected, __no);
        }
        case 1: {
            string judgeLog = "ooooxxxo";
            int good = 3;
            int bad = 4;
            string __expected = "NOT SPAM";
            return do_test(judgeLog, good, bad, __expected, __no);
        }
        case 2: {
            string judgeLog = "xooooooooooooooooooooooooooo";
            int good = 1000;
            int bad = 1;
            string __expected = "SPAM";
            return do_test(judgeLog, good, bad, __expected, __no);
        }
        case 3: {
            string judgeLog = "oxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
            int good = 1000;
            int bad = 1;
            string __expected = "NOT SPAM";
            return do_test(judgeLog, good, bad, __expected, __no);
        }
        case 4: {
            string judgeLog = "ooxoxoxooxoxxoxoxooxoxoxoxxoxx";
            int good = 15;
            int bad = 17;
            string __expected = "SPAM";
            return do_test(judgeLog, good, bad, __expected, __no);
        }
        case 5: {
            string judgeLog = "oooxoxoxoxoxoxooxooxoxooxo";
            int good = 16;
            int bad = 18;
            string __expected = "NOT SPAM";
            return do_test(judgeLog, good, bad, __expected, __no);
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
    cout << "SpamChecker (200 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397923243;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 200 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
