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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi num;
vii pat[105];
int d[105], fa[105];
map<int, int> has[105];

class Egalitarianism3 {
    public:
    int maxCities(int n, vector<int> a, vector<int> b, vector<int> len){
        //string no = "Impossible", yes = "Possible";
        //if (n == 1) return 1;
        int ans = min (n, 2);
        rep (i, 0, n-1) pat[i].clear();
        rep (i, 0, sz (a)-1) add (a[i]-1, b[i]-1, len[i]);

        rep (i, 0, n-1){
            d[i] = 0;
            dfs (i, -1, i);

            rep (j, 0, n-1) has[j].clear();
            rep (j, 0, n-1) if (j != i){
                //if (has[fa[j]].count (d[j])) has[fa[j]][d[j]] ++;
                //else has[fa[j]][d[j]] = 1;
                has[fa[j]][d[j]] = 1;
            }
            rep (j, 1, n*1000){
                int cnt = 0;
                for (auto v : pat[i]){
                    if (has[v.x].count (j)) ++ cnt;
                }
                chmax (ans, cnt);

            }
        }
        return ans;
    }
    void add (int u, int v, int w){
        pat[u].pb (mp (v, w)); pat[v].pb (mp (u, w));
    }
    void dfs (int x, int pre, int rt){
        for (auto v : pat[x]){
            if (v.x == pre) continue;
            d[v.x] = d[x] + v.y;
            fa[v.x] = (pre == -1 ? v.x : rt);
            dfs (v.x, x, pre==-1?v.x:rt);
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, vector<int> a, vector<int> b, vector<int> len, int __expected, int caseNo) {

    time_t startClock = clock();
    Egalitarianism3 *instance = new Egalitarianism3();
    int __result = instance->maxCities(n, a, b, len);
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
            int n = 4;
            int a[] = {
                1, 1, 1
            };
            int b[] = {
                2, 3, 4
            };
            int len[] = {
                1, 1, 1
            };
            int __expected = 3;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 1: {
            int n = 6;
            int a[] = {
                1, 2, 3, 2, 3
            };
            int b[] = {
                2, 3, 4, 5, 6
            };
            int len[] = {
                2, 1, 3, 2, 3
            };
            int __expected = 3;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 2: {
            int n = 10;
            int a[] = {
                1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            int b[] = {
                2, 3, 4, 5, 6, 7, 8, 9, 10
            };
            int len[] = {
                1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000
            };
            int __expected = 9;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 3: {
            int n = 1;
            int a[] = {
                
            };
            int b[] = {
                
            };
            int len[] = {
                
            };
            int __expected = 1;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
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
    cout << "Egalitarianism3 (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408669358;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
