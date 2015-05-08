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
#include <complex>

using namespace std;

#define x first
#define y second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x)*(x))
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) cout<<#x<<":"<<(x)<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
/***head***/

class OddEvenTree {
        public:
                vector<int> getTree(vector<string> x);
};

vector<int> OddEvenTree::getTree(vector<string> an){
        //string yes = "Possible", no = "Impossible";
        int n = SZ(an);
        vector<int> f, g;
        for(int i = 0; i < n; ++i) {
                if(an[0][i] == 'E') f.push_back(i);
                else g.push_back(i);
        }

        vector<int> no; no.push_back(-1);
        if(!SZ(f) || !SZ(g)) return no;
        for(auto i : f) {
                for(auto j : g) if(an[i][j] != 'O' || an[j][i] != 'O') return no;
                for(auto j : f) {
                        if(an[i][j] != 'E' || an[j][i] != 'E') return no;
                }
        }
        for(auto i : g) for(auto j : g) {
                if(an[i][j] != 'E' || an[j][i] != 'E') return no;
        }

        vector<int> res;
        for(int i : g) {
                res.push_back(0);
                res.push_back(i);
        }
        for(int i : f) if(i != 0){
                res.push_back(g[0]);
                res.push_back(i);
        }
        return res;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(vector<string> x, vector<int> __expected, int caseNo) {

    time_t startClock = clock();
    OddEvenTree *instance = new OddEvenTree();
    vector<int> __result = instance->getTree(x);
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
            string x[] = {
                "EOE",
                "OEO",
                "EOE"
            };
            int __expected[] = {
                0, 1, 2, 1
            };
            return do_test(to_vector(x), to_vector(__expected), __no);
        }
        case 1: {
            string x[] = {
                "EO",
                "OE"
            };
            int __expected[] = {
                0, 1
            };
            return do_test(to_vector(x), to_vector(__expected), __no);
        }
        case 2: {
            string x[] = {
                "OO",
                "OE"
            };
            int __expected[] = {
                -1
            };
            return do_test(to_vector(x), to_vector(__expected), __no);
        }
        case 3: {
            string x[] = {
                "EO",
                "EE"
            };
            int __expected[] = {
                -1
            };
            return do_test(to_vector(x), to_vector(__expected), __no);
        }
        case 4: {
            string x[] = {
                "EOEO",
                "OEOE",
                "EOEO",
                "OEOE"
            };
            int __expected[] = {
                0, 1, 0, 3, 2, 1
            };
            return do_test(to_vector(x), to_vector(__expected), __no);
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
    cout << "OddEvenTree (300 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430920278;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
