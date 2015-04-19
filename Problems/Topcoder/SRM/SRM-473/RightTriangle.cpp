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
const int maxn = 1000005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int f[maxn];
bool v[maxn];

class RightTriangle {
    public:
    long long triangleCount(int n, int m, int64 a, int64 b, int64 c) {
        int mod = n;

        clr (v, 0);
        repf (i, 0, n-1) f[i] = i;

        repf (i, 0, m-1){
            int64 tmp = ((a * i * i % mod) + (b * i % mod) + c) % mod;
            int pos = find (tmp);
            v[pos] = 1; f[pos] = f[(pos+1)%mod];
        }

        if (n & 1) return 0;

        int dif = n / 2;
        int64 ans = 0;
        repf (i, 0, dif-1) if (v[i] && v[i+dif]) ans += m - 2;
        return ans;
    }
    int find (int x){
        if (f[x] != x) f[x] = find (f[x]);
        return f[x];
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int places, int points, int a, int b, int c, long long __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    RightTriangle *instance = new RightTriangle();
    long long __result = instance->triangleCount(places, points, a, b, c);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int places = 9;
            int points = 3;
            int a = 0;
            int b = 3;
            int c = 0;
            long long __expected = 0LL;
            return do_test(places, points, a, b, c, __expected, __no);
        }
        case 1: {
            int places = 40;
            int points = 3;
            int a = 5;
            int b = 0;
            int c = 0;
            long long __expected = 1LL;
            return do_test(places, points, a, b, c, __expected, __no);
        }
        case 2: {
            int places = 4;
            int points = 4;
            int a = 16;
            int b = 24;
            int c = 17;
            long long __expected = 4LL;
            return do_test(places, points, a, b, c, __expected, __no);
        }
        case 3: {
            int places = 1000000;
            int points = 47000;
            int a = 0;
            int b = 2;
            int c = 5;
            long long __expected = 0LL;
            return do_test(places, points, a, b, c, __expected, __no);
        }
        case 4: {
            int places = 200000;
            int points = 700;
            int a = 123456;
            int b = 789012;
            int c = 345678;
            long long __expected = 6980LL;
            return do_test(places, points, a, b, c, __expected, __no);
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
    cout << "RightTriangle (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1396676097;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
