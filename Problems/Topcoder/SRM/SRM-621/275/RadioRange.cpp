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

bool cmp (pair<double, int> a, pair<double, int> b){
    return a.x < b.x;
}

class RadioRange {
    public:
    vector<pair<double, int> > num;
    double RadiusProbability(vector<int> xn, vector<int> yn, vector<int> rn, int ma) {
        num.clear();
        int cnt = 0;
        repf (i, 0, sz(xn)-1){
            double dis = sqrt(sqr((int64)xn[i]) + sqr((int64)yn[i]));
            cnt += gao (dis - rn[i], 0); cnt += gao (dis + rn[i], 1);
        }
        sort (all(num), cmp);
        double last = 0, ans_len = 0;
        repf (i, 0, sz(num)-1){
            if (num[i].y == 0){
                if (cnt == 0){
                    double tpos = num[i].x; chmin (tpos, (double)ma);
                    ans_len += tpos - last;
                }
                ++ cnt;
            }
            else{
                -- cnt; last = num[i].x;
            }
            if (ma < num[i].x) break;
        }
        if (cnt == 0 && ma > num[sz(num)-1].x) ans_len += ma - num[sz(num)-1].x;
        return ans_len / (double)ma;
    }
    int gao (double x, int flag){
        if (x <= 0.0) return 1;
        num.pb (mp (x, flag));
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<int> X, vector<int> Y, vector<int> R, int Z, double __expected, int caseNo) {

    time_t startClock = clock();
    RadioRange *instance = new RadioRange();
    double __result = instance->RadiusProbability(X, Y, R, Z);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            int X[] = {
                1, 2
            };
            int Y[] = {
                1, 2
            };
            int R[] = {
                5, 1
            };
            int Z = 20;
            double __expected = 0.5;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 1: {
            int X[] = {
                0
            };
            int Y[] = {
                0
            };
            int R[] = {
                10
            };
            int Z = 10;
            double __expected = 0.0;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 2: {
            int X[] = {
                10
            };
            int Y[] = {
                10
            };
            int R[] = {
                10
            };
            int Z = 10;
            double __expected = 0.4142135623730951;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 3: {
            int X[] = {
                11, -11, 0, 0
            };
            int Y[] = {
                0, 0, 11, -11
            };
            int R[] = {
                10, 10, 10, 10
            };
            int Z = 31;
            double __expected = 0.3548387096774194;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 4: {
            int X[] = {
                100
            };
            int Y[] = {
                100
            };
            int R[] = {
                1
            };
            int Z = 10;
            double __expected = 1.0;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 5: {
            int X[] = {
                1000000000
            };
            int Y[] = {
                1000000000
            };
            int R[] = {
                1000000000
            };
            int Z = 1000000000;
            double __expected = 0.41421356237309503;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 6: {
            int X[] = {
                20, -20, 0, 0
            };
            int Y[] = {
                0, 0, 20, -20
            };
            int R[] = {
                50, 50, 50, 50
            };
            int Z = 100;
            double __expected = 0.3;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }
        case 7: {
            int X[] = {
                0, -60, -62, -60, 63, -97
            };
            int Y[] = {
                -72, 67, 61, -8, -32, 89
            };
            int R[] = {
                6, 7, 8, 7, 5, 6
            };
            int Z = 918;
            double __expected = 0.9407071068962471;
            return do_test(to_vector(X), to_vector(Y), to_vector(R), Z, __expected, __no);
        }

        // Your custom testcase goes here
        case 8:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "RadioRange (275 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 8; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1400598670;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
