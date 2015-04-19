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
const int64 mod = 1000000007;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 f[555], s[555];
int d[77][77];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

class BricksN {
    public:
        int countStructures(int w, int h, int K){
            clr (f, 0); f[0] = 1;
            rep (i, 1, max (w, h)) rep (j, 1, i) if (j <= K) f[i] = (f[i] + f[i-j]) % mod;

            clr (d, 0);
            rep (i, 0, max (w, h)) d[i][0] = d[0][i] = 1;
            rep (j, 1, h) rep (i, 1, w){
                add (d[i][j], f[i] * d[i][j-1] % mod);
                add (d[i][j], d[i-1][j]);
                if (i > 1)
                    add (d[i][j], f[i-1] * d[i-1][j-1] % mod);
                rep (k, 1, i-2)
                    add (d[i][j], (f[k] * d[k][j-1] % mod) * d[i-k-1][j] % mod);
            }
            return d[w][h];
        }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int w, int h, int k, int __expected, int caseNo) {

    time_t startClock = clock();
    BricksN *instance = new BricksN();
    int __result = instance->countStructures(w, h, k);
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
                    int w = 3;
                    int h = 1;
                    int k = 3;
                    int __expected = 13;
                    return do_test(w, h, k, __expected, __no);
                }
        case 1: {
                    int w = 3;
                    int h = 2;
                    int k = 3;
                    int __expected = 83;
                    return do_test(w, h, k, __expected, __no);
                }
        case 2: {
                    int w = 1;
                    int h = 5;
                    int k = 1;
                    int __expected = 6;
                    return do_test(w, h, k, __expected, __no);
                }
        case 3: {
                    int w = 10;
                    int h = 10;
                    int k = 3;
                    int __expected = 288535435;
                    return do_test(w, h, k, __expected, __no);
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
    cout << "BricksN (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409056985;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
