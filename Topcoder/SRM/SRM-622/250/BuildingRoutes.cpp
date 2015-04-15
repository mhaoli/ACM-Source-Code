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

class BuildingRoutes {
    public:
    int d[55][55];
    int build(vector<string> dist, int T) {
        clr (d, 0);
        int n = sz(dist);
        repf (i, 0, n-1) repf (j, 0, n-1) d[i][j] = dist[i][j] - '0';
        repf (i, 0, n-1) repf (j, 0, n-1) repf (k, 0, n-1) chmin (d[j][k], d[j][i] + d[i][k]);

        int ret = 0;
        repf (i, 0, n-1) repf (j, 0, n-1){
            int cnt = 0;
            repf (t1, 0, n-1) repf (t2, 0, n-1) if (dist[i][j] - '0' + d[t1][i] + d[j][t2] == d[t1][t2]) ++ cnt;
            if (cnt >= T) ret += dist[i][j] - '0';
        }
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> dist, int T, int __expected, int caseNo) {

    time_t startClock = clock();
    BuildingRoutes *instance = new BuildingRoutes();
    int __result = instance->build(dist, T);
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
            string dist[] = {
                "011",
                "101",
                "110"
            };
            int T = 1;
            int __expected = 6;
            return do_test(to_vector(dist), T, __expected, __no);
        }
        case 1: {
            string dist[] = {
                "033",
                "309",
                "390"
            };
            int T = 1;
            int __expected = 12;
            return do_test(to_vector(dist), T, __expected, __no);
        }
        case 2: {
            string dist[] = {
                "0123",
                "1023",
                "1203",
                "1230"
            };
            int T = 2;
            int __expected = 5;
            return do_test(to_vector(dist), T, __expected, __no);
        }
        case 3: {
            string dist[] = {
                "05789654",
                "10347583",
                "65085479",
                "55602398",
                "76590934",
                "57939045",
                "12345608",
                "68647640"
            };
            int T = 3;
            int __expected = 40;
            return do_test(to_vector(dist), T, __expected, __no);
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
    cout << "BuildingRoutes (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1401771517;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
