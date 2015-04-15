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
const int inf = 2139062143 / 5;
const int maxn = 1005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int f[maxn];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

class CandyCollection {
    public:
    bool vis[maxn];
    int d[maxn][2], ans[maxn], cnt[maxn];
    vii an[maxn], pat[maxn];
    int solve(vector<int> ty1, vector<int> num1, vector<int> ty2, vector<int> num2){
        int n = sz(ty1);
        repf (i, 0, n-1) an[i].clear(), pat[i].clear();
        repf (i, 0, n-1){
            an[ty1[i]].pb (mp (i, num1[i])); an[ty2[i]].pb (mp (i, num2[i]));
        }

        repf (i, 0, n-1) f[i] = i;

        repf (i, 0, n-1){
            pii t1 = an[i][0], t2 = an[i][1];
            pat[t1.x].pb (mp (t2.x, t1.y)); pat[t2.x].pb (mp (t1.x, t2.y));
            int f1 = find (t1.x), f2 = find (t2.x);
            if (f1 != f2) f[f1] = f2;
        }

        repf (i, 0, n-1) if (pat[i][0].y > pat[i][1].y) swap (pat[i][0], pat[i][1]);

        clr (ans, 127); clr (cnt, 0);
        repf (i, 0, n-1) ++ cnt[find(i)];
        repf (i, 0, n-1) if (i == find(i)){
            if (cnt[i] != 2) clr (vis, 0), calc (i, i, 0);
            else{
                int t = 0;
                repf (j, 0, 1) if (an[ty1[i]][j].x != i) t = an[ty1[i]][j].x;
                if (num1[i] == num2[i] || num1[t] == num2[t]) continue;
                int t1 = num1[i] > num2[i] ? ty1[i] : ty2[i];
                int t2 = num1[t] > num2[t] ? ty1[t] : ty2[t];
                if (t1 != t2) chmin (ans[i], min(num1[i], num2[i]) + min(num1[t], num2[t]) + 2);
            }
        }

        repf (i, 0, n-1){
            clr (vis, 0);
            d[i][0] = inf; d[i][1] = pat[i][1].y + 1;
            dfs (i);
        }

        int ret = 0;
        repf (i, 0, n-1){
            int tf = find (i);
            if (tf == i) ret += ans[tf];
        }
        return ret;
    }
    void dfs (int x){
        vis[x] = 1;
        if (vis[pat[x][0].x] && vis[pat[x][1].x]){
            int fa = find (x);
            chmin (ans[fa], d[x][0]); chmin (ans[fa], d[x][1]);
            return;
        }
        repf (i, 0, 1) if (!vis[pat[x][i].x]){
            int v = pat[x][i].x, c, cc;
            repf (j, 0, 1){
                if (pat[v][j].x == x) c = pat[v][j].y, cc = pat[v][j^1].y;
            }
            if (c == cc){
                d[v][0] = d[x][1];
                d[v][1] = min (d[x][1], d[x][0]) + c + 1;
                dfs (v); return;
            }

            d[v][0] = d[x][1];
            if (c > cc) chmin (d[v][0], d[x][0] + cc + 1);

            if (c > cc) d[v][1] = min (d[x][1], d[x][0]) + c + 1;
            else d[v][1] = d[x][1] + c + 1, chmin (d[v][1], min (d[x][0], d[x][1]) + cc + 1);

            dfs (v); return;
        }
    }
    void calc (int fa, int x, int s){
        vis[x] = 1;
        if (pat[x][0].y == pat[x][1].y) return;
        if (vis[pat[x][1].x]){
            if (pat[x][1].x == fa && vis[pat[x][0].x]) chmin (ans[ find(x) ], s + pat[x][0].y + 1);
            return;
        }
        calc (fa, pat[x][1].x, s + pat[x][0].y + 1);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> Type1, vector<int> Number1, vector<int> Type2, vector<int> Number2, int __expected, int caseNo) {

    time_t startClock = clock();
    CandyCollection *instance = new CandyCollection();
    int __result = instance->solve(Type1, Number1, Type2, Number2);
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
            int Type1[] = {
                0, 0
            };
            int Number1[] = {
                3, 100
            };
            int Type2[] = {
                1, 1
            };
            int Number2[] = {
                4, 101
            };
            int __expected = 2137;
            return do_test(to_vector(Type1), to_vector(Number1), to_vector(Type2), to_vector(Number2), __expected, __no);
        }
        case 1: {
            int Type1[] = {
                3, 5, 3, 0, 2, 5
            };
            int Number1[] = {
                148, 557, 623, 725, 556, 934
            };
            int Type2[] = {
                1, 0, 2, 4, 1, 4
            };
            int Number2[] = {
                163, 226, 958, 341, 909, 621
            };
            int __expected = 1741;
            return do_test(to_vector(Type1), to_vector(Number1), to_vector(Type2), to_vector(Number2), __expected, __no);
        }
        case 2: {
            int Type1[] = {
                0, 0, 2, 3
            };
            int Number1[] = {
                1, 1, 2, 2
            };
            int Type2[] = {
                1, 1, 3, 2
            };
            int Number2[] = {
                1, 1, 2, 2
            };
            int __expected = 5;
            return do_test(to_vector(Type1), to_vector(Number1), to_vector(Type2), to_vector(Number2), __expected, __no);
        }
        case 3: {
            int Type1[] = {
                0, 1, 2, 3
            };
            int Number1[] = {
                5, 5, 10, 13
            };
            int Type2[] = {
                1, 2, 3, 0
            };
            int Number2[] = {
                8, 8, 10, 15
            };
            int __expected = 20;
            return do_test(to_vector(Type1), to_vector(Number1), to_vector(Type2), to_vector(Number2), __expected, __no);
        }
        case 4: {
            int Type1[] = {
                12, 9, 0, 16, 9, 18, 12, 3, 6, 0, 8, 2, 10, 6, 5, 2, 14, 10, 5, 13
            };
            int Number1[] = {
                895, 704, 812, 323, 334, 674, 665, 142, 712, 254, 869, 548, 645, 663, 758, 38, 860, 724, 742, 530
            };
            int Type2[] = {
                1, 4, 7, 11, 15, 8, 18, 13, 17, 17, 19, 14, 7, 11, 4, 1, 15, 19, 3, 16
            };
            int Number2[] = {
                779, 317, 36, 191, 843, 289, 107, 41, 943, 265, 649, 447, 806, 891, 730, 371, 351, 7, 102, 394
            };
            int __expected = 5101;
            return do_test(to_vector(Type1), to_vector(Number1), to_vector(Type2), to_vector(Number2), __expected, __no);
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
    cout << "CandyCollection (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407857014;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
