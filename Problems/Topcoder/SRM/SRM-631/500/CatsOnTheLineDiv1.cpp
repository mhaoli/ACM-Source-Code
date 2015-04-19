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
#define two(x) (1<<(x))
#define twol(x) (1LL<<(x))
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

vii vec;
int d[1005];
int pos[1005], pre[1005];

class CatsOnTheLineDiv1 {
    public:
    int getNumber(vector<int> an, vector<int> bn, int L){
        //string no = "Impossible", yes = "Possible";
        vec.clear ();
        int n = sz (an);
        rep (i, 0, n-1) vec.pb (mp (an[i], bn[i]));
        sort (all (vec));

        int p = 0, ans = 0;
        while (p < n){
            int mx = vec[p].x - L - 1;
            for (; p < n; ++ p){
                int mi = mx + 1; chmax (mi, vec[p].x - L);
                mx = mi + vec[p].y - 1;
                if (mx > vec[p].x + L) break;
            }

            if (p >= n) break;
            ++ ans;
            int tpos = p ++;
            while (p < n && vec[p].x - L <= vec[tpos].x + L) ++ p;
        }
        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> position, vector<int> count, int time, int __expected, int caseNo) {

    time_t startClock = clock();
    CatsOnTheLineDiv1 *instance = new CatsOnTheLineDiv1();
    int __result = instance->getNumber(position, count, time);
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
        //case 0: {
            //int position[] = {
                //-839, 175, 78, 638, -186, 305, -742, 29, -216, 8, 315, 562, 154, -439, -881, -503, -17, -866, -690, -681, -58, 953, -733, 614, -127, 944, 842, -443, -538, -282, -104, -688, 736, 694, -269, -750, 858, 973, -620, 459, 77, 882, -929, 364, -981, -436, 867, 291, -802, 498
            //};
            //int count[] = {
                //49, 10, 92, 120, 43, 56, 97, 26, 131, 140, 51, 93, 82, 101, 18, 35, 12, 123, 82, 34, 137, 73, 13, 8, 74, 39, 152, 151, 127, 9, 91, 29, 109, 67, 56, 96, 152, 117, 115, 120, 154, 81, 50, 67, 33, 63, 130, 27, 24, 78
            //};
            //int time = 97;
            //int __expected = 1012;
            //return do_test(to_vector(position), to_vector(count), time, __expected, __no);
        //}
        case 0: {
            int position[] = {
                0
            };
            int count[] = {
                7
            };
            int time = 3;
            int __expected = 0;
            return do_test(to_vector(position), to_vector(count), time, __expected, __no);
        }

        case 1: {
            int position[] = {
                0
            };
            int count[] = {
                6
            };
            int time = 2;
            int __expected = 1;
            return do_test(to_vector(position), to_vector(count), time, __expected, __no);
        }
        case 2: {
            int position[] = {
                4, 7, 47
            };
            int count[] = {
                4, 7, 4
            };
            int time = 1;
            int __expected = 3;
            return do_test(to_vector(position), to_vector(count), time, __expected, __no);
        }
        case 3: {
            int position[] = {
                3, 0, 7, 10
            };
            int count[] = {
                3, 7, 4, 5
            };
            int time = 2;
            int __expected = 2;
            return do_test(to_vector(position), to_vector(count), time, __expected, __no);
        }
        case 4: {
            int position[] = {
                -5, 0, 7
            };
            int count[] = {
                47, 85, 10
            };
            int time = 6;
            int __expected = 1;
            return do_test(to_vector(position), to_vector(count), time, __expected, __no);
        }
        case 5: {
            int position[] = {
                -8, 12, -15, -20, 17, -5, 7, 10
            };
            int count[] = {
                20, 10, 7, 9, 2, 8, 11, 10
            };
            int time = 2;
            int __expected = 5;
            return do_test(to_vector(position), to_vector(count), time, __expected, __no);
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
    cout << "CatsOnTheLineDiv1 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409415407;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

