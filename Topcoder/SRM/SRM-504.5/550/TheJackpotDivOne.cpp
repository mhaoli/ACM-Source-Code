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
typedef long double ld;
typedef vector<int64> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

class TheJackpotDivOne {
    public:
    vector<long long> find(vector<long long> an, long long sum){
        int n = sz(an);
        while (1){
            sort (all (an));
            if (an[0] == an.back() || !sum) break;
            int64 tmp = 0, yu = 0;
            for (auto i : an){
                tmp += i / n;
                yu += i % n;
                tmp += yu / n; yu %= n;
            }
            
            ++ tmp;
            if (tmp - an[0] <= sum) sum -= tmp - an[0], an[0] = tmp;
            else an[0] += sum, sum = 0;
        }

        if (sum){
            int64 tmp = sum / n; sum %= n;

            for (int64 &i : an) i += tmp;
            repf (i, 0, sum-1) ++an[i];
        }
        sort (all (an));
        return an;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(vector<long long> money, long long jackpot, vector<long long> __expected, int caseNo) {

    time_t startClock = clock();
    TheJackpotDivOne *instance = new TheJackpotDivOne();
    vector<long long> __result = instance->find(money, jackpot);
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
            long long money[] = 
                {805372452334228772LL, 323831522355545557LL, 222318376157839320LL, 890540141938216941LL};
            long long jackpot = 732581373992282617LL;
            long long __expected[] = {
                633666337549555264LL, 645064934956112230LL, 805372452334228772LL, 890540141938216941LL
            };
            return do_test(to_vector(money), jackpot, to_vector(__expected), __no);
        }
        case 1: {
            long long money[] = {
                4LL
            };
            long long jackpot = 7LL;
            long long __expected[] = {
                11LL
            };
            return do_test(to_vector(money), jackpot, to_vector(__expected), __no);
        }
        case 2: {
            long long money[] = {
                4LL, 44LL, 7LL, 77LL
            };
            long long jackpot = 47LL;
            long long __expected[] = {
                24LL, 34LL, 44LL, 77LL
            };
            return do_test(to_vector(money), jackpot, to_vector(__expected), __no);
        }
        case 3: {
            long long money[] = {
                4LL, 10LL, 8LL, 3LL, 6LL, 5LL, 8LL, 3LL, 7LL, 5LL
            };
            long long jackpot = 1000LL;
            long long __expected[] = {
                105LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL
            };
            return do_test(to_vector(money), jackpot, to_vector(__expected), __no);
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
    cout << "TheJackpotDivOne (550 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405136191;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
