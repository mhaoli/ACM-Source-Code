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

namespace maxflow{
        typedef int T;
        const static int Max_N = 9 + (int)2e4;
        const static int Max_E = 9 + (int)2e4;
        const static int inf = 1e6;

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

class Singing {
        public:
                int solve(int N, int low, int high, vector<int> pitch);
};

int N, L, R;

int Singing::solve(int NN, int low, int high, vector<int> an){
        map<pair<int, int>, int> has;
        N = NN; L = low; R = high;
        for(int i = 1; i < SZ(an); ++i) {
                int t1 = an[i-1], t2 = an[i];
                if(t1 == t2) continue;
                ++has[make_pair(t1, t2)];
                ++has[make_pair(t2, t1)];
        }
        int S = 0, T = N + 1;
        static int INF = 1e6;
        maxflow::init();
        for(int i = 1; i < L; ++i) {
                maxflow::add(S, i, INF);
        }
        for(int i = R+1; i <= N; ++i) {
                maxflow::add(i, T, INF);
        }
        for(auto i : has) {
                maxflow::add(i.first.first, i.first.second, i.second);
                maxflow::add(i.first.second, i.first.second, i.second);
        }
        return maxflow::maxflow(T + 1, S, T);
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int low, int high, vector<int> pitch, int __expected, int caseNo) {

    time_t startClock = clock();
    Singing *instance = new Singing();
    int __result = instance->solve(N, low, high, pitch);
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
            int N = 3;
            int low = 2;
            int high = 2;
            int pitch[] = {
                1, 2, 3, 2, 1, 2
            };
            int __expected = 2;
            return do_test(N, low, high, to_vector(pitch), __expected, __no);
        }
        case 1: {
            int N = 10;
            int low = 3;
            int high = 7;
            int pitch[] = {
                4, 4, 5, 5, 6, 5, 3, 6
            };
            int __expected = 0;
            return do_test(N, low, high, to_vector(pitch), __expected, __no);
        }
        case 2: {
            int N = 6;
            int low = 2;
            int high = 5;
            int pitch[] = {
                5, 3, 1, 6, 4, 2
            };
            int __expected = 1;
            return do_test(N, low, high, to_vector(pitch), __expected, __no);
        }
        case 3: {
            int N = 10;
            int low = 4;
            int high = 5;
            int pitch[] = {
                1, 4, 3, 5, 2, 5, 7, 5, 9
            };
            int __expected = 3;
            return do_test(N, low, high, to_vector(pitch), __expected, __no);
        }
        case 4: {
            int N = 100;
            int low = 20;
            int high = 80;
            int pitch[] = {
                2, 27, 3, 53, 53, 52, 52, 60, 85, 89, 100, 53, 60, 2, 3, 53, 100, 89, 40, 42, 2, 53, 2, 85
            };
            int __expected = 5;
            return do_test(N, low, high, to_vector(pitch), __expected, __no);
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
    cout << "Singing (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1430576177;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
