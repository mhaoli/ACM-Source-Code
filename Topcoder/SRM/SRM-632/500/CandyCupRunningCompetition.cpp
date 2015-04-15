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

class CandyCupRunningCompetition {
    public:
    int findMaximum(int N, vector<int> A, vector<int> B);
};

const int64 mod = 1000000007;
bool vis[2222];
int64 tre[2222];
int f[2222];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

int CandyCupRunningCompetition::findMaximum(int n, vector<int> A, vector<int> B){
    //string yes = "Possible", no = "Impossible";
    int m = sz (A), ans = 0;

    tre[0] = 1;
    rep (i, 1, m-1) tre[i] = tre[i-1] * 3 % mod;

    red (i, m-1, 0){
        vis[i] = 1;
        rep (j, 0, n-1) f[j] = j;
        red (j, m-1, i) if (vis[j]){
            int t1 = find (A[j]), t2 = find (B[j]);
            if (t1 != t2) f[t1] = t2;
        }

        if (find (0) == find (n-1)){
            vis[i] = 0;
            ans = (ans + tre[i]) % mod;
        }
    }
    return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<int> A, vector<int> B, int __expected, int caseNo) {

    time_t startClock = clock();
    CandyCupRunningCompetition *instance = new CandyCupRunningCompetition();
    int __result = instance->findMaximum(N, A, B);
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
            int N = 3;
            int A[] = {
                0, 1
            };
            int B[] = {
                1, 2
            };
            int __expected = 1;
            return do_test(N, to_vector(A), to_vector(B), __expected, __no);
        }
        case 1: {
            int N = 4;
            int A[] = {
                0, 1, 0, 2
            };
            int B[] = {
                1, 3, 2, 3
            };
            int __expected = 10;
            return do_test(N, to_vector(A), to_vector(B), __expected, __no);
        }
        case 2: {
            int N = 3;
            int A[] = {
                0
            };
            int B[] = {
                1
            };
            int __expected = 0;
            return do_test(N, to_vector(A), to_vector(B), __expected, __no);
        }
        case 3: {
            int N = 5;
            int A[] = {
                
            };
            int B[] = {
                
            };
            int __expected = 0;
            return do_test(N, to_vector(A), to_vector(B), __expected, __no);
        }
        case 4: {
            int N = 6;
            int A[] = {
                1, 1, 2, 0, 4, 3, 0, 1, 4
            };
            int B[] = {
                3, 2, 3, 1, 5, 5, 2, 4, 3
            };
            int __expected = 39;
            return do_test(N, to_vector(A), to_vector(B), __expected, __no);
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
    cout << "CandyCupRunningCompetition (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1410101834;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
