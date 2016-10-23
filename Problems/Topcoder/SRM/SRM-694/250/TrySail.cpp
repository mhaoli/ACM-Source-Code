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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;

int dp[55][256][256][2];
class TrySail {
        public:
        int get(vector<int> an) {
                int n = SZ(an);
                memset(dp, 0, sizeof dp);
                dp[0][an[0]][0][0] = 1;
                dp[0][0][an[0]][0] = 1;
                dp[0][0][0][0] = 1;
                for(int i = 1; i < n; ++i) {
                        for(int j = 0; j < 256; ++j) {
                                for(int k = 0; k < 256; ++k) {
                                        if(dp[i-1][j][k][0]) {
                                                dp[i][j][k][1] = 1;
                                                dp[i][j^an[i]][k][0] = 1;
                                                dp[i][j][k^an[i]][0] = 1;
                                        }
                                        if(dp[i-1][j][k][1]) {
                                                dp[i][j][k][1] = 1;
                                                dp[i][j^an[i]][k][1] = 1;
                                                dp[i][j][k^an[i]][1] = 1;
                                        }
                                }
                        }
                }
                int s = 0, ans = 0;
                for(int i : an) s ^= i;
                for(int i = 0; i < 256; ++i) {
                        for(int j = 0; j < 256; ++j) if(dp[n-1][i][j][1]){
                                chmax(ans, i + j + ((s ^ i) ^ j));
                        }
                }
                return ans;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> strength, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    TrySail *instance = new TrySail();
    int __result = instance->get(strength);
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
            int strength[] = {
                2,
                3,
                3
            };
            int __expected = 8;
            return do_test(to_vector(strength), __expected, __no);
        }
        case 1: {
            int strength[] = {
                7,
                3,
                5,
                2
            };
            int __expected = 17;
            return do_test(to_vector(strength), __expected, __no);
        }
        case 2: {
            int strength[] = {
                13,
                13,
                13,
                13,
                13,
                13,
                13,
                13
            };
            int __expected = 26;
            return do_test(to_vector(strength), __expected, __no);
        }
        case 3: {
            int strength[] = {
                114,
                51,
                4,
                191,
                9,
                81,
                0,
                89,
                3
            };
            int __expected = 470;
            return do_test(to_vector(strength), __expected, __no);
        }
        case 4: {
            int strength[] = {
                108,
                66,
                45,
                82,
                163,
                30,
                83,
                244,
                200,
                216,
                241,
                249,
                89,
                128,
                36,
                28,
                250,
                190,
                70,
                95,
                117,
                196,
                19,
                160,
                255,
                129,
                10,
                109,
                189,
                24,
                22,
                25,
                134,
                144,
                110,
                15,
                235,
                205,
                186,
                103,
                116,
                191,
                119,
                183,
                45,
                217,
                156,
                44,
                97,
                197
            };
            int __expected = 567;
            return do_test(to_vector(strength), __expected, __no);
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
        cout << "TrySail (250 Points)" << endl << endl;
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
        int T = time(NULL) - 1477153921;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
