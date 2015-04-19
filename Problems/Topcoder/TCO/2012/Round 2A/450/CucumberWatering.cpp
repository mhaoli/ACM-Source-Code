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
typedef pair<int64, int> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int64 inf = 1LL << 60;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

vector<pii > vec;
vector<int64> xn;
int64 d[55][55], dis[55], idx[55];

class CucumberWatering {
    public:
    long long theMin(vector<int> Xn, int m){
        xn.clear(); repf (i, 0, sz(Xn)-1) xn.pb (Xn[i]);
        vec.clear();
        int n = sz(xn);
        vec.pb (mp (-(1LL<<33), 0));
        repf (i, 0, n-1) vec.pb (mp (xn[i], i+1));

        int64 tot = 0;
        repf (i, 1, n-1) tot += llabs (xn[i] - xn[i-1]);
        if (!m) return tot;

        sort (all(vec));
        repf (i, 0, sz(vec)-1) idx[vec[i].y] = i;

        repf (i, 0, n-1) repf (j, 0, m) d[i][j] = inf;
        d[1][1] = 0;
        repf (i, 2, n){
            d[i][1] = dis (vec[0].x, vec[i].x);
            repf (j, 2, m){
                d[i][j] = inf;
                repf (k, 1, i-1) chmin (d[i][j], d[k][j-1] + dis (vec[k].x, vec[i].x));
            }
        }

        int64 ans = tot;
        repf (i, 1, n) repf (j, 1, m) chmin (ans, d[i][j] + dis (vec[i].x, 1LL<<33));
        return ans;
    }
    int64 dis (int64 s, int64 e){
        int64 ret = 0;
        repf (i, 1, sz(xn)-1){
            bool u1 = ok (xn[i-1], s, e), u2 = ok (xn[i], s, e);
            if (!u1 && !u2) continue;
            if (u1 && u2){
                int64 tmp = llmin (llabs(xn[i]-s), llabs(xn[i]-e)) + llmin (llabs(xn[i-1]-e), llabs(xn[i-1]-s));
                ret += llmin (llabs (xn[i]-xn[i-1]), tmp);
            }
            else if (u1) ret += llmin (llabs (xn[i-1] - e), llabs (xn[i-1] - s));
            else ret += llmin (llabs (xn[i] - e), llabs (xn[i] - s));
        }
        return ret;
    }
    int64 llmin (int64 a, int64 b){
        return a > b ? b : a;
    }
    int64 llabs (int64 a){
        return a > 0 ? a : -a;
    }
    bool ok (int64 a, int64 s, int64 e){
        if (a >= s && a <= e) return 1;
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, int K, long long __expected, int caseNo) {

    time_t startClock = clock();
    CucumberWatering *instance = new CucumberWatering();
    long long __result = instance->theMin(x, K);
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
            int x[] = {
                0, 6, 8, 2
            };
            int K = 2;
            long long __expected = 6LL;
            return do_test(to_vector(x), K, __expected, __no);
        }
        //case 0: {
            //int x[] = {
                //-485419501, 869992369, -237766831, -536692389, 587917460, -724559331, 165037606, -237315266, 379784329, -762332332, 36584326, -348342877, -324203280, 121982811, 745436682, -408401971, -770873170, -623866964, -743993184, 447999658, 655140981, 832021770, -899092739, 940920896, 519872561, -235259365, 987281, -576059810, -912995787, 684161129, 357569150, -212923458, 340007420, -392843948, -333464533, -185197708, -438253069, -512405373, 474896293, -114986051, 207049741, 781811135, -528800398, 883537430, 459635399, -836994604, 963298347, -113930922, -153493438, -484278794
            //};
            //int K = 2;
            //long long __expected = 18116173390LL;
            //return do_test(to_vector(x), K, __expected, __no);
        //}
        case 1: {
            int x[] = {
                -1000000000, 1000000000, 0
            };
            int K = 1;
            long long __expected = 3000000000LL;
            return do_test(to_vector(x), K, __expected, __no);
        }
        case 2: {
            int x[] = {
                58, 2012
            };
            int K = 50;
            long long __expected = 0LL;
            return do_test(to_vector(x), K, __expected, __no);
        }
        case 3: {
            int x[] = {
                9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11
            };
            int K = 3;
            long long __expected = 58LL;
            return do_test(to_vector(x), K, __expected, __no);
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
    cout << "CucumberWatering (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397742417;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
