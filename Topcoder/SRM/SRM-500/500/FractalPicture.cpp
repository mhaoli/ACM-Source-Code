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

class FractalPicture {
    public:
    double ans, tmp;
    int x1, x2, y1, y2;
    double getLength(int X1, int Y1, int X2, int Y2) {
        x1 = X1; y1 = Y1; x2 = X2; y2 = Y2;
        ans = 0; tmp = 0;
        double tseg = (double)1 / 3;
        repf (i, 6, 500) tmp += tseg + calc (tseg, i), tseg /= 3;
        dfs (mp (0, 0), mp (0, 81), 1);
        return ans;
    }
    double calc (double p, int idx){
        if (idx == 500) return 0;
        return p * 2 / 3 + 3 * calc (p/3, idx+1);
    }
    void dfs(pii a, pii b, int idx){
        pii c;
        int len = ask_len (a, b);
        if (a.x == b.x){
            c.x = a.x;
            if (a.y < b.y) c.y = b.y - len / 3;
            else c.y = b.y + len / 3;
        }
        else{
            c.y = a.y;
            if (a.x < b.x) c.x = b.x - len / 3;
            else c.x = b.x + len / 3;
        }

        if (a.x == b.x && x1 <= a.x && x2 >= a.x && len > 1){
            int mi = min (a.y, c.y), ma = max (a.y, c.y);
            ans += max (0, min (y2, ma) - max (y1, mi));
        }
        if (a.y == b.y && y1 <= a.y && y2 >= a.y && len > 1){
            int mi = min (a.x, c.x), ma = max (a.x, c.x);
            ans += max (0, min (x2, ma) - max (x1, mi));
        }

        if (len > 1){
            if (a.x == b.x){
                dfs (c, b, idx+1); 
                dfs (c, mp (c.x-len/3, c.y), idx+1);
                dfs (c, mp (c.x+len/3, c.y), idx+1);
            }
            else{
                dfs (c, b, idx+1);
                dfs (c, mp (c.x, c.y+len/3), idx+1);
                dfs (c, mp (c.x, c.y-len/3), idx+1);
            }
            return ;
        }
        
        if (a.x == b.x){
            int u1 = 0, u2 = 0;
            if (ok (a.x-1, min (a.y, b.y), a.x, max (a.y, b.y))) u1 = 1;
            if (ok (a.x, min (a.y, b.y), a.x+1, max (a.y, b.y))) u2 = 1;
            ans += (u1 + u2) * tmp;
            if (u1 || u2) ans += (double)1;
        }
        else{
            int u1 = 0, u2 = 0;
            if (ok (min (a.x, b.x), a.y-1, max (a.x, b.x), a.y)) u1 = 1;
            if (ok (min (a.x, b.x), a.y, max (a.x, b.x), a.y+1)) u2 = 1;
            ans += (u1 + u2) * tmp;
            if (u1 || u2) ans += (double)1;
        }
    }
    int ask_len (pii a, pii b){
        if (a.x == b.x) return abs (a.y - b.y);
        return abs (a.x - b.x);
    }
    bool ok (int t1, int p1, int t2, int p2){
        if (t1 >= x1 && p1 >= y1 && t2 <= x2 && p2 <= y2) return 1;
        return 0;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(int x1, int y1, int x2, int y2, double __expected, int caseNo) {

    time_t startClock = clock();
    FractalPicture *instance = new FractalPicture();
    double __result = instance->getLength(x1, y1, x2, y2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            int x1 = -1;
            int y1 = 0;
            int x2 = 1;
            int y2 = 53;
            double __expected = 53.0;
            return do_test(x1, y1, x2, y2, __expected, __no);
        }
        case 1: {
            int x1 = 1;
            int y1 = 1;
            int x2 = 10;
            int y2 = 10;
            double __expected = 0.0;
            return do_test(x1, y1, x2, y2, __expected, __no);
        }
        case 2: {
            int x1 = -10;
            int y1 = 54;
            int x2 = 10;
            int y2 = 55;
            double __expected = 21.0;
            return do_test(x1, y1, x2, y2, __expected, __no);
        }
        case 3: {
            int x1 = 14;
            int y1 = 45;
            int x2 = 22;
            int y2 = 54;
            double __expected = 2999.0;
            return do_test(x1, y1, x2, y2, __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FractalPicture (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402319714;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
