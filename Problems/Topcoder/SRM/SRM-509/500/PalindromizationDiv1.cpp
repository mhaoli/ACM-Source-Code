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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 3;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class PalindromizationDiv1 {
    public:
    string s;
    int d[55][55];
    int ers[50], add[50], cha[50][50];
    int getMinimumCost(string _s, vector<string> opt) {
        s = _s;
        repf (i, 0, 25){
            add[i] = ers[i] = inf;
            repf (j, 0, 25) cha[i][j] = i == j ? 0 : inf;
        }
        for (auto s : opt){
            int tmp = 0;
            for (char c : s) if (c >= '0' && c <= '9') tmp = tmp * 10 + c-'0';
            if (s[1] == 'd') chmin (add[s[4]-'a'], tmp);
            else if (s[1] == 'r') chmin (ers[s[6]-'a'], tmp);
            else chmin (cha[s[7]-'a'][s[9]-'a'], tmp);
        }

        repf (k, 0, 25) repf (i, 0, 25) repf (j, 0, 25) chmin (cha[i][j], cha[i][k]+cha[k][j]);
        repf (i, 0, 25) repf (j, 0, 25){
            chmin (add[i], add[j] + cha[j][i]);
            chmin (ers[i], cha[i][j] + ers[j]);
        }

        clr (d, -1);
        int tmp = dfs (0, sz(s)-1);
        return tmp < inf ? tmp : -1;
    }
    int dfs (int l, int r){
        if (l >= r) return 0;
        int &ret = d[l][r];
        if (ret != -1) return ret;
        ret = inf;

        int t1 = s[l] - 'a', t2 = s[r] - 'a';
        repf (i, 0, 25){
            if (s[l] == s[r]) chmin (ret, dfs (l+1, r-1));
            chmin (ret, add[i] + cha[t2][i] + dfs (l, r-1));
            chmin (ret, add[i] + cha[t1][i] + dfs (l+1, r));
            chmin (ret, ers[t1] + dfs (l+1, r));
            chmin (ret, ers[t2] + dfs (l, r-1));
            chmin (ret, cha[t1][i] + cha[t2][i] + dfs (l+1, r-1));
        }
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string word, vector<string> operations, int __expected, int caseNo) {

    time_t startClock = clock();
    PalindromizationDiv1 *instance = new PalindromizationDiv1();
    int __result = instance->getMinimumCost(word, operations);
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
            string word = "ltbgpjcsaknlzctionkqffrpevmybpptydvizassekdoznkln";
            string operations[] = 
{"change g n 47673", "erase r 77264", "change l t 42081", "add r 4800", "add b 96464", "erase k 51662", "change b n 39898", "erase d 22461", "erase g 27854", "change p u 14295", "add d 51496", "add e 75369", "add o 87389", "change t z 27185", "change c z 71695", "change b l 54216", "add i 19003", "add f 27638", "add u 85866", "change j u 67802", "erase t 57582", "erase i 22054", "add k 10000", "change q b 34740", "add q 72938", "change x m 44234", "erase s 36666", "erase b 14907", "add h 69181", "erase f 99058", "change p b 90898", "erase l 21277", "add x 32316", "change c m 85633", "change v o 96383", "change y u 61797", "change h v 19755", "change p r 8901", "change n h 99960"}
            ;
            int __expected = 1629924;
            return do_test(word, to_vector(operations), __expected, __no);
        }
        case 1: {
            string word = "topcoder";
            string operations[] = {
                "erase t 1",
                "erase o 1",
                "erase p 1",
                "erase c 1",
                "erase d 1",
                "erase e 1",
                "erase r 1"
            };
            int __expected = 5;
            return do_test(word, to_vector(operations), __expected, __no);
        }
        case 2: {
            string word = "topcoder";
            string operations[] = {
                "erase t 10",
                "erase o 1",
                "erase p 1",
                "erase c 1",
                "erase d 1",
                "erase e 1",
                "erase r 1"
            };
            int __expected = 7;
            return do_test(word, to_vector(operations), __expected, __no);
        }
        case 3: {
            string word = "caaaaaab";
            string operations[] = {
                "change b a 100000",
                "change c a 100000",
                "change c d 50000",
                "change b e 50000",
                "erase d 50000",
                "erase e 49999"
            };
            int __expected = 199999;
            return do_test(word, to_vector(operations), __expected, __no);
        }
        case 4: {
            string word = "moon";
            string operations[] = {
                "erase o 5",
                "add u 7",
                "change d p 3",
                "change m s 12",
                "change n d 6",
                "change s l 1"
            };
            int __expected = -1;
            return do_test(word, to_vector(operations), __expected, __no);
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
    cout << "PalindromizationDiv1 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405444354;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
