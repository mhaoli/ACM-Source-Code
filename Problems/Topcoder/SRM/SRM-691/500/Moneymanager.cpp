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
#include <numeric>
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

int dp[55][555];
class Moneymanager {
        public:
        int n, X;
        int getbest(vector<int> an, vector<int> bn, int _X) {
                n = SZ(an); X = _X;
                vector<pair<int, pair<int, int> > > vec(n);
                for(int i = 0; i < n; ++i) {
                        vec[i] = mp(an[i] * 2520 / bn[i], mp(an[i], bn[i]));
                }
                sort(ALL(vec));
                int Sum = std::accumulate(ALL(bn), 0), hf = n >> 1, ans = 0;
                for(int B = hf; B <= hf * 10; ++B) {
                        memset(dp, -1, sizeof dp);
                        dp[0][0] = 0;
                        for(int j = 0, s = 0; j < n; ++j) {
                                s += vec[j].y.y;
                                for(int i = min(j, hf); i >= 0; --i) {
                                        for(int b = i * 10; b >= i; --b) if(dp[i][b] >= 0) {
                                                if(i < hf && b + vec[j].y.y <= B) chmax(dp[i+1][b+vec[j].y.y], dp[i][b] + vec[j].y.x * (Sum - B + b + vec[j].y.y));
                                                if(j - i < hf) chmax(dp[i][b], dp[i][b] + vec[j].y.x * (s - b));
                                        }
                                }
                        }
                        if(~dp[hf][B]) chmax(ans, dp[hf][B] + X * (Sum - B));
                }
                return ans;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> a, vector<int> b, int X, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Moneymanager *instance = new Moneymanager();
    int __result = instance->getbest(a, b, X);
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
            int a[] = {
                1,
                1
            };
            int b[] = {
                2,
                1
            };
            int X = 0;
            int __expected = 5;
            return do_test(to_vector(a), to_vector(b), X, __expected, __no);
        }
        case 1: {
            int a[] = {
                1,
                1
            };
            int b[] = {
                1,
                5
            };
            int X = 10;
            int __expected = 61;
            return do_test(to_vector(a), to_vector(b), X, __expected, __no);
        }
        case 2: {
            int a[] = {
                4,
                4,
                6,
                6
            };
            int b[] = {
                2,
                2,
                3,
                3
            };
            int X = 100;
            int __expected = 726;
            return do_test(to_vector(a), to_vector(b), X, __expected, __no);
        }
        case 3: {
            int a[] = {
                30,
                13,
                28,
                59,
                26,
                62,
                48,
                75,
                6,
                69,
                94,
                51
            };
            int b[] = {
                4,
                6,
                4,
                5,
                4,
                3,
                1,
                5,
                6,
                5,
                2,
                2
            };
            int X = 62;
            int __expected = 22096;
            return do_test(to_vector(a), to_vector(b), X, __expected, __no);
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
        for (int i = 0; i < 4; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "Moneymanager (500 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 4; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1478180828;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
