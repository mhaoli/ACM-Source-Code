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

class CompositeSmash {
    public:
    set<int> has;
    string thePossible(int n, int t) {
        string no = "No", yes = "Yes";
        if (n == t) return yes;
        return ok (n, t) ? yes : no;
    }
    bool ok (int n, int t){
        if (t > n) return 0;
        if (n == t) return 1;
        if (n % t) return 0;
        for (int i = 2; i < t; ++ i){
            if (n % i == 0 && !ok (n/i, t)) return 0;
        }
        return 1;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int target, string __expected, int caseNo) {

    time_t startClock = clock();
    CompositeSmash *instance = new CompositeSmash();
    string __result = instance->thePossible(N, target);
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
            int N = 24517;
            int target = 23868;
            string __expected = "No";
            return do_test(N, target, __expected, __no);
        }
        case 1: {
            int N = 8;
            int target = 4;
            string __expected = "Yes";
            return do_test(N, target, __expected, __no);
        }
        case 2: {
            int N = 12;
            int target = 6;
            string __expected = "No";
            return do_test(N, target, __expected, __no);
        }
        case 3: {
            int N = 5;
            int target = 8;
            string __expected = "No";
            return do_test(N, target, __expected, __no);
        }
        case 4: {
            int N = 100000;
            int target = 100000;
            string __expected = "Yes";
            return do_test(N, target, __expected, __no);
        }
        case 5: {
            int N = 5858;
            int target = 2;
            string __expected = "Yes";
            return do_test(N, target, __expected, __no);
        }
        case 6: {
            int N = 81461;
            int target = 2809;
            string __expected = "No";
            return do_test(N, target, __expected, __no);
        }
        case 7: {
            int N = 65536;
            int target = 256;
            string __expected = "No";
            return do_test(N, target, __expected, __no);
        }

        // Your custom testcase goes here
        case 8:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "CompositeSmash (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 8; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407485177;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
