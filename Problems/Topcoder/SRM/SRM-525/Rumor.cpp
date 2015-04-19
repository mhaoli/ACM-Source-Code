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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int d[20][2];

class Rumor {
    public:
    vi first, pat[20];
    int getMinimum(string know, vector<string> G){
        //string no = "Impossible", yes = "Possible";
        first.clear ();
        rep (i, 0, sz (know)-1){
            pat[i].clear ();
            rep (j, 0, sz (G[i])-1) if (G[i][j] == 'Y') pat[i].pb (j);
        }
        rep (i, 0, sz (know)-1) if (know[i] == 'Y') first.pb (i);
        if (sz (first) == sz (know)) return 0;

        //for (auto i : first) out (i);
        //rep (i, 0, sz (G)-1){
            //for (auto v : pat[i]) tst (v);
            //cout << endl;
        //}

        int N = sz (first), ans = inf;
        rep (i, 0, (1<<N)-1){
            clr (d, 127);
            rep (j, 0, N-1){
                d[first[j]][0] = (i & (j<<1)) ? 0 : 1;
                d[first[j]][1] = 1 - d[first[j]][0];
            }

            //if (!i) tst (d[0][0]), out (d[0][1]), out (d[1][0]), out (d[1][1]);

            for (auto u : first) dfs (u);

            int res = 0;
            rep (j, 0, sz (G)-1){
                chmax (res, max (d[j][0], d[j][1]));
            }
            chmin (ans, res);
        }
        return ans >= inf ? -1 : ans;
    }
    void dfs (int u){
        for (auto v : pat[u]){
            //if (!u) out (chmin (d[v][0], d[u][0] + 1));
            bool u1 = chmin (d[v][0], d[u][0] + 1), u2 = chmin (d[v][1], d[u][1] + 1);
            if (u1 || u2) dfs (v);
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string knowledge, vector<string> graph, int __expected, int caseNo) {

    time_t startClock = clock();
    Rumor *instance = new Rumor();
    int __result = instance->getMinimum(knowledge, graph);
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
            string knowledge = "YNN";
            string graph[] = {
                "NYN",
                "NNY",
                "NNN"
            };
            int __expected = 3;
            return do_test(knowledge, to_vector(graph), __expected, __no);
        }
        case 1: {
            string knowledge = "YNNY";
            string graph[] = {
                "NYYN",
                "YNNY",
                "YNNY",
                "NYYN"
            };
            int __expected = 1;
            return do_test(knowledge, to_vector(graph), __expected, __no);
        }
        case 2: {
            string knowledge = "YYYY";
            string graph[] = {
                "NYNN",
                "YNYN",
                "NYNY",
                "NNYN"
            };
            int __expected = 0;
            return do_test(knowledge, to_vector(graph), __expected, __no);
        }
        case 3: {
            string knowledge = "YYYYYN";
            string graph[] = {
                "NYYYYN",
                "YNYYYN",
                "YYNYYN",
                "YYYNYN",
                "YYYYNN",
                "NNNNNN"
            };
            int __expected = -1;
            return do_test(knowledge, to_vector(graph), __expected, __no);
        }
        case 4: {
            string knowledge = "NNNY";
            string graph[] = {
                "NNNN",
                "YNNN",
                "YNNN",
                "NYYN"
            };
            int __expected = 3;
            return do_test(knowledge, to_vector(graph), __expected, __no);
        }
        case 5: {
            string knowledge =  "NNNNNNNYYY";
            string graph[] = {
                "NYNNYNNYNN",
                "NNYNYNNNNY",
                "YYNNNYNNNN",
                "YNNNYNYNNN",
                "NNYNNYNNYN",
                "NNNNYNNNYY",
                "NYNYNYNNNN",
                "NNNNNNYNYY",
                "NNNYNNNYNY",
                "NYYNNNNYNN"
            };
            int __expected = 2;
            return do_test(knowledge, to_vector(graph), __expected, __no);
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
    cout << "Rumor (525 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409277807;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 525 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
