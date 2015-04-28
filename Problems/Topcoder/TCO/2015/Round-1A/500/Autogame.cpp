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

class Autogame {
        public:
                int wayscnt(vector<int> a, int K);
};

const int mod = 1000000007;
vector<int> A;
int f[111];

int find(int x) {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
}

int K, cnt[111];
bool vis[111], flag;
void dfs(int t1, int t2, int tk) {
        if(t1 == t2) {
                flag = 1; return;
        }
        if(vis[t1] || tk >= K) return;
        vis[t1] = 1;
        dfs(A[t1], A[t2], tk+1);
}

int Autogame::wayscnt(vector<int> a, int KK){
        //string yes = "Possible", no = "Impossible";
        A = a; K = KK;
        for(auto&i : A) --i;
        int n = A.size();
        //vector<vector<bool> > G(n);
        for(int i = 0; i < n; ++i) f[i] = i;
        for(int i = 0, j; i < n; ++i) {
                for(j = i+1; j < n; ++j) if(find(i) != find(j)){
                        flag = 0;
                        memset(vis, 0, sizeof vis);
                        dfs(i, j, 0);
                        if(flag) {
                                f[find(i)] = find(j);
                        }
                }
        }
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; ++i) ++cnt[find(i)];
        int ans = 1;
        for(int i = 0; i < n; ++i) if(find(i) == i) ans = ans * (cnt[i] + 1ll) % mod;
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> a, int K, int __expected, int caseNo) {

    time_t startClock = clock();
    Autogame *instance = new Autogame();
    int __result = instance->wayscnt(a, K);
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
                1, 2, 3
            };
            int K = 5;
            int __expected = 8;
            return do_test(to_vector(a), K, __expected, __no);
        }
        case 1: {
            int a[] = {
                1, 1, 1
            };
            int K = 1;
            int __expected = 4;
            return do_test(to_vector(a), K, __expected, __no);
        }
        case 2: {
            int a[] = {
                2, 1
            };
            int K = 42;
            int __expected = 4;
            return do_test(to_vector(a), K, __expected, __no);
        }
        case 3: {
            int a[] = {
                2, 3, 4, 3
            };
            int K = 3;
            int __expected = 9;
            return do_test(to_vector(a), K, __expected, __no);
        }
        case 4: {
            int a[] = {
                4, 4, 3, 2, 1
            };
            int K = 3;
            int __expected = 18;
            return do_test(to_vector(a), K, __expected, __no);
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
    cout << "Autogame (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430125632;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
