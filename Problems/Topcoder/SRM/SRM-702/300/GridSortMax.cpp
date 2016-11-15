#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#include <cassert>
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define all(v) (v).begin(), (v).end()
#define unq(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define mem(f,x) memset((f), (x), sizeof(f))
#define clr(f) mem(f,0)
#define SZ(v) ((int)(v).size())
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<pair<int,pii > > viii;

class GridSortMax {
        public:
        string findMax(int n, int m, vector<int> grid);
};

int col[55], row[55], colinv[55], rowinv[55];

string GridSortMax::findMax(int n, int m, vector<int> grid) {
        vii pos(n * m + 1);
        rep(i, 0, n) rep(j, 0, m) {
                pos[grid[i*m+j]] = mp(i, j);
        }
        mem(col, -1); mem(colinv, -1); mem(row, -1); mem(rowinv, -1);
        string ans;
        rep(i, 0, n) rep(j, 0, m) {
                pii p = pos[i * m + j + 1];
                if((row[i] == -1 || row[i] == p.x) && (col[j] == -1 || col[j] == p.y) && (rowinv[p.x] == -1 || rowinv[p.x] == i) && (colinv[p.y] == -1 || colinv[p.y] == j)) {
                        row[i] = p.x; col[j] = p.y;
                        rowinv[p.x] = i; colinv[p.y] = j;
                        ans.pb('1');
                } else {
                        ans.pb('0');
                }
        }
        return ans;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string to_str(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int m, vector<int> grid, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GridSortMax *instance = new GridSortMax();
    string __result = instance->findMax(n, m, grid);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_str(__expected) << endl;
        cout << "           Received: " << to_str(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int n = 2;
            int m = 2;
            int grid[] = {
                1,
                2,
                3,
                4
            };
            string __expected = "1111";
            return do_test(n, m, to_vector(grid), __expected, __no);
        }
        case 1: {
            int n = 2;
            int m = 2;
            int grid[] = {
                2,
                1,
                3,
                4
            };
            string __expected = "1100";
            return do_test(n, m, to_vector(grid), __expected, __no);
        }
        case 2: {
            int n = 2;
            int m = 2;
            int grid[] = {
                4,
                2,
                3,
                1
            };
            string __expected = "1001";
            return do_test(n, m, to_vector(grid), __expected, __no);
        }
        case 3: {
            int n = 1;
            int m = 10;
            int grid[] = {
                10,
                6,
                2,
                3,
                5,
                7,
                1,
                9,
                4,
                8
            };
            string __expected = "1111111111";
            return do_test(n, m, to_vector(grid), __expected, __no);
        }
        case 4: {
            int n = 3;
            int m = 5;
            int grid[] = {
                5,
                2,
                10,
                7,
                9,
                3,
                4,
                14,
                11,
                1,
                15,
                12,
                6,
                8,
                13
            };
            string __expected = "101100100100000";
            return do_test(n, m, to_vector(grid), __expected, __no);
        }
        case 5: {
            int n = 6;
            int m = 2;
            int grid[] = {
                3,
                9,
                5,
                1,
                10,
                6,
                2,
                7,
                8,
                11,
                12,
                4
            };
            string __expected = "100000101010";
            return do_test(n, m, to_vector(grid), __expected, __no);
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
    
    bool mainProcess = true;
    set<int> testCases;
    for (int i = 1; i < argc; i++) {
        if ( string(argv[i]) == "-" ) {
            mainProcess = false;
        } else {
            testCases.insert( atoi(argv[i]) );
        }
    }
    if (testCases.size() == 0) {
        for (int i = 0; i < 6; i++) {
            testCases.insert(i);
        }
    }
    if (mainProcess) {
        cout << "GridSortMax (300 Points)" << endl << endl;
    }

    int nPassed = 0;
    
    for (int i = 0; i < 6; ++i) {
        if ( testCases.empty()  || testCases.count(i) ) {
            //run
            nPassed += run_testcase(i);
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << nPassed << "/" << testCases.size() << " cases" << endl;
        int T = time(NULL) - 1479188200;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}
// CUT end
