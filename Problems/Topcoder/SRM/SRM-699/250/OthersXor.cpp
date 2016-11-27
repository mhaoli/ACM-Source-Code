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

class OthersXor {
        public:
        long long minSum(vector<int> x);
};

int dig[2];
int calc(int n, int m) {
        if(n - m > 0) {
                return min((dig[0]&1) ? dig[0] : dig[0] + 1, (dig[1]&1) ? 1+dig[1] : dig[1]);
        } else {
                int cnt = -1;
                if(dig[0]&1) {
                        cnt = dig[0];
                }
                if((dig[1]&1) == 0) {
                        if(cnt == -1) cnt = dig[1];
                        else chmin(cnt, dig[1]);
                }
                return cnt;
        }
}
long long OthersXor::minSum(vector<int> x) {
        vi an;
        int n = SZ(x);
        rep(i, 0, n) if(~x[i]) an.pb(x[i]);
        if(!SZ(an)) return 0;
        ll sum = 0, t = 1;
        bool flag = 1;
        while(flag) {
                flag = 0;
                clr(dig);
                rep(i, 0, SZ(an)) {
                        if(an[i]) flag = 1;
                        dig[an[i]&1]++;
                        an[i] >>= 1;
                }
                int cnt = calc(n, SZ(an));
                if(cnt == -1) return -1;
                sum += cnt * t;
                t <<= 1;
        }
        return sum;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, long long __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    OthersXor *instance = new OthersXor();
    long long __result = instance->minSum(x);
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
                1,
                -1,
                3
            };
            long long __expected = 3LL;
            return do_test(to_vector(x), __expected, __no);
        }
        case 1: {
            int x[] = {
                0,
                0,
                1
            };
            long long __expected = -1LL;
            return do_test(to_vector(x), __expected, __no);
        }
        case 2: {
            int x[] = {
                70,
                100
            };
            long long __expected = 170LL;
            return do_test(to_vector(x), __expected, __no);
        }
        case 3: {
            int x[] = {
                -1,
                0,
                -1,
                100,
                36
            };
            long long __expected = 164LL;
            return do_test(to_vector(x), __expected, __no);
        }
        case 4: {
            int x[] = {
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                0,
                536870912,
                1073741823,
                1073741823,
                1073741823,
                123456789,
                987654321,
                804289383
            };
            long long __expected = 11992352010LL;
            return do_test(to_vector(x), __expected, __no);
        }
        case 5: {
            int x[] = {
                1287325,
                424244444,
                92759185,
                812358213,
                1000000000,
                825833522,
                749092703
            };
            long long __expected = -1LL;
            return do_test(to_vector(x), __expected, __no);
        }
        case 6: {
            int x[] = {
                -1,
                -1
            };
            long long __expected = 0LL;
            return do_test(to_vector(x), __expected, __no);
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
        cout << "OthersXor (250 Points)" << endl << endl;
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
        int T = time(NULL) - 1480256364;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
