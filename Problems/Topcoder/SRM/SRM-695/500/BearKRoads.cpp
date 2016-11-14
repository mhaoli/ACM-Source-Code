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

vi x;
viii e;
int ret;
int cnt[1111];

class BearKRoads {
        public:
        void dfs(int p, int K, int s) {
                if(p == 31 || p == SZ(e)) {
                        chmax(ret, s);
                } else {
                        dfs(p + 1, K, s);
                        if(K) {
                                int ts = s;
                                if(++cnt[e[p].y.x] == 1) ts += x[e[p].y.x];
                                if(++cnt[e[p].y.y] == 1) ts += x[e[p].y.y];
                                dfs(p + 1, K - 1, ts);
                                --cnt[e[p].y.y]; --cnt[e[p].y.x];
                        }
                }
        }
        int maxHappy(vector<int> x, vector<int> a, vector<int> b, int K) {
                ::x = x;
                e.clear();
                for(int i = 0; i < SZ(a); ++i) {
                        e.pb(mp(x[a[i]] + x[b[i]], mp(a[i], b[i])));
                }
                sort(ALL(e)); reverse(ALL(e));
                ret = 0; CLR(cnt);
                dfs(0, K, 0);
                return ret;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, vector<int> a, vector<int> b, int K, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    BearKRoads *instance = new BearKRoads();
    int __result = instance->maxHappy(x, a, b, K);
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
                10,
                50,
                50,
                10
            };
            int a[] = {
                0,
                1,
                2
            };
            int b[] = {
                1,
                2,
                3
            };
            int K = 1;
            int __expected = 100;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 1: {
            int x[] = {
                10,
                50,
                50,
                10
            };
            int a[] = {
                0,
                1,
                2
            };
            int b[] = {
                1,
                2,
                3
            };
            int K = 2;
            int __expected = 120;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 2: {
            int x[] = {
                42,
                100,
                500
            };
            int a[] = {
                0,
                1
            };
            int b[] = {
                1,
                2
            };
            int K = 2;
            int __expected = 642;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 3: {
            int x[] = {
                42,
                100,
                500,
                999,
                999,
                999,
                999
            };
            int a[] = {
                0,
                1
            };
            int b[] = {
                1,
                2
            };
            int K = 2;
            int __expected = 642;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 4: {
            int x[] = {
                969,
                467,
                808,
                263,
                179,
                428,
                595,
                557,
                406,
                80
            };
            int a[] = {
                5,
                4,
                9,
                7,
                9,
                3
            };
            int b[] = {
                4,
                0,
                8,
                8,
                0,
                1
            };
            int K = 3;
            int __expected = 2841;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 5: {
            int x[] = {
                1,
                2,
                3,
                4
            };
            int a[] = {
                0,
                0,
                0
            };
            int b[] = {
                1,
                2,
                3
            };
            int K = 2;
            int __expected = 8;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 6: {
            int x[] = {
                1,
                2,
                3,
                4,
                2
            };
            int a[] = {
                0,
                0,
                0,
                1
            };
            int b[] = {
                1,
                2,
                3,
                4
            };
            int K = 2;
            int __expected = 9;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }
        case 7: {
            int x[] = {
                8,
                18,
                14,
                10,
                7,
                16,
                4,
                19,
                6,
                12,
                17,
                10,
                12,
                3,
                15,
                8,
                15,
                12
            };
            int a[] = {
                0,
                15,
                1,
                5,
                7,
                3,
                17,
                4,
                15,
                3,
                13,
                14,
                4,
                7
            };
            int b[] = {
                8,
                10,
                16,
                13,
                2,
                10,
                2,
                10,
                11,
                13,
                0,
                9,
                3,
                6
            };
            int K = 7;
            int __expected = 173;
            return do_test(to_vector(x), to_vector(a), to_vector(b), K, __expected, __no);
        }

        // Your custom testcase goes here
        case 8:
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
        for (int i = 0; i < 8; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "BearKRoads (500 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 8; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1478830087;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
