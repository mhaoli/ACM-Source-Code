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
#define two(x) (1<<(x))
#define twol(x) (1LL<<(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

class ShoppingSurveyDiv1 {
    public:
    int minValue(int N, int K, vector<int> s);
};

vi s;
int n, k;

int calc (int m){
    vi t = s;
    rep (i, 0, m-1) for (auto &v : t) if (v > 0) -- v;
    rep (i, 0, n-m-1){
        sort (all (t), greater<int>() );
        rep (j, 0, k-2) if (t[j]) --t[j];
    }

    for (auto v: t) if (v) return 0;
    return 1;
}

int ShoppingSurveyDiv1::minValue(int _n, int _k, vector<int> _s){
    s = _s; n = _n; k = _k;
    sort (all (s));
    int l = 0, r = n, ans = n;
    while (l <= r){
        int m = (l + r) >> 1;
        if (calc (m)) ans = m, r = m - 1;
        else l = m + 1;
    }
    return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int K, vector<int> s, int __expected, int caseNo) {

    time_t startClock = clock();
    ShoppingSurveyDiv1 *instance = new ShoppingSurveyDiv1();
    int __result = instance->minValue(N, K, s);
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
            int N = 10;
            int K = 2;
            int s[] = {
                1, 2, 3
            };
            int __expected = 0;
            return do_test(N, K, to_vector(s), __expected, __no);
        }
        case 1: {
            int N = 5;
            int K = 2;
            int s[] = {
                1, 2, 3
            };
            int __expected = 1;
            return do_test(N, K, to_vector(s), __expected, __no);
        }
        case 2: {
            int N = 4;
            int K = 4;
            int s[] = {
                4, 4, 4, 2
            };
            int __expected = 2;
            return do_test(N, K, to_vector(s), __expected, __no);
        }
        case 3: {
            int N = 20;
            int K = 3;
            int s[] = {
                1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3
            };
            int __expected = 10;
            return do_test(N, K, to_vector(s), __expected, __no);
        }
        case 4: {
            int N = 4;
            int K = 2;
            int s[] = {
                1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1
            };
            int __expected = 2;
            return do_test(N, K, to_vector(s), __expected, __no);
        }
        case 5: {
            int N = 2;
            int K = 3;
            int s[] = {
                1, 1, 1, 2
            };
            int __expected = 1;
            return do_test(N, K, to_vector(s), __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "ShoppingSurveyDiv1 (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1411693251;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
