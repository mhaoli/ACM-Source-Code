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

class HeavyBooks {
    public:
    int v[55], d[55][55];
    pair<int, int> ans[55][55];
    vector<int> findWeight(vector<int> num, vector<int> mov){
        clr (v, 0);
        int n = mov[0];
        repf (i, 1, n) v[i] = 1;
        repf (i, 1, sz(mov)-1){
            int tcnt = 0, add = i&1 ? -2 : 2;
            repf (j, 1, n){
                if (add == -2 && v[j] == 1) ++ tcnt, v[j] += add;
                if (add == 2 && v[j] == -1) ++ tcnt, v[j] += add;
                if (tcnt == mov[i]) break;
            }
        }

        sort (all(num), greater<int>());
        clr (d, 0);
        repf (i, 0, sz(num)-1) repf (j, 1, n) d[i][j] = -inf;
        repf (i, 0, sz(num)-1) repf (j, 1, n) ans[i][j] = mp (inf, 0);
        repf (i, 0, sz(num)-1) ans[i][0] = mp (0, 0);
        d[0][1] = v[1] * num[0];
        ans[0][1] = Mypair(0, 0, v[1], num[0]);
        
        repf (i, 1, sz(num)-1) repf (j, 1, n){
            if (d[i][j] < d[i-1][j]) ans[i][j] = ans[i-1][j], d[i][j] = d[i-1][j];

            if (d[i][j] < d[i-1][j-1] + v[j] * num[i]){
                d[i][j] = d[i-1][j-1] + v[j] * num[i];
                ans[i][j] = Mypair (ans[i-1][j-1].x, ans[i-1][j-1].y, v[j], num[i]);
            }
            else if (d[i][j] == d[i-1][j-1] + v[j] * num[i]) 
                chmax (ans[i][j], Mypair (ans[i-1][j-1].x, ans[i-1][j-1].y, v[j], num[i]));
        }

        int ma = -inf;
        repf (i, 0, sz(num)-1) chmax (ma, d[i][n]);

        pair<int, int> ret = mp (inf, 0);
        repf (i, 0, sz(num)-1) if (d[i][n] == ma) {
            if (ret.x == inf) ret = ans[i][n];
            else chmax (ret, ans[i][n]);
        }

        vi vret;
        vret.pb (ret.x); vret.pb (ret.y);
        return vret;
    }
    pair<int, int> Mypair(int x, int y, int vv, int tnum){
        if (vv == 1) return mp (x, y + tnum);
        return mp (x + tnum, y);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(vector<int> books, vector<int> moves, vector<int> __expected, int caseNo) {

    time_t startClock = clock();
    HeavyBooks *instance = new HeavyBooks();
    vector<int> __result = instance->findWeight(books, moves);
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
            int books[] = {
                5, 2, 3, 1
            };
            int moves[] = {
                3, 2, 1, 1, 1
            };
            int __expected[] = {
                3, 7
            };
            return do_test(to_vector(books), to_vector(moves), to_vector(__expected), __no);
        }
        case 1: {
            int books[] = {
                10, 100, 1000
            };
            int moves[] = {
                2, 3
            };
            int __expected[] = {
                110, 0
            };
            return do_test(to_vector(books), to_vector(moves), to_vector(__expected), __no);
        }
        case 2: {
            int books[] = {
                155870, 565381
            };
            int moves[] = {
                1, 1, 1
            };
            int __expected[] = {
                0, 565381
            };
            return do_test(to_vector(books), to_vector(moves), to_vector(__expected), __no);
        }
        case 3: {
            int books[] = {
                500, 500, 500, 500
            };
            int moves[] = {
                4, 1, 1, 3, 2
            };
            int __expected[] = {
                500, 1500
            };
            return do_test(to_vector(books), to_vector(moves), to_vector(__expected), __no);
        }
        case 4: {
            int books[] = {
                1, 1, 1, 1, 1000000
            };
            int moves[] = {
                1
            };
            int __expected[] = {
                0, 1000000
            };
            return do_test(to_vector(books), to_vector(moves), to_vector(__expected), __no);
        }
        case 5: {
            int books[] = {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
            };
            int moves[] = {
                20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
            };
            int __expected[] = {
                110, 100
            };
            return do_test(to_vector(books), to_vector(moves), to_vector(__expected), __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "HeavyBooks (550 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1398251493;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
