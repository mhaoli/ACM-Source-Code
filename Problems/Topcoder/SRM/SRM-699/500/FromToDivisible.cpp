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

class FromToDivisible {
        public:
        int shortest(int N, int S, int T, vector<int> a, vector<int> b);
};

namespace Dijskra {
        const int maxn = 1e3;
        int dis[maxn + 5];
        int n;
        vector<vii > G;
        //G[x] = (y,t): x -> y, value = t
        void init(int _n, vector<vii > _G) {
                n = _n; G = _G;
        }
        vi getMin(int S) {
                //vi res(n);
                //map<int, int> res;
                //priority_queue<pii > q;
                memset(dis, -1, n * (sizeof(dis[0])));
                dis[S] = 0;
                set<pii > q;
                q.insert(mp(0, S));
                while(SZ(q)) {
                        pii x = *q.begin(); q.erase(q.begin());
                        for(pii t : G[x.y]) {
                                if(dis[t.x] == -1 || dis[t.x] > x.x + t.y) {
                                        q.erase(mp(dis[t.x], t.x));
                                        dis[t.x] = x.x + t.y;
                                        q.insert(mp(dis[t.x], t.x));
                                }
                        }
                }
                return vi(dis, dis + n);

        }
}


int FromToDivisible::shortest(int N, int S, int T, vector<int> a, vector<int> b) {
        int n = SZ(a);
        vector<vii > G(n + 1, vii());
        rep(i, 0, n) if(S % a[i] == 0) G[n].pb(mp(i, 1));
        rep(i, 0, n) rep(j, 0, n) if(i != j && (1ll * b[i] * a[j] / __gcd(b[i], a[j]) <= N)) G[i].pb(mp(j, 1));
        Dijskra::init(n + 1, G);
        vi dis = Dijskra::getMin(n);
        int res = 1<<30;
        rep(i, 0, n) if(T % b[i] == 0) chmin(res, dis[i]);
        if(res == (1<<30)) return -1;
        return res;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int S, int T, vector<int> a, vector<int> b, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FromToDivisible *instance = new FromToDivisible();
    int __result = instance->shortest(N, S, T, a, b);
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
            int N = 11;
            int S = 9;
            int T = 6;
            int a[] = {
                3,
                10
            };
            int b[] = {
                5,
                2
            };
            int __expected = 2;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
        }
        case 1: {
            int N = 123456789;
            int S = 18;
            int T = 12;
            int a[] = {
                1,
                42,
                50
            };
            int b[] = {
                1,
                17,
                3
            };
            int __expected = 1;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
        }
        case 2: {
            int N = 60;
            int S = 30;
            int T = 8;
            int a[] = {
                16,
                15,
                12
            };
            int b[] = {
                2,
                20,
                5
            };
            int __expected = -1;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
        }
        case 3: {
            int N = 77;
            int S = 10;
            int T = 62;
            int a[] = {
                2,
                5,
                7,
                4,
                17,
                26
            };
            int b[] = {
                25,
                7,
                11,
                13,
                31,
                34
            };
            int __expected = 4;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
        }
        case 4: {
            int N = 100;
            int S = 90;
            int T = 40;
            int a[] = {
                20,
                30,
                100,
                99,
                100
            };
            int b[] = {
                10,
                30,
                100,
                100,
                99
            };
            int __expected = 2;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
        }
        case 5: {
            int N = 1000000000;
            int S = 7000;
            int T = 424212345;
            int a[] = {
                35000000,
                120000000,
                424212345,
                200000000,
                3500,
                19
            };
            int b[] = {
                15,
                1,
                7000,
                200000000,
                400000000,
                17
            };
            int __expected = 3;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
        }
        case 6: {
            int N = 2;
            int S = 1;
            int T = 2;
            int a[] = {
                2
            };
            int b[] = {
                1
            };
            int __expected = -1;
            return do_test(N, S, T, to_vector(a), to_vector(b), __expected, __no);
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
        cout << "FromToDivisible (500 Points)" << endl << endl;
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
        int T = time(NULL) - 1480174091;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
