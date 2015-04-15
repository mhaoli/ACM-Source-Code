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

class WolvesAndSheep {
    public:
    int flag[100], idx[100];
    int wol[20], she[20], tw[20], ts[20];
    bool v[100];
    int getmin(vector<string> vec) {
        int ans = inf;
        int n = sz(vec), m = sz(vec[0]);
        repf (sta, 0, (1<<n)-1){
            repf (i, 0, n-2) flag[i] = (sta & (1 << i)) > 0;
            flag[n-1] = 1;

            int num = 0;
            repf (i, 0, n-1) 
                if (flag[i] == 1) idx[i] = num ++;
                else idx[i] = num;

            int cnt = 0;
            clr (v, 0); clr (wol, 0); clr (she, 0);
            repf (j, 0, m-1){
                clr (tw, 0); clr (ts, 0);
                repf (i, 0, n-1){
                    int id = idx[i];
                    if (vec[i][j] == 'W') tw[id] = 1;
                    if (vec[i][j] == 'S') ts[id] = 1;

                    if (flag[i] == 1){
                        //if (n == 8 && sta == 42 && j == 3 && i == 1) 
                            //out (tw[id]), out (ts[id]), out (id), out (wol[id]);

                        if (ts[id] && tw[id]) cnt = inf;
                        else if (ts[id]){
                            she[id] = 1;
                            if (she[id] && wol[id]) v[j] = 1;
                        }
                        else if (tw[id]){
                            wol[id] = 1;
                            if (she[id] && wol[id]) v[j] = 1;
                        }

                        if (v[j]) repf (i, 0, num-1) wol[i] = tw[i], she[i] = ts[i];
                    }
                }
            }

            repf (i, 0, m-1) if (v[i]) ++ cnt;
            //if (n == 8 && sta == 42)
                //repf (i, 0, m-1) tst (i), out (v[i]);
            chmin (ans, cnt + (int)__builtin_popcount(sta));
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
    WolvesAndSheep *instance = new WolvesAndSheep();
    int __result = instance->getmin(field);
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
                "W.WSS",
                "WW.S.",
                ".SSS.",
                "SSS.S",
                ".SS.S"
            };
            int __expected = 2;
            return do_test(to_vector(field), __expected, __no);
        }
        case 1: {
            string field[] = {
                ".....",
                ".....",
                "....."
            };
            int __expected = 0;
            return do_test(to_vector(field), __expected, __no);
        }
        case 2: {
            string field[] = {
                ".SS",
                "...",
                "S..",
                "W.W"
            };
            int __expected = 1;
            return do_test(to_vector(field), __expected, __no);
        }
        case 3: {
            string field[] = {
                "WWWSWWSSWWW",
                "WWSWW.SSWWW",
                "WS.WSWWWWS."
            };
            int __expected = 10;
            return do_test(to_vector(field), __expected, __no);
        }
        case 4: {
            string field[] = {
                ".W.S.W.W",
                "W.W.S.W.",
                ".S.S.W.W",
                "S.S.S.W.",
                ".S.W.W.S",
                "S.S.W.W.",
                ".W.W.W.S",
                "W.W.S.S."
            };
            int __expected = 7;
            return do_test(to_vector(field), __expected, __no);
        }
        case 5: {
            string field[] = {
                "W.SSWWSSSW.SS",
                ".SSSSW.SSWWWW",
                ".WWWWS.WSSWWS",
                "SS.WSS..W.WWS",
                "WSSS.SSWS.W.S",
                "WSS.WS...WWWS",
                "S.WW.S.SWWWSW",
                "WSSSS.SSW...S",
                "S.WWSW.WWSWSW",
                ".WSSS.WWSWWWS",
                "..SSSS.WWWSSS",
                "SSWSWWS.W.SSW",
                "S.WSWS..WSSS.",
                "WS....W..WSS."
            };
            int __expected = 24;
            return do_test(to_vector(field), __expected, __no);
        }
        case 6: {
            string field[] = {
                "WW..SS",
                "WW..SS",
                "......",
                "......",
                "SS..WW",
                "SS..WW"
            };
            int __expected = 2;
            return do_test(to_vector(field), __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "WolvesAndSheep (600 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1397924668;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
