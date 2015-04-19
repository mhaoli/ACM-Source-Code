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

class RotatedClock {
    public:
    string getEarliest(int h, int m) {
        repf (i, 0, 11) repf (j, 0, 11) repf (k, 0, 59){
            if (k & 1) continue;
            int t1 = j - i; while (t1 < 0) t1 += 12; t1 *= 30; t1 += k / 2;
            int t2 = (i % 12) * 5; t2 = k - t2; while (t2 < 0) t2 += 60; t2 *= 6;
            if (t1 == h && t2 == m){
                char buf[100];
                sprintf (buf, "%02d:%02d", j, k);
                return (string)buf;
            }
        }
        return "";
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int hourHand, int minuteHand, string __expected, int caseNo) {

    time_t startClock = clock();
    RotatedClock *instance = new RotatedClock();
    string __result = instance->getEarliest(hourHand, minuteHand);
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
            int hourHand = 70;
            int minuteHand = 300;
            string __expected = "08:20";
            return do_test(hourHand, minuteHand, __expected, __no);
        }
        case 1: {
            int hourHand = 90;
            int minuteHand = 120;
            string __expected = "11:00";
            return do_test(hourHand, minuteHand, __expected, __no);
        }
        case 2: {
            int hourHand = 240;
            int minuteHand = 36;
            string __expected = "";
            return do_test(hourHand, minuteHand, __expected, __no);
        }
        case 3: {
            int hourHand = 19;
            int minuteHand = 19;
            string __expected = "";
            return do_test(hourHand, minuteHand, __expected, __no);
        }
        case 4: {
            int hourHand = 1;
            int minuteHand = 12;
            string __expected = "00:02";
            return do_test(hourHand, minuteHand, __expected, __no);
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
    cout << "RotatedClock (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407326701;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
