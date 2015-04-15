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
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
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
//const int inf = 2139062143 / 2;
const int inf = 1000000000;
const int64 llinf = 9223372036854775807;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class DivisorsPower {
    public:
    long long findArgument(long long n) {
        int64 ans = 1LL<<60;
        repf (i, 2, 100){
            int64 t = -1, l = 1, r = inf;
            while (l <= r){
                int64 m = (l + r) >> 1;
                int64 tmp = calc (m, i);
                if (tmp == -1 || tmp > n) r = m - 1;
                else{
                    if (tmp == n) t = m;
                    l = m + 1;
                }
            }
            if (t != -1 && fac (t) == i) chmin (ans, t);
        }
        return ans < (1LL<<45) ? ans : -1;
    }
    int64 calc (int64 x, int64 n){
        int64 ret = 1;
        repf (i, 0, n-1){
            if (llinf / ret <= x) return -1;
            ret *= x;
        }
        return ret;
    }
    int64 fac (int64 x){
        int64 ret = 1;
        for (int64 i = 2; i*i <= x; ++ i) if (x % i == 0){
            int64 cnt = 0;
            while (x % i == 0) x /= i, ++ cnt;
            ret *= (cnt + 1);
        }
        if (x > 1) ret *= 2;
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long n, long long __expected, int caseNo) {

    time_t startClock = clock();
    DivisorsPower *instance = new DivisorsPower();
    long long __result = instance->findArgument(n);
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
            long long n = 893623315422378256LL;
            long long __expected = 30746LL;
            return do_test(n, __expected, __no);
        }
        case 1: {
            long long n = 10LL;
            long long __expected = -1LL;
            return do_test(n, __expected, __no);
        }
        case 2: {
            long long n = 64LL;
            long long __expected = 4LL;
            return do_test(n, __expected, __no);
        }
        case 3: {
            long long n = 10000LL;
            long long __expected = 10LL;
            return do_test(n, __expected, __no);
        }
        case 4: {
            long long n = 2498388559757689LL;
            long long __expected = 49983883LL;
            return do_test(n, __expected, __no);
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
    cout << "DivisorsPower (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1406026969;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
