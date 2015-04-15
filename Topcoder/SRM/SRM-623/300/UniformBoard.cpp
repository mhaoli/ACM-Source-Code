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
const int inf = 2139062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class UniformBoard {
    public:
    vs bod;
    int getBoard(vector<string> bod, int K) {
        this -> bod = bod;
        int n = sz(bod);
        int ans = -1;
        repf (i, 0, n-1) repf (j, 0, n-1) if (bod[i][j] == '.') ans = 0;
        if (ans == -1) K = 0, ans = 0;

        int cnt = 0;
        repf (i, 0, n-1) repf (j, 0, n-1) if (bod[i][j] == 'A') ++ cnt;
        repf (i, 0, n-1) repf (j, 0, n-1) repf (t1, 1, n) repf (t2, 1, n) 
            if (t1 * t2 <= cnt && calc (i, j, t1, t2) <= K) chmax (ans, t1 * t2);
        return ans;
    }
    int calc (int x, int y, int t1, int t2){
        int ret = 0, n = sz(bod);
        if (x + t1 - 1 >= n || y + t2 - 1 >= n) return inf;
        repf (i, x, x+t1-1) repf (j, y, y+t2-1){
            if (bod[i][j] == 'A') continue;
            if (bod[i][j] == '.') ++ ret;
            if (bod[i][j] == 'P') ret += 2;
        }
        //if (!x && !y && t1 == 1 && t2 == 2) out (ret);
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, int K, int __expected, int caseNo) {

    time_t startClock = clock();
    UniformBoard *instance = new UniformBoard();
    int __result = instance->getBoard(board, K);
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
            string board[] = {
"A..P.....APP..P.PPPP"
,"PA..PA.PAAPPPP.A.PP."
,"AA.PPAAPPA.A..PA.AP."
,"AA.A.PPPA..P..A.P.AP"
,"P.PPAAA.AAPAA.PPAP.P"
,"APA...A..A...A.A..AP"
,"AAPPAPPP.APA.AAPPPPA"
,"...AAPAA..P..AAAA.PA"
,"AA.PA....AP...AAAPAP"
,"A.APPA..P.APPPAAA.AP"
,"P..P.PPAPPPPA.P.PAPP"
,".AP.AA..PA.P.AA.AA.A"
,".AAPAA.APPPAPP.AP.P."
,"P.AAA...PP...PAAPPP."
,"P.APAAA....P...P.PA."
,"A..PPAP..AAAPAA....A"
,".P..PAPAAP..PAAPPP.P"
,"AAP.AP.A..P..PPAAPP."
,"P..P.PA..AP..AP..AAP"
,".AA..AAAP.PPAAPA.AA."
            };
            int K = 1000;
            int __expected = 1;
            return do_test(to_vector(board), K, __expected, __no);
        }
        case 1: {
            string board[] = {
                "AP",
                ".A"
            };
            int K = 1;
            int __expected = 2;
            return do_test(to_vector(board), K, __expected, __no);
        }
        case 2: {
            string board[] = {
                "PPP",
                "APA",
                "A.P"
            };
            int K = 2;
            int __expected = 3;
            return do_test(to_vector(board), K, __expected, __no);
        }
        case 3: {
            string board[] = {
                "AAA",
                "PPP",
                "AAA"
            };
            int K = 10;
            int __expected = 3;
            return do_test(to_vector(board), K, __expected, __no);
        }
        case 4: {
            string board[] = {
                "."
            };
            int K = 1000;
            int __expected = 0;
            return do_test(to_vector(board), K, __expected, __no);
        }
        case 5: {
            string board[] = {
                "PPAAPA..AP",
                "PPA.APAP..",
                "..P.AA.PPP",
                "P.P..APAA.",
                "P.P..P.APA",
                "PPA..AP.AA",
                "APP..AAPAA",
                "P.P.AP...P",
                ".P.A.PAPPA",
                "..PAPAP..P"
            };
            int K = 10;
            int __expected = 15;
            return do_test(to_vector(board), K, __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "UniformBoard (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1401930157;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
