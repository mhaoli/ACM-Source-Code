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
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
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

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class PolynomialGCD {
        public:
                int gcd(string s);
};

const int Max_N = 1e4 + 9;
const long long mod = 1e9 + 7;

bool prm[Max_N];

int calc(vector<int> &A, int p) {
        int n = SZ(A), ret = ~0u>>1, tmp;
        if(p > n) return 0;
        for(int i = 0; i < p; ++i) {
                tmp = 0;
                vector<int> B;
                for(int j = i; j < n; j += p) {
                        tmp += A[j];
                        B.push_back(A[j]);
                }
                tmp += calc(B, p);
                chmin(ret, tmp);
        }
        return ret;
}

int PolynomialGCD::gcd(string s){
        //string yes = "Possible", no = "Impossible";
        int n = SZ(s), ans = 1;
        vector<int> A(n);
        for(int i = 0; i < n; ++i) A[i] = s[i] - '0';
        for(int i = 2; i <= n; ++i) {
                if(prm[i]) continue;
                for(int j = i*i; j <= n; j += i) prm[j] = 1;
                ans = ans * pow_mod(i, calc(A, i), mod) % mod;
        }
        return ans;
}

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string s, int __expected, int caseNo) {

    time_t startClock = clock();
    PolynomialGCD *instance = new PolynomialGCD();
    int __result = instance->gcd(s);
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
            string s = "111";
            int __expected = 6;
            return do_test(s, __expected, __no);
        }
        case 1: {
            string s = "00000";
            int __expected = 1;
            return do_test(s, __expected, __no);
        }
        case 2: {
            string s = "2014";
            int __expected = 16;
            return do_test(s, __expected, __no);
        }
        case 3: {
            string s = "31415926535";
            int __expected = 659897170;
            return do_test(s, __expected, __no);
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
    cout << "PolynomialGCD (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430401117;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
