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
const int mod = 1000000007;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int num[1000];
vi an[1000];

bool cmp (vi a, vi b){
    int t1 = 0, t2 = 0;
    int c = 0;
    for (auto x : b) t1 += c * x, t2 += 50 * x * (c++);
    c = 0;
    for (auto x : a) t2 += c * x, t1 += 50 * x * (c++);
    return t2 < t1;
}

class RowsOrdering {
    public:
    int order(vector<string> rows) {
        int n = sz(rows), m = sz (rows[0]);
        repd (j, m-1, 0){
            an[j].clear(); clr (num, 0);
            repf (i, 0, n-1) ++ num[idx(rows[i][j])];
            sort (num+1, num+51, greater<int>());
            repf (i, 1, 51) if (num[i] > 0) an[j].pb (num[i]);
        }

        sort (an, an+m, cmp);

        int ans = 0, len = 1;
        repf (i, 0, m-1){
            int s = (!i);
            repf (j, 0, sz(an[i])-1){
                int tmp = 1LL * (s + j) * len % mod;
                tmp = 1LL * tmp * an[i][j] % mod;
                add (ans, tmp);
            }
            len = 50LL * len % mod;
        }
        return ans;
    }
    void add (int &a, int b){
        a += b; if (a >= mod) a -= mod;
    }
    int idx (char c){
        if (c >= 'a' && c <= 'z') return c - 'a' + 1;
        return c - 'A' + 27;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> rows, int __expected, int caseNo) {

    time_t startClock = clock();
    RowsOrdering *instance = new RowsOrdering();
    int __result = instance->order(rows);
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
            string rows[] = {
                "dolphinigle", 
                "ivanmetelsk",
                "lympandaaaa"
                //"bb",
                //"cb",
                //"ca"
            };
            //int __expected = 54;
            int __expected = 356186235;
            return do_test(to_vector(rows), __expected, __no);
        }
        case 1: {
            string rows[] = {
                "abcd",
                "ABCD"
            };
            int __expected = 127553;
            return do_test(to_vector(rows), __expected, __no);
        }
        case 2: {
            string rows[] = {
                "Example",
                "Problem"
            };
            int __expected = 943877448;
            return do_test(to_vector(rows), __expected, __no);
        }
        case 3: {
            string rows[] = {
                "a",
                "b",
                "c",
                "d",
                "e",
                "f",
                "g"
            };
            int __expected = 28;
            return do_test(to_vector(rows), __expected, __no);
        }
        case 4: {
            string rows[] = {
                "a",
                "a"
            };
            int __expected = 2;
            return do_test(to_vector(rows), __expected, __no);
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
    cout << "RowsOrdering (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407414341;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
