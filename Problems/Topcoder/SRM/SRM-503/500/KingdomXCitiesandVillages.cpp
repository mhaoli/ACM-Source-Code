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

class KingdomXCitiesandVillages {
    public:
    vector<pair<int64, int> > vec;
    vi anx, any, bnx, bny;
    double determineLength(vector<int> anX, vector<int> anY, vector<int> bnX, vector<int> bnY){
        anx = anX; any = anY; bnx = bnX; bny = bnY;
        double ret = 0;
        int n = sz(anx), m = sz(bnx);
        repf (i, 0, m-1){
            vec.clear();
            repf (j, 0, n-1) vec.pb (mp (dis (bnx[i], bny[i], anx[j], any[j]), 1));
            repf (j, 0, m-1) if (i != j) vec.pb (mp (dis (bnx[i], bny[i], bnx[j], bny[j]), 0));
            sort (all (vec));

            double sum = 1;
            repf (k, 0, sz(vec)-1){
                double d = sqrt (vec[k].x + 0.0);
                if (vec[k].y == 1){
                    ret += sum * d; break;
                }
                else{
                    double tmp = 1.0 / (k+2) / (k+1);
                    sum -= tmp; ret += d * tmp;
                }
            }
        }
        return ret;
    }
    int64 dis (int64 x1, int64 y1, int64 x2, int64 y2){
        return (sqr (x1 - x2) + sqr (y1 - y2));
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<int> cityX, vector<int> cityY, vector<int> villageX, vector<int> villageY, double __expected, int caseNo) {

    time_t startClock = clock();
    KingdomXCitiesandVillages *instance = new KingdomXCitiesandVillages();
    double __result = instance->determineLength(cityX, cityY, villageX, villageY);
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
            int cityX[] = {
                3
            };
            int cityY[] = {
                0
            };
            int villageX[] = {
                3, 3
            };
            int villageY[] = {
                2, 1
            };
            double __expected = 2.5;
            return do_test(to_vector(cityX), to_vector(cityY), to_vector(villageX), to_vector(villageY), __expected, __no);
        }
        case 1: {
            int cityX[] = {
                1, 4, 7, 10
            };
            int cityY[] = {
                5, 5, 5, 5
            };
            int villageX[] = {
                1, 4, 7, 10
            };
            int villageY[] = {
                4, 4, 4, 4
            };
            double __expected = 4.0;
            return do_test(to_vector(cityX), to_vector(cityY), to_vector(villageX), to_vector(villageY), __expected, __no);
        }
        case 2: {
            int cityX[] = {
                1, 2, 3
            };
            int cityY[] = {
                4, 4, 4
            };
            int villageX[] = {
                4, 5, 6
            };
            int villageY[] = {
                4, 4, 4
            };
            double __expected = 4.166666666666667;
            return do_test(to_vector(cityX), to_vector(cityY), to_vector(villageX), to_vector(villageY), __expected, __no);
        }

        // Your custom testcase goes here
        case 3:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "KingdomXCitiesandVillages (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 3; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1402834538;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
