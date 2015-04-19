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
#define sqr(x) ((x)*(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/***head***/

class TheKingsRoadsDiv2 {
        public:
                string getAnswer(int h, vector<int> a, vector<int> b);
};

int h, n, deg[1111], cnt[1111];
vector<int> t1, t2;
vector<int> E[1111];
bool vis[1111], ans_u;

void dfs(int x, int dep) {
        ++cnt[dep];
        vis[x] = 1;
        snuke(it, E[x]) if(!vis[*it]) dfs(*it, dep + 1);
}

bool check(int x) {
        for(int i = 1; i < (1<<h); ++i) E[i].clear();
        memset(deg, 0, sizeof deg);
        memset(vis, 0, sizeof vis);
        memset(cnt, 0, sizeof cnt);

        for(int i = 0; i < n; ++i) if(i != x) {
                E[t1[i]].push_back(t2[i]);
                E[t2[i]].push_back(t1[i]);
                ++deg[t1[i]]; ++deg[t2[i]];
                if(t1[i] == t2[i]) return 0;
        }

        int sta = -1;
        for(int i = 1; i < (1<<h); ++i) if(deg[i] == 2) {
                if(sta != -1) return 0;
                sta = i;
        }

        for(int i = 1; i < (1<<h); ++i) if(i != sta && deg[i] != 3 && deg[i] != 1) return 0;
        
        ans_u = 1;
        dfs(sta, 1);
        if(!ans_u) return 0;
        int sum = 0;
        for(int i = 1; i <= h; ++i) {
                sum += cnt[i];
                if(sum != (1 << i) - 1) return 0;
        }
        return 1;
}

string TheKingsRoadsDiv2::getAnswer(int _h, vector<int> a, vector<int> b){
        t1 = a; t2 = b; h = _h;
        string yes = "Correct", no = "Incorrect";
        n = a.size();
        for(int i = 0; i < n; ++i) {
                if(check(i)) return yes;
        }
        return no;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int h, vector<int> a, vector<int> b, string __expected, int caseNo) {

    time_t startClock = clock();
    TheKingsRoadsDiv2 *instance = new TheKingsRoadsDiv2();
    string __result = instance->getAnswer(h, a, b);
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
            int h = 3;
            int a[] = {
                1, 2, 3, 7, 1, 5, 4
            };
            int b[] = {
                6, 7, 4, 3, 3, 1, 7
            };
            string __expected = "Correct";
            return do_test(h, to_vector(a), to_vector(b), __expected, __no);
        }
        case 1: {
            int h = 2;
            int a[] = {
                1, 2, 3
            };
            int b[] = {
                2, 1, 3
            };
            string __expected = "Incorrect";
            return do_test(h, to_vector(a), to_vector(b), __expected, __no);
        }
        case 2: {
            int h = 3;
            int a[] = {
                7, 1, 1, 2, 2, 3, 1
            };
            int b[] = {
                7, 1, 7, 4, 5, 2, 6
            };
            string __expected = "Incorrect";
            return do_test(h, to_vector(a), to_vector(b), __expected, __no);
        }
        case 3: {
            int h = 2;
            int a[] = {
                1, 3, 3
            };
            int b[] = {
                2, 1, 2
            };
            string __expected = "Correct";
            return do_test(h, to_vector(a), to_vector(b), __expected, __no);
        }
        case 4: {
            int h = 3;
            int a[] = {
                6, 5, 3, 3, 5, 5, 6
            };
            int b[] = {
                1, 5, 5, 6, 4, 7, 2
            };
            string __expected = "Correct";
            return do_test(h, to_vector(a), to_vector(b), __expected, __no);
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
    cout << "TheKingsRoadsDiv2 (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1424225412;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
