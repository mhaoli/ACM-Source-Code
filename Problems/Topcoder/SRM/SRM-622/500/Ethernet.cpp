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
const int inf = 2039062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class Ethernet {
    public:
    vi son[55];
    int d[55][55], ok[55][55];
    int connect(vector<int> pat, vector<int> dist, int maxd) {
        int n = sz(pat) + 1;
        repf (i, 0, n-1) son[i].clear();
        repf (i, 0, n-2) son[pat[i]].pb (i + 1);

        clr (d, 0); clr (ok, -1);
        repd (i, n-1, 0) repf (j, 0, sz(son[i])-1){
            int v = son[i][j];

            repd (k, n-1, 1){
                int td = inf;
                repf (t, 0, k) if (d[v][t] < inf){
                    int tlen = d[i][k-t] + d[v][t] + dist[v-1];
                    if (k - t) chmin (td, d[i][k-t-1]);
                    if (tlen <= maxd) chmin (td, max (d[i][k-t], d[v][t]+dist[v-1]));
                }
                d[i][k] = td;
            }

            if (d[i][0] + d[v][0] + dist[v-1] <= maxd) chmax (d[i][0], d[v][0] + dist[v-1]);
            else d[i][0] = inf;
        }

        repf (i, 0, n-1) if (d[0][i] <= maxd) return i + 1;
        return n;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> parent, vector<int> dist, int maxDist, int __expected, int caseNo) {

    time_t startClock = clock();
    Ethernet *instance = new Ethernet();
    int __result = instance->connect(parent, dist, maxDist);
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
            int parent[] = {
                0, 0, 0
            };
            int dist[] = {
                1, 1, 1
            };
            int maxDist = 2;
            int __expected = 1;
            return do_test(to_vector(parent), to_vector(dist), maxDist, __expected, __no);
        }
        case 1: {
            int parent[] = {
                0, 0, 0, 0, 0, 0, 0
            };
            int dist[] = {
                1, 2, 3, 4, 5, 6, 7
            };
            int maxDist = 8;
            int __expected = 4;
            return do_test(to_vector(parent), to_vector(dist), maxDist, __expected, __no);
        }
        case 2: {
            int parent[] = {
                0, 1, 2, 3, 4, 5
            };
            int dist[] = {
                1, 2, 3, 4, 5, 6
            };
            int maxDist = 6;
            int __expected = 3;
            return do_test(to_vector(parent), to_vector(dist), maxDist, __expected, __no);
        }
        case 3: {
            int parent[] = {
                0, 0, 0, 1, 1
            };
            int dist[] = {
                1, 1, 1, 1, 1
            };
            int maxDist = 2;
            int __expected = 2;
            return do_test(to_vector(parent), to_vector(dist), maxDist, __expected, __no);
        }
        case 4: {
            int parent[] = {
                0, 1, 0, 3, 0, 5, 0, 6, 0, 6, 0, 6, 4, 6, 9, 4, 5, 5, 2, 5, 2
            };
            int dist[] = {
                93, 42, 104, 105, 59, 73, 161, 130, 30, 81, 62, 93, 131, 133, 139, 5, 13, 34, 25, 111, 4
            };
            int maxDist = 162;
            int __expected = 11;
            return do_test(to_vector(parent), to_vector(dist), maxDist, __expected, __no);
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
    cout << "Ethernet (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1401858653;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
