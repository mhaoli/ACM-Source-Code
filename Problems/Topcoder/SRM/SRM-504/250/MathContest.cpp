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

class MathContest {
    public:
    int countBlack(string an, int rept) {
        string s;
        repf (i, 0, rept-1) s += an;
        int cha = 0, dir = 0, ret = 0;
        int pos[2] = {0, sz(s)-1};
        while (pos[0] <= pos[1]){
            if (ok (cha, s[pos[dir]])){
                cha ^= 1;
                if (!dir) ++ pos[0];
                else -- pos[1];
                ++ ret;
            }
            else{
                if (!dir) ++ pos[0];
                else -- pos[1];
                dir ^= 1;
            }
        }
        return ret;
    }
    bool ok (int u, char c){
        if (u) c = (c == 'B') ? 'W' : 'B';
        if (c == 'B') return 1;
        return 0;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string ballSequence, int repetitions, int __expected, int caseNo) {

    time_t startClock = clock();
    MathContest *instance = new MathContest();
    int __result = instance->countBlack(ballSequence, repetitions);
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
            string ballSequence = "BBWWB";
            int repetitions = 1;
            int __expected = 2;
            return do_test(ballSequence, repetitions, __expected, __no);
        }
        case 1: {
            string ballSequence = "BBB";
            int repetitions = 10;
            int __expected = 1;
            return do_test(ballSequence, repetitions, __expected, __no);
        }
        case 2: {
            string ballSequence = "BW";
            int repetitions = 10;
            int __expected = 20;
            return do_test(ballSequence, repetitions, __expected, __no);
        }
        case 3: {
            string ballSequence = "WWWWWWWBWWWWWWWWWWWWWW";
            int repetitions = 1;
            int __expected = 2;
            return do_test(ballSequence, repetitions, __expected, __no);
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
    cout << "MathContest (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402838016;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
