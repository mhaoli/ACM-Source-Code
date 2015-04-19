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
#define pow pown
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
const int mod = 1000000007;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int siz[1<<11];
int64 pow[2][3000], d[55][1<<11];

class MagicalGirlLevelTwoDivOne {
    public:
    vi bn[55], bn_num[55];
    int theCount(vector<string> an, int tn, int tm) {
        int n = sz(an), m = sz(an[0]);

        repf (i, 0, tn-1) bn[i].resize(tm, 0), bn_num[i].resize (tm, 0);
        repf (i, 0, n-1) repf (j, 0, m-1) if (an[i][j] == '.') ++ bn_num[i%tn][j%tm];

        repf (i, 0, tn-1) repf (j, 0, tm-1){
            int tmp = 0;
            for (int k = i; k < n; k += tn) if (an[k][j] != '.'){
                if (!tmp) tmp = an[k][j] - '0';
                else if ((tmp&1) != ((an[k][j]-'0')&1)) return 0;
            }
            if (!tmp) continue;
            bn[i][j] = tmp;
            for (int k = i; k < n; k += tn) an[k][j] = tmp + '0';
        }

        repf (i, 0, n-1) repf (j, 0, tm-1){
            int tmp = 0;
            for (int k = j; k < m; k += tm) if (an[i][k] != '.'){
                if (!tmp) tmp = an[i][k] - '0';
                else if ((tmp&1) != ((an[i][k]-'0')&1)) return 0;
            }
            if (!tmp) continue;
            bn[i%tn][j] = tmp;
            for (int k = j; k < m; k += tm) an[i][j] = tmp + '0';
        }

        //repf (i, 0, tn-1){
            //for (int xx : bn[i]) tst (xx);
            //cout << endl;
        //}
//
        //cout << endl;
//
        //repf (i, 0, tn-1){
            //for (int xx : bn_num[i]) tst (xx);
            //cout << endl;
        //}

        pow[0][0] = pow[1][0] = 1LL;
        repf (i, 1, n*m) pow[0][i] = pow[0][i-1] * 4 % mod;
        repf (i, 1, n*m) pow[1][i] = pow[1][i-1] * 5 % mod;

        siz[0] = 0;
        repf (i, 1, (1<<tm)-1) siz[i] = siz[i>>1] + (i & 1);

        clr (d, 0);
        repf (i, 0, (1<<tm)-1) if (ok (0, i)){
            d[0][i] = 1;
            repf (t, 0, tm-1) d[0][i] = d[0][i] * pow[(i>>t)&1][bn_num[0][t]] % mod;
        }
        repf (i, 1, tn-1) repf (j, 0, (1<<tm)-1) if (d[i-1][j]){
            repf (k, 0, (1<<tm)-1) if (ok (i, k)){
                int64 tmp = 1;
                repf (t, 0, tm-1) tmp = pow[(k>>t)&1][bn_num[i][t]] * tmp % mod;
                d[i][k^j] = (d[i][k^j] + d[i-1][j] * tmp) % mod;
            }
        }
        return d[tn-1][(1<<tm)-1];
    }
    bool ok (int x, int s){
        if (!(siz[s] & 1)) return 0;
        repf (i, 0, sz(bn[x])-1){
            int t = bn[x][i];
            if (!t) continue;
            if ((t&1) != ((s>>i) & 1)) return 0;
        }
        return 1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> palette, int n, int m, int __expected, int caseNo) {

    time_t startClock = clock();
    MagicalGirlLevelTwoDivOne *instance = new MagicalGirlLevelTwoDivOne();
    int __result = instance->theCount(palette, n, m);
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

//{{"8...4........", "..1....4...95", ".............", "............8", ".........3...", ".6...........", "....363.28...", "4..3.........", "...5........9", "...5.2.......", "1......9..9..", ".........5..8", ".8...........", "..........5.1", "24...4..1.2..", "8...8.......1", "2..3.........", "..2..28.77...", "5........7..."}, 7, 9}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            string palette[] = {
                "12",
                "2."
            };
            int n = 2;
            int m = 2;
            int __expected = 5;
            return do_test(to_vector(palette), n, m, __expected, __no);
        }
        case 1: {
            string palette[] = {
                "21",
                "1."
            };
            int n = 2;
            int m = 2;
            int __expected = 4;
            return do_test(to_vector(palette), n, m, __expected, __no);
        }
        case 2: {
            string palette[] = {
                "...",
                "...",
                "..."
            };
            int n = 1;
            int m = 1;
            int __expected = 1953125;
            return do_test(to_vector(palette), n, m, __expected, __no);
        }
        case 3: {
            string palette[] = {
                "..58..",
                "..47.."
            };
            int n = 2;
            int m = 3;
            int __expected = 0;
            return do_test(to_vector(palette), n, m, __expected, __no);
        }
        case 4: {
            string palette[] = {
                "...1.2.3",
                "4.5.6...",
                "...7.8.9",
                "1.2.3..."
            };
            int n = 4;
            int m = 4;
            int __expected = 886073030;
            return do_test(to_vector(palette), n, m, __expected, __no);
        }
        case 5: {
            string palette[] = {
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "....................",
                "...................."
            };
            int n = 10;
            int m = 10;
            int __expected = 240076532;
            return do_test(to_vector(palette), n, m, __expected, __no);
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
    cout << "MagicalGirlLevelTwoDivOne (600 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1406645759;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
