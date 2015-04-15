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

class SRMCodingPhase {
    public:
    int ans, luck;
    vi poi, tim;
    int use[30], id[10];
    int countScore(vector<int> points, vector<int> skills, int _luck){
        //string no = "Impossible", yes = "Possible";
        ans = 0; luck = _luck;
        poi = points; tim = skills;
        string s = "123";
        do{
            calc (s);
        }while (next_permutation(all (s)));
        return ans;
    }
    void calc (string s){
        rep (i, 0, 2) id[i] = s[i] - '1';
        rep (i, 0, luck) rep (j, 0, luck-i){
            use[0] = max (1, tim[id[0]] - i);
            use[1] = max (1, tim[id[1]] - j);
            use[2] = max (1, tim[id[2]] - (luck - i - j));
            int res = 0, all = 0;
            rep (i, 0, 2){
                all += use[i];
                if (all > 75) continue;
                res += poi[id[i]] - (1<<(id[i]+1)) * use[i];
            }
            chmax (ans, res);
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> points, vector<int> skills, int luck, int __expected, int caseNo) {

    time_t startClock = clock();
    SRMCodingPhase *instance = new SRMCodingPhase();
    int __result = instance->countScore(points, skills, luck);
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
            int points[] = {
                250, 500, 1000
            };
            int skills[] = {
                10, 25, 40
            };
            int luck = 0;
            int __expected = 1310;
            return do_test(to_vector(points), to_vector(skills), luck, __expected, __no);
        }
        case 1: {
            int points[] = {
                300, 600, 900
            };
            int skills[] = {
                30, 65, 90
            };
            int luck = 25;
            int __expected = 680;
            return do_test(to_vector(points), to_vector(skills), luck, __expected, __no);
        }
        case 2: {
            int points[] = {
                250, 550, 950
            };
            int skills[] = {
                10, 25, 40
            };
            int luck = 75;
            int __expected = 1736;
            return do_test(to_vector(points), to_vector(skills), luck, __expected, __no);
        }
        case 3: {
            int points[] = {
                256, 512, 1024
            };
            int skills[] = {
                35, 30, 25
            };
            int luck = 0;
            int __expected = 1216;
            return do_test(to_vector(points), to_vector(skills), luck, __expected, __no);
        }
        case 4: {
            int points[] = {
                300, 600, 1100
            };
            int skills[] = {
                80, 90, 100
            };
            int luck = 4;
            int __expected = 0;
            return do_test(to_vector(points), to_vector(skills), luck, __expected, __no);
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
    cout << "SRMCodingPhase (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408760949;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
