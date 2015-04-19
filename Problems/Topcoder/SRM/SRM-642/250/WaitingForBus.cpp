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
#include <complex>

using namespace std;

#define x first
#define y second
#define sqr(x) ((x)*(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/***head***/

class WaitingForBus {
        public:
                double whenWillBusArrive(vector<int> time, vector<int> prob, int s);
};

const int Max_N = 9 + (int)2e5;
double p[Max_N], dp[Max_N];
int tim[Max_N];
double WaitingForBus::whenWillBusArrive(vector<int> time, vector<int> prob, int s){
        //string yes = "Possible", no = "Impossible";
        int n = time.size();
        for(int i = 0; i < n; ++i) tim[i] = time[i], p[i] = prob[i] / 100.0;
        dp[0] = 1;
        for(int i = 1, j; i < Max_N; ++i) {
                dp[i] = 0;
                for(j = 0; j < n; ++j) if(i - tim[j] >= 0 && i - tim[j] < s) dp[i] += dp[i-tim[j]] * p[j];
        }
        double ans = 0;
        for(int i = s; i < Max_N; ++i) ans += (i - s) * dp[i];
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<int> time, vector<int> prob, int s, double __expected, int caseNo) {

    time_t startClock = clock();
    WaitingForBus *instance = new WaitingForBus();
    double __result = instance->whenWillBusArrive(time, prob, s);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            int time[] = {
                5, 100
            };
            int prob[] = {
                90, 10
            };
            int s = 5;
            double __expected = 9.5;
            return do_test(to_vector(time), to_vector(prob), s, __expected, __no);
        }
        case 1: {
            int time[] = {
                5
            };
            int prob[] = {
                100
            };
            int s = 101;
            double __expected = 4.0;
            return do_test(to_vector(time), to_vector(prob), s, __expected, __no);
        }
        case 2: {
            int time[] = {
                5, 10
            };
            int prob[] = {
                50, 50
            };
            int s = 88888;
            double __expected = 3.666666666666667;
            return do_test(to_vector(time), to_vector(prob), s, __expected, __no);
        }
        case 3: {
            int time[] = {
                1, 2, 3, 4
            };
            int prob[] = {
                10, 20, 30, 40
            };
            int s = 1000;
            double __expected = 1.166666666666667;
            return do_test(to_vector(time), to_vector(prob), s, __expected, __no);
        }
        case 4: {
            int time[] = {
                10, 100, 1000, 10000, 100000
            };
            int prob[] = {
                90, 4, 3, 2, 1
            };
            int s = 100000;
            double __expected = 21148.147303578935;
            return do_test(to_vector(time), to_vector(prob), s, __expected, __no);
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
    cout << "WaitingForBus (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1418781645;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
