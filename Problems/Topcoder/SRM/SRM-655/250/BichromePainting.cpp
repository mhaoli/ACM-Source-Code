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
#include <complex>

using namespace std;

#define x first
#define y second
#define sqr(x) ((x)*(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/***head***/

class BichromePainting {
        public:
                string isThatPossible(vector<string> board, int k);
};

int K, n;
vector<string> vec;

bool check(int t1, int t2) {
        char tmp = 0;
        for(int i = t1, j; i < t1 + K; ++i) {
                for(j = t2; j < t2 + K; ++j)  {

                        if(tmp == 0) tmp = vec[i][j];
                        else if(vec[i][j] && vec[i][j] != tmp) {
                                return 0;
                        }
                }
        }
        if(tmp == 0) return 0;
        for(int i = t1, j; i < t1 + K; ++i) {
                for(j = t2; j < t2 + K; ++j) vec[i][j] = 0;
        }
        return 1;
}

string BichromePainting::isThatPossible(vector<string> board, int _k){
        string yes = "Possible", no = "Impossible";
        vec = board; K = _k;
        n = vec.size();
        bool flag = 0;
        while(1) {
                flag = 0;
                for(int i = 0, j; i + K <= n; ++i) {
                        for(j = 0; j + K <= n; ++j) {
                                if(check(i, j)) {
                                        flag = 1;
                                }
                        }
                }
                if(!flag) break;
        }
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(vec[i][j]) return no;
        return yes;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, int k, string __expected, int caseNo) {

    time_t startClock = clock();
    BichromePainting *instance = new BichromePainting();
    string __result = instance->isThatPossible(board, k);
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
                "BBBW",
                "BWWW",
                "BWWW",
                "WWWW"
            };
            int k = 3;
            string __expected = "Possible";
            return do_test(to_vector(board), k, __expected, __no);
        }
        case 1: {
            string board[] = {
                "BW",
                "WB"
            };
            int k = 2;
            string __expected = "Impossible";
            return do_test(to_vector(board), k, __expected, __no);
        }
        case 2: {
            string board[] = {
                "BWBWBB",
                "WBWBBB",
                "BWBWBB",
                "WBWBBB",
                "BBBBBB",
                "BBBBBB"
            };
            int k = 2;
            string __expected = "Possible";
            return do_test(to_vector(board), k, __expected, __no);
        }
        case 3: {
            string board[] = {
                "BWBWBB",
                "WBWBWB",
                "BWBWBB",
                "WBWBWB",
                "BWBWBB",
                "BBBBBB"
            };
            int k = 2;
            string __expected = "Impossible";
            return do_test(to_vector(board), k, __expected, __no);
        }
        case 4: {
            string board[] = {
                "BWBWBB",
                "WBWBWB",
                "BWBWBB",
                "WBWBWB",
                "BWBWBB",
                "BBBBBB"
            };
            int k = 1;
            string __expected = "Possible";
            return do_test(to_vector(board), k, __expected, __no);
        }
        case 5: {
            string board[] = {
                "BB",
                "BB"
            };
            int k = 2;
            string __expected = "Possible";
            return do_test(to_vector(board), k, __expected, __no);
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
    cout << "BichromePainting (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1429267684;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
