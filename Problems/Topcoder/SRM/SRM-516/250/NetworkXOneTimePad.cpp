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

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class NetworkXOneTimePad {
    public:
        int crack(vector<string> s1, vector<string> s2) {
            set<string> has(all (s1));
            set<string> ans;
            for (string t1 : s1) for (string t2 : s2) ans.insert (calc (t1, t2));

            int ret = 0;
            for (auto &t : ans){
                bool u = 0;
                for (auto t2 : s2){
                    string tmp = calc (t, t2);
                    if (!has.count (tmp)){
                        u = 1; break;
                    }
                }
                if (!u) ++ ret;
            }
            return ret;
        }
        string calc (string s, string t){
            string ret;
            repf (i, 0, sz(s)-1){
                int t1 = s[i] - '0', t2 = t[i] - '0';
                ret.pb ((t1^t2) + '0');
            }
            return ret;
        }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> plaintexts, vector<string> ciphertexts, int __expected, int caseNo) {

    time_t startClock = clock();
    NetworkXOneTimePad *instance = new NetworkXOneTimePad();
    int __result = instance->crack(plaintexts, ciphertexts);
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
            string plaintexts[] = {
                "110",
                "001"
            };
            string ciphertexts[] = {
                "101",
                "010"
            };
            int __expected = 2;
            return do_test(to_vector(plaintexts), to_vector(ciphertexts), __expected, __no);
        }
        case 1: {
            string plaintexts[] = {
                "00",
                "01",
                "10",
                "11"
            };
            string ciphertexts[] = {
                "00",
                "01",
                "10",
                "11"
            };
            int __expected = 4;
            return do_test(to_vector(plaintexts), to_vector(ciphertexts), __expected, __no);
        }
        case 2: {
            string plaintexts[] = {
                "01",
                "10"
            };
            string ciphertexts[] = {
                "00"
            };
            int __expected = 2;
            return do_test(to_vector(plaintexts), to_vector(ciphertexts), __expected, __no);
        }
        case 3: {
            string plaintexts[] = {
                "000",
                "111",
                "010",
                "101",
                "110",
                "001"
            };
            string ciphertexts[] = {
                "011",
                "100"
            };
            int __expected = 6;
            return do_test(to_vector(plaintexts), to_vector(ciphertexts), __expected, __no);
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
    cout << "NetworkXOneTimePad (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407405321;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
