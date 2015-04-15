// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "PolylineUnion.cpp"
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
#include <stack>

using namespace std;

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<" "
#define tst1(a) cout<<#a<<endl
#define zero(x) (((x)>0?(x):-(x))<eps)
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

struct pnt{
    int x, y;
    bool operator == (pnt a){
        if (x == a.x && y == a.y) return 1;
        return 0;
    }
};

vector<vector<pnt> > pol;
int f[10000];
bool v[10000];

class PolylineUnion
{
    public:
        double xmult(pnt p1,pnt p2,pnt p0){
            return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
        }
        int dot_online_in (pnt p, pnt l1, pnt l2)
        {
            return zero (xmult (p, l1, l2)) && (l1.x - p.x) * (l2.x - p.x) < eps
                && (l1.y - p.y) * (l2.y - p.y) < eps;
        }
        int same_side (pnt p1, pnt p2, pnt l1, pnt l2)
        {
            return xmult (l1, p1, l2) * xmult (l1, p2, l2) > eps;
        }
        int dots_inline (pnt p1, pnt p2, pnt p3)
        {
            return zero (xmult (p1, p2, p3));
        }
        int intersect_in (pnt u1, pnt u2, pnt v1, pnt v2)
        {
            if (!dots_inline (u1, u2, v1) || !dots_inline(u1, u2, v2))
                return !same_side (u1, u2, v1, v2) && !same_side(v1, v2, u1, u2);
            return 
                dot_online_in (u1, v1, v2) || dot_online_in (u2, v1, v2)
                || dot_online_in (v1, u1, u2) || dot_online_in (v2, u1, u2);
        }
        bool sam(int a, int b)
        {
            if (sz(pol[a]) == 1) swap (a, b);
            if (sz(pol[a]) == 1){
                if (pol[a][0] == pol[b][0]) return 1;
                return 0;
            }
            if (sz(pol[b]) == 1){
                for (int i = 0; i < sz(pol[a])-1; ++ i){
                    if (!(pol[a][i] == pol[a][i+1])){
                        if (dot_online_in (pol[b][0], pol[a][i], pol[a][i+1])) return 1;
                    }
                    else if (pol[b][0] == pol[a][i]) return 1;
                }
                return 0;
            }
            for (int i = 0; i < sz(pol[a])-1; ++ i)
                for (int j = 0; j < sz(pol[b])-1; ++ j){
                    if (pol[a][i] == pol[a][i+1]){
                        if (pol[b][j] == pol[b][j+1]){
                            if (pol[a][i] == pol[b][j]) return 1;
                        }
                        else if (dot_online_in (pol[a][i], pol[b][j], pol[b][j+1])) return 1;
                    }
                    else if (pol[b][j] == pol[b][j+1]){
                        if (dot_online_in (pol[b][j], pol[a][i], pol[a][i+1])) return 1;
                    }
                    else if (intersect_in(pol[a][i], pol[a][i+1], pol[b][j], pol[b][j+1])) return 1;
                }
            return 0;
        }
        int find (int x)
        {
            if (x != f[x]) f[x] = find(f[x]);
            return f[x];
        }
        int countComponents(vector <string> poly){
            string s = accumulate(all(poly), string("")) + " ";
            pnt tmp;
            vector<pnt> ttmp;
            pol.clear();
            int cnt = 0;
            for (int i = 0; i < sz(s); ++ i){
                if (s[i] == ' '){
                    tmp.y = cnt; cnt = 0;
                    ttmp.pb (tmp); pol.pb (ttmp); ttmp.clear();
                }
                else if (s[i] == '-') tmp.y = cnt, cnt = 0, ttmp.pb (tmp);
                else if (s[i] == ',') tmp.x = cnt, cnt = 0;
                else cnt = cnt*10 + s[i] - '0';
            }

            int n = sz(pol);
            for (int i = 0; i < n; ++ i) f[i] = i;
            for (int i = 0; i < n; ++ i)
                for (int j = i+1; j < n; ++ j) if (sam(i, j)){
                    int t1 = find (i), t2 = find(j);
                    if (t1 != t2) f[t1] = t2;
                }

            clr (v);
            int ans = 0;
            for (int i = 0; i < n; ++ i){
                int t = find(i);
                if (!v[t]) ++ ans, v[t] = 1;
            }
            return ans;
        }

        // BEGIN CUT HERE
    public:
        //void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0();}
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        //void test_case_0() { string Arr0[] = {"0,0-10,10 0,10-10,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countComponents(Arg0)); }
        void test_case_0() { string Arr0[] = {"9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-", "9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,", "9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 ", "9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 8,9-8,9 9,", "9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9 9,9-9,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countComponents(Arg0)); }
        void test_case_1() { string Arr0[] = {"0,0-10,5 5,0-15,5-10,10-5,5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countComponents(Arg0)); }
        void test_case_2() { string Arr0[] = {"1","3,0-5,5 4,0-4,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, countComponents(Arg0)); }
        void test_case_3() { string Arr0[] = {"10,0-10,1-9,2-9,3-8,4 ","8,2-9,2-10,3 ","12,2-11,2-9,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, countComponents(Arg0)); }
        void test_case_4() { string Arr0[] = {"0,0-10,0-0,0 20,0-8,0-20,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, countComponents(Arg0)); }
        void test_case_5() { string Arr0[] = {"1,1 2,2 3,3 4,4 3,3-4,4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, countComponents(Arg0)); }
        void test_case_6() { string Arr0[] = {"10,10-20,10 20,10-15,18 15,18-10,10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, countComponents(Arg0)); }
        void test_case_7() { string Arr0[] = {"1,1 1,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(7, Arg1, countComponents(Arg0)); }

        // END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	PolylineUnion ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
