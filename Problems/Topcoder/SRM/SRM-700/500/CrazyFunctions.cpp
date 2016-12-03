#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define SZ(v) ((int)(v).size())
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define x first
#define y second
#define mp make_pair
#define pb push_back
//#define debug
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;

class CrazyFunctions {
        public:
        int count(int n, int k);
};

const ll mod = 7 + int(1e9);

void add(int&a, int b) {
        a += b; if(a >= mod) a -= mod;
}

int C[5005][5005];
ll fac[5005];

ll gao1(int n) {
        vi d(n + 1);
        d[0] = d[1] = 1;
        rep(i, 2, n+1) {
                d[i] = 0;
                rep(j, 1, i+1) {
                        add(d[i], (1ll * C[i-1][j-1] * fac[j-1] % mod) * d[i-j] % mod);
                }
        }
        return (ll)d[n];
}

ll gao2(int n, int K) {
        vi d(n + 1), f(n + 1), g(n + 1);
        d[1] = 1; f[0] = f[1] = 1;
        g[0] = 1; g[1] = K;
        rep(i, 2, n+1) {
                g[i] = f[i] = d[i] = 0;
                rep(j, 1, i) add(d[i], (1ll * C[i-2][j-1] * d[j] % mod) * f[i-1-j] % mod);
                d[i] = 1ll * i * d[i] % mod;
                rep(j, 1, i+1) add(f[i], (1ll * C[i-1][j-1] * d[j] % mod) * f[i-j] % mod);
                rep(j, 1, i+1) add(g[i], ((1ll * C[i-1][j-1] * d[j] % mod) * K % mod) * g[i-j] % mod);
        }

        return (ll)g[n];
}

int CrazyFunctions::count(int n, int k) {
        C[0][0] = C[1][0] = C[1][1] = 1;
        rep(i, 2, 5003) {
                C[i][i] = C[i][0] = 1;
                rep(j, 1, i) C[i][j] = C[i-1][j], add(C[i][j], C[i-1][j-1]);
        }
        fac[0] = fac[1] = 1;
        rep(i, 2, 5003) fac[i] = fac[i-1] * i % mod;
#ifdef debug
        rep(i, 1, 5) {
                cout << i << " " ;
                OUT(gao1(i));
        }
#endif
#ifdef debug
        gao2(5, k);
        //return 1;
#endif
        return ((C[n][k] * gao1(k) % mod) * gao2(n - k, k)) % mod;
}

// CUT begin
template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int k, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    CrazyFunctions *instance = new CrazyFunctions();
    int __result = instance->count(n, k);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_str(__expected) << endl;
        cout << "           Received: " << to_str(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int n = 2;
            int k = 1;
            int __expected = 2;
            return do_test(n, k, __expected, __no);
        }
        case 1: {
            int n = 2;
            int k = 2;
            int __expected = 2;
            return do_test(n, k, __expected, __no);
        }
        case 2: {
            int n = 1;
            int k = 1;
            int __expected = 1;
            return do_test(n, k, __expected, __no);
        }
        case 3: {
            int n = 3;
            int k = 1;
            int __expected = 9;
            return do_test(n, k, __expected, __no);
        }
        case 4: {
            int n = 3;
            int k = 3;
            int __expected = 6;
            return do_test(n, k, __expected, __no);
        }
        case 5: {
            int n = 5;
            int k = 3;
            int __expected = 900;
            return do_test(n, k, __expected, __no);
        }
        case 6: {
            int n = 5000;
            int k = 5000;
            int __expected = 541108809;
            return do_test(n, k, __expected, __no);
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
    
    bool mainProcess = true;
    set<int> testCases;
    for (int i = 1; i < argc; i++) {
        if ( string(argv[i]) == "-" ) {
            mainProcess = false;
        } else {
            testCases.insert( atoi(argv[i]) );
        }
    }
    if (testCases.size() == 0) {
        for (int i = 0; i < 7; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "CrazyFunctions (500 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 7; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1480176790;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
