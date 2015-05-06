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

int tot, cnt;
int va[55], vb[55];
int v[55][55];

class SwitchesAndLamps {
    public:
    int n;
    int theMin(vector<string> an, vector<string> bn) {
        n = sz(an[0]);
        clr (v, 0);
        repf (i, 0, n-1) repf (j, 0, n-1){
            repf (t, 0, sz(an)-1) if (an[t][i] != bn[t][j]) v[i][j] = 1;
        }

        clr (va, 0); clr (vb, 0);
        int tot = 0, ans = 0;
        repf (i, 0, n-1) if (!va[i]){
            dfs (i, 0, ++ tot);
            int t1 = 0, t2 = 0;
            repf (j, 0, n-1) if (va[j] == tot) ++ t1;
            repf (j, 0, n-1) if (vb[j] == tot) ++ t2;
            if (t1 != t2) return -1;
            chmax (ans, (int)ceil (log(t1) / log(2)));
        }
        repf (i, 0, n-1){
            if (!va[i]) return -1;
            if (!vb[i]) return -1;
        }
        return ans;
    }
    void dfs (int p, int u, int col){
        if (!u){
            va[p] = col;
            repf (i, 0, n-1) if (!v[p][i] && !vb[i]) dfs (i, u^1, col);
        }
        else{
            vb[p] = col;
            repf (i, 0, n-1) if (!v[i][p] && !va[i]) dfs (i, u^1, col);
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> switches, vector<string> lamps, int __expected, int caseNo) {

    time_t startClock = clock();
    SwitchesAndLamps *instance = new SwitchesAndLamps();
    int __result = instance->theMin(switches, lamps);
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
            string switches[] = {
                "NYNN",
                "NNYN"
            };
            string lamps[] = {
                "NNNY",
                "NNYN"
            };
            int __expected = 1;
            return do_test(to_vector(switches), to_vector(lamps), __expected, __no);
        }
        case 1: {
            string switches[] = {
                "YYN",
                "YNY",
                "YYN"
            };
            string lamps[] = {
                "YNY",
                "NYY",
                "YNY"
            };
            int __expected = 0;
            return do_test(to_vector(switches), to_vector(lamps), __expected, __no);
        }
        case 2: {
            string switches[] = {
                "NYYYNYNNYYYNYNNNNY",
                "NYYYNYNNYYYNYNNNNY"
            };
            string lamps[] = {
                "YYYNNNYNNYNYNYNYNY",
                "YYYNNNYNNYNYYNNYNY"
            };
            int __expected = -1;
            return do_test(to_vector(switches), to_vector(lamps), __expected, __no);
        }
        case 3: {
            string switches[] = {
                "YYNNN",
                "NNYYN"
            };
            string lamps[] = {
                "NYNNY",
                "NNNYY"
            };
            int __expected = -1;
            return do_test(to_vector(switches), to_vector(lamps), __expected, __no);
        }
        case 4: {
            string switches[] = {
                "YNNYNNYNYY",
                "NYNNYNYNYN",
                "YNYNYYYYYN",
                "NNYYNYNYNN"
            };
            string lamps[] = {
                "NYYNYNNYNY",
                "NYYYNNYNNN",
                "YYYYNYNNYY",
                "YNNNNYNYYN"
            };
            int __expected = 2;
            return do_test(to_vector(switches), to_vector(lamps), __expected, __no);
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
    cout << "SwitchesAndLamps (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397735280;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
