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
#define two(x) (1<<(x))
#define twol(x) (1LL<<(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > 0) - (x < 0);}

template<class Tf, class Tc> 
struct Costflow{
    const static int maxn = 4005;  //max node number
    const static int maxe = 3e4;  //max edge number
    const static Tc maxx = 3e8;  //max cost
    //3 * maxx < maxint
    //change the type of eps

    struct edge{
        int v, nxt;
        Tf f, cap;
        Tc c;
        edge(){}
        edge(int _v, Tf cp, Tc _c, int n):v(_v), cap(cp), c(_c), nxt(n){f = 0;}
        Tf flow(){ return cap - f; }
    };

    int head[maxn];
    int pre[maxn];
    int vis[maxn];
    int n, m, s, t;
    edge e[maxe];    //edge
    Tc dis[maxn];
    void add(int u, int v, Tf f, Tc c){
        e[m] = edge(v, f, c, head[u]); head[u] = m++;
        e[m] = edge(u, 0, -c, head[v]); head[v] = m++; 
    }
    void init(){
        m = 0; clr (head, -1);
    }
    int spfa(){
        for (int i = 0; i <= n; ++i) dis[i] = maxx; dis[s] = 0;
        memset(vis, 0, sizeof(vis)); vis[s] = 1;
        memset(pre, -1, sizeof(pre));
        queue<int> q; q.push(s); 
        int p, u, v;
        while (!q.empty()){
            for (p = head[u=q.front()]; ~p; p = e[p].nxt){
                v = e[p].v;
                if (sgn (dis[v] - dis[u] - e[p].c) > 0 && sgn (e[p].flow()) > 0){
                    dis[v] = dis[u] + e[p].c;
                    pre[v] = p;
                    if (!vis[v]) vis[v] = 1, q.push(v);
                }   
            }
            vis[u] = 0; q.pop(); 
        }
        return sgn (maxx - dis[t]) > 0;  
    }
    pair<Tf, Tc> costflow(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
        Tc cost = 0; Tf flow = 0;
        while (spfa()){
            Tf f = maxx;
            for (int p = pre[t]; p != -1; p = pre[e[p^1].v]) chmin(f, e[p].flow());
            flow += f;
            cost += f * dis[t];
            for (int p = pre[t]; p != -1; p = pre[e[p^1].v])
                e[p].f += f, e[p^1].f -= f;     
        }
        return make_pair(flow, cost);
    }
    /***********/ 
};

class StoryFromTCO {
    public:
    int minimumChanges(vector<int> places, vector<int> cutoff);
};

vii vec;
Costflow<int, int> gao;

int StoryFromTCO::minimumChanges(vector<int> a, vector<int> b){
    //string yes = "Possible", no = "Impossible";
    int n = sz (a), sta = n * 3, tar = sta + 1;
    gao.init ();
    vec.resize (n);
    rep (i, 0, n-1){
        vec[i].x = b[i];
        vec[i].y = a[i];
    }
    sort (all (vec));
    rep (i, 0, n-1){
        gao.add (sta, i, 1, 0);
        gao.add (i + (n<<1), tar, 1, 0);
        gao.add (i + n, i + (n<<1), inf, 0);
        if (i < n-1) gao.add (i + n, i + 1 + n, inf, 0);
        
        if (vec[i].y <= vec[i].x) gao.add (i, i + (n<<1), 1, 0);
        rep (j, 0, n-1) if (vec[i].y <= vec[j].x){
            gao.add (i, j + n, 1, 1); break;
        }
    }
    pii ans = gao.costflow (tar + 1, sta, tar);
    if (ans.x != n) return -1;
    return ans.y;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> places, vector<int> cutoff, int __expected, int caseNo) {

    time_t startClock = clock();
    StoryFromTCO *instance = new StoryFromTCO();
    int __result = instance->minimumChanges(places, cutoff);
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
            int places[] = {
                20, 100, 500, 50
            };
            int cutoff[] = {
                7500, 2250, 150, 24
            };
            int __expected = 3;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }
        case 1: {
            int places[] = {
                5, 4, 3, 2, 1
            };
            int cutoff[] = {
                5, 4, 3, 2, 1
            };
            int __expected = 0;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }
        case 2: {
            int places[] = {
                1, 5, 5, 5
            };
            int cutoff[] = {
                8, 6, 4, 2
            };
            int __expected = -1;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }
        case 3: {
            int places[] = {
                3, 1, 5
            };
            int cutoff[] = {
                6, 4, 2
            };
            int __expected = 3;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }
        case 4: {
            int places[] = {
                14, 11, 42, 9, 19
            };
            int cutoff[] = {
                11, 16, 37, 41, 47
            };
            int __expected = 4;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }
        case 5: {
            int places[] = {
                4, 1, 3, 3, 2, 4, 5, 5, 4, 4
            };
            int cutoff[] = {
                3, 3, 5, 2, 4, 4, 5, 4, 3, 5
            };
            int __expected = 6;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }
        case 6: {
            int places[] = {
                213, 177, 237, 444, 497, 315, 294, 104, 522, 635, 13, 26, 22, 276, 88, 249, 374, 17, 42, 245, 80, 553, 121, 625, 62, 105, 53, 132, 178, 250, 18, 210, 492, 181, 2, 99, 29, 21, 62, 218, 188, 584, 702, 63, 41, 79, 28, 452, 2
            };
            int cutoff[] = {
                33, 40, 41, 48, 74, 84, 117, 125, 126, 164, 197, 197, 201, 218, 222, 231, 244, 277, 290, 309, 321, 321, 360, 376, 440, 442, 465, 477, 491, 513, 639, 645, 647, 675, 706, 710, 726, 736, 736, 765, 801, 838, 845, 854, 863, 865, 887, 902, 908
            };
            int __expected = 23;
            return do_test(to_vector(places), to_vector(cutoff), __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "StoryFromTCO (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1412441087;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
