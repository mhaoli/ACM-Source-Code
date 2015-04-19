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

class Nine {
        public:
                int count(int N, vector<int> d);
};

const long long mod = 1000000007;
const int Max_M = 5555;

int cnt[Max_M][10], m;
int dp[35][60000], dig[10];
//int status[59050][32][10];

void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}

int trans(int sta, int p, int d) {
        if(!d) return sta;
        //int &ret = status[sta][p][d];
        //if(ret != -1) return ret;
        int ret = 0;
        int pos = 0;
        while(pos < m) {
                dig[pos] = sta % 9;
                if(p & 1) dig[pos] = (dig[pos] + d) % 9;
                p >>= 1;
                pos++;
                sta /= 9;
        }
        //ret = 0;
        while(pos > 0) {
                ret = ret * 9 + dig[--pos];
        }
        return ret;
}

int Nine::count(int _m, vector<int> vec){
        //string yes = "Possible", no = "Impossible";
        m = _m;
        int n = vec.size();
        memset(cnt, 0, sizeof cnt);
        cnt[0][0] = 1;
        for(int i = 0, j, k; i < n; ++i) {
                for(j = 0; j < 10; ++j) 
                        for(k = 0; k < 10; ++k) 
                                add(cnt[i+1][(j+k)%9], cnt[i][j]);
        }
        sort(vec.begin(), vec.end());
        vec.push_back(-1); ++n;
        int idx = 0, up = 1;
        for(int i = 0; i < m; ++i) up *= 9;
        memset(dp, 0, sizeof dp);
        //memset(status, -1, sizeof status);
        dp[0][0] = 1;
        for(int i = 0, t = 0, j, tmp, k; i < n; ++i) {
                if(i && vec[i] != vec[i-1]) {
                        for(j = 0; j < 9; ++j) {
                                for(k = 0; k < up; ++k) {
                                        add(dp[idx+1][trans(k, vec[i-1], j)], (long long)dp[idx][k] * cnt[t][j] % mod);
                                }
                        }
                        ++idx;
                        t = 1;
                } else ++t;
        }
        return dp[idx][0];
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<int> d, int __expected, int caseNo) {

    time_t startClock = clock();
    Nine *instance = new Nine();
    int __result = instance->count(N, d);
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
            int N = 2;
            int d[] = {
                1, 2
            };
            int __expected = 4;
            return do_test(N, to_vector(d), __expected, __no);
        }
        case 1: {
            int N = 2;
            int d[] = {
                1, 2, 3
            };
            int __expected = 16;
            return do_test(N, to_vector(d), __expected, __no);
        }
        case 2: {
            int N = 1;
            int d[] = {
                0, 0, 1
            };
            int __expected = 200;
            return do_test(N, to_vector(d), __expected, __no);
        }
        case 3: {
            int N = 5;
            int d[] = {
                1, 3, 5, 8, 24, 22, 25, 21, 30, 2, 4, 0, 6, 7, 9, 11, 14, 13, 12, 15, 18, 17, 16, 19, 26, 29, 31, 28, 27, 10, 20, 23
            };
            int __expected = 450877328;
            return do_test(N, to_vector(d), __expected, __no);
        }
        case 4: {
            int N = 5;
            int d[] = {
                31, 31, 31, 31, 31
            };
            int __expected = 11112;
            return do_test(N, to_vector(d), __expected, __no);
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
    cout << "Nine (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1429266692;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
