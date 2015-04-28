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

class Similars {
        public:
                int maxsim(int L, int R);
};

int calc(int x) {
        int ret = 0, t;
        while(x) {
                t = x % 10;
                ret |= (1 << t);
                x /= 10;
        }
        return ret;
}

int Similars::maxsim(int L, int R){
        //string yes = "Possible", no = "Impossible";
        set<int> has;
        has.clear();
        int ans = 0;
        for(int i = L; i <= R; ++i) {
                int tmp = calc(i);
                if(has.find(tmp) != has.end()) {
                        ans = max(ans, __builtin_popcount(tmp));
                }
                has.insert(tmp);
        }
        snuke(i, has) snuke(j, has) if((*i) != (*j))
                ans = max(ans, __builtin_popcount((*i)&(*j)));
        return ans;
}

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int L, int R, int __expected, int caseNo) {

    time_t startClock = clock();
    Similars *instance = new Similars();
    int __result = instance->maxsim(L, R);
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
            int L = 1;
            int R = 10;
            int __expected = 1;
            return do_test(L, R, __expected, __no);
        }
        case 1: {
            int L = 1;
            int R = 99;
            int __expected = 2;
            return do_test(L, R, __expected, __no);
        }
        case 2: {
            int L = 99;
            int R = 100;
            int __expected = 0;
            return do_test(L, R, __expected, __no);
        }
        case 3: {
            int L = 1000;
            int R = 1010;
            int __expected = 2;
            return do_test(L, R, __expected, __no);
        }
        case 4: {
            int L = 444;
            int R = 454;
            int __expected = 2;
            return do_test(L, R, __expected, __no);
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
    cout << "Similars (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430124495;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
