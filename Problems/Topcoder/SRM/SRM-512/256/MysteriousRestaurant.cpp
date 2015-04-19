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

class MysteriousRestaurant {
    public:
    vs pri;
    int num[100];
    int maxDays(vector<string> prices, int mon) {
        pri = prices; 
        int l = 0, r = sz(pri), ans = 0;
        while (l <= r){
            int m = (l + r) >> 1;
            if (ok (m, mon)) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
    bool ok (int n, int mon){
        int m = sz(pri[0]);
        repf (i, 0, 6){
            clr (num, 0);
            for (int j = i; j < n; j += 7){
                repf (k, 0, m-1) num[k] += calc (pri[j][k]);
            }
            sort (num, num+m);
            mon -= num[0];
        }
        if (mon >= 0) return 1;
        return 0;
    }
    int calc (char c){
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
        return c - 'a' + 36;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> prices, int budget, int __expected, int caseNo) {

    time_t startClock = clock();
    MysteriousRestaurant *instance = new MysteriousRestaurant();
    int __result = instance->maxDays(prices, budget);
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
            string prices[] = {
                "26",
                "14",
                "72",
                "39",
                "32",
                "85",
                "06"
            };
            int budget = 13;
            int __expected = 5;
            return do_test(to_vector(prices), budget, __expected, __no);
        }
        case 1: {
            string prices[] = {
                "26",
                "14",
                "72",
                "39",
                "32",
                "85",
                "06",
                "91"
            };
            int budget = 20;
            int __expected = 8;
            return do_test(to_vector(prices), budget, __expected, __no);
        }
        case 2: {
            string prices[] = {
                "SRM",
                "512"
            };
            int budget = 4;
            int __expected = 0;
            return do_test(to_vector(prices), budget, __expected, __no);
        }
        case 3: {
            string prices[] = {
                "Dear",
                "Code",
                "rsHa",
                "veFu",
                "nInT",
                "heCh",
                "alle",
                "ngeP",
                "hase",
                "andb",
                "ecar",
                "eful"
            };
            int budget = 256;
            int __expected = 10;
            return do_test(to_vector(prices), budget, __expected, __no);
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
    cout << "MysteriousRestaurant (256 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405958996;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 256 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
