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
#define sqr(x) ((x)*(x) % mod)
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
const int mod = 1e9 + 7;
const int maxn = 40000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

bool check[maxn+5];
int prm[maxn+5], mo[maxn+5];

class ReflectiveRectangle {
    public:
    vi fac;
    int64 tab;
    vector<pii > vec;
    int findSum(int A, int B, int k){
        if (k & 1) return 0;
        tab = (1LL * A * A + 1LL * B * B) % mod;
        k += 2;
        divide (k);

        vec.clear(); 
        dfs (1, -1, 1);

        //repf (i, 0, sz(vec)-1) tst (vec[i].x), out (vec[i].y);
//
        //int64 ans = (sqr (b) + sqr ((k-1) * a % mod)) % mod;
        //ans = (ans + sqr (a) + sqr ((k-1) * b % mod)) % mod;
        int ans = 0;
        repf (i, 0, sz(vec)-1){
            int64 tmp = calc (k / vec[i].x - 1) * sqr (1LL * vec[i].x) % mod;
            ans = (ans + vec[i].y * tmp) % mod;
            //if(ans < 0) tst (i), tst (tmp), tst (vec[i].x), out (vec[i].y);
        }
        return ans < 0 ? ans + mod : ans;
    }
    void divide (int x){
        fac.clear();
        for (int i = 2; i*i <= x; ++ i) if (x % i == 0){
            fac.pb (i);
            while (x % i == 0) x /= i;
        }
        if (x != 1) fac.pb (x);
    }
    void dfs (int x, int p, int t){
        vec.pb (mp (x, t));
        repf (i, p+1, sz(fac)-1) dfs (x*fac[i], i, -1*t);
    }
    int64 calc (int64 x){
        int t1, t2;
        if ((x % 3 == 0) || (x % 3 == 2)) t1 = 6, t2 = 1;
        else t1 = 2, t2 = 3;
        int64 ret = ((x * (x + 1) / t1) % mod) * ((2*x+1) / t2) % mod;
        return tab * ret % mod;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int sideA, int sideB, int bounces, int __expected, int caseNo) {

    time_t startClock = clock();
    ReflectiveRectangle *instance = new ReflectiveRectangle();
    int __result = instance->findSum(sideA, sideB, bounces);
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
            int sideA = 493285;
            int sideB = 816238;
            int bounces = 223092868;
            int __expected = 25;
            return do_test(sideA, sideB, bounces, __expected, __no);
        }
        case 1: {
            int sideA = 3;
            int sideB = 3;
            int bounces = 2;
            int __expected = 180;
            return do_test(sideA, sideB, bounces, __expected, __no);
        }
        case 2: {
            int sideA = 13;
            int sideB = 17;
            int bounces = 1;
            int __expected = 0;
            return do_test(sideA, sideB, bounces, __expected, __no);
        }
        case 3: {
            int sideA = 59325;
            int sideB = 31785;
            int bounces = 262142;
            int __expected = 48032850;
            return do_test(sideA, sideB, bounces, __expected, __no);
        }
        case 4: {
            int sideA = 1000000;
            int sideB = 1000000;
            int bounces = 1000000000;
            int __expected = 145972110;
            return do_test(sideA, sideB, bounces, __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "ReflectiveRectangle (900 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405084166;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
