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
typedef pair<int64, int64> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;
const int64 maxn = 10000000010;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class SetMultiples {
    public:
    long long smallestSubset(long long a, long long b, long long c, long long d){
        pii t1 = mp (a, b), t2 = mp (c, d);
        int64 ans = d - c + b - a + 2;
        ans -= merge (t1, mp (a, b/2)) + merge (t2, mp (c, d/2));
        chmax (t1.x, b / 2 + 1);
        if (t1.y <= 100000){
            repf (i, t1.x, t1.y) if (ok (i, c, d)) -- ans;
        }
        else{
            int64 k = 2, up = 1LL << 50;
            while (1){
                if (k * t1.x > d) break;
                pii tmp = mp (ceil ((c+0.0)/k), d/k); chmin (tmp.y, up);
                ans -= merge (t1, tmp);
                ++ k; up = tmp.x - 1;
            }
        }
        return ans;
    }
    int64 merge (pii a, pii b){
        if (a.y < a.x) return 0;
        if (b.y < b.x) return 0;
        int64 t1 = a.x; chmax (t1, b.x);
        int64 t2 = a.y; chmin (t2, b.y);
        return t2 - t1 + 1> 0 ? t2-t1+1 : 0;
    }
    bool ok (int64 m, int64 c, int64 d){
        if (c % m == 0 || d % m == 0) return 1;
        int64 t = c / m, t2 = d / m;
        if (t2 > t) return 1;
        return 0;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long A, long long B, long long C, long long D, long long __expected, int caseNo) {

    time_t startClock = clock();
    SetMultiples *instance = new SetMultiples();
    long long __result = instance->smallestSubset(A, B, C, D);
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
            //long long A = 1LL;
            //long long B = 1LL;
            //long long C = 2LL;
            //long long D = 2LL;
            //long long A = 12805LL;
            //long long B = 4631846LL;
            //long long C = 38028364LL;
            //long long D = 53266554LL;
            long long A = 9LL;
            long long B = 9LL;
            long long C = 470LL;
            long long D = 9911LL;
            long long __expected = 4956LL;
            return do_test(A, B, C, D, __expected, __no);
        }
        case 1: {
            long long A = 1LL;
            long long B = 2LL;
            long long C = 3LL;
            long long D = 4LL;
            long long __expected = 2LL;
            return do_test(A, B, C, D, __expected, __no);
        }
        case 2: {
            long long A = 2LL;
            long long B = 3LL;
            long long C = 5LL;
            long long D = 7LL;
            long long __expected = 3LL;
            return do_test(A, B, C, D, __expected, __no);
        }
        case 3: {
            long long A = 1LL;
            long long B = 10LL;
            long long C = 100LL;
            long long D = 1000LL;
            long long __expected = 500LL;
            return do_test(A, B, C, D, __expected, __no);
        }
        case 4: {
            long long A = 1000000000LL;
            long long B = 2000000000LL;
            long long C = 9000000000LL;
            long long D = 10000000000LL;
            long long __expected = 1254365078LL;
            return do_test(A, B, C, D, __expected, __no);
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
    cout << "SetMultiples (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403021778;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
