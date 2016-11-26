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
//#define debug
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;

class XorOrderDiv1 {
        public:
        int get(int m, int n, int a0, int b);
};
namespace Trie {
        struct node {
                node *son[2];
                int sz;
                void clear(){
                        sz = 0; clr(son);
                }
                void dfs() {
                        rep(i, 0, 2) if(son[i] != 0){
                                son[i]->dfs();
                                sz += son[i]->sz;
                        }
                }
                node *go(int c);
        };
        node memo[35*300000], *rt, *bat;
        void newNode(node*&o) {
                bat->clear(); o = bat++;
        }
        node *node::go(int c) {
                if(son[c] == 0) newNode(son[c]);
                return son[c];
        }
        void clear() {
                bat = memo; bat->clear(); rt = bat++;
        }
        void insert(int *s, int n) {
                node *x = rt;
                rep(i, 0, n) x = x->go(s[i]);
                x->sz = 1;
        }
        vi find(int *s, int n) {
                vi res;
                node *x = rt, *y = x;
                rep(i, 0, n) {
                        y = x;
                        x = x->son[s[i]];
                        res.pb(y->sz - x->sz);
                }
                return res;
        }
}

int m;
int dig[33], an[int(3e5)];
void transform(int a) {
        rep(i, 0, m) {
                dig[i] = a & 1;
                a >>= 1;
        }
        reverse(dig, dig + m);
}
int XorOrderDiv1::get(int m, int n, int a0, int b) {
        ::m = m;
        ll mod = 1<<m;
        Trie::clear();
        rep(i, 0, n) {
                an[i] = (a0 + 1ll * i * b) % mod;
                transform(an[i]);
                Trie::insert(dig, m);
        }
        Trie::rt->dfs();
        mod = 7 + int(1e9);
        ll ans = 0;
        rep(i, 0, n) {
                transform(an[i]);
                vi cnt = Trie::find(dig, m);

                ll total = 0, sum = 0, sz = 1;
                for(int x : cnt) {
                        total = (total * 2 + (2ll * x * sum % mod) + ((1ll * x * x % mod) * sz) % mod) % mod;
                        sum = (sum * 2 + (x * sz % mod)) % mod;
                        sz = (sz << 1) % mod;
                }
                ans ^= total;
        }
        return ans;
}

// CUT begin
template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int m, int n, int a0, int b, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    XorOrderDiv1 *instance = new XorOrderDiv1();
    int __result = instance->get(m, n, a0, b);
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
            int m = 2;
            int n = 3;
            int a0 = 0;
            int b = 1;
            int __expected = 8;
            return do_test(m, n, a0, b, __expected, __no);
        }
        case 1: {
            int m = 3;
            int n = 5;
            int a0 = 1;
            int b = 3;
            int __expected = 48;
            return do_test(m, n, a0, b, __expected, __no);
        }
        case 2: {
            int m = 16;
            int n = 100;
            int a0 = 41;
            int b = 5;
            int __expected = 523436032;
            return do_test(m, n, a0, b, __expected, __no);
        }
        case 3: {
            int m = 30;
            int n = 200000;
            int a0 = 399;
            int b = 18082016;
            int __expected = 408585698;
            return do_test(m, n, a0, b, __expected, __no);
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
        cout << "XorOrderDiv1 (500 Points)" << endl << endl;
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
        int T = time(NULL) - 1480083640;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
