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

class TheAlmostLuckyNumbersDivOne {
    public:
    int64 ten[20];
    vector<int64> num;
    long long find(long long a, long long b) {
        ten[0] = 1;
        repf (i, 1, 18) ten[i] = ten[i-1] * 10;
        num.clear(); dfs_init (0, 0LL);
        return calc (b) - calc (a-1);
    }
    void dfs_init (int p, int64 x){
        if (x) num.pb (x);
        if (p >= 16) return;
        dfs_init (p+1, x+4*ten[p]);
        dfs_init (p+1, x+7*ten[p]);
    }
    int64 calc (int64 up){
        if (!up) return 1;
        int64 ret = 0;
        repf (i, 0, 9) if (i != 4 && i != 7 && i <= up) ++ ret;
        for (auto x : num) if (x <= up){
            ++ ret;
            repf (i, 0, 17){
                int64 tmp = (x/ten[i]) * ten[i]*10 + (x%ten[i]);
                repf (j, ten[i]>x? 1 : 0, 9) if (j != 4 && j != 7){
                    int64 tt = tmp + ten[i]*j;
                    if (tt <= up) ++ ret;
                }
                if (ten[i] > x) break;
            }
        }
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long a, long long b, long long __expected, int caseNo) {

    time_t startClock = clock();
    TheAlmostLuckyNumbersDivOne *instance = new TheAlmostLuckyNumbersDivOne();
    long long __result = instance->find(a, b);
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
            long long a = 4LL;
            long long b = 7LL;
            long long __expected = 4LL;
            return do_test(a, b, __expected, __no);
        }
        case 1: {
            long long a = 8LL;
            long long b = 19LL;
            long long __expected = 4LL;
            return do_test(a, b, __expected, __no);
        }
        case 2: {
            long long a = 28LL;
            long long b = 33LL;
            long long __expected = 0LL;
            return do_test(a, b, __expected, __no);
        }
        case 3: {
            long long a = 12345678900LL;
            long long b = 98765432100LL;
            long long __expected = 91136LL;
            return do_test(a, b, __expected, __no);
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
    cout << "TheAlmostLuckyNumbersDivOne (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405502806;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
