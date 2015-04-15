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
const int inf = 100000;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

class FourBears {
    public:
    vs bod;
    int n, m, N, dis[360][360], bn[4];
    int cost (int x, int y){
        if (x < 0 || x >= n || y < 0 || y >= m) return -1;
        if ((y == 0 || y == m-1) && bod[x][y] != 'B') return -1;
        if (bod[x][y] == '.') return 1;
        return 0;
    }
    int cost (int x){
        return cost (x/m, x%m);
    }
    int clearPassages(vector<string> _bod) {
        bod = _bod;
        n = sz(bod); m = sz(bod[0]); N = n * m;
        repf (i, 0, N-1) repf (j, 0, N-1)
            if (i != j) dis[i][j] = inf;
            else dis[i][j] = cost(i) == -1 ? inf : 0;
        repf (i, 0, n-1) repf (j, 0, m-1) repf (k, 0, 3){
            int tx = i + dx[k], ty = j + dy[k];
            if (cost(tx, ty) != -1) dis[i*m+j][tx*m+ty] = cost (tx, ty);
        }
        repf (k, 0, N-1) repf (i, 0, N-1) repf (j, 0, N-1) chmin (dis[i][j], dis[i][k]+dis[k][j]);
        //repf (i, 0, N-1) repf (j, 0, N-1) if (dis[i][j] < inf){
            //tst (i/m), tst (i%m), tst (j/m), tst (j%m), out (dis[i][j]);
        //}

        int tidx = 0;
        repf (i, 0, N-1) if (bod[i/m][i%m] == 'B') bn[tidx++] = i;

        int ans = inf;
        repf (i, 0, N-1) repf (j, 0, N-1) if (cost (i) != -1 && cost(j) != -1){
            chmin (ans, dis[bn[0]][i] + dis[bn[1]][i] + dis[bn[2]][j] + dis[bn[3]][j] - cost(i) - cost(j) + dis[i][j] - cost(j));
            chmin (ans, dis[bn[0]][i] + dis[bn[2]][i] + dis[bn[1]][j] + dis[bn[3]][j] - cost(i) - cost(j) + dis[i][j] - cost(j));
            chmin (ans, dis[bn[0]][i] + dis[bn[3]][i] + dis[bn[2]][j] + dis[bn[1]][j] - cost(i) - cost(j) + dis[i][j] - cost(j));
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> field, int __expected, int caseNo) {

    time_t startClock = clock();
    FourBears *instance = new FourBears();
    int __result = instance->clearPassages(field);
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
            string field[] = {
                "B.X...............",
                "..X..XXXXXXXXXX..B",
                "B.X..X........X...",
                ".....X........X...",
                "..XXXX........X..B"
            };
            int __expected = 7;
            return do_test(to_vector(field), __expected, __no);
        }
        case 1: {
            string field[] = {
                "..................",
                "B..........XXXX..B",
                "..........X.......",
                "....XXXXXX........",
                "..........XX......",
                "B............XX..B",
                ".................."
            };
            int __expected = 15;
            return do_test(to_vector(field), __expected, __no);
        }
        case 2: {
            string field[] = {
                "B.B",
                "...",
                "B.B"
            };
            int __expected = 3;
            return do_test(to_vector(field), __expected, __no);
        }
        case 3: {
            string field[] = {
                "..B",
                "B.B",
                "B.."
            };
            int __expected = 1;
            return do_test(to_vector(field), __expected, __no);
        }
        case 4: {
            string field[] = {
                "B..................XX.................XX.XXX.....B",
                "...XXXXX.....XXXX......XXXXX.....XXXX..XXX.XXXX...",
                "............XX..................XX................",
                ".......XXX........XX..X....XXX...........XXX......",
                "............XXX......X.XXX......XXX.XXX..X.XXX....",
                "....XXXX......XXX...X...XXXX......XXX.XXXX........",
                "B..XX..............XX............................B"
            };
            int __expected = 28;
            return do_test(to_vector(field), __expected, __no);
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
    cout << "FourBears (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405440951;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
