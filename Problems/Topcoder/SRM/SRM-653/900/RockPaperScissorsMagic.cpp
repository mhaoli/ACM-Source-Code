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

class RockPaperScissorsMagic {
        public:
                int count(int win, int lose, int tie, vector<int> card);
};

const long long mod = 1e9 + 7;

void add(int &a, int b) {
        a += b; if(a >= mod) a -= mod;
}

struct oo;

int W, L, T;
int C[1005][1005];
map<oo, int>::iterator it;

void C_init(int n) {
        C[1][0] = C[1][1] = C[0][0] = 1;
        for(int i = 2; i <= n; ++i) {
                C[i][0] = 1;
                for(int j = 1; j <= i; ++j) {
                        C[i][j] = C[i-1][j];
                        add(C[i][j], C[i-1][j-1]);
                }
        }
}

struct oo {
        int x, y, z;
        bool operator<(const oo&t) const {
                if(x != t.x) {
                        return x < t.x;
                } else {
                        if(y != t.y) {
                                return y < t.y;
                        } else {
                                return z < t.z;
                        }
                }
        }
};

oo calc(int t1, int t2, int t3) {
        oo ret;
        ret.x = t1 * T + t2 * W + t3 * L;
        ret.y = t2 * T + t3 * W + t1 * L;
        ret.z = t3 * T + t1 * W + t2 * L;
        return ret;
}

void calc(int n, map<oo, int> &has) {
        int t1, t2, t3, cnt;
        oo score;
        has.clear();
        for(int i = 0, k; i <= n; ++i) {
                for(int j = 0; i + j <= n; ++j) {
                        k = n - i - j;
                        t1 = i - k; t2 = k - j; t3 = j - i;
                        score = calc(t1, t2, t3);
                        cnt = 1LL * C[n][i] * C[n-i][j] % mod;

                        it = has.find(score);
                        if(it != has.end()) add(cnt, it->second);
                        has[score] = cnt;
                }
        }

        //if(n == 1) {
        //for(auto i : has) printf("%d %d\n", i.first, i.second);
        //puts("");
        //}
}

int cnt[3];
map<oo, int> has[3];

int RockPaperScissorsMagic::count(int win, int lose, int tie, vector<int> card){
        //string yes = "Possible", no = "Impossible";
        C_init(SZ(card));
        W = win; L = lose; T = tie;
        memset(cnt, 0, sizeof cnt);
        for(int i : card) ++cnt[i];
        for(int i = 0; i < 3; ++i) calc(cnt[i], has[i]);

        int ans = 0;
        long long tmp;
        for(auto &i : has[0]) {
                tmp = i.second;
                for(int j = 1; j < 3; ++j) {
                        it = has[j].find(i.first);
                        if(it == has[j].end()) tmp = 0;
                        else tmp = tmp * it->second % mod;
                }
                add(ans, tmp);
        }
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int win, int lose, int tie, vector<int> card, int __expected, int caseNo) {

    time_t startClock = clock();
    RockPaperScissorsMagic *instance = new RockPaperScissorsMagic();
    int __result = instance->count(win, lose, tie, card);
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
            int win = 2;
            int lose = 0;
            int tie = 1;
            int card[] = {
                0, 1, 2
            };
            int __expected = 3;
            return do_test(win, lose, tie, to_vector(card), __expected, __no);
        }
        case 1: {
            int win = 2;
            int lose = 0;
            int tie = 1;
            int card[] = {
                0, 0, 0
            };
            int __expected = 6;
            return do_test(win, lose, tie, to_vector(card), __expected, __no);
        }
        case 2: {
            int win = 0;
            int lose = 0;
            int tie = 0;
            int card[] = {
                1, 0, 2, 2, 2, 0
            };
            int __expected = 729;
            return do_test(win, lose, tie, to_vector(card), __expected, __no);
        }
        case 3: {
            int win = 514;
            int lose = 451;
            int tie = 145;
            int card[] = {
                0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2
            };
            int __expected = 0;
            return do_test(win, lose, tie, to_vector(card), __expected, __no);
        }
        case 4: {
            int win = 3;
            int lose = 6;
            int tie = 9;
            int card[] = {
                0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2
            };
            int __expected = 2336040;
            return do_test(win, lose, tie, to_vector(card), __expected, __no);
        }
        case 5: {
            int win = 514;
            int lose = 451;
            int tie = 145;
            int card[] = {
                0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2
            };
            int __expected = 116100;
            return do_test(win, lose, tie, to_vector(card), __expected, __no);
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
    cout << "RockPaperScissorsMagic (900 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430749482;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
