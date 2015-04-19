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

class RectangleArea {
    public:
    int f[105];
    int vis[105];
    int minimumQueries(vector<string> an){
        int n = sz(an), m = sz(an[0]);
        repf (i, 0, n+m-1) f[i] = i;
        repf (i, 0, n-1) repf (j, 0, m-1) if (an[i][j] == 'Y'){
            int t1 = find (i), t2 = find (j+n);
            if (t1 != t2) f[t1] = t2;
        }
        int cnt = 0;
        clr (vis, 0);
        repf (i, 0, n+m-1){
            int t = find (i);
            if (!vis[t]) ++ vis[t], ++ cnt;
        }
        return cnt - 1;
    }
    int find (int x){
        return x == f[x] ? f[x] : f[x] = find(f[x]);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> known, int __expected, int caseNo) {

    time_t startClock = clock();
    RectangleArea *instance = new RectangleArea();
    int __result = instance->minimumQueries(known);
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
            string known[] = {
                "NN",
                "NN"
            };
            int __expected = 3;
            return do_test(to_vector(known), __expected, __no);
        }
        case 1: {
            string known[] = {
                "YNY",
                "NYN",
                "YNY"
            };
            int __expected = 1;
            return do_test(to_vector(known), __expected, __no);
        }
        case 2: {
            string known[] = {
                "YY",
                "YY",
                "YY",
                "YY"
            };
            int __expected = 0;
            return do_test(to_vector(known), __expected, __no);
        }
        case 3: {
            string known[] = {
                "NNNNNNNNNN"
            };
            int __expected = 10;
            return do_test(to_vector(known), __expected, __no);
        }
        case 4: {
            string known[] = {
                "NNYYYNN",
                "NNNNNYN",
                "YYNNNNY",
                "NNNYNNN",
                "YYNNNNY"
            };
            int __expected = 2;
            return do_test(to_vector(known), __expected, __no);
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
    cout << "RectangleArea (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402895914;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
