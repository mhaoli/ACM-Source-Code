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

bool cmp (pii a, pii b){
    return a.y > b.y;
}

class HappyLetterDiv1 {
    public:
    int num[1000];
    vector<pii > vec;
    string getHappyLetters(string s) {
        vec.clear();
        int n = sz(s);
        clr (num, 0);
        repf (i, 0, n-1) num[s[i]-'a'] ++;
        repf (i, 0, 25) if (num[i]) vec.pb (mp (i, num[i]));
        sort (all (vec), cmp);
        
        int m = n / 2;
        string ret;
        if (vec[0].y > m){
            ret.pb (char(vec[0].x + 'a'));
        }
        else if (vec[0].y == m){
            if (n & 1){
                repf (i, 0, sz(vec)-1) if (vec[i].y > 0) ret.pb (char(vec[i].x + 'a')); 
            }
            else{
                if (sz(vec) == 2) ret.clear();
                else{
                    ret.pb (char(vec[0].x + 'a'));
                }
            }
        }
        else{
            int tmp = (n & 1) ? 0 : 1;
            repf (i, 0, sz(vec)-1) if (vec[i].y > tmp) ret.pb (char(vec[i].x + 'a'));
        }
        sort (all (ret));
        return ret;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string letters, string __expected, int caseNo) {

    time_t startClock = clock();
    HappyLetterDiv1 *instance = new HappyLetterDiv1();
    string __result = instance->getHappyLetters(letters);
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
            string letters = "abc";
            string __expected = "abc";
            return do_test(letters, __expected, __no);
        }
        case 1: {
            string letters = "aaaaaaaccdd";
            string __expected = "a";
            return do_test(letters, __expected, __no);
        }
        case 2: {
            string letters = "ddabccadb";
            string __expected = "abcd";
            return do_test(letters, __expected, __no);
        }
        case 3: {
            string letters = "aaabbb";
            string __expected = "";
            return do_test(letters, __expected, __no);
        }
        case 4: {
            string letters = "rdokcogscosn";
            string __expected = "cos";
            return do_test(letters, __expected, __no);
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
    cout << "HappyLetterDiv1 (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405004496;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
