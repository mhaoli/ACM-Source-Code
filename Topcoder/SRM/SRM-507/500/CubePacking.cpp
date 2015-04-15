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
#define tre(x) ((x)*(x)*(x))
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
const int inf = 2139062143;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class CubePacking {
    public:
    int getMinimumVolume(int n1, int n2, int l){
        int tot =  n2 * tre(l) + n1;
        int ans = inf;
        repf (i, l, 2000) for (int j = l; j*j*i > 0; ++ j){
            int t1 = i / l, t2 = j / l;
            int t3 = l * ceil(n2 * 1.0 / (t1 * t2));

            int k = ceil (tot * 1.0 / (i * j));
            chmax (k, t3);
            if (i * j * k > 0) chmin (ans, i * j * k);
        }
        return ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int Ns, int Nb, int L, int __expected, int caseNo) {

    time_t startClock = clock();
    CubePacking *instance = new CubePacking();
    int __result = instance->getMinimumVolume(Ns, Nb, L);
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
            int Ns = 158846335;
            int Nb = 973328;
            int L = 9;
            int __expected = 868402447;
            return do_test(Ns, Nb, L, __expected, __no);
        }
        case 1: {
            int Ns = 19;
            int Nb = 1;
            int L = 2;
            int __expected = 27;
            return do_test(Ns, Nb, L, __expected, __no);
        }
        case 2: {
            int Ns = 51;
            int Nb = 7;
            int L = 5;
            int __expected = 950;
            return do_test(Ns, Nb, L, __expected, __no);
        }
        case 3: {
            int Ns = 12345;
            int Nb = 987;
            int L = 10;
            int __expected = 999400;
            return do_test(Ns, Nb, L, __expected, __no);
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
    cout << "CubePacking (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405269185;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
