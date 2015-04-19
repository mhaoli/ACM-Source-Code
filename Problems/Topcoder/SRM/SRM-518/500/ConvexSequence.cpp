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

class ConvexSequence {
    public:
    long long getMinimum(vector<int> a){
        int64 ans = 0;
        bool u = 1;
        while (u){
            u = 0;
            repf (i, 1, sz(a)-2) if (2*a[i] > a[i-1] + a[i+1]){
                int t = floor ((a[i-1] + a[i+1]) / 2.0);
                ans += a[i] - t; a[i] = t;
                u = 1;
            }
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> a, long long __expected, int caseNo) {

    time_t startClock = clock();
    ConvexSequence *instance = new ConvexSequence();
    long long __result = instance->getMinimum(a);
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
            int a[] = {
                6, 5, 1, 5, 3, 3
            };
            long long __expected = 7LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 1: {
            int a[] = {
                3, 0, 1, 4
            };
            long long __expected = 0LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 2: {
            int a[] = {
                1, 1, 1, 0, 2, 2, 2
            };
            long long __expected = 5LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 3: {
            int a[] = {
                854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519, 274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743, 946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939, 823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006, 903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213, 876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625, 686305822, 663789601
            };
            long long __expected = 20178337330LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 4: {
            int a[] = {
                5
            };
            long long __expected = 0LL;
            return do_test(to_vector(a), __expected, __no);
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
    cout << "ConvexSequence (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407586596;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
