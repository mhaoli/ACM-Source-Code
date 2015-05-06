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

class EllysSortingTrimmer {
    public:
    string getMin(string s, int l){
        //string no = "Impossible", yes = "Possible";
        if (sz(s) == l){
            sort (all(s)); return s;
        }

        string tmp = s.substr (1, sz(s)-1);
        sort (all(tmp)); tmp = tmp.substr (0, l-1);
        string ret; ret.pb (s[0]);
        ret += tmp; sort (all(ret));
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string S, int L, string __expected, int caseNo) {

    time_t startClock = clock();
    EllysSortingTrimmer *instance = new EllysSortingTrimmer();
    string __result = instance->getMin(S, L);
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
            string S = "ABRACADABRA";
            int L = 5;
            string __expected = "AAAAA";
            return do_test(S, L, __expected, __no);
        }
        case 1: {
            string S = "ESPRIT";
            int L = 3;
            string __expected = "EIP";
            return do_test(S, L, __expected, __no);
        }
        case 2: {
            string S = "BAZINGA";
            int L = 7;
            string __expected = "AABGINZ";
            return do_test(S, L, __expected, __no);
        }
        case 3: {
            string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            int L = 13;
            string __expected = "ABCDEFGHIJKLM";
            return do_test(S, L, __expected, __no);
        }
        case 4: {
            string S = "GOODLUCKANDHAVEFUN";
            int L = 10;
            string __expected = "AACDDEFGHK";
            return do_test(S, L, __expected, __no);
        }
        case 5: {
            string S = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
            int L = 21;
            string __expected = "AAAAAAAAABBDDDDDDDEEI";
            return do_test(S, L, __expected, __no);
        }
        case 6: {
            string S = "TOPCODER";
            int L = 3;
            string __expected = "CDT";
            return do_test(S, L, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "EllysSortingTrimmer (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397318765;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
