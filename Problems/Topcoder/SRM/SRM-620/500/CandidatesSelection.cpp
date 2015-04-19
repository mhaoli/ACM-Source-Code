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

class CandidatesSelection {
    public:
    int use[55], flag[55];
    string possible(vector<string> sco, vector<int> res){
        string no = "Impossible", yes = "Possible";
        clr (use, 0); clr (flag, 0);
        int n = sz(sco), m = sz(sco[0]);

        repf (cas, 0, m-1){
            int cur = -1;
            repf (i, 0, m-1) if (!use[i]){
                bool u = 1;
                repf (j, 0, n-2) if (!flag[j]){
                    if (sco[res[j]][i] > sco[res[j+1]][i]) u = 0;
                }
                if (u){
                    cur = i; break;
                }
            }
            if (cur == -1) break;

            use[cur] = 1;
            repf (i, 0, n-2) if (sco[res[i]][cur] < sco[res[i+1]][cur]) flag[i] = 1;
        }

        repf (i, 0, n-2){
            if (flag[i]) continue;
            if (res[i] < res[i+1]) continue;
            return no;
        }
        return yes;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> score, vector<int> result, string __expected, int caseNo) {

    time_t startClock = clock();
    CandidatesSelection *instance = new CandidatesSelection();
    string __result = instance->possible(score, result);
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
            string score[] = {
                "CC",
                "AA",
                "BB"
            };
            int result[] = {
                1, 2, 0
            };
            string __expected = "Possible";
            return do_test(to_vector(score), to_vector(result), __expected, __no);
        }
        case 1: {
            string score[] = {
                "BAB",
                "ABB",
                "AAB",
                "ABA"
            };
            int result[] = {
                2, 0, 1, 3
            };
            string __expected = "Possible";
            return do_test(to_vector(score), to_vector(result), __expected, __no);
        }
        case 2: {
            string score[] = {
                "BAB",
                "ABB",
                "AAB",
                "ABA"
            };
            int result[] = {
                0, 1, 3, 2
            };
            string __expected = "Impossible";
            return do_test(to_vector(score), to_vector(result), __expected, __no);
        }
        case 3: {
            string score[] = {
                "AAA",
                "ZZZ"
            };
            int result[] = {
                1, 0
            };
            string __expected = "Impossible";
            return do_test(to_vector(score), to_vector(result), __expected, __no);
        }
        case 4: {
            string score[] = {
                "ZZZ",
                "AAA"
            };
            int result[] = {
                0, 1
            };
            string __expected = "Possible";
            return do_test(to_vector(score), to_vector(result), __expected, __no);
        }
        case 5: {
            string score[] = {
                "ZYYYYX",
                "YXZYXY",
                "ZZZZXX",
                "XZXYYX",
                "ZZZYYZ",
                "ZZXXYZ",
                "ZYZZXZ",
                "XZYYZX"
            };
            int result[] = {
                3, 7, 1, 0, 2, 5, 6, 4
            };
            string __expected = "Possible";
            return do_test(to_vector(score), to_vector(result), __expected, __no);
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
    cout << "CandidatesSelection (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1399865408;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
