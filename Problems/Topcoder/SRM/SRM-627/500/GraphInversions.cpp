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
#define lowbit(x) ((x)&(-x))
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
const int maxn = 1005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int c[maxn];

void add(int x, int d)
{
    while (x <= 1000) c[x] += d, x += lowbit(x);
}

int sum(int x)
{
    int ret = 0;
    while (x > 0) ret += c[x], x -= lowbit(x);
    return ret;
}


class GraphInversions {
    public:
    vi pat[maxn], V;
    int k, ans, vis[maxn];
    int getMinimumInversions(vector<int> A, vector<int> B, vector<int> VV, int K) {
        k = K; V = VV;
        int n = sz(A);
        repf (i, 0, n-1) pat[i].clear();
        repf (i, 0, n-1) pat[A[i]].pb (B[i]), pat[B[i]].pb (A[i]);

        ans = inf;
        clr (c, 0); clr (vis, 0);
        repf (i, 0, n-1){
            add (V[i], 1);
            dfs (i, 1, 0);
            add (V[i], -1);
        }
        return ans == inf ? -1 : ans;
    }
    void dfs (int x, int all, int num){
        if (all == k){
            chmin (ans, num); return;
        }

        vis[x] = 1;
        repf (i, 0, sz(pat[x])-1){
            int v = pat[x][i];
            if (vis[v]) continue;
            int tmp = sum (V[v]-1);
            add (V[v], 1);
            dfs (v, all+1, num+tmp);
            add (V[v], -1);
        }
        vis[x] = 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> A, vector<int> B, vector<int> V, int K, int __expected, int caseNo) {

    time_t startClock = clock();
    GraphInversions *instance = new GraphInversions();
    int __result = instance->getMinimumInversions(A, B, V, K);
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
            int A[] = {
                0, 1, 2
            };
            int B[] = {
                1, 2, 0
            };
            int V[] = {
                40, 50, 60
            };
            int K = 3;
            int __expected = 0;
            return do_test(to_vector(A), to_vector(B), to_vector(V), K, __expected, __no);
        }
        case 1: {
            int A[] = {
                0, 1, 2, 3
            };
            int B[] = {
                1, 2, 3, 0
            };
            int V[] = {
                60, 40, 50, 30
            };
            int K = 3;
            int __expected = 1;
            return do_test(to_vector(A), to_vector(B), to_vector(V), K, __expected, __no);
        }
        case 2: {
            int A[] = {
                0, 1, 2, 3, 0
            };
            int B[] = {
                1, 2, 3, 0, 4
            };
            int V[] = {
                10, 10, 10, 5, 5
            };
            int K = 5;
            int __expected = 1;
            return do_test(to_vector(A), to_vector(B), to_vector(V), K, __expected, __no);
        }
        case 3: {
            int A[] = {
                0, 1, 2, 3, 0, 2
            };
            int B[] = {
                1, 2, 3, 0, 4, 5
            };
            int V[] = {
                10, 2, 5, 3, 7, 1
            };
            int K = 6;
            int __expected = -1;
            return do_test(to_vector(A), to_vector(B), to_vector(V), K, __expected, __no);
        }
        case 4: {
            int A[] = {
                5, 7, 7, 5, 5, 7, 6, 4
            };
            int B[] = {
                2, 0, 2, 0, 1, 4, 7, 3
            };
            int V[] = {
                15, 10, 5, 30, 22, 10, 5, 2
            };
            int K = 6;
            int __expected = 3;
            return do_test(to_vector(A), to_vector(B), to_vector(V), K, __expected, __no);
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
    cout << "GraphInversions (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405005948;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
