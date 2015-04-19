#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <string>
#include <utility>
#include <map>
#include <ctime>
#include <typeinfo>
#include <stack>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define two(x) (1<<(x))
#define twol(x) (1LL<<(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;
const int maxn = 1005;
const int maxs = 26;
const int mod = 1000000009;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *ch[maxs+5], *f;
    nod *jp[maxs+5];
    int v;
    nod *go (int c);
}memo[maxn], *bat = memo, *rt, *q[maxn];

void newnod (nod *&o){
    o = bat ++; clr (o->ch, 0); o->v = 0;
}

nod *nod::go(int c){
    if (ch[c] == 0) newnod (ch[c]);
    return ch[c];
}

void init (){
    bat = memo; newnod (rt);
}

int idx (nod *x){
    return x - memo;
}

void insert (int *s, int n, int v){
    nod *x = rt;
    rep (i, 0, n-1) x = x->go (s[i]);
    x->v += v;
}

void build (){
    int ql = 0, qr = 0;
    q[qr++] = rt;
    while (ql != qr){
        nod *x = q[ql++];
        rep (c, 0, maxs-1){
            nod *v = x->ch[c];
            if (!v) continue;

            nod *last = x->f;
            while (last && last->ch[c] == 0) last = last->f;
            if (last) v->f = last->ch[c];
            else v->f = rt;
            q[qr++] = v;
        }
    }

    rep (i, 0, maxs-1) rt->jp[i] = rt->ch[i] ? rt->ch[i] : rt;
    rep (i, 1, qr-1){
        nod *x = q[i];
        rep (j, 0, maxs-1)
            if (x->ch[j]) x->jp[j] = x->ch[j];
            else x->jp[j] = x->f->jp[j];
    }
    rep (i, 1, qr-1) q[i]->v |= q[i]->f->v;
}

int s[111];
int d[55][1111][66];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

class RequiredSubstrings {
    public:
    int solve(vector<string> words, int C, int L){
        init ();
        int sta = 1;
        for (auto i : words){
            rep (j, 0, sz(i)-1) s[j] = i[j] - 'a';
            insert (s, sz (i), sta);
            sta <<= 1;
        }

        build ();

        int m = bat - memo;
        clr (d, 0); d[0][0][0] = 1;
        rep (i, 1, L) rep (j, 0, m-1) rep (s, 0, sta-1) if (d[i-1][j][s]){
            rep (k, 0, maxs-1){
                nod *nxt = memo[j].jp[k];
                add (d[i][idx(nxt)][s|nxt->v], d[i-1][j][s]);
            }
        }

        int ans = 0;
        rep (i, 0, sta-1) if (__builtin_popcount (i) == C) 
            rep (j, 0, m-1) add (ans, d[L][j][i]);
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> words, int C, int L, int __expected, int caseNo) {

    time_t startClock = clock();
    RequiredSubstrings *instance = new RequiredSubstrings();
    int __result = instance->solve(words, C, L);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "  Testcase #" << caseNo << " ... ";
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "  Testcase #" << caseNo << " ... ";
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            string words[] = {
                "a",
                "aa",
                "aaa",
                "aaaa"
            };
            int C = 2;
            int L = 3;
            int __expected = 50;
            return do_test(to_vector(words), C, L, __expected, __no);
        }
        case 1: {
            string words[] = {
                "abcdefgh"
            };
            int C = 0;
            int L = 7;
            int __expected = 31810104;
            return do_test(to_vector(words), C, L, __expected, __no);
        }
        case 2: {
            string words[] = {
                "abcdefgh"
            };
            int C = 1;
            int L = 7;
            int __expected = 0;
            return do_test(to_vector(words), C, L, __expected, __no);
        }
        case 3: {
            string words[] = {
                "a",
                "b",
                "c",
                "d"
            };
            int C = 3;
            int L = 3;
            int __expected = 24;
            return do_test(to_vector(words), C, L, __expected, __no);
        }
        case 4: {
            string words[] = {
                "ab",
                "bc",
                "xy",
                "yz"
            };
            int C = 2;
            int L = 3;
            int __expected = 2;
            return do_test(to_vector(words), C, L, __expected, __no);
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
    cout << "RequiredSubstrings (600 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408715768;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
