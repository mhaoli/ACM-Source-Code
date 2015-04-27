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

class TheTips {
        public:
                double solve(vector<string> clues, vector<int> probability);
};


double TheTips::solve(vector<string> an, vector<int> p){
        //string yes = "Possible", no = "Impossible";
        int n = an.size();
        vector<vector<bool> > G(n);
        snuke(i, an) {
                G[i - an.begin()].clear();
                snuke(j, *i) {
                        G[i-an.begin()].push_back((*j) == 'Y');
                }
        }
        for(int i = 0, j, k; i < n; ++i) {
                for(j = 0; j < n; ++j) {
                        for(k = 0; k < n; ++k) if(G[j][i] && G[i][k]) G[j][k] = 1;
                }
        }
        double ans = 0, tmp;
        for(int i = 0, j; i < n; ++i) {
                tmp = 1 - (p[i] / 100.0);
                for(j = 0; j < n; ++j) if(i != j && G[j][i]) tmp *= 1 - p[j] / 100.0;
                ans += 1 - tmp;
        }
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<string> clues, vector<int> probability, double __expected, int caseNo) {

    time_t startClock = clock();
    TheTips *instance = new TheTips();
    double __result = instance->solve(clues, probability);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            string clues[] = {
                "Y"
            };
            int probability[] = {
                50
            };
            double __expected = 0.5;
            return do_test(to_vector(clues), to_vector(probability), __expected, __no);
        }
        case 1: {
            string clues[] = {
                "YN",
                "NY"
            };
            int probability[] = {
                100, 50
            };
            double __expected = 1.5;
            return do_test(to_vector(clues), to_vector(probability), __expected, __no);
        }
        case 2: {
            string clues[] = {
                "YYY",
                "NYY",
                "NNY"
            };
            int probability[] = {
                100, 0, 0
            };
            double __expected = 3.0;
            return do_test(to_vector(clues), to_vector(probability), __expected, __no);
        }
        case 3: {
            string clues[] = {
                "NNN",
                "NNN",
                "NNN"
            };
            int probability[] = {
                0, 0, 0
            };
            double __expected = 0.0;
            return do_test(to_vector(clues), to_vector(probability), __expected, __no);
        }
        case 4: {
            string clues[] = {
                "NYYNYYNNNN",
                "NNNNYNNNYN",
                "YNNYYYYYNN",
                "YYNYNNNNYN",
                "NYNNNNNNNY",
                "YNYYNNYNNY",
                "NYNNYYYYYY",
                "NYYYYNNNNN",
                "YYNYNNYYYN",
                "NNYYNYNYYY"
            };
            int probability[] = {
                11, 66, 99, 37, 64, 45, 21, 67, 71, 62
            };
            double __expected = 9.999891558057332;
            return do_test(to_vector(clues), to_vector(probability), __expected, __no);
        }
        case 5: {
            string clues[] = {
                "NNY",
                "NNY",
                "NNN"
            };
            int probability[] = {
                50, 50, 1
            };
            double __expected = 1.7525;
            return do_test(to_vector(clues), to_vector(probability), __expected, __no);
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
    cout << "TheTips (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430115339;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
