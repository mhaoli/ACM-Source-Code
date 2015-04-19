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

class RectangleCovering {
    public:
    vii vec;
    int minimumNumber(int h, int w, vector<int> bh, vector<int> bw){
        vec.clear();
        repf (i, 0, sz(bh)-1) vec.pb (mp (bh[i], bw[i]));
        int ans = solve (h, w);
        chmin (ans, solve (w, h));
        return ans < inf ? ans : -1;
    }
    int solve (int h, int w){
        vi tmp;
        for (auto x : vec){
            if (x.x > h && x.y > h) tmp.pb (max (x.x, x.y));
            else if (x.x > h) tmp.pb (x.y);
            else if (x.y > h) tmp.pb (x.x);
        }
        
        sort (all (tmp), greater<int>());
        int sum = 0;
        repf (i, 0, sz(tmp)-1){
            sum += tmp[i];
            if (sum >= w) return i + 1;
        }
        return inf;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int holeH, int holeW, vector<int> boardH, vector<int> boardW, int __expected, int caseNo) {

    time_t startClock = clock();
    RectangleCovering *instance = new RectangleCovering();
    int __result = instance->minimumNumber(holeH, holeW, boardH, boardW);
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
            int holeH = 5;
            int holeW = 5;
            int boardH[] = {
                8, 8, 8
            };
            int boardW[] = {
                2, 3, 4
            };
            int __expected = 2;
            return do_test(holeH, holeW, to_vector(boardH), to_vector(boardW), __expected, __no);
        }
        case 1: {
            int holeH = 10;
            int holeW = 10;
            int boardH[] = {
                6, 6, 6, 6
            };
            int boardW[] = {
                6, 6, 6, 6
            };
            int __expected = -1;
            return do_test(holeH, holeW, to_vector(boardH), to_vector(boardW), __expected, __no);
        }
        case 2: {
            int holeH = 5;
            int holeW = 5;
            int boardH[] = {
                5
            };
            int boardW[] = {
                5
            };
            int __expected = -1;
            return do_test(holeH, holeW, to_vector(boardH), to_vector(boardW), __expected, __no);
        }
        case 3: {
            int holeH = 3;
            int holeW = 5;
            int boardH[] = {
                6
            };
            int boardW[] = {
                4
            };
            int __expected = 1;
            return do_test(holeH, holeW, to_vector(boardH), to_vector(boardW), __expected, __no);
        }
        case 4: {
            int holeH = 10000;
            int holeW = 5000;
            int boardH[] = {
                12345, 12343, 12323, 12424, 1515, 6666, 6789, 1424, 11111, 25
            };
            int boardW[] = {
                1442, 2448, 42, 1818, 3535, 3333, 3456, 7890, 1, 52
            };
            int __expected = 3;
            return do_test(holeH, holeW, to_vector(boardH), to_vector(boardW), __expected, __no);
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
    cout << "RectangleCovering (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407855815;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
