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
//const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/***head***/

long long mymax(long long t1, long long t2) {
        return t1 < t2 ? t2 : t1;
}

class ProblemSets {
        public:
                long long maxSets(long long E, long long EM, long long M, long long MH, long long H);
};

const long long inf = 1e18;
long long t1, t2, t3, t4, t5;

bool check(long long t) {
        long long s1 = t - t1, s3 = t - t5;
        //if(s1 >= 0 && s2 >= 0 && s3 >= 0) return 1;
        long long a1 = t2 - mymax(s1,0ll), a2 = t4 - mymax(0ll,s3);
        //if(t == 5) out(a1);
        if(a1 < 0 || a2 < 0 || t3 + a1 + a2 < t) return 0;
        return 1;
}

long long ProblemSets::maxSets(long long E, long long EM, long long M, long long MH, long long H){
        t1 = E; t2 = EM; t3 = M; t4 = MH; t5 = H;
        //string yes = "Possible", no = "Impossible";
        long long l = 0, r = inf << 1, mid, ans;
        //out(check(5));
        while(l <= r) {
                mid = (l + r) >> 1;
                if(check(mid)) ans = mid, l = mid + 1;
                else r = mid - 1;
        }
        return ans;
}

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long E, long long EM, long long M, long long MH, long long H, long long __expected, int caseNo) {

    time_t startClock = clock();
    ProblemSets *instance = new ProblemSets();
    long long __result = instance->maxSets(E, EM, M, MH, H);
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
            long long E = 2LL;
            long long EM = 2LL;
            long long M = 1LL;
            long long MH = 2LL;
            long long H = 2LL;
            long long __expected = 3LL;
            return do_test(E, EM, M, MH, H, __expected, __no);
        }
        case 1: {
            long long E = 100LL;
            long long EM = 100LL;
            long long M = 100LL;
            long long MH = 0LL;
            long long H = 0LL;
            long long __expected = 0LL;
            return do_test(E, EM, M, MH, H, __expected, __no);
        }
        case 2: {
            long long E = 657LL;
            long long EM = 657LL;
            long long M = 657LL;
            long long MH = 657LL;
            long long H = 657LL;
            long long __expected = 1095LL;
            return do_test(E, EM, M, MH, H, __expected, __no);
        }
        case 3: {
            long long E = 1LL;
            long long EM = 2LL;
            long long M = 3LL;
            long long MH = 4LL;
            long long H = 5LL;
            long long __expected = 3LL;
            return do_test(E, EM, M, MH, H, __expected, __no);
        }
        case 4: {
            long long E = 1000000000000000000LL;
            long long EM = 1000000000000000000LL;
            long long M = 1000000000000000000LL;
            long long MH = 1000000000000000000LL;
            long long H = 1000000000000000000LL;
            long long __expected = 1666666666666666666LL;
            return do_test(E, EM, M, MH, H, __expected, __no);
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
    cout << "ProblemSets (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430318607;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
