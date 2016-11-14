//a better solution: https://community.topcoder.com/stat?c=problem_solution&rm=329040&rd=16767&pm=14365&cr=23028146
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

class BearPasswordLexic {
        public:
        vi X;
        int cnt[111], n;
        string ans, temp;
        int idx;
        string findPassword(vector<int> _X) {
                X = _X; n = SZ(X);
                ans = "";
                temp.resize(n);
                CLR(cnt);
                dfs(1, n);
                return ans;
        }
        void getNext(int&l, int&lcnt, int&r, int&rcnt) {
                while(l <= r && !lcnt) lcnt = cnt[++l];
                while(l <= r && !rcnt) rcnt = cnt[--r];
        }
        void add(int c, int fg) {
                while(c--) {
                        temp[idx++] = fg + 'a';
                }
        }
        void calc(int last) {
                int l = 1, lcnt = cnt[l], r = last, rcnt = cnt[r];
                int t = 0;
                idx = 0;
                while(l <= r) {
                        if(!lcnt || !rcnt) getNext(l, lcnt, r, rcnt);
                        if(l > r) break;
                        if(!t) {
                                add(r, t);
                                --rcnt;
                                if(l == r) --lcnt;
                        } else {
                                add(l, t);
                                --lcnt;
                                if(l == r) --rcnt;
                        }
                        t = 1-t;
                }
                if(idx == n) {
                        if(ans == "") ans = temp;
                        else if(temp < ans) ans = temp;
                }
        }
        bool ok(int last) {
                for(int i = 1, c; i <= n; ++i) {
                        c = X[i-1];
                        for(int j = i; j <= last; ++j) {
                                c -= cnt[j] * (j - i + 1);
                                if(c < 0) return 0;
                        }
                        if(c > 0) return 0;
                }
                return 1;
        }
        void dfs(int p, int l) {
                if(l == 0) {
                        if(ok(p - 1)) calc(p - 1);
                        return;
                }
                if(p > n || p > l) return;
                for(int i = 0; i * p <= l; ++i) { 
                        cnt[p] = i;
                        dfs(p + 1, l - i * p);
                }
                cnt[p] = 0;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    BearPasswordLexic *instance = new BearPasswordLexic();
    string __result = instance->findPassword(x);
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
                5,
                0,
                0,
                0,
                0
            };
            string __expected = "ababa";
            return do_test(to_vector(x), __expected, __no);
        }
        case 1: {
            int x[] = {
                4,
                2,
                1,
                0
            };
            string __expected = "aaab";
            return do_test(to_vector(x), __expected, __no);
        }
        case 2: {
            int x[] = {
                3,
                1,
                1
            };
            string __expected = "";
            return do_test(to_vector(x), __expected, __no);
        }
        case 3: {
            int x[] = {
                4,
                3,
                2,
                1
            };
            string __expected = "aaaa";
            return do_test(to_vector(x), __expected, __no);
        }
        case 4: {
            int x[] = {
                0
            };
            string __expected = "";
            return do_test(to_vector(x), __expected, __no);
        }
        case 5: {
            int x[] = {
                4,
                0,
                3,
                2
            };
            string __expected = "";
            return do_test(to_vector(x), __expected, __no);
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
        cout << "BearPasswordLexic (300 Points)" << endl << endl;
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
        int T = time(NULL) - 1478187899;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
