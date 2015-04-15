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
const int mod = 1000000007;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int f[8][3][200111], fs[8][3][200111];
int d[2][222222], s[2][222222];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

class SRMIntermissionPhase {
    public:
    vi sco;
    int countWays(vector<int> Sco, vector<string> vec){
        sco = Sco;
        clr (f, 0); clr (fs, 0); f[0][2][0] = 1;
        rep (i, 1, 7){
            int first = 0;
            int up = 0;
            rep (j, 0, 2) if (i & (1<<j)) up += sco[j];
            rep (j, 0, 2){
                if (!(i & (1<<j))){
                    if (!first) f[i][j][0] = 1, fs[i][j][0] = 1;
                    else{
                        red (k, up, 0){
                            f[i][j][k] = f[i][j-1][k];
                            fs[i][j][k] = fs[i][j-1][k];
                        }
                    }
                }
                else{
                    if (!first){
                        red (k, sco[j], 1){
                            fs[i][j][k] = f[i][j][k] = 1;
                            add (fs[i][j][k], fs[i][j][k+1]);
                        }
                        fs[i][j][0] = fs[i][j][1];
                    }
                    else{
                        red (k, up, first+1){
                            f[i][j][k] = (fs[i][j-1][max (k-sco[j], 0)] - fs[i][j-1][k] + mod) % mod;
                            fs[i][j][k] = f[i][j][k]; add (fs[i][j][k], fs[i][j][k+1]);
                        }
                        red (k, first, 0) fs[i][j][k] = fs[i][j][k+1];
                    }
                    ++ first;
                }
            }
        }

        clr (d, 0); clr (s, 0); 
        pii range = calc (vec[0]);

        int sta = calc_sta (vec[0]);
        red (i, range.y, range.x) d[0][i] = f[sta][2][i], s[0][i] = s[0][i+1], add (s[0][i], d[0][i]);
        red (i, range.x-1, 0) s[0][i] = s[0][i+1];

        //out (s[0][0]);
//
        int now = 0, nxt = 1;
        rep (i, 1, sz (vec)-1){
            clr (d[nxt], 0); clr (s[nxt], 0);
            range = calc (vec[i]);
            sta = calc_sta (vec[i]);
            red (j, range.y, range.x){
                d[nxt][j] = 1LL * s[now][j+1] * f[sta][2][j] % mod;
                add (s[nxt][j], s[nxt][j+1]); add (s[nxt][j], d[nxt][j]);
            }
            red (j, range.x-1, 0) s[nxt][j] = s[nxt][j+1];
//
            //tst (i), out (s[i][0]);
            swap (now, nxt);
        }
        return s[now][0];
    }
    pii calc (string s){
        int mi = 0, mx = 0;
        rep (i, 0, 2) if (s[i] == 'Y') ++ mi, mx += sco[i];
        return mp (mi, mx);
    }
    int calc_sta (string s){
        int ret = 0;
        red (i, 2, 0) ret = (ret<<1) | (s[i] == 'Y');
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> points, vector<string> description, int __expected, int caseNo) {

    time_t startClock = clock();
    SRMIntermissionPhase *instance = new SRMIntermissionPhase();
    int __result = instance->countWays(points, description);
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
            int points[] = {
                25000, 50000, 100000
            };
            string description[] = {
                "YNN",
                "NNN"
            };
            int __expected = 25000;
            return do_test(to_vector(points), to_vector(description), __expected, __no);
        }
        case 1: {
            int points[] = {
                30000, 60000, 90000
            };
            string description[] = {
                "NYN",
                "NYN"
            };
            int __expected = 799969993;
            return do_test(to_vector(points), to_vector(description), __expected, __no);
        }
        case 2: {
            int points[] = {
                25000, 45000, 110000
            };
            string description[] = {
                "NNN",
                "YYY"
            };
            int __expected = 0;
            return do_test(to_vector(points), to_vector(description), __expected, __no);
        }
        case 3: {
            int points[] = {
                25600, 51200, 102400
            };
            string description[] = {
                "NYY",
                "YNY",
                "YYY",
                "YNN",
                "YYN",
                "NNY",
                "NYN",
                "NNN"
            };
            int __expected = 867560805;
            return do_test(to_vector(points), to_vector(description), __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "SRMIntermissionPhase (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408844893;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
