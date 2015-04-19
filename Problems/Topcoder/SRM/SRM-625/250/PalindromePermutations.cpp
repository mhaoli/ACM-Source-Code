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

class PalindromePermutations {
    public:
    int num[30];
    double palindromeProbability(string s){
        int n = sz(s);
        repf (i, 0, n-1) num[s[i] - 'a'] ++;
        int cnt = 0;
        repf (i, 0, 25) if (num[i] & 1) ++ cnt;
        if (cnt > 0 && (!(n & 1))) return 0.0;
        if (cnt > 1) return 0.0;

        double t1 = calc ();
        repf (i, 0, 25) num[i] /= 2;
        double t2 = calc ();
        return (double)(t2 / t1);
    }
    double calc(){
        int sum = 0;
        repf (i, 0, 25) sum += num[i];
        double t = fac (sum);
        repf (i, 0, 25) t /= fac(num[i]);
        return t;
    }
    double fac(int x){
        double ret = 1.0;
        repf (i, 2, x) ret *= (i + 0.0);
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(string word, double __expected, int caseNo) {

    time_t startClock = clock();
    PalindromePermutations *instance = new PalindromePermutations();
    double __result = instance->palindromeProbability(word);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            string word = "haha";
            double __expected = 0.3333333333333333;
            return do_test(word, __expected, __no);
        }
        case 1: {
            string word = "xxxxy";
            double __expected = 0.2;
            return do_test(word, __expected, __no);
        }
        case 2: {
            string word = "xxxx";
            double __expected = 1.0;
            return do_test(word, __expected, __no);
        }
        case 3: {
            string word = "abcde";
            double __expected = 0.0;
            return do_test(word, __expected, __no);
        }
        case 4: {
            string word = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
            double __expected = 0.025641025641025637;
            return do_test(word, __expected, __no);
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
    cout << "PalindromePermutations (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403175771;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
