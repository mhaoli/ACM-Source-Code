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
    int s, e, cap, flow, cost;
    edge(){ }
    edge (int _s, int _e, int c, int f, int _c) : s(_s), e(_e), cap(c), flow(f), cost(_c){ }
};

template <class Tf, class Tc> struct MCMF{
    const static int maxn = 1000;
    
    Tc cost; Tf flow;
    int n, m, s, t;
    vector<edge> pat;
    vi g[maxn];
    int inq[maxn];
    int p[maxn];        //from which path
    Tc d[maxn];         //SPFA, min cost
    Tf ff[maxn];

    void init(int _n){
        n = _n; m = 0; flow = 0; cost = 0;
        repf (i, 0, n-1) g[i].clear();
        pat.clear();
    }
    void add (int s, int e, Tf cap, Tc cost){
        //if (!cost) tst (s), out (e);
        pat.pb (edge(s, e, cap, 0, cost));
        pat.pb (edge(e, s, 0, 0, -cost));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
    }
    bool SPFA(Tf &flow, Tc &cost){
        clr (d, 127); clr (inq, 0);
        d[s] = 0; p[s] = -1; ff[s] = inf;

        queue<int> q; q.push (s); inq[s] = 1;
        while (sz(q)){
            int u = q.front(); q.pop(); inq[u]= 0;
            repf (i, 0, sz(g[u])-1){
                edge &e = pat[g[u][i]];
                if (e.cap > e.flow && d[e.e] > d[e.s] + e.cost){
                    d[e.e] = d[e.s] + e.cost;
                    p[e.e] = g[u][i];
                    ff[e.e] = ff[u]; chmin (ff[e.e], e.cap - e.flow);
                    if (!inq[e.e]) q.push (e.e), inq[e.e] = 1;
                }
            }
        }

        if (d[t] >= inf) return 0;
        flow += ff[t];
        cost += d[t] * ff[t];
        int u = t;
        while (u != s){
            pat[p[u]].flow += ff[t];
            pat[p[u]^1].flow -= ff[t];
            u = pat[p[u]].s;
        }
        return 1;
    }
    Tc mincost(int _s, int _t){
        s = _s; t = _t;
        while (SPFA(flow, cost));
        return cost;
    }
};

MCMF<int, int> gao;

class SlimeXGrandSlimeAuto{
    public:
    int d[55][55];
    int travel(vector<int> car, vector<int> bn, vector<string> road, int ws, int ds){
        vi an; 
        if (bn[0] != 0) an.pb (0);
        repf (i, 0, sz(bn)-1) an.pb (bn[i]);

        int n = sz(road), m = sz(car);
        repf (i, 0, n-1) repf (j, 0, n-1) d[i][j] = (i == j ? 0 : inf);
        repf (i, 0, sz(road)-1) repf (j, 0, sz(road[i])-1) chmin (d[i][j], calc (road[i][j]));
        repf (k, 0, n-1) repf (i, 0, n-1) repf (j, 0, n-1) chmin (d[i][j], d[i][k] + d[k][j]);
        
        //repf (i, 0, n-1){
            //repf (j, 0, n-1) tst (d[i][j]);
            //cout << endl;
        //}

        int sta = 2*(sz(an)-1) + m, tar = sta + 1;
        gao.init (tar + 1); 
        repf (i, 0, m-1) gao.add (sta, i, 1, 0);
        repf (i, 0, sz(an)-2){
            gao.add (sta, m+2*i, 1, 0);
            gao.add (m+2*i+1, tar, 1, 0);
            int tmp = ws * d[an[i]][an[i+1]];
            gao.add (m+2*i, m+2*i+1, 1, tmp);

            repf (j, 0, m-1){
                gao.add (j, m+2*i, 1, ws*d[an[i]][car[j]] + ds*d[an[i+1]][car[j]] - tmp);
            }
        }
        return gao.mincost (sta, tar);
    }
    int calc (char c){
        if (c == '.') return inf;
        if ('0' <= c && c <= '9') return c - '0' + 1;
        if ('a' <= c && c <= 'z') return c - 'a' + 11;
        return c - 'A' + 37;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> cars, vector<int> districts, vector<string> roads, int inverseWalkSpeed, int inverseDriveSpeed, int __expected, int caseNo) {

    time_t startClock = clock();
    SlimeXGrandSlimeAuto *instance = new SlimeXGrandSlimeAuto();
    int __result = instance->travel(cars, districts, roads, inverseWalkSpeed, inverseDriveSpeed);
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
            int cars[] = {2, 3, 3, 2, 3};
            int districts[] = {2, 3, 0, 2, 0, 2, 0, 2, 1, 0, 1, 3, 1, 2, 1, 3, 2, 3, 0, 2, 3, 1, 2, 0, 3, 2, 0, 1, 2, 3, 0, 1, 2, 0, 2, 0, 1, 3, 2, 3, 0, 1, 3, 0, 1, 2, 0, 1, 3, 1};
            string roads[] = {
                "..A.",
                "..kd",
                "Ak..",
                ".d.."
            };
            int inverseWalkSpeed = 75;
            int inverseDriveSpeed = 63;
            int __expected = 140220;
            return do_test(to_vector(cars), to_vector(districts), to_vector(roads), inverseWalkSpeed, inverseDriveSpeed, __expected, __no);
        }
        case 1: {
            int cars[] = {
                1
            };
            int districts[] = {
                2, 0
            };
            string roads[] = {
                ".A.",
                "A.B",
                ".B."
            };
            int inverseWalkSpeed = 2;
            int inverseDriveSpeed = 1;
            int __expected = 262;
            return do_test(to_vector(cars), to_vector(districts), to_vector(roads), inverseWalkSpeed, inverseDriveSpeed, __expected, __no);
        }
        case 2: {
            int cars[] = {
                2, 2
            };
            int districts[] = {
                1, 2, 1
            };
            string roads[] = {
                ".a4",
                "a..",
                "4.."
            };
            int inverseWalkSpeed = 3;
            int inverseDriveSpeed = 1;
            int __expected = 95;
            return do_test(to_vector(cars), to_vector(districts), to_vector(roads), inverseWalkSpeed, inverseDriveSpeed, __expected, __no);
        }
        case 3: {
            int cars[] = {
                1
            };
            int districts[] = {
                2, 0
            };
            string roads[] = {
                ".B.",
                "B.A",
                ".A."
            };
            int inverseWalkSpeed = 2;
            int inverseDriveSpeed = 1;
            int __expected = 262;
            return do_test(to_vector(cars), to_vector(districts), to_vector(roads), inverseWalkSpeed, inverseDriveSpeed, __expected, __no);
        }
        case 4: {
            int cars[] = {
                2, 5, 1, 2
            };
            int districts[] = {
                1, 5, 1, 2, 4
            };
            string roads[] = {
                ".12.4.",
                "1....7",
                "2..3..",
                "..3..5",
                "4.....",
                ".7.5.."
            };
            int inverseWalkSpeed = 53;
            int inverseDriveSpeed = 37;
            int __expected = 1259;
            return do_test(to_vector(cars), to_vector(districts), to_vector(roads), inverseWalkSpeed, inverseDriveSpeed, __expected, __no);
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
    cout << "SlimeXGrandSlimeAuto (600 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1403076651;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
