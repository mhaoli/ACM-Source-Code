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
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x)*(x))
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) cout<<#x<<":"<<(x)<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class TwoEntrances {
        public:
                int count(vector<int> a, vector<int> b, int s1, int s2);
};

const int Max_N = 3333;
const long long mod = 1e9 + 7;

void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}

int C[Max_N][Max_N];

void C_init(int n) {
        C[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
                C[i][0] = 1;
                for(int j = 1; j <= i; ++j) {
                        C[i][j] = C[i-1][j];
                        add(C[i][j], C[i-1][j-1]);
                }
        }
}

bool off[Max_N];
vector<int> E[Max_N], pat;
int fa[Max_N], dp[Max_N], sz[Max_N], siz[Max_N][Max_N], f[Max_N][Max_N];

void dfs(int x) {
        for(int i : E[x]) if(i != fa[x]) {
                fa[i] = x;
                dfs(i);
        }
}

void DP(int x) {
        dp[x] = sz[x] = 1;
        for(int i : E[x]) if(i != fa[x] && !off[i]) {
                DP(i);
                sz[x] += sz[i];
        }

        int tot = sz[x] - 1;
        for(int i : E[x]) if(i != fa[x] && !off[i]) {
                dp[x] = dp[x] * (1ll * dp[i] * C[tot][sz[i]] % mod) % mod;
                tot -= sz[i];
        }
}

int calc(int s, int t, int ret, int p) {
        int tot = siz[s][t] + sz[p] - 1;
        ret = 1ll * ret * C[tot][siz[s][t]] % mod;
        tot -= siz[s][t];
        for(int i : E[p]) if(i != fa[p] && !off[i]) {
                ret = ret * (1ll * dp[i] * C[tot][sz[i]] % mod) % mod;
                tot -= sz[i];
        }
        return ret;
}

int solve(int s, int t) {
        if(s == t) return dp[pat[s]];
        int &ret = f[s][t];
        if(~ret) return ret;
        ret = calc(s + 1, t, solve(s+1, t), pat[s]);
        add(ret, calc(s, t - 1, solve(s, t - 1), pat[t]));
        return ret;
}

int TwoEntrances::count(vector<int> a, vector<int> b, int s1, int s2){
        //string yes = "Possible", no = "Impossible"       
        int n = SZ(a) + 1;
        C_init(n);
        pat.clear();
        memset(off, 0, sizeof off);
        memset(dp, -1, sizeof dp);
        memset(f, -1, sizeof f);
        for(int i = 0; i < n; ++i) E[i].clear();

        for(int i = 0; i < SZ(a); ++i) {
                E[a[i]].push_back(b[i]);
                E[b[i]].push_back(a[i]);
        }

        fa[s1] = -1;
        dfs(s1);
        for(int i = s2; ~i; i = fa[i]) {
                pat.push_back(i);
                off[i] = 1;
        }
        snuke(it, pat) DP(*it);

        int m = SZ(pat);
        for(int i = 0; i < m; ++i) {
                siz[i][i] = sz[pat[i]];
                for(int j = i+1; j < m; ++j) {
                        siz[i][j] = siz[i][j-1] + sz[pat[j]];
                }
        }
        return solve(0, m-1);
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> a, vector<int> b, int s1, int s2, int __expected, int caseNo) {

    time_t startClock = clock();
    TwoEntrances *instance = new TwoEntrances();
    int __result = instance->count(a, b, s1, s2);
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
            int a[] = {
                0, 1, 2
            };
            int b[] = {
                1, 2, 3
            };
            int s1 = 0;
            int s2 = 1;
            int __expected = 4;
            return do_test(to_vector(a), to_vector(b), s1, s2, __expected, __no);
        }
        case 1: {
            int a[] = {
                0, 1, 2
            };
            int b[] = {
                1, 2, 3
            };
            int s1 = 0;
            int s2 = 2;
            int __expected = 9;
            return do_test(to_vector(a), to_vector(b), s1, s2, __expected, __no);
        }
        case 2: {
            int a[] = {
                0, 1, 1, 3, 3, 3, 6, 7, 6
            };
            int b[] = {
                1, 2, 3, 4, 5, 6, 7, 8, 9
            };
            int s1 = 1;
            int s2 = 9;
            int __expected = 16000;
            return do_test(to_vector(a), to_vector(b), s1, s2, __expected, __no);
        }
        case 3: {
            int a[] = {
                0, 0, 1, 2, 3, 1, 2, 0, 6, 5, 10, 10
            };
            int b[] = {
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
            };
            int s1 = 3;
            int s2 = 6;
            int __expected = 310464;
            return do_test(to_vector(a), to_vector(b), s1, s2, __expected, __no);
        }
        case 4: {
            int a[] = {
                0
            };
            int b[] = {
                1
            };
            int s1 = 1;
            int s2 = 0;
            int __expected = 2;
            return do_test(to_vector(a), to_vector(b), s1, s2, __expected, __no);
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
    cout << "TwoEntrances (850 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430458622;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 850 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
