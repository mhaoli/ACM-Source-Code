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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

bool cmp (pair<int64, pii > a, pair<int64, pii > b){
    return -a.y.y*b.y.x > -a.y.x*b.y.y;
}

class TheProgrammingContestDivOne {
    public:
    vector<pair <int64, pii > > vec;
    int64 d[55][100005];
    int find(int T, vector<int> an, vector<int> des, vector<int> tim) {
        vec.clear();
        
        repf (i, 0, sz(an)-1) vec.pb (mp ((int64)an[i], mp ((int64)des[i], (int64)tim[i])));
        sort (all (vec), cmp);

        clr (d, 0);
        int n = sz(vec);
        repf (i, 1, n) repf (j, 0, T){
            chmax (d[i][j], d[i-1][j]);
            int64 times = j + vec[i-1].y.y;
            if (times > T) continue;
            chmax (d[i][times], d[i-1][j] + vec[i-1].x - vec[i-1].y.x * (vec[i-1].y.y+j));
        }

        int64 ans = 0;
        repf (i, 0, T) chmax (ans, d[n][i]);
        return (int)ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int T, vector<int> maxPoints, vector<int> pointsPerMinute, vector<int> requiredTime, int __expected, int caseNo) {

    time_t startClock = clock();
    TheProgrammingContestDivOne *instance = new TheProgrammingContestDivOne();
    int __result = instance->find(T, maxPoints, pointsPerMinute, requiredTime);
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
            int T = 74;
            int maxPoints[] = {
                502
            };
            int pointsPerMinute[] = {
                2
            };
            int requiredTime[] = {
                47
            };
            int __expected = 408;
            return do_test(T, to_vector(maxPoints), to_vector(pointsPerMinute), to_vector(requiredTime), __expected, __no);
        }
        case 1: {
            int T = 40000;
            int maxPoints[] = {
                100000, 100000
            };
            int pointsPerMinute[] = {
                1, 100000
            };
            int requiredTime[] = {
                50000, 30000
            };
            int __expected = 0;
            return do_test(T, to_vector(maxPoints), to_vector(pointsPerMinute), to_vector(requiredTime), __expected, __no);
        }
        case 2: {
            int T = 75;
            int maxPoints[] = {
                250, 500, 1000
            };
            int pointsPerMinute[] = {
                2, 4, 8
            };
            int requiredTime[] = {
                25, 25, 25
            };
            int __expected = 1200;
            return do_test(T, to_vector(maxPoints), to_vector(pointsPerMinute), to_vector(requiredTime), __expected, __no);
        }
        case 3: {
            int T = 30;
            int maxPoints[] = {
                100, 100, 100000
            };
            int pointsPerMinute[] = {
                1, 1, 100
            };
            int requiredTime[] = {
                15, 15, 30
            };
            int __expected = 97000;
            return do_test(T, to_vector(maxPoints), to_vector(pointsPerMinute), to_vector(requiredTime), __expected, __no);
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
    cout << "TheProgrammingContestDivOne (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402504691;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
