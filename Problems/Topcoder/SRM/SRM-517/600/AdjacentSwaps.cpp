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
const int maxn = 555;
const int mod = 1000000007;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi an;
int n;
int pre[maxn], suf[maxn];
int d[77][77], C[77][77];

class AdjacentSwaps {
    public:
    int theCount(vector<int> _an){
        an = _an;
        n = sz (an);

        C[0][0] = C[1][0] = C[1][1] = 1;
        repf (i, 2, n){
            C[i][0] = C[i][i] = 1;
            repf (j, 1, n-1) C[i][j] = C[i-1][j], add (C[i][j], C[i-1][j-1]);
        }

        pre[0] = pre[1] = an[0]; repf (i, 2, n-1) pre[i] = pre[i-1], chmax (pre[i], an[i-1]);
        suf[n-1] = suf[n-2] = an[n-1]; repd (i, n-3, 0) suf[i] = suf[i+1], chmin (suf[i], an[i+1]);

        //repf (i, 0, n-1) tst (i), tst (pre[i]), out (suf[i]);
       // 
        clr (d, -1);
        return dfs (0, n-1);
    }
    int dfs (int l, int r){
        int &ret = d[l][r];
        if (~ret) return ret;
        ret = 0;

        repf (i, l+1, r-2) if (pre[i+1] == an[i] && suf[i] == an[i+1]){
            int tmp = 1LL * dfs (l, i) * dfs (i+1, r) % mod;
            tmp = 1LL * tmp * C[r-l-1][i-l] % mod;
            add (ret, tmp);
        }
        if (l + 1 == r){
            if (pre[l] == r && suf[r] == l) return ret = 1;
            else return ret = 0;
        }
        else{
            if (pre[l+1] == pre[l] && l == an[l+1]){
                add (ret, dfs (l+1, r) % mod);
            }
            if (suf[r-1] == suf[r] && r == an[r-1]){
                add (ret, dfs (l, r-1) % mod);
            }
        }
        return ret;
    }
    void add (int &a, int b){
        a += b; if (a >= mod) a -= mod;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> p, int __expected, int caseNo) {

    time_t startClock = clock();
    AdjacentSwaps *instance = new AdjacentSwaps();
    int __result = instance->theCount(p);
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
            int p[] = {
                1, 2, 0
            };
            int __expected = 1;
            return do_test(to_vector(p), __expected, __no);
        }
        case 1: {
            int p[] = {
                0, 1
            };
            int __expected = 0;
            return do_test(to_vector(p), __expected, __no);
        }
        case 2: {
            int p[] = {
                2, 0, 3, 1
            };
            int __expected = 2;
            return do_test(to_vector(p), __expected, __no);
        }
        case 3: {
            int p[] = {
                1, 0, 3, 2
            };
            int __expected = 0;
            return do_test(to_vector(p), __expected, __no);
        }
        case 4: {
            int p[] = {
                1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17
            };
            int __expected = 716743312;
            return do_test(to_vector(p), __expected, __no);
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
    cout << "AdjacentSwaps (600 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407495437;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
