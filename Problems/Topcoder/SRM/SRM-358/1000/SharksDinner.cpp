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

struct edge{
    int s, e;
    int cap, flow;
    edge(){ }
    edge (int _s, int _e, int c, int f) : s(_s), e(_e), cap(c), flow(f){ }
};

template <class T> struct dinic{
    const static int maxn = 1005;
    
    T flow;
    int n, m, s, t;         // 0,1,2...n-1
    vector<edge> pat;       // edge
    vector<int> g[maxn];    // graph
    int d[maxn], cur[maxn]; // distance
    bool vis[maxn];    

    void init(int _n){
        n = _n; m = 0; flow = 0;
        repf (i, 0, n-1) g[i].clear();
        pat.clear(); m = 0;
    }
    void add (int s, int e, T cap){
        //tst (s); out (e);
        pat.pb (edge(s, e, cap, 0));
        pat.pb (edge(e, s, 0, 0));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
    }
    bool bfs(){
        queue<int> q;
        q.push (s); d[s] = 0;
        clr (vis, 0); vis[s] = 1; 
        while (sz(q)){
            int x = q.front(); q.pop();
            repf (i, 0, sz(g[x])-1){
                edge e = pat[g[x][i]];
                if (!vis[e.e] && e.cap > e.flow){
                    q.push (e.e);
                    vis[e.e] = 1;
                    d[e.e] = d[x] + 1;
                }
            }
        }
        return vis[t];
    }
    T dfs (int x, T rf){
        if (x == t || sgn(rf) == 0) return rf;
        T flow = 0, ff;
        for (int &i = cur[x]; i < sz(g[x]); ++ i){
            edge &e = pat[g[x][i]];
            T tmp = rf; chmin (tmp, T(e.cap - e.flow));
            if (d[e.e] == d[x] + 1 && (ff = dfs (e.e, tmp)) > 0){
                e.flow += ff;
                pat[g[x][i]^1].flow -= ff;
                flow += ff; rf -= ff;
                if (sgn(rf) == 0) break;
            }
        }
        return flow;
    }
    T maxflow(int _s, int _t){
        s = _s; t = _t;
        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }
        return flow;
    }
};

dinic<int> gao;

class SharksDinner {
    public:
    vi a, b, c;
    int minSurvivors(vector<int> _a, vector<int> _b, vector<int> _c) {
        a = _a; b = _b; c = _c;
        int n = sz(a);
        int sta = n << 1, tar = sta | 1;
        gao.init (tar + 1);
        repf (i, 0, n-1) gao.add (sta, i<<1, 2);
        repf (i, 0, n-1) gao.add (i<<1|1, tar, 1);
        repf (i, 0, n-1) repf (j, 0, n-1) if (i != j){
            int q = ok (i, j);
            if (q == 1) gao.add (i<<1, j<<1|1, 1);
            else if (q == -1 && i > j) gao.add (i<<1, j<<1|1, 1);
        }
        return n - gao.maxflow (sta, tar);
    }
    int ok (int s, int t){
        if (a[s] < a[t]) return 0;
        if (b[s] < b[t]) return 0;
        if (c[s] < c[t]) return 0;
        if (a[s] == a[t] && b[s] == b[t] && c[s] == c[t]) return -1;
        return 1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> size, vector<int> speed, vector<int> intelligence, int __expected, int caseNo) {

    time_t startClock = clock();
    SharksDinner *instance = new SharksDinner();
    int __result = instance->minSurvivors(size, speed, intelligence);
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
            int size[] = {
                1, 4, 3
            };
            int speed[] = {
                2, 3, 1
            };
            int intelligence[] = {
                1, 5, 2
            };
            int __expected = 1;
            return do_test(to_vector(size), to_vector(speed), to_vector(intelligence), __expected, __no);
        }
        case 1: {
            int size[] = {
                4, 10, 5, 8, 8
            };
            int speed[] = {
                5, 10, 7, 7, 10
            };
            int intelligence[] = {
                5, 8, 10, 7, 3
            };
            int __expected = 2;
            return do_test(to_vector(size), to_vector(speed), to_vector(intelligence), __expected, __no);
        }
        case 2: {
            int size[] = {
                1, 2, 3, 4, 100
            };
            int speed[] = {
                4, 3, 2, 1, 100
            };
            int intelligence[] = {
                2, 4, 1, 3, 100
            };
            int __expected = 3;
            return do_test(to_vector(size), to_vector(speed), to_vector(intelligence), __expected, __no);
        }
        case 3: {
            int size[] = {
                4, 4, 4, 4
            };
            int speed[] = {
                3, 3, 3, 3
            };
            int intelligence[] = {
                8, 8, 8, 8
            };
            int __expected = 1;
            return do_test(to_vector(size), to_vector(speed), to_vector(intelligence), __expected, __no);
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
    cout << "SharksDinner (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1407418033;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
