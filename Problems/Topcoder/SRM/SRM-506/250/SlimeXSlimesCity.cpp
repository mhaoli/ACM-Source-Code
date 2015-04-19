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

class SlimeXSlimesCity {
    public:
    bool v[55];
    int merge(vector<int> an){
        vector<int64> num; repf (i, 0, sz(an)-1) num.pb (an[i]);
        int n = sz(num), ans = 0;
        repf (i, 0, n-1){
            int64 sum = num[i], cnt = 1;
            clr (v, 0); v[i] = 1;
            while (cnt < n){
                int idx = -1;
                repf (j, 0, n-1) if (!v[j] && sum >= num[j]) idx = j;
                if (idx == -1) break;
                v[idx] = 1; sum += num[idx]; ++ cnt;
            }
            if (cnt == n) ++ ans;
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> population, int __expected, int caseNo) {

    time_t startClock = clock();
    SlimeXSlimesCity *instance = new SlimeXSlimesCity();
    int __result = instance->merge(population);
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
            int population[] = {
                2, 3, 4
            };
            int __expected = 2;
            return do_test(to_vector(population), __expected, __no);
        }
        case 1: {
            int population[] = {
                1, 2, 3
            };
            int __expected = 2;
            return do_test(to_vector(population), __expected, __no);
        }
        case 2: {
            int population[] = {
                8, 2, 3, 8
            };
            int __expected = 2;
            return do_test(to_vector(population), __expected, __no);
        }
        case 3: {
            int population[] = {
                1000000000, 999999999, 999999998, 999999997
            };
            int __expected = 3;
            return do_test(to_vector(population), __expected, __no);
        }
        case 4: {
            int population[] = {
                1, 1, 1
            };
            int __expected = 3;
            return do_test(to_vector(population), __expected, __no);
        }
        case 5: {
            int population[] = {
                1, 2, 4, 6, 14, 16, 20
            };
            int __expected = 3;
            return do_test(to_vector(population), __expected, __no);
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
    cout << "SlimeXSlimesCity (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403011529;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
