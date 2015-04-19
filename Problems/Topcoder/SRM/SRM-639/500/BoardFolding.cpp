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

class BoardFolding {
        public:
                int howMany(int N, int M, vector<string> compressedPaper);
};

int n, m;

typedef unsigned long long uii;
const uii key = 157;
uii has[255], pre[255], Pow[255], pre2[255];
uii Hash(int l1, int l2) {
        if (!l1) return pre[l2];
        return pre[l2] - pre[l1-1] * Pow[l2-l1+1];
}
uii Hash2(int l1, int l2) {
        if (l2 == m - 1) return pre2[l1];
        return pre2[l1] - pre2[l2+1] * Pow[l2-l1+1];
}

int board[255][255], board2[255][255], dp[255][255];
bool equ[255][255];
int calc() {
        for (int i = 0; i < m; ++i) {
                has[i] = 0;
                for (int j = 0; j < n; ++j)
                        has[i] = has[i] * key + board[j][i];
                pre[i] = has[i];
                if (i) pre[i] += pre[i-1] * key;
                Pow[i] = i ? Pow[i-1] * key : 1;
        }
        Pow[m] = Pow[m-1] * key;

        pre2[m-1] = has[m-1];
        for (int i = m-2; i >= 0; --i) pre2[i] = pre2[i+1] * key + has[i];

        memset (dp, 0, sizeof dp);
        dp[0][m-1] = 1;
        for (int i, j, k, l = m; l > 1; --l) {
                for (i = 0, j = i + l - 1; j < m; ++i, ++j) if (dp[i][j]){
                        for (k = i; k < j; ++k) {
                                if (k - i + 1 < j - k) {
                                        if (Hash(i, k) == Hash2(k+1, 2*k-i+1)) {
                                                dp[k+1][j] = 1;
                                        }
                                } else if (k - i + 1 == j - k) {
                                        if (Hash(i, k) == Hash2(k+1, j)){
                                                dp[i][k] = dp[k+1][j] = 1;
                                        }
                                } else {
                                        if (Hash2(k+1, j) == Hash(2*k-j+1, k)){
                                                dp[i][k] = 1;
                                        }
                                }
                        }
                }
        }
        int ret = 0;
        for (int i = 0; i < m; ++i)
                for (int j = i; j < m; ++j) if (dp[i][j]) ++ret;
        return ret;
}
int Map(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
        if (c == '#') return 62;
        return 63;
}
int BoardFolding::howMany(int N, int M, vector<string> vec){
        //string yes = "Possible", no = "Impossible";
        n = N; m = M;
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                        board[i][j] = (Map(vec[i][j/6]) >> (j % 6)) % 2;
        int ans = calc();
        for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                        board2[i][j] = board[j][i];
        swap (n, m);
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                        board[i][j] = board2[i][j];
        ans *= calc();
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int M, vector<string> compressedPaper, int __expected, int caseNo) {

    time_t startClock = clock();
    BoardFolding *instance = new BoardFolding();
    int __result = instance->howMany(N, M, compressedPaper);
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
            int M = 2;
            string compressedPaper[] = {
                "1",
                "3"
            };
            int __expected = 1;
            return do_test(N, M, to_vector(compressedPaper), __expected, __no);
        }
        case 1: {
            int N = 2;
            int M = 7;
            string compressedPaper[] = {
                "@@",
                "@@"
            };
            int __expected = 84;
            return do_test(N, M, to_vector(compressedPaper), __expected, __no);
        }
        case 2: {
            int N = 4;
            int M = 4;
            string compressedPaper[] = {
                "6",
                "9",
                "9",
                "6"
            };
            int __expected = 9;
            return do_test(N, M, to_vector(compressedPaper), __expected, __no);
        }
        case 3: {
            int N = 6;
            int M = 1;
            string compressedPaper[] = {
                "0",
                "2",
                "6",
                "@",
                "4",
                "A"
            };
            int __expected = 6;
            return do_test(N, M, to_vector(compressedPaper), __expected, __no);
        }
        case 4: {
            int N = 3;
            int M = 3;
            string compressedPaper[] = {
                "0",
                "2",
                "0"
            };
            int __expected = 1;
            return do_test(N, M, to_vector(compressedPaper), __expected, __no);
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
    cout << "BoardFolding (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1417177014;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
