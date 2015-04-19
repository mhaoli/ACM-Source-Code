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

class Family {
    public:
    int col[1005];
    vi son[1005];
    string isFamily(vector<int> p1, vector<int> p2) {
        string no = "Impossible", yes = "Possible";
        int n = sz(p1);
        repf (i, 0, n-1) son[i].clear();
        repf (i, 0, n-1){
            if (p1[i] == -1 && p2[i] == -1) continue;
            if (p1[i] == p2[i]) return no;
            son[p1[i]].pb (p2[i]); son[p2[i]].pb (p1[i]);
        }

        clr (col, 0);
        repf (i, 0, n-1) if (!col[i]) if (!dfs (i, 1)) return no;
        return yes; 
    }
    bool dfs (int x, int c){
        col[x] = c;
        repf (i, 0, sz(son[x])-1){
            int j = son[x][i];
            if (!col[j]){
                if (!dfs (j, 3-c)) return 0;
            }
            else if (col[j] == c) return 0;
        }
        return 1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> parent1, vector<int> parent2, string __expected, int caseNo) {

    time_t startClock = clock();
    Family *instance = new Family();
    string __result = instance->isFamily(parent1, parent2);
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
            int parent1[] = {
                -1, -1, 0, 0, 3, 2, 0, -1, 1, 3, -1, 6, 6, 7, 10, -1, 14
            };
            int parent2[] = {
                -1, -1, 1, 2, 1, 0, 1, -1, 4, 8, -1, 8, 9, 11, 4, -1, 11
            };
            string __expected = "Possible";
            return do_test(to_vector(parent1), to_vector(parent2), __expected, __no);
        }
        case 1: {
            int parent1[] = {
                -1, -1, -1, -1, -1
            };
            int parent2[] = {
                -1, -1, -1, -1, -1
            };
            string __expected = "Possible";
            return do_test(to_vector(parent1), to_vector(parent2), __expected, __no);
        }
        case 2: {
            int parent1[] = {
                -1, -1, 0, 0, 1
            };
            int parent2[] = {
                -1, -1, 1, 2, 2
            };
            string __expected = "Impossible";
            return do_test(to_vector(parent1), to_vector(parent2), __expected, __no);
        }
        case 3: {
            int parent1[] = {
                -1, -1, -1, -1, 1, -1, 0, 5, 6, -1, 0, 3, 8, 6
            };
            int parent2[] = {
                -1, -1, -1, -1, 3, -1, 4, 6, 5, -1, 5, 4, 6, 1
            };
            string __expected = "Possible";
            return do_test(to_vector(parent1), to_vector(parent2), __expected, __no);
        }
        case 4: {
            int parent1[] = {
                -1, -1, -1, 2, 2, -1, 5, 6, 4, 6, 2, 1, 8, 0, 2, 4, 6, 9, -1, 16, -1, 11
            };
            int parent2[] = {
                -1, -1, -1, 1, 0, -1, 1, 4, 2, 0, 4, 8, 2, 3, 0, 5, 14, 14, -1, 7, -1, 13
            };
            string __expected = "Impossible";
            return do_test(to_vector(parent1), to_vector(parent2), __expected, __no);
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
    cout << "Family (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1398387747;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
