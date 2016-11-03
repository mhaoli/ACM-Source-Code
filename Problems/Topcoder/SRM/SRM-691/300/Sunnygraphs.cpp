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

int G[55][55], vis[55];
vector<int> an;
ll two[111];

class Sunnygraphs {
        public:
        void getG(vector<int> an) {
                memset(G, 0, sizeof G);
                for(int i = 0; i < SZ(an); ++i) {
                        G[i][an[i]] = G[an[i]][i] = 1;
                }
        }
        void dfs(int x, int n) {
                vis[x] = 1;
                for(int i = 0; i < n; ++i) {
                        if(!G[x][i] || vis[i]) continue;
                        dfs(i, n);
                }
        }
        bool find(int x, int y) {
                int n = SZ(an);
                vector<int> bn = an;
                bn[y] = n;
                getG(bn);
                memset(vis, 0, sizeof vis);
                dfs(x, n+1);
                return vis[n];

        }
        ll count(vector<int> &bn, vector<int>&cn, int n) {
                int cnt = 0;
                for(int i : bn) {
                        for(int j : cn) if(i == j) ++cnt;
                }
                int t1 = SZ(bn) - cnt, t2 = SZ(cn) - cnt;
                int flag = cnt > 0;
                //OUT(t1); OUT(t2); OUT(cnt); OUT(n);
                return ((two[cnt]-1) * two[t1] * two[t2] + (two[t1]-1) * (two[t2]-1) + flag) * two[n - t1 - t2 - cnt];
        }
        long long count(vector<int> _an) {
                two[0] = 1;
                for(int i = 1; i <= 50; ++i) two[i] = two[i-1] << 1;

                an = _an;
                int n = SZ(an);
                vector<int> vec[2];
                for(int i = 0; i < 2; ++i) {
                        for(int j = 0; j < n; ++j) {
                                if(find(i, j)) vec[i].pb(j);
                        }
                }
                //for(int i : vec[0]) OUT(i);
                //puts("-----------");
                //for(int i : vec[1]) OUT(i);
                return count(vec[0], vec[1], n);
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> a, long long __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Sunnygraphs *instance = new Sunnygraphs();
    long long __result = instance->count(a);
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
                0
            };
            long long __expected = 4LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 1: {
            int a[] = {
                2,
                2,
                0
            };
            long long __expected = 7LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 2: {
            int a[] = {
                2,
                3,
                0,
                1
            };
            long long __expected = 9LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 3: {
            int a[] = {
                2,
                2,
                3,
                4,
                3
            };
            long long __expected = 30LL;
            return do_test(to_vector(a), __expected, __no);
        }
        case 4: {
            int a[] = {
                18,
                18,
                20,
                28,
                7,
                27,
                8,
                13,
                40,
                3,
                7,
                21,
                30,
                17,
                13,
                34,
                29,
                16,
                15,
                11,
                0,
                9,
                39,
                36,
                38,
                23,
                24,
                8,
                4,
                9,
                29,
                22,
                35,
                5,
                13,
                23,
                3,
                27,
                34,
                23,
                8
            };
            long long __expected = 2198754820096LL;
            return do_test(to_vector(a), __expected, __no);
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
        cout << "Sunnygraphs (300 Points)" << endl << endl;
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
        int T = time(NULL) - 1477794376;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
