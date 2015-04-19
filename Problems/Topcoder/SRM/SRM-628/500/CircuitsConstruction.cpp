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
const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

struct Nod{
    char c;
    int fa, cap, siz, l, r;
    void clear(){
        l = -1; r = -1; fa = -1;
    }
};

Nod nod[maxn];

class CircuitsConstruction {
    public:
    int pos, cnt;
    string s;
    int maximizeResistance(string _s, vector<int> num){
        s = _s;
        repf (i, 0, sz(s)-1) nod[i].clear();
        cnt = pos = 0;
        dfs ();

        //repf (i, 2, cnt-1){
            //tst (i), tst (nod[i].fa), tst (nod[i].c);
            //repf (j, 0, sz(nod[i].son)-1) tst (nod[i].son[j]);
            //cout << endl;
        //}
        int sum = 0;
        sort (all (num), greater<int>());
        repf (i, 0, nod[0].siz-1) sum += num[i];
        return sum;
    }
    int dfs (){
        char c = s[pos++]; 
        int id = cnt ++;
        nod[id].c = c;
        if (c == 'X') {
            nod[id].siz = 1; return id;
        }
        int v = dfs (); 
        nod[v].fa = id; nod[id].l = v;
        nod[id].siz = nod[v].siz;
        v = dfs();
        nod[v].fa = id; nod[id].r = v;
        if (nod[id].c == 'A') nod[id].siz += nod[v].siz;
        else chmax (nod[id].siz, nod[v].siz);
        return id;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string circuit, vector<int> conductors, int __expected, int caseNo) {

    time_t startClock = clock();
    CircuitsConstruction *instance = new CircuitsConstruction();
    int __result = instance->maximizeResistance(circuit, conductors);
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
            string circuit = "BXBXX";
            int conductors[] = {
                8, 2, 3
            };
            int __expected = 8;
            return do_test(circuit, to_vector(conductors), __expected, __no);
        }
        case 1: {
            string circuit = "AAXXAXAXX";
            int conductors[] = {
                1, 1, 2, 8, 10
            };
            int __expected = 22;
            return do_test(circuit, to_vector(conductors), __expected, __no);
        }
        case 2: {
            string circuit = "AXBXX";
            int conductors[] = {
                8, 2, 3
            };
            int __expected = 11;
            return do_test(circuit, to_vector(conductors), __expected, __no);
        }
        case 3: {
            string circuit = "BAAXBXXBXAXXBBAXXBXXAAXXX";
            int conductors[] = {
                17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30
            };
            int __expected = 454;
            return do_test(circuit, to_vector(conductors), __expected, __no);
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
    cout << "CircuitsConstruction (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1406028169;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
