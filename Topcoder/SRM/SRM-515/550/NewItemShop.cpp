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

int id[30];
pii qn[30];
vi tim[30], cn[30];
vd pn[30];
double d[26][1<<12][26];

class NewItemShop {
    public:
    double getMaximum(int m, vector<string> vec) {
        int n = sz(vec);
        repf (i, 0, n-1){
            tim[i].clear(); cn[i].clear(); pn[i].clear();
            stringstream ss(vec[i]);
            char buf[100];
            while (ss >> buf){
                int t0, t1, t2;
                sscanf (buf, "%d,%d,%d", &t0, &t1, &t2);
                tim[i].pb (t0); cn[i].pb (t1); pn[i].pb (t2 / 100.0);
            }
        }

        repf (i, 0, n-1){
            double sum = 0;
            for (auto &j : pn[i]){
                double t = j;
                j /= (1.0 - sum);
                sum += t;
            }
        }

        int tot = 0;
        clr (id, -1);
        repf (i, 0, n-1) if (sz (tim[i]) > 1) id[i] = tot++;
        repf (i, 0, 23) qn[i] = mp (-1, -1);
        repf (i, 0, n-1) repf (j, 0, sz(tim[i])-1) qn[tim[i][j]] = mp (i, j);

        clr (d, 0);
        int up = (1 << tot) - 1;
        repd (i, 23, 0) repf (j, 0, up) repf (k, 0, m){
            pii t = qn[i];
            if (t.x == -1 || !k){
                d[i][j][k] = d[i+1][j][k];
            }
            else if (id[t.x] == -1){
                double tmp = d[i+1][j][k-1] + cn[t.x][t.y];
                chmax (tmp, d[i+1][j][k]);
                d[i][j][k] = tmp * pn[t.x][t.y] + (1 - pn[t.x][t.y]) * d[i+1][j][k];
            }
            else if (j & (1 << id[t.x])){
                d[i][j][k] = d[i+1][j][k];
            }
            else{
                double tmp = d[i+1][j|(1<<id[t.x])][k-1] + cn[t.x][t.y];
                chmax (tmp, d[i+1][j|(1<<id[t.x])][k]);
                d[i][j][k] += pn[t.x][t.y] * tmp + (1 - pn[t.x][t.y]) * d[i+1][j][k];
            }
        }
        return d[0][0][m];
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(int swords, vector<string> customers, double __expected, int caseNo) {

    time_t startClock = clock();
    NewItemShop *instance = new NewItemShop();
    double __result = instance->getMaximum(swords, customers);
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
            int swords = 11;
            string customers[] = {
                "0,1,33 12,2,33", "1,3,33 13,4,33", "2,5,33 14,6,33", "3,7,33 15,8,33", "4,9,33 16,10,33", "5,11,33 17,12,33", "6,13,33 18,14,33", "7,15,33 19,16,33", "8,17,33 20,18,33", "9,19,33 21,20,33", "10,21,33 22,22,33", "11,23,33 23,24,33"
            };
            double __expected = 19.0;
            return do_test(swords, to_vector(customers), __expected, __no);
        }
        case 1: {
            int swords = 2;
            string customers[] = {
                "8,1,80 16,100,11",
                "12,10,100"
            };
            double __expected = 21.8;
            return do_test(swords, to_vector(customers), __expected, __no);
        }
        case 2: {
            int swords = 1;
            string customers[] = {
                "0,90,25 2,90,25 4,90,25 6,90,25",
                "7,100,80"
            };
            double __expected = 90.0;
            return do_test(swords, to_vector(customers), __expected, __no);
        }
        case 3: {
            int swords = 3;
            string customers[] = {
                "17,31,41 20,59,26 23,53,5",
                "19,89,79",
                "16,32,38 22,46,26",
                "18,43,38 21,32,7"
            };
            double __expected = 135.5121414;
            return do_test(swords, to_vector(customers), __expected, __no);
        }
        case 4: {
            int swords = 5;
            string customers[] = {
                "1,1,10",
                "2,2,9",
                "3,3,8",
                "4,4,7",
                "5,5,6",
                "6,6,5",
                "7,7,4",
                "8,8,3",
                "9,9,2",
                "10,10,1"
            };
            double __expected = 2.1999744634845344;
            return do_test(swords, to_vector(customers), __expected, __no);
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
    cout << "NewItemShop (550 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407401053;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
