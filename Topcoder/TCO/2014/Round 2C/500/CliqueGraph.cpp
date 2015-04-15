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

struct cmp{
    bool operator()(pii a, pii b){
        return a.x > b.x;
    }
};

class CliqueGraph {
    public:
    int n, d[2505*2];
    vi pat[2505*2];
    long long calcSum(int N, vector<int> V, vector<int> S) {
        n = N;
        repf (i, 0, n+sz(S)-1) pat[i].clear();
        int t1 = 0, t2;
        repf (i, 0, sz(S)-1){
            t2 = t1 + S[i];
            repf (j, t1, t2-1){
                pat[V[j]].pb (n + i);
                pat[n+i].pb (V[j]);
            }
            t1 = t2;
        }

        //repf (i, 0, n-1){
            //cout << i << " : ";
            //repf (j, 0, sz(pat[i])-1)
                //tst (pat[i][j]);
            //cout << endl;
        //}
//
        int64 ans = 0;
        repf (i, 0, n-1){
            clr (d, 127);
            bfs (i);
            //cout << i << " : ";
            //repf (i, 0, n-1) tst (d[i]);
            //cout << endl;
            repf (i, 0, n-1) ans += d[i];
        }
        return ans / 4;
    }
    void bfs (int x){
        d[x] = 0;
        priority_queue<pii, vector<pii >, cmp> q;
        q.push (mp (0, x));
        while (sz(q)){
            int u = q.top().y, dis = q.top().x;
            q.pop();
            if (dis > d[u]) continue;
            repf (i, 0, sz(pat[u])-1){
                int v = pat[u][i];
                if (dis + 1 >= d[v]) continue;
                d[v] = dis + 1;
                q.push (mp (dis+1, v));
            }
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<int> V, vector<int> sizes, long long __expected, int caseNo) {

    time_t startClock = clock();
    CliqueGraph *instance = new CliqueGraph();
    long long __result = instance->calcSum(N, V, sizes);
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
            int N = 4;
            int V[] = {
                0, 1, 2, 0, 3
            };
            int sizes[] = {
                3, 2
            };
            long long __expected = 8LL;
            return do_test(N, to_vector(V), to_vector(sizes), __expected, __no);
        }
        case 1: {
            int N = 5;
            int V[] = {
                0, 1, 2, 3, 1, 2, 4
            };
            int sizes[] = {
                4, 3
            };
            long long __expected = 12LL;
            return do_test(N, to_vector(V), to_vector(sizes), __expected, __no);
        }
        case 2: {
            int N = 15;
            int V[] = {
                1, 3, 5, 7, 9, 11, 13, 0, 2, 3, 6, 7, 10, 11, 14, 0, 4, 5, 6, 7, 12, 13, 14, 0, 8, 9, 10, 11, 12, 13, 14, 0
            };
            int sizes[] = {
                8, 8, 8, 8
            };
            long long __expected = 130LL;
            return do_test(N, to_vector(V), to_vector(sizes), __expected, __no);
        }

        // Your custom testcase goes here
        case 3:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "CliqueGraph (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 3; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1405092107;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
