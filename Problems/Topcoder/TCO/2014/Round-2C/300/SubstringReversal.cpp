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

class SubstringReversal {
    public:
    vector<pii > vec;
    string s;
    vector<int> solve(string S){
        s = S;
        int n = sz(s);
        vec.clear();
        repf (i, 0, n-1) vec.pb (mp ((int)s[i], i));
        sort (all (vec));
        int p1 = 0, p2 = 0;
        while (1){
            if (vec[p1].y == p2) ++ p1, ++ p2;
            else{
                ++ p2; break;
            }
            if (p1 >= n) break;
        }
        vi ans; ans.pb (0); ans.pb (0);
        if (p1 == p2) return ans;
        ans[0] = p1; ans[1] = vec[p1].y;
        repf (i, p1+1, n-1){
            if (vec[i].x != vec[i-1].x) break;
            if (xiao (vec[i].y, ans[1], ans[0])) ans[1] = vec[i].y;
        }
        return ans;
    }
    bool xiao(int t1, int t2, int t0){
        int tmp = t2;
        while (t1 >= t0 && t2 >= t0){
            if (s[t1] < s[t2]) return 1;
            if (s[t1] > s[t2]) return 0;
            t2 += (t2 <= tmp ? -1 : 1); -- t1;
            if (t2 < t0) t2 = tmp + 1;
        }
        return 0;
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

bool do_test(string S, vector<int> __expected, int caseNo) {

    time_t startClock = clock();
    SubstringReversal *instance = new SubstringReversal();
    vector<int> __result = instance->solve(S);
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
            string S = "aaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzaaaaaaijrstuwxyzabcdefghijklmnopqrstuwxyzaaaaabbbbbbcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyzabcdefghijklmnopqrstuwxyz";
            int __expected[] = {
                6, 155
            };
            return do_test(S, to_vector(__expected), __no);
        }
        case 1: {
            string S = "xazxa";
            int __expected[] = {
                0, 6
            };
            return do_test(S, to_vector(__expected), __no);
        }
        case 2: {
            string S = "misof";
            int __expected[] = {
                0, 4
            };
            return do_test(S, to_vector(__expected), __no);
        }
        case 3: {
            string S = "ivan";
            int __expected[] = {
                0, 2
            };
            return do_test(S, to_vector(__expected), __no);
        }
        case 4: {
            string S = "thisseemstobeaneasyproblem";
            int __expected[] = {
                0, 13
            };
            return do_test(S, to_vector(__expected), __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "SubstringReversal (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1404576125;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
