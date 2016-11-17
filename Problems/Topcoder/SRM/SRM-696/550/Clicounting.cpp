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

class Clicounting {
        public:
        int count(vector<string> g);
};

int clk[1<<20], Bmin[1<<20], ans[1<<20], connect[55];
vector<string> G;
const int HALF = 20;

int check(vi pos, int sta) {
        rep(i, 0, SZ(pos)) if(sta & (1<<i)) {
                rep(j, i+1, SZ(pos)) if(sta & (1<<j)) {
                        if(G[pos[i]][pos[j]] == '0') return 0;
                }
        }
        return 1;
}

int Clicounting::count(vector<string> G) {
        ::G = G;
        rep(i, 0, 1 << 20) Bmin[i] = __builtin_ctz(i);

        vii uncertain;
        set<int> st;
        rep(i, 0, SZ(G)) {
                rep(j, i+1, SZ(G[0])) {
                        if(G[i][j] == '?') uncertain.pb(mp(i, j)), st.insert(i), st.insert(j);
                }
        }

        vi pos1;
        rep(i, 0, SZ(G)) {
                if(st.find(i) == st.end()) {
                        if(SZ(st) < HALF) st.insert(i);
                        else pos1.pb(i);
                }
        }
        vi pos0(all(st));

        for(pii &t : uncertain) {
                bool fg0 = 1, fg1 = 1;
                rep(i, 0, SZ(pos0)) {
                        if(fg0 && t.x == pos0[i]) {
                                t.x = i; fg0 = 0;
                        } 
                        if(fg1 && t.y == pos0[i]) {
                                t.y = i; fg1 = 0;
                        }
                }
        }

        //deal pos1
        rep(i, 0, 1 << SZ(pos1)) {
                if(check(pos1, i)) clk[i] = __builtin_popcount(i);
                else {
                        clk[i] = 0;
                        rep(j, 0, SZ(pos1)) if(i & (1<<j)) {
                                chmax(clk[i], clk[i ^ (1<<j)]);
                        }
                }
        }

        clr(ans);

        //deal pos0
        rep(i, 0, SZ(pos0)) {
                connect[i] = 0;
                rep(j, 0, SZ(pos1)) {
                        if(G[pos0[i]][pos1[j]] == '1') connect[i] |= 1 << j;
                }
        }
        rep(s, 0, 1 << SZ(pos0)) {
                if(!check(pos0, s)) continue;

                int con = (1 << SZ(pos1)) - 1, sta = s;
                while(sta) {
                        con &= connect[Bmin[sta]];
                        sta ^= 1 << Bmin[sta];
                }

                int mx = __builtin_popcount(s) + clk[con], ts = 0;
                rep(i, 0, SZ(uncertain)) {
                        pii t = uncertain[i];
                        if((s & (1 << t.x)) && (s & (1 << t.y))) {
                                ts |= 1 << i;
                        }
                }
                chmax(ans[ts], mx);
        }
        int res = 0;
        rep(i, 0, 1 << SZ(uncertain)) {
                res += ans[i];
                rep(j, i + 1, 1 << SZ(uncertain)) {
                        bool fg = 1;
                        rep(t, 0, SZ(uncertain)) if(i & (1<<t)) {
                                if((j & (1<<t)) == 0) {
                                        fg = 0; break; 
                                }
                        }
                        if(fg) chmax(ans[j], ans[i]);
                }
        }
        return res;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> g, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Clicounting *instance = new Clicounting();
    int __result = instance->count(g);
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
            string g[] = {
                "011",
                "101",
                "110"
            };
            int __expected = 3;
            return do_test(to_vector(g), __expected, __no);
        }
        case 1: {
            string g[] = {
                "01?",
                "101",
                "?10"
            };
            int __expected = 5;
            return do_test(to_vector(g), __expected, __no);
        }
        case 2: {
            string g[] = {
                "0?",
                "?0"
            };
            int __expected = 3;
            return do_test(to_vector(g), __expected, __no);
        }
        case 3: {
            string g[] = {
                "0??",
                "?0?",
                "??0"
            };
            int __expected = 16;
            return do_test(to_vector(g), __expected, __no);
        }
        case 4: {
            string g[] = {
                "0???",
                "?0??",
                "??0?",
                "???0"
            };
            int __expected = 151;
            return do_test(to_vector(g), __expected, __no);
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
        cout << "Clicounting (550 Points)" << endl << endl;
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
        int T = time(NULL) - 1479294284;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
