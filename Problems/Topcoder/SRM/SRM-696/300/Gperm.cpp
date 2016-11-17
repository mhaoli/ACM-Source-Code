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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define MEM(f,x) memset((f), (x), sizeof(f))
#define CLR(f) MEM(f,0)
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;

int cnt[55];

class Gperm {
        public:
        int countfee(vector<int> x, vector<int> y) {
                int n = SZ(x), res = 1e9;
                for(int i = 0; i < (1 << n); ++i) {
                        CLR(cnt);
                        for(int j = 0; j < n; ++j) {
                                if(i & (1 << j)) ++cnt[x[j]];
                                else ++cnt[y[j]];
                        }
                        sort(cnt, cnt + 50, greater<int>());
                        int tmp = 0;
                        for(int i = 0; i < 50; ++i) {
                                tmp += cnt[i] * (i + 1);
                        }
                        chmin(res, tmp);
                }
                return res;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, vector<int> y, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Gperm *instance = new Gperm();
    int __result = instance->countfee(x, y);
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
            int x[] = {
                0
            };
            int y[] = {
                1
            };
            int __expected = 1;
            return do_test(to_vector(x), to_vector(y), __expected, __no);
        }
        case 1: {
            int x[] = {
                0,
                1
            };
            int y[] = {
                1,
                2
            };
            int __expected = 2;
            return do_test(to_vector(x), to_vector(y), __expected, __no);
        }
        case 2: {
            int x[] = {
                4,
                7,
                7
            };
            int y[] = {
                7,
                4,
                4
            };
            int __expected = 3;
            return do_test(to_vector(x), to_vector(y), __expected, __no);
        }
        case 3: {
            int x[] = {
                0,
                0,
                1
            };
            int y[] = {
                1,
                2,
                2
            };
            int __expected = 4;
            return do_test(to_vector(x), to_vector(y), __expected, __no);
        }
        case 4: {
            int x[] = {
                7,
                8,
                9
            };
            int y[] = {
                4,
                5,
                6
            };
            int __expected = 6;
            return do_test(to_vector(x), to_vector(y), __expected, __no);
        }
        case 5: {
            int x[] = {
                45,
                28,
                42,
                5,
                27,
                27,
                42,
                36,
                14,
                27,
                19,
                42,
                24,
                27,
                8,
                31,
                24,
                27,
                14,
                28
            };
            int y[] = {
                45,
                27,
                45,
                8,
                34,
                34,
                28,
                0,
                11,
                42,
                24,
                19,
                14,
                31,
                45,
                42,
                14,
                24,
                28,
                27
            };
            int __expected = 53;
            return do_test(to_vector(x), to_vector(y), __expected, __no);
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
        for (int i = 0; i < 6; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "Gperm (300 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 6; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1479130573;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
