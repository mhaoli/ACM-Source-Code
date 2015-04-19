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

class EllysScrabble {
    public:
        bool v[105];
    string getMin(string an, int dis) {
        //string no = "Impossible", yes = "Possible";
        string ret(sz(an), 0);
        clr (v, 0);
        repf (i, 0, sz(an)-1){
            int l = max (0, i - dis), r = min (sz(an)-1, i + dis);
            int tmp = l;
            repf (j, l, r) if (!v[j]){
                tmp = j; break;
            }
            if (tmp != i - dis) repf (j, l, r) if (!v[j] && an[tmp] > an[j]) tmp = j;
            v[tmp] = 1; ret[i] = an[tmp];
        }
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string letters, int maxDistance, string __expected, int caseNo) {

    time_t startClock = clock();
    EllysScrabble *instance = new EllysScrabble();
    string __result = instance->getMin(letters, maxDistance);
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
            string letters = "TOPCODER";
            int maxDistance = 3;
            string __expected = "CODTEPOR";
            return do_test(letters, maxDistance, __expected, __no);
        }
        case 1: {
            string letters = "ESPRIT";
            int maxDistance = 3;
            string __expected = "EIPRST";
            return do_test(letters, maxDistance, __expected, __no);
        }
        case 2: {
            string letters = "BAZINGA";
            int maxDistance = 8;
            string __expected = "AABGINZ";
            return do_test(letters, maxDistance, __expected, __no);
        }
        case 3: {
            string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            int maxDistance = 9;
            string __expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            return do_test(letters, maxDistance, __expected, __no);
        }
        case 4: {
            string letters = "GOODLUCKANDHAVEFUN";
            int maxDistance = 7;
            string __expected = "CADDGAHEOOFLUKNNUV";
            return do_test(letters, maxDistance, __expected, __no);
        }
        case 5: {
            string letters = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
            int maxDistance = 6;
            string __expected = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";
            return do_test(letters, maxDistance, __expected, __no);
        }
        case 6: {
            string letters = "ABRACADABRA";
            int maxDistance = 2;
            string __expected = "AABARACBDAR";
            return do_test(letters, maxDistance, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "EllysScrabble (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397319280;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
