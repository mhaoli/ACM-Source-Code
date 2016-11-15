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
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define SZ(v) ((int)(v).size())
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
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

class RepeatedStrings {
        public:
        string findKth(string s, int k);
};

vector<string> sv[160], ans;

int contain(string s, string t) {
        int idx = 0;
        for(char c : t) {
                while(idx < SZ(s) && s[idx] != c) ++idx;
                if(idx >= SZ(s)) return 0;
                ++idx;
        }
        return 1;
}

string RepeatedStrings::findKth(string S, int K) {
        string t = "()";
        ans.clear();
        rep(i, 0, 155) sv[i].clear();
        if(contain(S, t)) sv[2].pb(t), ans.pb(t);
        for(int i = 4; i <= SZ(S); i += 2) {
                for(int j = 2; j <= i-2; j += 2) if((i-2) % j == 0){
                        int cnt = (i - 2) / j;
                        for(string s : sv[j]) {
                                string res = "(";
                                rep(k, 0, cnt) res = res + s;
                                res.pb(')');
                                if(contain(S, res)) {
                                        sv[i].pb(res);
                                        ans.pb(res);
                                }
                        }
                }
        }
        sort(all(ans));
        if(K > SZ(ans)) return "";
        else return ans[K-1];
}

// CUT begin
template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string s, int k, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    RepeatedStrings *instance = new RepeatedStrings();
    string __result = instance->findKth(s, k);
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
            string s = "()))((()())";
            int k = 3;
            string __expected = "(())";
            return do_test(s, k, __expected, __no);
        }
        case 1: {
            string s = "))))))))))))((((((((((";
            int k = 1;
            string __expected = "";
            return do_test(s, k, __expected, __no);
        }
        case 2: {
            string s = "(())(()(()))";
            int k = 1;
            string __expected = "(((())))";
            return do_test(s, k, __expected, __no);
        }
        case 3: {
            string s = "(())))()((())())";
            int k = 8;
            string __expected = "()";
            return do_test(s, k, __expected, __no);
        }
        case 4: {
            string s = "(()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()())";
            int k = 64;
            string __expected = "(((((((((((((()()()())(()()()())))))))))))))";
            return do_test(s, k, __expected, __no);
        }
        case 5: {
            string s = "(";
            int k = 1000000000;
            string __expected = "";
            return do_test(s, k, __expected, __no);
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
        cout << "RepeatedStrings (500 Points)" << endl << endl;
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
        int T = time(NULL) - 1479188633;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
