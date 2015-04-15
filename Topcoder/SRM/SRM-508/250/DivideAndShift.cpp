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

class DivideAndShift {
    public:
    vi fac;
    int ans;
    int getLeast(int n, int m) {
        fac.clear();
        int nn = n;
        for (int i = 2; i*i <= nn; ++ i)
            while (nn % i == 0) nn /= i, fac.pb (i);
        if (nn != 1) fac.pb (nn);

        //for (int i : fac) out (i);
        ans = inf;
        dfs (-1, n, m-1, 0);
        return ans;
    }
    void dfs (int p, int n, int m, int num){
        chmin (ans, num + calc (n, m));
        repf (i, p+1, sz(fac)-1){
            dfs (i, n/fac[i], m%(n/fac[i]), num+1);
        }
    }
    int calc (int n, int m){
        int ret = m; chmin (ret, n - m);
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int M, int __expected, int caseNo) {

    time_t startClock = clock();
    DivideAndShift *instance = new DivideAndShift();
    int __result = instance->getLeast(N, M);
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
            int N = 56;
            int M = 14;
            int __expected = 3;
            return do_test(N, M, __expected, __no);
        }
        case 1: {
            int N = 49;
            int M = 5;
            int __expected = 2;
            return do_test(N, M, __expected, __no);
        }
        case 2: {
            int N = 256;
            int M = 7;
            int __expected = 6;
            return do_test(N, M, __expected, __no);
        }
        case 3: {
            int N = 6;
            int M = 1;
            int __expected = 0;
            return do_test(N, M, __expected, __no);
        }
        case 4: {
            int N = 77777;
            int M = 11111;
            int __expected = 2;
            return do_test(N, M, __expected, __no);
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
    cout << "DivideAndShift (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405326673;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
