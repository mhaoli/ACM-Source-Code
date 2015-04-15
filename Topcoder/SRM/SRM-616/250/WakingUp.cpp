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
const int maxn = 100000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class WakingUp {
    public:
    int maxSleepiness(vector<int> pn, vector<int> sn, vector<int> vn, int d) {
        int64 ans = 0, ret = 0;
        repf (i, 1, maxn){
            ans += d;
            repf (j, 0, sz(pn)-1) if (i >= sn[j] && (i-sn[j])%pn[j] == 0) ans -= vn[j];
            chmin (ret, ans);
        }
        int64 tmp = ret;
        repf (i, maxn+1, 2*maxn){
            ans += d;
            repf (j, 0, sz(pn)-1) if (i >= sn[j] && (i-sn[j])%pn[j] == 0) ans -= vn[j];
            chmin (ret, ans);
        }
        if (ret == tmp) return (int)(-ret);
        return -1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> period, vector<int> start, vector<int> volume, int D, int __expected, int caseNo) {

    time_t startClock = clock();
    WakingUp *instance = new WakingUp();
    int __result = instance->maxSleepiness(period, start, volume, D);
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
            int period[] = {
                10, 9, 8, 7, 6, 5, 4, 3, 2, 1
            };
            int start[] = {
                10, 9, 8, 7, 6, 5, 4, 3, 2, 1
            };
            int volume[] = {
                10, 9, 8, 7, 6, 5, 4, 3, 2, 1
            };
            int D = 3;
            int __expected = 2;
            return do_test(to_vector(period), to_vector(start), to_vector(volume), D, __expected, __no);
        }
        case 1: {
            int period[] = {
                1
            };
            int start[] = {
                1
            };
            int volume[] = {
                17
            };
            int D = 17;
            int __expected = 0;
            return do_test(to_vector(period), to_vector(start), to_vector(volume), D, __expected, __no);
        }
        case 2: {
            int period[] = {
                1
            };
            int start[] = {
                1
            };
            int volume[] = {
                23
            };
            int D = 17;
            int __expected = -1;
            return do_test(to_vector(period), to_vector(start), to_vector(volume), D, __expected, __no);
        }
        case 3: {
            int period[] = {
                9, 2, 5, 5, 7
            };
            int start[] = {
                6, 1, 4, 1, 6
            };
            int volume[] = {
                71, 66, 7, 34, 6
            };
            int D = 50;
            int __expected = 78;
            return do_test(to_vector(period), to_vector(start), to_vector(volume), D, __expected, __no);
        }
        case 4: {
            int period[] = {
                5, 6, 5, 3, 8, 3, 4
            };
            int start[] = {
                1, 1, 3, 2, 6, 3, 3
            };
            int volume[] = {
                42, 85, 10, 86, 21, 78, 38
            };
            int D = 88;
            int __expected = -1;
            return do_test(to_vector(period), to_vector(start), to_vector(volume), D, __expected, __no);
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
    cout << "WakingUp (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397142325;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
