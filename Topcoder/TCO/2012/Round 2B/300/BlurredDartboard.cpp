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

class BlurredDartboard {
    public:
    bool v[55];
    int minThrows(vector<int> an, int sum) {
        clr (v, 0);
        int n = sz(an), ma = 0, tsum = 0, tcnt = 0;
        repf (i, 0, n-1) v[an[i]] = 1, chmax (ma, an[i]);
        repf (i, 1, n) if (!v[i]) tsum += i, tcnt ++;

        int ans = ma ? (int)ceil ((sum+0.0) / ma) : inf;
        if (tsum == 0) return ans;

        int cnt = (sum / tsum);
        sum -= cnt * tsum;
        cnt *= tcnt;
        if (ma) chmin (ans, cnt + (int)ceil ((sum+0.0) / ma));
        repf (i, 1, n){
            if (sum <= 0) break;
            if (!v[i]) sum -= i, cnt ++;
        }
        if (sum <= 0) chmin (ans, cnt);
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> points, int P, int __expected, int caseNo) {

    time_t startClock = clock();
    BlurredDartboard *instance = new BlurredDartboard();
    int __result = instance->minThrows(points, P);
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
            int points[] = {
                0, 3, 4, 0, 0
            };
            int P = 8;
            int __expected = 2;
            return do_test(to_vector(points), P, __expected, __no);
        }
        case 1: {
            int points[] = {
                0, 0, 0, 0, 0
            };
            int P = 15;
            int __expected = 5;
            return do_test(to_vector(points), P, __expected, __no);
        }
        case 2: {
            int points[] = {
                4, 7, 8, 1, 3, 2, 6, 5
            };
            int P = 2012;
            int __expected = 252;
            return do_test(to_vector(points), P, __expected, __no);
        }
        case 3: {
            int points[] = {
                0, 0, 5, 0, 0, 0, 1, 3, 0, 0
            };
            int P = 2012;
            int __expected = 307;
            return do_test(to_vector(points), P, __expected, __no);
        }
        case 4: {
            int points[] = {
                0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0
            };
            int P = 1000000000;
            int __expected = 84656087;
            return do_test(to_vector(points), P, __expected, __no);
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
    cout << "BlurredDartboard (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1398180288;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
