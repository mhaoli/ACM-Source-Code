// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "WebsiteRank.cpp"
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

#define clr0(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(x) cout<<x<<":"<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef long long int64;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2139062143 / 2;

inline int MyMod( int a , int b ) { return (a%b+b)%b;}

class WebsiteRank
{
	public:
        int all;
        int64 d[1000];
        bool v[1000][1000];
        vi pat[1000];
        map<string, int> mp;
        void dfs(int x, int y)
        {
            v[x][y] = 1;
            for (int i = 0; i < sz(pat[y]); ++ i) if (!v[x][pat[y][i]]) dfs(x, pat[y][i]);
        }
        int64 gao(int x)
        {
            int64 &ret = d[x];
            if (ret != -1) return ret;
            
            ret = 1;
            for (int i = 0; i < sz(pat[x]); ++ i) if (!v[pat[x][i]][x]) ret += gao(pat[x][i]);
            return ret;
        }
        long long countVotes(vector <string> vot, string x){
            for (int i = 0; i < 1000; ++ i) pat[i].clear();
            mp.clear(); all = 0;
            for (int i = 0; i < sz(vot); ++ i){
                vot[i].pb (' ');
                string tmp; tmp.clear();
                int idx = -1;
                for (int j = 0; j < sz(vot[i]); ++ j){
                    if (vot[i][j] == ' '){
                        if (!mp.count(tmp)) mp[tmp] = all ++;
                        if (idx != -1) pat[idx].pb (mp[tmp]);
                        else idx = mp[tmp];
                        tmp.clear();
                    }
                    else tmp.pb(vot[i][j]);
                }
            }
            //for (int i = 0; i < all; ++ i){
                //out (i);
                //for (int j = 0; j < sz(pat[i]); ++ j) tst(pat[i][j]);
                //cout << endl;
            //}
            clr0 (v);
            for (int i = 0; i < all; ++ i) dfs(i, i);
            //for (int i = 0; i < all; ++ i){
                //tst(i);
                //for (int j = 0; j < all; ++ j)
                    //cout << v[i][j] << " ";
                //cout << endl;
            //}
            clr1 (d);
            return gao(mp[x]);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	//void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_5();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"C A B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C"; long long Arg2 = 3LL; verify_case(0, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A B C D", "B C D", "C D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 8LL; verify_case(1, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 1LL; verify_case(2, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A B", "B A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 1LL; verify_case(3, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A B C D E F", "B A", "C B", "D B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 3LL; verify_case(4, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"R B", "U Q B F", "Q", "B K", "O F K", "F R", "K Q F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "O"; long long Arg2 = 4LL; verify_case(5, Arg2, countVotes(Arg0, Arg1)); }

// END CUT HERE

};
//by plum rain
// BEGIN CUT HERE
int main()
{
    //freopen( "a.out" , "w" , stdout );    
	WebsiteRank ___test;
    ___test.run_test(-1);
   	return 0;
}
// END CUT HERE
