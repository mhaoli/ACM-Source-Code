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

const int maxn = 5005;
vi pat[maxn];
bool vis[maxn];

class LongestSequence {
    public:
    int maxLength(vector<int> an){
        //string no = "Impossible", yes = "Possible";
        rep (i, 0, 5002) pat[i].clear ();
        sort (all (an));
        if (an[sz(an) - 1] < 0 || an[0] > 0) return -1;

        for (int i = 1; ; ++ i){
            for (auto x : an){
                if (abs(x) <= i){
                    if (x < 0) pat[i].pb (i + x);
                    else pat[i-x].pb (i);
                }
            }

            if (clr (vis, 0), dfs (0)) return i - 1;
        }
        return 0;
    }
    int dfs (int u){
        vis[u] = 1;
        for (auto v : pat[u]){
            if (!v || (!vis[v] && dfs (v))) return 1;
        }
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> C, int __expected, int caseNo) {

    time_t startClock = clock();
    LongestSequence *instance = new LongestSequence();
    int __result = instance->maxLength(C);
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
            int C[] = {
                1000, -999
            };
            int __expected = 3;
            return do_test(to_vector(C), __expected, __no);
        }
        case 1: {
            int C[] = {
                524
            };
            int __expected = -1;
            return do_test(to_vector(C), __expected, __no);
        }
        case 2: {
            int C[] = {
                1, -1
            };
            int __expected = 0;
            return do_test(to_vector(C), __expected, __no);
        }
        case 3: {
            int C[] = {
                11, -7
            };
            int __expected = 16;
            return do_test(to_vector(C), __expected, __no);
        }
        case 4: {
            int C[] = {
                -227, 690, 590, -524
            };
            int __expected = 713;
            return do_test(to_vector(C), __expected, __no);
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
    cout << "LongestSequence (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409191719;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
