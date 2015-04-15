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
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/***head***/
const int inf = 1e8;
namespace maxflow{
        typedef int T;
        const static int Max_N = 9 + (int)2e4;
        const static int Max_E = 9 + (int)5e5;

        template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
        template <class T> int sgn(T x) { return (x > 0) - (x < 0);}

        struct edge{
                int s, e;
                T cap, f;
                edge *nxt;
                void add (int _s, int _e, T c, edge *t){
                        f = 0; s = _s; e = _e; cap = c; nxt = t;
                }
                T flow(){ return cap - f;}
        };

        T flow;
        int n, m, s, t;         // 0,1,2...n-1
        edge memo[Max_E];        //edge
        edge *bat, *head[Max_N], *cur[Max_N];
        int d[Max_N]; // distance
        bool vis[Max_N];    

        void init(){
                bat = memo;
                memset(head, 0, sizeof head);
        }
        void add (int s, int e, T cap){
                bat -> add (s, e, cap, head[s]); head[s] = bat++;
                bat -> add (e, s, 0, head[e]); head[e] = bat++;
        }
        bool bfs(){
                std::queue<int> q;
                q.push (s); d[s] = 0;
                memset (vis, 0, sizeof vis); vis[s] = 1; 
                while (q.size ()){
                        int x = q.front(); q.pop();
                        for (edge *e = head[x]; e; e = e->nxt){
                                if (!vis[e->e] && e->flow() > 0){
                                        q.push (e->e);
                                        vis[e->e] = 1;
                                        d[e->e] = d[x] + 1;
                                }
                        }
                }
                return vis[t];
        }
        T dfs (int x, T rf){
                if (x == t || sgn(rf) == 0) return rf;
                T flow = 0, ff;
                for (edge *&e = cur[x]; e; e = e->nxt){
                        T tmp = rf; chmin(tmp, e->flow());
                        if (d[e->e] == d[x] + 1 && (ff = dfs (e->e, tmp)) > 0){
                                e->f += ff;
                                memo[(e-memo)^1].f -= ff;
                                flow += ff; rf -= ff;
                                if (sgn(rf) == 0) break;
                        }
                }
                return flow;
        }
        T maxflow(int _n, int _s, int _t){
                n = _n; flow = 0;
                s = _s; t = _t;
                while (bfs()){
                        //clr (cur, 0);
                        for (int i = 0; i < n; ++ i) cur[i] = head[i];
                        flow += dfs (s, inf);
                }
                return flow;
        }
}

class FoxAndCity {
        public:
                int minimalCost(vector<string> linked, vector<int> want);
};

int n, dis[111], src, tar;
vector<string> G;
vector<int> want;
void dfs(int x) {
        for(int i = 0; i < n; ++i) if(i != x && dis[i] > dis[x] + 1 && G[i][x]=='Y') {
                dis[i] = dis[x] + 1; dfs(i);
        }
}
int node(int u, int x) {
        return x == dis[u]+1 ? src : u * n + x - 1;
}
int f(int u, int x) {
        return sqr(want[u] - x);
}
int FoxAndCity::minimalCost(vector<string> linked, vector<int> Want){
        G = linked; want = Want;
        n = G.size(); 
        memset(dis, 127, sizeof dis);
        dis[0] = 0; dfs(0);

        maxflow::init();
        src = n * n; tar = src + 1;
        for(int i = 1, j; i < n; ++i) {
                for(j = dis[i]; j; --j) if(f(i, j)) maxflow::add(node(i, j+1), node(i, j), f(i, j));
                maxflow::add(node(i, 1), tar, inf);
        }
        for(int i = 0, j, k; i < n; ++i) for(j = 0; j < n; ++j) if(G[i][j] == 'Y') {
                for(k = 1; k <= dis[i]; ++k) if(k+1 <= dis[j]){
                        maxflow::add(node(i, k), node(j, k+1), inf);
                }
        }
        return maxflow::maxflow(tar + 1, src, tar);
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> linked, vector<int> want, int __expected, int caseNo) {

    time_t startClock = clock();
    FoxAndCity *instance = new FoxAndCity();
    int __result = instance->minimalCost(linked, want);
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
            string linked[] = {
                "NYN",
                "YNY",
                "NYN"
            };
            int want[] = {
                0, 1, 1
            };
            int __expected = 0;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }
        case 1: {
            string linked[] = {
                "NYNN",
                "YNYN",
                "NYNY",
                "NNYN"
            };
            int want[] = {
                0, 3, 3, 3
            };
            int __expected = 5;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }
        case 2: {
            string linked[] = {
                "NYNNNY",
                "YNYNNN",
                "NYNYNN",
                "NNYNYN",
                "NNNYNY",
                "YNNNYN"
            };
            int want[] = {
                0, 2, 2, 2, 2, 2
            };
            int __expected = 2;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }
        case 3: {
            string linked[] = {
                "NYY",
                "YNN",
                "YNN"
            };
            int want[] = {
                0, 0, 0
            };
            int __expected = 2;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }
        case 4: {
            string linked[] = {
                "NYNNNN",
                "YNYNNN",
                "NYNYYY",
                "NNYNYY",
                "NNYYNY",
                "NNYYYN"
            };
            int want[] = {
                0, 1, 2, 3, 0, 3
            };
            int __expected = 3;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }
        case 5: {
            string linked[] = {
                "NYNNNN",
                "YNYNNN",
                "NYNYYY",
                "NNYNYY",
                "NNYYNY",
                "NNYYYN"
            };
            int want[] = {
                0, 1, 2, 4, 0, 4
            };
            int __expected = 6;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }
        case 6: {
            string linked[] = {
                "NYNYYYYYYYY",
                "YNYNNYYNYYY",
                "NYNNNYYNYYN",
                "YNNNYYYYYYY",
                "YNNYNYYYNYY",
                "YYYYYNNYYNY",
                "YYYYYNNNYYY",
                "YNNYYYNNNYY",
                "YYYYNYYNNNY",
                "YYYYYNYYNNY",
                "YYNYYYYYYYN"
            };
            int want[] = {
                0, 1, 2, 0, 0, 5, 1, 3, 0, 2, 3
            };
            int __expected = 28;
            return do_test(to_vector(linked), to_vector(want), __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
        //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxAndCity (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1419333351;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
