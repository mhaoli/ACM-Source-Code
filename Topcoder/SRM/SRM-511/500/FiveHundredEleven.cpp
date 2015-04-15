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

class FiveHundredEleven {
    public:
    vi num;
    int n;
    int d[600][55], f[600][55];
    bool vis[55][600][55];
    string theWinner(vector<int> _num) {
        string yes = "Fox Ciel", no = "Toastman";
        n = sz(_num); num = _num;

        int tsta = 0;
        for (int x : num) tsta |= x;
        if (tsta != 511) return ((n & 1) ? yes : no);

        clr (vis, 0); clr (f, 0); dfs (-1, 0, 0);

        clr (d, 0);
        repf (i, 1, n) d[511][i] = (i % 2 ? 2 : 1);
        repd (i, 510, 0) repd (j, n, 0) if (f[i][j]){
            int tmp = ((j & 1) ? 2 : 1);
            bool u = 0;
            if (d[i][j+1] == tmp) u = 1;
            for (int x : num) if ((i | x) != i){
                if (d[i|x][j+1] == tmp) u = 1;
            }
            if (u) d[i][j] = tmp;
            else d[i][j] = 3 - tmp;
        }
        return ((d[0][0] == 1 || d[0][1] == 1) ? yes : no);
    }
    void dfs (int p, int x, int cnt){
        if (vis[p+1][x][cnt]) return;
        vis[p+1][x][cnt] = 1;
        f[x][cnt] = 1;
        repf (i, p+1, n-1) dfs (i, x|num[i], cnt+1);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> cards, string __expected, int caseNo) {

    time_t startClock = clock();
    FiveHundredEleven *instance = new FiveHundredEleven();
    string __result = instance->theWinner(cards);
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
            int cards[] = {
                0, 511
            };
            string __expected = "Fox Ciel";
            return do_test(to_vector(cards), __expected, __no);
        }
        case 1: {
            int cards[] = {
                0, 0, 0, 0
            };
            string __expected = "Toastman";
            return do_test(to_vector(cards), __expected, __no);
        }
        case 2: {
            int cards[] = {
                511
            };
            string __expected = "Toastman";
            return do_test(to_vector(cards), __expected, __no);
        }
        case 3: {
            int cards[] = {
                5, 58, 192, 256
            };
            string __expected = "Fox Ciel";
            return do_test(to_vector(cards), __expected, __no);
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
    cout << "FiveHundredEleven (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405653236;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
