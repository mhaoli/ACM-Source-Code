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
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define sz(v) ((int)(v).size())
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl

const double eps = 1e-11;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/***head***/

class TaroCutting {
        public:
                int getNumber(vector<int> height, vector<int> add, vector<int> device, int time);
};

namespace costflow {
        typedef int Tf;
        typedef int Tc;
        const static int Max_N = 1009;  //max node number
        const static int Max_E = 240009;  //max edge number
        const static Tc Max_C = 5e8;  //max cost
        //template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
        template <class T> int sgn(T x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }

        struct Edge{
                int v;
                Edge *nxt;
                Tf f, cap;
                Tc c;
                void add(int _v, Tf cp, Tc _c, Edge*n){
                        v = _v; cap = cp; c = _c; nxt = n; f = 0;
                }
                Tf flow(){ return cap - f; }
        };

        Edge *head[Max_N], e[Max_E], *bat, *pre[Max_N];
        int vis[Max_N];
        int n, m, s, t;
        Tc dis[Max_N];
        void add(int u, int v, Tf f, Tc c){
                bat->add(v, f, c, head[u]); head[u] = bat++;
                bat->add(u, 0, -c, head[v]); head[v] = bat++;
        }
        void init(){
                bat = e; m = 0; memset(head, 0, sizeof head);
        }
        int spfa(){
                for (int i = 0; i <= n; ++i) dis[i] = Max_C; dis[s] = 0;
                memset(vis, 0, sizeof(vis)); vis[s] = 1;
                memset(pre, 0, sizeof(pre));
                queue<int> q; q.push(s); 
                int u, v;
                Edge *p;
                while (!q.empty()){
                        p = head[u=q.front()]; q.pop();
                        for (; p; p = p->nxt){
                                v = p->v;
                                if (sgn(dis[v] - dis[u] - p->c) > 0 && sgn(p->flow()) > 0){
                                        dis[v] = dis[u] + p->c;
                                        pre[v] = p;
                                        if (!vis[v]) vis[v] = 1, q.push(v);
                                }   
                        }
                        vis[u] = 0; 
                }
                return sgn(Max_C - dis[t]) > 0;  
        }
        pair<Tf, Tc> solve(int _n, int _s, int _t){
                n = _n; s = _s; t = _t;
                Tc cost = 0; Tf flow = 0;
                while (spfa()){
                        Tf f = Max_C;
                        for (Edge *p = pre[t]; p; p = pre[e[(p-e)^1].v]) chmin(f, p->flow());
                        flow += f;
                        cost += f * dis[t];
                        for (Edge *p = pre[t]; p; p = pre[e[(p-e)^1].v])
                                p->f += f, e[(p-e)^1].f -= f;     
                }
                return make_pair(flow, cost);
        }
}

int TaroCutting::getNumber(vector<int> h, vector<int> add, vector<int> dev, int time){
        //string yes = "Possible", no = "Impossible";
        int n = h.size(), m = dev.size(), src = time + n + m, tar = src + 1;
        costflow::init();
        for(int i = 0, j; i < m; ++i) {
                costflow::add(src, i, n, 0);
                for(j = 0; j < time; ++j) {
                        costflow::add(i, m + j, 1, dev[i]);
                }
        }
        for(int i = 0, j; i < n; ++i) {
                costflow::add(src, m + time + i, 1, h[i] + add[i] * time);
                costflow::add(m + time + i, tar, 1, 0);
                for(j = 0; j < time; ++j) {
                        costflow::add(m + j, m + time + i, 1, add[i] * j);
                }
        }
        return costflow::solve(tar + 1, src, tar).second;
}

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> height, vector<int> add, vector<int> device, int time, int __expected, int caseNo) {

        time_t startClock = clock();
        TaroCutting *instance = new TaroCutting();
        int __result = instance->getNumber(height, add, device, time);
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
                                int height[] = {
                                        4, 7
                                };
                                int add[] = {
                                        7, 1
                                };
                                int device[] = {
                                        7
                                };
                                int time = 1;
                                int __expected = 15;
                                return do_test(to_vector(height), to_vector(add), to_vector(device), time, __expected, __no);
                        }
                case 1: {
                                int height[] = {
                                        3, 1, 2
                                };
                                int add[] = {
                                        1, 1, 1
                                };
                                int device[] = {
                                        7, 7, 7
                                };
                                int time = 2;
                                int __expected = 12;
                                return do_test(to_vector(height), to_vector(add), to_vector(device), time, __expected, __no);
                        }
                case 2: {
                                int height[] = {
                                        100, 50
                                };
                                int add[] = {
                                        75, 30
                                };
                                int device[] = {
                                        200, 100, 50
                                };
                                int time = 2;
                                int __expected = 130;
                                return do_test(to_vector(height), to_vector(add), to_vector(device), time, __expected, __no);
                        }
                case 3: {
                                int height[] = {
                                        7, 10, 1, 7, 5, 4, 11, 5, 7, 9, 10, 8
                                };
                                int add[] = {
                                        1, 3, 4, 10, 2, 1, 6, 4, 8, 7, 5, 10
                                };
                                int device[] = {
                                        7, 1, 5, 10
                                };
                                int time = 3;
                                int __expected = 96;
                                return do_test(to_vector(height), to_vector(add), to_vector(device), time, __expected, __no);
                        }
                case 4: {
                                int height[] = {
                                        35, 45, 32, 8
                                };
                                int add[] = {
                                        2, 25, 31, 5
                                };
                                int device[] = {
                                        29, 28, 3, 11, 28, 37
                                };
                                int time = 8;
                                int __expected = 29;
                                return do_test(to_vector(height), to_vector(add), to_vector(device), time, __expected, __no);
                        }
                case 5: {
                                int height[] = {
                                        614, 649, 977, 808, 821, 356, 801, 493, 669, 650, 652, 627, 129, 261, 883, 513, 62, 698, 83, 772, 779, 719, 83, 105, 774, 867, 412, 892, 142, 851, 743, 66, 221, 494, 125, 905, 638, 342, 723, 680, 407, 197, 111, 368, 676, 694, 765, 482, 712, 188, 325, 535, 6, 49, 655, 595, 958, 805, 659, 893, 370, 904, 276, 156, 29, 458, 757, 632, 731, 289, 582, 207, 843, 365, 387, 521, 69, 269, 459, 428, 423, 885, 744, 199, 998, 968, 296, 473, 50, 752, 492, 919, 473, 981, 380, 896, 769, 991, 269, 93, 108, 184, 762, 312, 511, 256, 374, 600, 643, 445, 908, 250, 384, 518, 119, 464, 499, 124, 82, 999, 881, 767, 177, 796, 2, 620, 759, 380, 901, 221, 407, 622, 260, 622, 729, 264, 768, 79, 236, 524, 437, 215, 108, 518, 820, 725, 490, 796, 986, 318
                                };
                                int add[] = {
                                        391, 938, 772, 630, 54, 775, 379, 613, 647, 8, 946, 885, 604, 822, 663, 559, 452, 565, 637, 695, 24, 515, 92, 956, 194, 551, 813, 362, 190, 268, 440, 781, 450, 789, 566, 372, 402, 860, 531, 608, 434, 761, 754, 26, 504, 873, 132, 756, 206, 93, 284, 807, 642, 637, 936, 954, 205, 303, 582, 822, 134, 269, 967, 147, 589, 549, 24, 670, 403, 105, 40, 531, 486, 695, 898, 287, 443, 542, 599, 151, 45, 567, 548, 945, 912, 764, 451, 404, 700, 522, 227, 954, 84, 347, 625, 278, 377, 730, 635, 604, 959, 845, 41, 193, 459, 532, 429, 216, 473, 415, 85, 933, 90, 643, 94, 927, 692, 99, 771, 594, 318, 627, 89, 340, 110, 488, 909, 253, 20, 114, 179, 177, 116, 42, 676, 91, 787, 437, 551, 51, 880, 336, 759, 795, 243, 727, 279, 620, 488, 607
                                };
                                int device[] = {
                                        942, 79, 387, 184, 104, 981, 766, 678, 715, 998, 161, 125, 439, 532, 550, 415, 4, 467, 211, 852, 781, 577, 728, 592, 40, 971, 852, 592, 338, 555, 662, 636, 823, 122, 728, 69, 701, 476, 346, 190, 36, 535, 826, 739, 517, 551, 257, 36, 906, 171, 629, 292, 49, 29, 109, 151, 299, 180, 193, 731, 655, 877, 174, 688, 866, 957, 57, 89, 513, 765, 68, 245, 454, 968, 224, 417, 657, 383, 769, 809, 13, 51, 813, 970, 632, 357, 787, 717, 254, 645, 352, 636, 370, 950, 917, 959, 364, 453, 890, 43, 98, 438, 748, 277, 115, 298, 431, 709, 312, 49, 553, 395, 798, 58, 419, 355, 770, 818, 460, 89, 880, 515, 952, 219, 608, 284, 532, 254, 361, 524, 199, 265, 407, 782, 737, 928, 977, 729, 510, 175, 609, 81, 155, 24, 425, 186, 999, 839, 896, 721
                                };
                                int time = 150;
                                int __expected = 43325;
                                return do_test(to_vector(height), to_vector(add), to_vector(device), time, __expected, __no);
                        }

                        // Your custom testcase goes here
                case 6:
                        break;
                default: break;
        }
        return 0;
}

int main(int argc, char *argv[]) {
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << "TaroCutting (500 Points)" << endl << endl;

        int nPassed = 0, nAll = 0;
        if (argc == 1)
                for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
        else
                for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
        cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

        int T = time(NULL) - 1418955724;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
        return 0;
}
// CUT end
