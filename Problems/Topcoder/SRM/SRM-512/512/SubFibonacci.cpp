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
const int inf = 1e9;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class SubFibonacci {
    public:
    vector<pii > fib;
    int maxElements(vector<int> s){
        //string no = "Impossible", yes = "Possible";
        init();
        sort (all (s));
        int ret = 0;
        repf (i, 0, sz(s)) chmax (ret, calc (vi(s.begin(), s.begin()+i)) + calc (vi(s.begin()+i, s.end())));
        return ret;
    }
    int calc (vi an){
        if (sz (an) <= 2) return sz (an);
        int ret = 2;
        set<int> has(all (an));
        repf (i, 0, sz(an)-1) repf (j, i+2, sz(an)-1){
            repf (k, 3, sz(fib)){
                int t = (an[j] - an[i] * fib[k-1].x) / fib[k-1].y;
                if (t <= 0) continue;
                if (t * fib[k-1].y + an[i] * fib[k-1].x != an[j]) continue;
                int cnt = has.count (an[i]);
                if (t > an[i]) cnt += has.count (t);
                int t1 = an[i];
                while (t != an[j]){
                    int tmp = t1; t1 = t; t += tmp;
                    if (t > an[i] && has.count (t)) ++ cnt;
                }
                chmax (ret, cnt);
            }
        }
        return ret;
    }
    void init(){
        fib.clear();
        fib.pb (mp (1, 0)); fib.pb (mp (0, 1));
        repf (i, 2, 1000){
            int x = fib[i-1].x + fib[i-2].x, y = fib[i-1].y + fib[i-2].y;
            if ((x > inf || x < 0) && (y > inf || y < 0)) break;
            fib.pb (mp (x, y));
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> S, int __expected, int caseNo) {

    time_t startClock = clock();
    SubFibonacci *instance = new SubFibonacci();
    int __result = instance->maxElements(S);
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
            int S[] = {
                8, 1, 20, 3, 10
            };
            int __expected = 5;
            return do_test(to_vector(S), __expected, __no);
        }
        case 1: {
            int S[] = {
                19, 47, 50, 58, 77, 99
            };
            int __expected = 4;
            return do_test(to_vector(S), __expected, __no);
        }
        case 2: {
            int S[] = {
                512
            };
            int __expected = 1;
            return do_test(to_vector(S), __expected, __no);
        }
        case 3: {
            int S[] = {
                3, 5, 7, 10, 13, 15, 20, 90
            };
            int __expected = 7;
            return do_test(to_vector(S), __expected, __no);
        }
        case 4: {
            int S[] = {
                1, 2, 3, 5, 8, 13, 21, 34, 55, 89
            };
            int __expected = 10;
            return do_test(to_vector(S), __expected, __no);
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
    cout << "SubFibonacci (512 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405960209;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 512 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
