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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) cout<<#x<<":"<<(x)<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class DevuAndBeautifulSubstrings {
        public:
                long long countBeautifulSubstrings(int n, int cnt);
};

long long dp[2][1305][55][3];

long long DevuAndBeautifulSubstrings::countBeautifulSubstrings(int n, int cnt){
        //string yes = "Possible", no = "Impossible";
        memset(dp, 0, sizeof dp);
        dp[0][1][1][0] = dp[0][1][1][1] = 1;
        int now = 0, nxt = 1;
        for(int i = 0, j, k, t; i < n-1; ++i) {
                for(j = 0; j <= cnt; ++j) {
                        for(k = 0; k <= i+3; ++k) {
                                for(t = 0; t < 2; ++t) {
                                        dp[nxt][j][k][t] = 0;
                                }
                        }
                }

                for(j = 0; j <= cnt; ++j) {
                        for(k = 0; k <= i + 2; ++k) {
                                for(t = 0; t < 2; ++t) if(dp[now][j][k][t]) {
                                        dp[nxt][j+1][1][t] += dp[now][j][k][t];
                                        dp[nxt][j+k+1][k+1][t^1] += dp[now][j][k][t];
                                }
                        }
                }
                swap(nxt, now);
        }
        long long ans = 0;
        for(int i = 0; i <= n + 2; ++i) {
                for(int j = 0; j < 2; ++j) {
                        ans += dp[now][cnt][i][j];
                }
        }
        return ans;
}

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int cnt, long long __expected, int caseNo) {

    time_t startClock = clock();
    DevuAndBeautifulSubstrings *instance = new DevuAndBeautifulSubstrings();
    long long __result = instance->countBeautifulSubstrings(n, cnt);
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
            int n = 2;
            int cnt = 2;
            long long __expected = 2LL;
            return do_test(n, cnt, __expected, __no);
        }
        case 1: {
            int n = 2;
            int cnt = 1;
            long long __expected = 0LL;
            return do_test(n, cnt, __expected, __no);
        }
        case 2: {
            int n = 3;
            int cnt = 4;
            long long __expected = 4LL;
            return do_test(n, cnt, __expected, __no);
        }
        case 3: {
            int n = 15;
            int cnt = 35;
            long long __expected = 642LL;
            return do_test(n, cnt, __expected, __no);
        }
        case 4: {
            int n = 40;
            int cnt = 820;
            long long __expected = 2LL;
            return do_test(n, cnt, __expected, __no);
        }
        case 5: {
            int n = 50;
            int cnt = 94;
            long long __expected = 32357325751902LL;
            return do_test(n, cnt, __expected, __no);
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
    cout << "DevuAndBeautifulSubstrings (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1431188538;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
