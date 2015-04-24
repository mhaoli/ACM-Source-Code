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

class PermutationCounts {
        public:
                int countPermutations(int N, vector<int> pos);
};

const long long mod = 1000000007;
const int Max_N = 9 + (int)1e6;

int fac[Max_N], inv[Max_N], fac_inv[Max_N], dp[Max_N];

long long powmod(long long p, int n) {
        long long ret = 1;
        while(n) {
                if(n & 1) ret = ret * p % mod;
                else p = p * p % mod;
                n >>= 1;
        }
        return ret;
}

long long C(int n, int m) {
        return (long long)fac[n] * fac_inv[m] % mod * fac_inv[n-m] % mod;
}
void add(int &a, int b) {
        if(b < 0) {
                add(a, mod + b);
        } else {
                a += b; if(a >= mod) a -= mod;
        }
}

int PermutationCounts::countPermutations(int N, vector<int> pos){
        //string yes = "Possible", no = "Impossible";
        fac_inv[0] = fac_inv[1] = inv[1] = fac[1] = 1;
        for(int i = 2; i <= N; ++i) {
                fac[i] = (long long)fac[i-1] * i % mod;
                inv[i] = (long long)(mod - mod / i) * inv[mod%i] % mod;
                fac_inv[i] = (long long)fac_inv[i-1] * inv[i] % mod;
        }
        //if(N == 5) for(int i = 1; i <= N; ++i) 
                //printf("%d %d %d\n", fac[i], inv[i], fac_inv[i]);
        pos.push_back(0); pos.push_back(N);
        std::sort(pos.begin(), pos.end());
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 1, j; i < (int)pos.size(); ++i) {
                for(j = i-1; j >= 0; --j) {
                        if((j - i - 1) & 1) add(dp[i], mod - dp[j] * C(N - pos[j], pos[i] - pos[j]) % mod);
                        else add(dp[i], dp[j] * C(N - pos[j], pos[i] - pos[j]) % mod);
                }
        }
        return dp[(int)pos.size()-1];
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<int> pos, int __expected, int caseNo) {

    time_t startClock = clock();
    PermutationCounts *instance = new PermutationCounts();
    int __result = instance->countPermutations(N, pos);
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
            int N = 5;
            int pos[] = {
                3
            };
            int __expected = 9;
            return do_test(N, to_vector(pos), __expected, __no);
        }
        case 1: {
            int N = 13;
            int pos[] = {
                12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
            };
            int __expected = 1;
            return do_test(N, to_vector(pos), __expected, __no);
        }
        case 2: {
            int N = 13;
            int pos[] = {
                
            };
            int __expected = 1;
            return do_test(N, to_vector(pos), __expected, __no);
        }
        case 3: {
            int N = 9;
            int pos[] = {
                2, 4, 5
            };
            int __expected = 1421;
            return do_test(N, to_vector(pos), __expected, __no);
        }
        case 4: {
            int N = 80;
            int pos[] = {
                31, 41, 59, 26, 53, 58, 9, 79, 32, 3, 8, 46
            };
            int __expected = 82650786;
            return do_test(N, to_vector(pos), __expected, __no);
        }
        case 5: {
            int N = 875;
            int pos[] = {
                295, 311, 98, 345, 420, 547, 646, 734, 380, 325, 608, 783, 141, 65, 305, 437, 769, 252, 44, 872, 123, 6, 50, 507, 450, 426, 343, 740, 69, 695, 101, 607, 597, 535, 342, 307, 329, 837, 803, 237, 459, 444, 498, 15, 712, 134, 473, 14, 715, 223, 787, 192, 710, 750, 193, 293, 242, 652, 212, 580, 545, 488, 506, 533, 774, 460, 285, 534, 350, 210, 559, 805, 686, 67, 159, 541, 706, 514, 657, 801, 373, 754, 310, 800, 589, 736, 863, 675, 254, 283, 604, 27, 628, 103, 81, 235, 677, 461, 609, 30, 581, 75, 756, 688, 262, 563, 679, 21, 217, 515, 836, 868, 13, 728, 717, 309, 267, 767, 259, 414, 332, 744, 129, 859, 4, 179, 632, 415, 278, 812, 79, 77, 784, 573, 433, 865, 407, 121, 477, 567, 790, 127, 593, 57, 674, 114, 239, 599, 552, 738
            };
            int __expected = 169176190;
            return do_test(N, to_vector(pos), __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "PermutationCounts (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1429323710;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
