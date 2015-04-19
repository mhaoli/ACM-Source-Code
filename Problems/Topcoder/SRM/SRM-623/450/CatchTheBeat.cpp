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
const int inf = 2139062143;
const int maxn = 500005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int64 g[maxn];
pii an[maxn], bn[maxn];

//bool cmp (pii a, pii b){
    //return a.x != b.x ? a.x < b.x : a.y < b.y;
//}
//
class CatchTheBeat {
    public:
    int maxCatched(int n, int64 x0, int64 y0, int64 a, int64 b, int64 c, int64 d, int64 mod1, int64 mod2, int64 offset){
        an[0].x = x0;
        repf (i, 1, n-1) an[i].x = (an[i-1].x * a + b) % mod1;
        repf (i, 0, n-1) an[i].x -= offset;
        an[0].y = y0;
        repf (i, 1, n-1) an[i].y = (an[i-1].y * c + d) % mod2;

        repf (i, 0, n-1) bn[i].x = an[i].y - an[i].x, bn[i].y = an[i].x + an[i].y;
        sort (bn, bn + n);
        return solve (n);
    }
    int solve (int n){
        repf (i, 0, n) g[i] = inf;
        repf (i, 0, n-1){
            if (bn[i].x < 0 || bn[i].y < 0) continue;
            int pos = bin_search (0, n, bn[i].y);
            chmin (g[pos], bn[i].y);
        }
        repd (i, n-1, 0) if (g[i] < inf) return i + 1;
        return 0;
    }
    int bin_search (int l, int r, int64 key){
        int ret = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (g[mid] > key) ret = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset, int __expected, int caseNo) {

    time_t startClock = clock();
    CatchTheBeat *instance = new CatchTheBeat();
    int __result = instance->maxCatched(n, x0, y0, a, b, c, d, mod1, mod2, offset);
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
            int n = 500000;
            int x0 = 999999957;
            int y0 = 79;
            int a = 993948167;
            int b = 24597383;
            int c = 212151897;
            int d = 999940854;
            int mod1 = 999999986;
            int mod2 = 999940855;
            int offset = 3404;
            int __expected = 992;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }
        case 1: {
            int n = 1;
            int x0 = 0;
            int y0 = 1234;
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            int mod1 = 1000000000;
            int mod2 = 1000000000;
            int offset = 1000;
            int __expected = 1;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }
        case 2: {
            int n = 1;
            int x0 = 0;
            int y0 = 999;
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            int mod1 = 1000000000;
            int mod2 = 1000000000;
            int offset = 1000;
            int __expected = 0;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }
        case 3: {
            int n = 100;
            int x0 = 0;
            int y0 = 0;
            int a = 1;
            int b = 1;
            int c = 1;
            int d = 1;
            int mod1 = 3;
            int mod2 = 58585858;
            int offset = 1;
            int __expected = 66;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }
        case 4: {
            int n = 500000;
            int x0 = 123456;
            int y0 = 0;
            int a = 1;
            int b = 0;
            int c = 1;
            int d = 1;
            int mod1 = 1000000000;
            int mod2 = 1000000000;
            int offset = 0;
            int __expected = 376544;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }
        case 5: {
            int n = 500000;
            int x0 = 0;
            int y0 = 0;
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            int mod1 = 1;
            int mod2 = 1;
            int offset = 0;
            int __expected = 500000;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }
        case 6: {
            int n = 10;
            int x0 = 999999957;
            int y0 = 79;
            int a = 993948167;
            int b = 24597383;
            int c = 212151897;
            int d = 999940854;
            int mod1 = 999999986;
            int mod2 = 999940855;
            int offset = 3404;
            int __expected = 3;
            return do_test(n, x0, y0, a, b, c, d, mod1, mod2, offset, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "CatchTheBeat (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1401957275;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
