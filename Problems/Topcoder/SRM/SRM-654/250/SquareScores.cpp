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
#define SQR(x) ((x)*(x))
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define OUT(x) cout<<#x<<":"<<(x)<<endl
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class SquareScores {
        public:
                double calcexpectation(vector<int> p, string s);
};

const int Max_N = 2222;
vector<int> p;
string s;

double quick(double p, int n) {
        double ret = 1;
        for(; n; n >>= 1) {
                if(n & 1) ret = ret * p;
                p *= p;
        }
        return ret;
}

double calc(int t1, int t2, int t, int cnt) {
        double ret = 0, tmp;
        if(~t) { 
                ret += (tmp = quick(p[t] / 100.0, cnt));
                //if(t1 == 0 && t2 == 2) out(tmp);
        } else {
                snuke(it, p) ret += quick((*it) / 100.0, cnt);
        }
        return ret;
}

double SquareScores::calcexpectation(vector<int> P, string S){
        s = S; p = P;
        while(SZ(p) < 26) p.push_back(0);
        //string yes = "Possible", no = "Impossible";
        int n = SZ(s);
        double ans = 0;
        for(int i = 0; i < n; ++i) {
                int t = s[i] == '?' ? -1 : s[i] - 'a', cnt = 0;
                for(int j = i; j < n; ++j) {
                        int tmp = s[j] == '?' ? -1 : s[j] - 'a';
                        if(t != tmp) {
                                if(~t && ~tmp) break;
                                else if(t == -1) t = tmp;
                        }
                        if(tmp == -1) ++cnt;
                        ans += calc(i, j, t, cnt);
                        //if(i == 2) out(j), out(ans);
                }
        }
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<int> p, string s, double __expected, int caseNo) {

    time_t startClock = clock();
    SquareScores *instance = new SquareScores();
    double __result = instance->calcexpectation(p, s);
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
            int p[] = {
                1, 99
            };
            string s = "aaaba";
            double __expected = 8.0;
            return do_test(to_vector(p), s, __expected, __no);
        }
        case 1: {
            int p[] = {
                10, 20, 70
            };
            string s = "aa?bbbb";
            double __expected = 15.0;
            return do_test(to_vector(p), s, __expected, __no);
        }
        case 2: {
            int p[] = {
                10, 20, 30, 40
            };
            string s = "a??c?dc?b";
            double __expected = 11.117;
            return do_test(to_vector(p), s, __expected, __no);
        }
        case 3: {
            int p[] = {
                25, 25, 21, 2, 2, 25
            };
            string s = "a??b???????ff??e";
            double __expected = 21.68512690712425;
            return do_test(to_vector(p), s, __expected, __no);
        }
        case 4: {
            int p[] = {
                4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4
            };
            string s = "??????????????????????????????";
            double __expected = 31.16931963781721;
            return do_test(to_vector(p), s, __expected, __no);
        }
        case 5: {
            int p[] = {
                4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3
            };
            string s = "makigotapresentfromniko";
            double __expected = 23.0;
            return do_test(to_vector(p), s, __expected, __no);
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
    cout << "SquareScores (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430406333;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
