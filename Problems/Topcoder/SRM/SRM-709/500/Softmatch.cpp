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

class Softmatch {
        public:
        int count(string S, vector<string> patterns);
};

typedef vector<string> vs;

namespace AC {
        int idx(char c);
        //----------------------------------------template
        const int Max_S = 5;
        const int Max_N = 13000;
        struct node {
                node *son[Max_S+5], *f, *jump[Max_S+5];
                int v;
                node *go(int c);
                void clear() {
                        v = 0; clr(son);
                }
        }pool[Max_N+5], *rt, *bat;

        void newNode(node*&o) {
                bat->clear(); o = bat++;
        }
        node *node::go(int c) {
                if(son[c]==0) newNode(son[c]);
                return son[c];
        }
        void clear() {
                bat = pool; bat->clear(); rt = bat++;
        }
        
        void insert(string s, int val) {
                node*x = rt;
                rep(i,0,SZ(s)) x = x->go(idx(s[i]));
                x->v += val;
        }

        node *q[Max_N + 5];
        void build() {
                int ql = 0, qr = 0;
                q[qr++] = rt;
                while(ql != qr) {
                        node *x = q[ql++];
                        rep(c,0,Max_S) {
                                node*v = x->son[c];
                                if(!v) continue;
                                
                                node*last = x->f;
                                while(last && last->son[c]==0) last=last->f;
                                if(last) v->f = last->son[c];
                                else v->f = rt;
                                q[qr++] = v;
                        }
                }

                rep(i,0,Max_S) rt->jump[i] = rt->son[i] ? rt->son[i] : rt;
                rep(i,1,qr) {
                        node *x = q[i];
                        rep(j,0,Max_S) {
                                if(x->son[j]) x->jump[j] = x->son[j];
                                else x->jump[j] = x->f->jump[j];
                        }
                }

                rep(i,1,qr) {
                        node*x = q[i];
                        if(x->f) x->v += x->f->v;
                }
        }

        //-------------------------------------------
        int idx(char c) {
                if(c == 'a') return 0;
                if(c == 'A') return 1;
                if(c == 'b') return 2;
                return 3;
        }

        int dp[55][Max_N+5];

        int solve(string s) {
                int n = SZ(s);
                mem(dp,-1);
                dp[0][0] = 0;

                int flag;
                node *tmp, *nxt;
                string temp[2]; temp[0] = "aA"; temp[1] = "bB";
                rep(i,0,n) rep(j,0,Max_N) if(dp[i][j] != -1) {
                        flag = s[i] == 'a' ? 0 : 1;
                        tmp = &pool[j];
                        rep(k,0,2) {
                                nxt = tmp->jump[idx(temp[flag][k])];
                                chmax(dp[i+1][nxt-pool], dp[i][j] + nxt->v);
                        }
                }
                return *std::max_element(dp[n], dp[n]+Max_N);
        }
}

char trans_sin(char c, char t) {
        if(c == 'a') {
                return t < '2' ? 'a' : 'A';
        } else {
                return (t=='0' || t=='2') ? 'b' : 'B';
        }
}

vs trans(vs vec, string s) {
        int n = SZ(s);
        set<string> res;
        for(string t : vec) {
                int m = SZ(t);
                rep(i,0,n-m+1) {
                        string ans(m,0);
                        rep(j,0,m) {
                                ans[j] = trans_sin(s[i+j], t[j]);
                        }
                        res.insert(ans);
                }
        }
        return vs(all(res));
}

bool match_sin(char c, char t) {
        if(c == 'a' || c == 'A') {
                if(c == 'a') return t < '2';
                return t > '1';
        } else {
                if(c == 'b') return t == '0' || t == '2';
                return t == '1' || t == '3';
        }
}

int match(string s, string t) {
        if(SZ(s) != SZ(t)) return 0;
        rep(i,0,SZ(s)) {
                if(!match_sin(s[i],t[i])) return 0;
        }
        return 1;
}

char sss[555];

int Softmatch::count(string s, vector<string> pat) {
        vs vec = trans(pat, s);
        
        AC::clear();
        rep(i,0,SZ(vec)) {
                int cnt = 0;
                for(string t : pat) cnt += match(vec[i], t);
                AC::insert(vec[i], cnt);
        }
        AC::build();
        return AC::solve(s);
}


// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string S, vector<string> patterns, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Softmatch *instance = new Softmatch();
    int __result = instance->count(S, patterns);
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
            string S = "aaa";
            string patterns[] = {
                "03",
                "21"
            };
            int __expected = 2;
            return do_test(S, to_vector(patterns), __expected, __no);
        }
        case 1: {
            string S = "aba";
            string patterns[] = {
                "03",
                "11"
            };
            int __expected = 3;
            return do_test(S, to_vector(patterns), __expected, __no);
        }
        case 2: {
            string S = "bba";
            string patterns[] = {
                "00",
                "00"
            };
            int __expected = 4;
            return do_test(S, to_vector(patterns), __expected, __no);
        }
        case 3: {
            string S = "bbbbbb";
            string patterns[] = {
                "1110",
                "011",
                "100"
            };
            int __expected = 3;
            return do_test(S, to_vector(patterns), __expected, __no);
        }
        case 4: {
            string S = "abbaa";
            string patterns[] = {
                "123"
            };
            int __expected = 2;
            return do_test(S, to_vector(patterns), __expected, __no);
        }
        case 5: {
            string S = "aababbaab";
            string patterns[] = {
                "012",
                "332",
                "101",
                "0313"
            };
            int __expected = 7;
            return do_test(S, to_vector(patterns), __expected, __no);
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
        cout << "Softmatch (500 Points)" << endl << endl;
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
        int T = time(NULL) - 1488086096;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
