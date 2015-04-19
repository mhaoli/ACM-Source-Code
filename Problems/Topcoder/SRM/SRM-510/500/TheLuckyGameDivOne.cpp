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
typedef vector<pii > vii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

bool cmp (pair<int64, vii > a, pair<int64, vii > b){
    return a.x < b.x;
}

class TheLuckyGameDivOne {
    public:
    int64 a, b, l1, l2;
    vector<int64> num;
    map<int64, int> an;
    map<int64, vii > bn;
    map<int, int> ans;
    vector<pair<int64, int> > cha1;
    vector<pair<int64, vii > > cha2;
    int find(long long _a, long long _b, long long L2, long long L1){
        a = _a; b = _b; l1 = L1; l2 = L2;
        num.clear(); dfs (0LL); sort (all (num));

        //for (auto x : num) out (x);

        int64 l = l1;
        an.clear();
        for (auto x : num){
            if(x + l <= b){
                if (an.count (x+1)) an[x+1] -= 1;
                else an[x+1] = -1;
            }

            int64 pos = x + 1 - l; chmax (pos, a);
            if (an.count (pos)) an[pos] += 1;
            else an[pos] = 1;
        }
        cha1.clear();
        if (!an.count (a)) cha1.pb (mp (a, 0));
        for (auto x : an) cha1.pb (x); sort (all (cha1));
        int tmp = 0;
        for (auto &x : cha1) x.y += tmp, tmp = x.y;

        //for (auto x : cha1) tst (x.x), out (x.y);

        l = l2 - l1 + 1;
        bn.clear();
        repf (i, 0, sz(cha1)-1){
            auto x = cha1[i];
            if (i && x.x + l2 - 1 <= b){
                if (bn.count (x.x)) bn[x.x].pb (mp (cha1[i-1].y, -1));
                else{
                    vii ttmp; ttmp.pb (mp (cha1[i-1].y, -1));
                    bn[x.x] = ttmp;
                }
            }
            int64 pos = x.x + 1 - l; chmax (pos, a);
            if (bn.count (pos)) bn[pos].pb (mp (x.y, 1));
            else{
                vii ttmp; ttmp.pb (mp (x.y, 1));
                bn[pos] = ttmp;
            }
        }
        cha2.clear();
        for (auto x : bn) cha2.pb (x); sort (all (cha2), cmp);

        //repf (i, 0, sz(cha2)-1){
            //cout << cha2[i].x << " : " << endl;
            //for (auto x : cha2[i].y) tst (x.x), out (x.y);
        //}

        int ret = 0;
        ans.clear();
        for (auto tt : cha2){
            for (auto ttmp : tt.y){
                if (ttmp.y < 0){
                    ans[ttmp.x] --;
                    if (ans[ttmp.x] == 0) ans.erase (ttmp.x);
                }
                else{
                    if (ans.count (ttmp.x)) ans[ttmp.x] ++;
                    else ans[ttmp.x] = 1;
                }
            }
            for (auto ttmp : ans){
                chmax (ret, ttmp.x); break;
            }
            //if (ret == 2) out (tt.x);
        }
        return ret;
    }
    void dfs(int64 x){
        if (x > b) return;
        if (x >= a) num.pb (x);
        dfs (x*10+4); dfs (x*10+7);
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(long long a, long long b, long long jLen, long long bLen, int __expected, int caseNo) {

    time_t startClock = clock();
    TheLuckyGameDivOne *instance = new TheLuckyGameDivOne();
    int __result = instance->find(a, b, jLen, bLen);
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
            long long a = 3224LL;
            long long b = 4554LL;
            long long jLen = 334LL;
            long long bLen = 151LL;
            int __expected = 0;
            //long long a = 1LL;
            //long long b = 10LL;
            //long long jLen = 2LL;
            //long long bLen = 1LL;
            //int __expected = 0;
            return do_test(a, b, jLen, bLen, __expected, __no);
        }
        case 1: {
            long long a = 1LL;
            long long b = 100LL;
            long long jLen = 100LL;
            long long bLen = 100LL;
            int __expected = 6;
            return do_test(a, b, jLen, bLen, __expected, __no);
        }
        case 2: {
            long long a = 4LL;
            long long b = 8LL;
            long long jLen = 3LL;
            long long bLen = 2LL;
            int __expected = 1;
            return do_test(a, b, jLen, bLen, __expected, __no);
        }
        case 3: {
            long long a = 1LL;
            long long b = 100LL;
            long long jLen = 75LL;
            long long bLen = 50LL;
            int __expected = 2;
            return do_test(a, b, jLen, bLen, __expected, __no);
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
    cout << "TheLuckyGameDivOne (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405522260;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
