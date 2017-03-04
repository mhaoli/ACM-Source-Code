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
#define debug
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;

class Xscoregame {
        public:
        int getscore(vector<int> A);
};

int dp[1<<16][1<<6];

int Xscoregame::getscore(vector<int> A) {
        mem(dp, 0);
        int n = SZ(A), t;
        rep(i,0,1<<n) rep(j,0,1<<6) {
                rep(k,0,n) if(!(i & (1<<k))) {
                        t = dp[i][j] + (dp[i][j] ^ A[k]);
                        chmax(dp[i ^ (1<<k)][t % (1<<6)], t);
                }
        }
        return *max_element(dp[(1<<n)-1], dp[(1<<n)-1] + (1<<6));
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> A, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Xscoregame *instance = new Xscoregame();
    int __result = instance->getscore(A);
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
            int A[] = {
                1,
                2,
                3
            };
            int __expected = 12;
            return do_test(to_vector(A), __expected, __no);
        }
        case 1: {
            int A[] = {
                10,
                0,
                0,
                0
            };
            int __expected = 80;
            return do_test(to_vector(A), __expected, __no);
        }
        case 2: {
            int A[] = {
                1,
                1,
                1,
                1,
                1,
                1
            };
            int __expected = 1;
            return do_test(to_vector(A), __expected, __no);
        }
        case 3: {
            int A[] = {
                1,
                0,
                1,
                0,
                1,
                0,
                1,
                0
            };
            int __expected = 170;
            return do_test(to_vector(A), __expected, __no);
        }
        case 4: {
            int A[] = {
                50,
                0,
                1,
                0,
                1,
                0,
                1,
                0,
                1,
                0,
                1,
                0,
                1,
                0,
                1
            };
            int __expected = 830122;
            return do_test(to_vector(A), __expected, __no);
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
        for (int i = 0; i < 5; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "Xscoregame (250 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 5; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1488605842;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
