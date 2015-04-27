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

class TheTreeAndMan {
        public:
                int solve(vector<int> parent);
};

const int Max_N = 2222;
const long long mod = 1000000007;

int fac[Max_N], inv[Max_N], fac_inv[Max_N];

void init(int n) {
        fac_inv[0] = fac_inv[1] = inv[1] = fac[1] = 1;
        for(int i = 2; i <= n; ++i) {
                fac[i] = (long long)fac[i-1] * i % mod;
                inv[i] = (long long)(mod - mod / i) * inv[mod%i] % mod;
                fac_inv[i] = (long long)fac_inv[i-1] * inv[i] % mod;
        }
}

void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}

long long C(int n, int m) {
        return ((long long)fac[n] * fac_inv[m] % mod) * fac_inv[n-m] % mod;
}

int fa[Max_N], sz[Max_N], dif[Max_N];
vector<int> son[Max_N];
int dp[Max_N][10];

void dfs(int x) { 
        sz[x] = 1;
        dif[x] = 0;
        snuke(it, son[x]) if(*it != fa[x]) {
                dfs(*it);
                sz[x] += sz[*it];
                add(dif[x], (sz[*it] * (sz[*it] - 1ll) % mod) * inv[2] % mod);
        }
}

long long calc(int last, int t1, int t2) {
        int cnt = sz[t1] - 1 - sz[last];
        if(t2 == 1) return 1;
        if(t2 == 2) {
                if(cnt < 2) return 0;
                int ret = C(cnt, 2);
                add(ret, mod - dif[t1]);
                add(ret, (sz[last] * (sz[last] - 1ll) % mod) * inv[2] % mod);
                return ret;
        } else {
                if(cnt < 1) return 0;
                return C(cnt, 1);
        }
}

int TheTreeAndMan::solve(vector<int> parent){
        //string yes = "Possible", no = "Impossible";
        int n = parent.size() + 1;
        init(n);
        memset(son, 0, sizeof son);
        memset(sz, 0, sizeof sz);
        for(int i = 0; i < n; ++i) {
                fa[i] = i ? parent[i-1] : -1;
                if(i) son[fa[i]].push_back(i);
        }
        dfs(0);
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; ++i) dp[i][1] = 1;
        for(int i = 1, j, k, last; i < n; ++i) {
                for(j = fa[i], last = i; ~j; last = j, j = fa[j]) {
                        for(k = 1; k < 4; ++k) if(dp[j][k]) {
                                add(dp[i][k+1], dp[j][k] * calc(last, j, k) % mod);
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) add(ans, dp[i][4]);
        return (int)((long long)ans * inv[2] % mod);
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> parent, int __expected, int caseNo) {

    time_t startClock = clock();
    TheTreeAndMan *instance = new TheTreeAndMan();
    int __result = instance->solve(parent);
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
                0, 1, 1, 1, 4, 4
            };
            int __expected = 1;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 1: {
            int parent[] = {
                0, 0, 2, 2, 2, 4, 0, 4, 7, 2, 10, 11, 9, 0, 1, 0
            };
            int __expected = 7;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 2: {
            int parent[] = {
                0, 0, 2, 2, 3, 1, 0, 1, 5
            };
            int __expected = 0;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 3: {
            int parent[] = {
                0, 0, 0, 2, 3, 5, 2, 5, 3, 7, 7, 7, 2
            };
            int __expected = 3;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 4: {
            int parent[] = {
                0, 0, 1, 2, 2, 2, 1, 4, 2, 9, 0, 1, 5
            };
            int __expected = 0;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 5: {
            int parent[] = {
                0, 0, 0, 2, 4, 2, 5, 6, 5, 9, 5, 0, 3, 8, 8, 15, 0, 17, 9
            };
            int __expected = 3;
            return do_test(to_vector(parent), __expected, __no);
        }
        case 6: {
            int parent[] = {
                0, 0, 0, 3, 0, 1, 3, 5, 6, 8, 2, 7, 1, 9, 1, 5, 13, 6, 3, 7, 8, 4, 2, 18, 12, 11, 17, 13, 10, 25, 11, 26, 22, 32, 32, 18, 35, 33, 25, 31, 24, 38, 41, 34, 43, 42, 32, 43, 31, 35, 47, 49, 36, 35, 39, 42, 36, 39, 47, 53, 40, 61, 60, 43, 47, 61, 51, 56, 67, 69, 53, 53, 63, 56, 71, 55, 76, 73, 70, 74, 67, 76, 64, 80, 68, 85, 78, 69, 79, 73, 70, 75, 77, 81, 80, 94, 85, 88, 88, 99, 83, 99, 93, 90, 85, 100, 89, 96, 96, 103, 107, 96, 105, 95, 100, 97, 97
            };
            int __expected = 9864;
            return do_test(to_vector(parent), __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "TheTreeAndMan (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430116621;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
