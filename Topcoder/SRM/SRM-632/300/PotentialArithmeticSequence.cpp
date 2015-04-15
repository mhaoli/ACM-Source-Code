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

int tar[1000];

class PotentialArithmeticSequence {
    public:
    vi d;
    int n;
    int numberOfSubsequences(vector<int> D){
        //string no = "Impossible", yes = "Possible";
        d = D; n = sz (d);
        int ans = 0;
        rep (i, 0, n-1){
            ans += solve (i) - i;
        }
        return ans;
    }
    int solve (int p){
        if (p == n-1) return n;
        if (!d[p]) ++ p;
        if (!d[p]) return p;

        int mx = d[p] - 1;
        clr (tar, -1);
        while (p < n){
            if (tar[p] == -1){
                if (mx >= d[p]) return p;
                mx = d[p];
                int up = n; 
                if (d[p] < 10) chmin (up, p + (1<<d[p]));

                rep (i, p+1, up-1) tar[i] = len (i - p);
            } else if (tar[p] != d[p]) return p;
            ++ p;
        }
        return n;
    }
    int len (int x){
        int ret = 0;
        while (x){
            if (x & 1) break;
            else ++ ret, x >>= 1;
        }
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> d, int __expected, int caseNo) {

    time_t startClock = clock();
    PotentialArithmeticSequence *instance = new PotentialArithmeticSequence();
    int __result = instance->numberOfSubsequences(d);
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
            int d[] = {
                0, 1, 0, 2, 0, 1, 0
            };
            int __expected = 28;
            return do_test(to_vector(d), __expected, __no);
        }
        case 1: {
            int d[] = {
                0, 0, 0, 0, 0, 0, 0
            };
            int __expected = 7;
            return do_test(to_vector(d), __expected, __no);
        }
        case 2: {
            int d[] = {
                0, 0, 0, 0, 1, 1, 1
            };
            int __expected = 8;
            return do_test(to_vector(d), __expected, __no);
        }
        case 3: {
            int d[] = {
                0, 100, 0, 2, 0
            };
            int __expected = 11;
            return do_test(to_vector(d), __expected, __no);
        }
        case 4: {
            int d[] = {
                1, 11, 3, 0, 1, 0, 1, 0, 1, 0, 1, 0, 3, 0, 2, 0, 0, 0, 0, 1, 2, 3, 20
            };
            int __expected = 49;
            return do_test(to_vector(d), __expected, __no);
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
    cout << "PotentialArithmeticSequence (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409915072;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
