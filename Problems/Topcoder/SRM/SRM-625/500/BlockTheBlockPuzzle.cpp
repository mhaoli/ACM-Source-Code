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
const int inf = 2139062143 / 10005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int nn;

struct edge{
    int s, e;
    int cap, flow;
    edge(){ }
    edge (int _s, int _e, int c, int f) : s(_s), e(_e), cap(c), flow(f){ }
};

template <class T> struct dinic{
    const static int maxn = 5005;
    
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

dinic<int64> gao;

class BlockTheBlockPuzzle {
    public:
    int num[55][55], cnt, point[3000], n;
    vs bod;
    int minimumHoles(vector<string> Bod){
        bod = Bod;
        nn = n = sz(bod);
        int tx, ty;
        repf (i, 0, n-1) repf (j, 0, n-1) if (bod[i][j] == '$') tx = i, ty = j;

        int sta = 2 * n * n, tar = 2*idx(tx, ty);
        gao.init (sta + 1);
        repf (i, 0, n-1) repf (j, 0, n-1) 
            if ((abs(tx-i) % 3 == 0) && (abs(ty-j) % 3 == 0)){
                if (2*idx(i, j) == tar) continue;

                repf (k, 0, 3){
                    int t1 = i + 3*dx[k], t2 = j + 3*dy[k];
                    if (t1 < 0 || t1 >= n || t2 < 0 || t2 >= n) continue;
                    char c1 = bod[i+dx[k]][j+dy[k]], c2 = bod[t1-dx[k]][t2-dy[k]];

                    int sum = inf;
                    if (c1 != 'b' && c2 != 'b') sum = ((c1 == '.') + (c2 == '.'));
                    gao.add (2*idx(i, j)+1, 2*idx(t1, t2), sum);
                }
            }

        repf (i, 0, n-1) repf (j, 0, n-1)
            if ((abs(tx-i) % 3 == 0) && (abs(ty-j) % 3 == 0)){
                if (bod[i][j] == 'b') {
                    gao.add (sta, 2*idx(i, j), inf);
                    gao.add (2*idx(i, j), 2*idx(i,j)+1, inf);
                }
                else if (bod[i][j] != '$'){
                    gao.add (2*idx(i,j), 2*idx(i,j)+1, bod[i][j]=='.');
                }
            }

        int64 max = gao.maxflow (sta, tar);
        return (int)(max < inf ? max : -1);
    }
    int idx(int x, int y){
        return x * n + y;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, int __expected, int caseNo) {

    time_t startClock = clock();
    BlockTheBlockPuzzle *instance = new BlockTheBlockPuzzle();
    int __result = instance->minimumHoles(board);
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
        case 0: { string board[] = {
                    "....HH.......H.............H........b......H..",
                    "........H.................H...H...........H...",
                    "...H....H....H........b..H.........HH.........",
                    "...H..........H..H.......H...........H.....H.b",
                    "................................b..H....H....H",
                    "...............H..................H...........",
                    "....H............H.......H..........b.........",
                    "...............H...........b...H.........H....",
                    "..H............H.b.H................H..H$.....",
                    "......H..........H....H....................H..",
                    "..............b..........................H....",
                    "..........H..H.....b......H.........H..H.HH...",
                    ".....H.......H..........H.......H.......H.H...",
                    "............b......H................bH....H...",
                    "....H......H.........H......bH................",
                    "H......H...H.HH...............H...H........b..",
                    "...................H......H..H............H...",
                    "...H.....................b..H.............H...",
                    "..H.Hb..H............H....H......H....H....H..",
                    "..............H.b.H......HH.H....b..b.........",
                    "...H...H..H............H.H....bH..H..bH.......",
                    ".......H............H............H...........H",
                    "..H...b........b..b..H.H.H.....H.....bH.H.....",
                    "..........H............H..........H.....H...H.",
                    ".............H....H...........b...H...H.H.....",
                    "...H..................bH......................",
                    "..H...H.b.....Hb.........H.............H......",
                    ".........b...H......H......H........H.H....H..",
                    ".H...................H........H....H........H.",
                    "H......b.......H.....H...................H....",
                    "....H...H...........H.H...............H.......",
                    "..............H...............H...H......H..H.",
                    "..H...H......H.H.........H.H...H..........H...",
                    "...........Hb..........H.......H..............",
                    "...........H....H..............H........H.....",
                    ".......................b.........H.H...H......",
                    "......H.............H....b..................H.",
                    "b....H....................H........H....H.....",
                    "...H..............H......H...............H..H.",
                    "...................H.........H..H............H",
                    ".........H.......H...........H.H.....H......HH",
                    "H.....H.............H..................HH...H.",
                    "..........H..H........................HH.....H",
                    "....H.................H..........H.H......H...",
                    "H.............................H.....b...HH...H",
                    ".......H.H...............H...................."
            };
            int __expected = 3;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "............H..",
                "...............",
                "...............",
                "HHH$HHH.....H..",
                "HHHHHHH........",
                "HHHHHHHH.......",
                "......b..H.....",
                "...............",
                "...............",
                "...H..H..H.....",
                "...............",
                "...............",
                "...............",
                "...............",
                "..............."
            };
            int __expected = 0;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "............H..",
                "...............",
                "...............",
                "HHH$HHH........",
                "HHHHHHH........",
                "HHHHHHHH.......",
                "......b..H.....",
                "...............",
                "...............",
                "...H..H..H.....",
                "...............",
                "...............",
                "...............",
                "...............",
                "..............."
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "b..$...",
                "...H...",
                ".......",
                "b..b..b",
                "...H...",
                ".......",
                "b..b..b"
            };
            int __expected = 4;
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                "b..b..b",
                "..b..b.",
                ".......",
                "b..$bbb",
                ".b.....",
                "....b..",
                "b..b..b"
            };
            int __expected = -1;
            return do_test(to_vector(board), __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    //freopen("a.out","w",stdout);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "BlockTheBlockPuzzle (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403176756;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
