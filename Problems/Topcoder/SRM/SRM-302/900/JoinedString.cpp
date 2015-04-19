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

vs vec;
int num[20][20], d[5000][20], vis[20];

class JoinedString {
    public:
    string joinWords(vector<string> words){
        vec.clear();
        repf (i, 0, sz(words)-1) vis[i] = 1;
        repf (i, 0, sz(words)-1) if (vis[i]){
            repf (j, 0, sz(words)-1) if (i != j && vis[j] && inside (words[i], words[j])) vis[i] = 0;
            if (vis[i]) vec.pb (words[i]);
        }

        clr (num, 0);
        int n = sz(vec);
        repf (i, 0, n-1) repf (j, 0, n-1) if (i != j) num[i][j] = calc (vec[i], vec[j]);

        clr (d, 127);
        repf (i, 1, (1<<n)-1) repf (j, 0, n-1) if (i & (1<<j)){
            int cnt = __builtin_popcount(i);
            if (cnt == 1) d[i][j] = sz(vec[j]);

            repf (k, 0, n-1) if (!(i & (1<<k))){
                chmin (d[i|(1<<k)][k], d[i][j] + sz(vec[k]) - num[k][j]);
            }
        }

        //repf (i, 1, (1<<n)-1){
            //cout << i << " : ";
            //repf (j, 0, n-1) tst (d[i][j]);
            //cout << endl;
        //}

        int mi = inf, sta = (1<<n) - 1, pos = -1;
        repf (i, 0, n-1) chmin (mi, d[sta][i]);
        string ans;
        repf (i, 0, n-1) if (d[sta][i] == mi){
            if (pos == -1) ans = vec[i], pos = i;
            else if (ans > vec[i]) ans = vec[i], pos = i;
        }
        int cnt = n-1;
        while (cnt){
            string best;
            int opt = -1;
            repf (i, 0, n-1) if ((sta & (1<<i)) && d[sta][pos] == d[sta^(1<<pos)][i] + sz(vec[pos]) - num[pos][i]){
                string tmp = vec[i].substr (num[pos][i], sz(vec[i])-num[pos][i]);
                if (opt == -1) best = tmp, opt = i;
                else if (best > tmp) best = tmp, opt = i;
            }
            sta ^= (1 << pos); pos = opt; ans += best; -- cnt;
        }
        return ans;
    }
    int calc (string s1, string s2){
        int ret = 0, mi = min (sz(s1), sz(s2));
        repf (i, 1, mi){
            bool u = 1;
            for (int p1 = sz(s1)-i, p2 = 0; p2 < i; ++ p1, ++ p2)
                if (s1[p1] != s2[p2]){ u = 0; break;}
            if (u) ret = i;
        }
        return ret;
    }
    bool inside (string s1, string s2){
        int n = sz(s1);
        repf (i, 0, sz(s2)-n) if (s1 == (s2.substr (i, n))) return 1;
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> words, string __expected, int caseNo) {

    time_t startClock = clock();
    JoinedString *instance = new JoinedString();
    string __result = instance->joinWords(words);
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
            string words[] = {
                "BAB",
                "ABA"
            };
            string __expected = "ABAB";
            return do_test(to_vector(words), __expected, __no);
        }
        case 1: {
            string words[] = {
                "ABABA",
                "AKAKA",
                "AKABAS",
                "ABAKA"
            };
            string __expected = "ABABAKAKABAS";
            return do_test(to_vector(words), __expected, __no);
        }
        case 2: {
            string words[] = {
                "AAA",
                "BBB",
                "CCC",
                "ABC",
                "BCA",
                "CAB"
            };
            string __expected = "AAABBBCABCCC";
            return do_test(to_vector(words), __expected, __no);
        }
        case 3: {
            string words[] = {
                "OFG",
                "SDOFGJTILM",
                "KBWNF",
                "YAAPO",
                "AWX",
                "VSEAWX",
                "DOFGJTIL",
                "YAA"
            };
            string __expected = "KBWNFSDOFGJTILMVSEAWXYAAPO";
            return do_test(to_vector(words), __expected, __no);
        }
        case 4: {
            string words[] = {
                "NVCSKFLNVS",
                "HUFSPMRI",
                "FLNV",
                "KMQD",
                "RPJK",
                "NVSQORP",
                "UFSPMR",
                "AIHUFSPMRI"
            };
            string __expected = "AIHUFSPMRINVCSKFLNVSQORPJKMQD";
            return do_test(to_vector(words), __expected, __no);
        }
        case 5: {
            string words[] = {
                "STRING",
                "RING"
            };
            string __expected = "STRING";
            return do_test(to_vector(words), __expected, __no);
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
    cout << "JoinedString (900 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405350637;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
