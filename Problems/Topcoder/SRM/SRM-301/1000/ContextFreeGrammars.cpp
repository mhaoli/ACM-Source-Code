// BEGIN CUT HERE

// END CUT HERE
#line 5 "ContextFreeGrammars.cpp"
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
//const int inf = 2139062143 / 2;
const int inf = 1e9;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

vs has[26];
int64 d[50][50][100];

class ContextFreeGrammars {
	public:
    string word;
	int countParsingTrees(vector <string> rules, char seed, string word) {

        repf (i, 0, 25) has[i].clear();
        for (auto s : rules){
            char c = s[0];
            string tmp;
            repf (i, 6, sz(s)-1){
                if (s[i] == ' '){
                    if (sz(tmp)) has[c-'A'].pb (tmp); tmp.clear();
                }
                else if (s[i] != '|') tmp.pb (s[i]);

                if (i == sz(s)-1 && sz(tmp)) has[c-'A'].pb (tmp);
            }
        }

        //if(seed == 'F') repf (i, 0, 25) {
            //if (!sz(has[i])) continue;
            //out ((char)(i + 'A'));
            //for (auto s : has[i]) tst (s);
            //cout << endl;
        //}

        this -> word = word;
        repf (i, 0, 40) repf (j, 0, 40) repf (k, 0, 30) d[i][j][k] = -2;
        return dfs (0, sz(word)-1, seed);
	}
    int64 dfs (int l, int r, char c){
        if (c >= 'a' && c <= 'z'){
            if (l == r && c == word[l]) return 1;
            return 0;
        }
        
        int64 &ret = d[l][r][c-'A'];
        int64 f[40][40];

        if (ret != -2) return ret;
        else ret = 0;
        for (string s : has[c-'A']){
            if (sz(s) > r - l + 1) continue;
            clr (f, 0); f[0][0] = 1;
            int n = sz(s);
            repf (i, 0, r - l) repf (j, 0, n-1) if (f[i][j] != 0)
                repf (k, i+1, r - l + 1){
                    int64 tmp = dfs (i + l, l + k - 1, s[j]);
                    if ((f[i][j] == -1 && tmp != 0) || tmp == -1) f[k][j+1] = -1;
                    else if (f[k][j+1] != -1){
                        f[k][j+1] += f[i][j] * tmp;
                        if (f[k][j+1] > inf) f[k][j+1] = -1;
                    }
                }

            if (f[r-l+1][n] == -1) return ret = -1;
            ret += f[r-l+1][n];
            if (ret > inf) return ret = -1;
        }
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = 
        {"A ::= a | Aa | Ba | Ca | Da | Ea | Fa | Ga | Ha", "A ::= a | Ia | Ja | Ka | La | Ma | Na | Oa | Pa", "B ::= a | Ba | Ca | Da | Ea | Fa | Ga | Ha | Ia", "B ::= a | Ja | Ka | La | Ma | Na | Oa | Pa | Qa", "C ::= a | Ca | Da | Ea | Fa | Ga | Ha | Ia | Ja", "C ::= a | Ka | La | Ma | Na | Oa | Pa | Qa | Ra", "D ::= a | Da | Ea | Fa | Ga | Ha | Ia | Ja | Ka", "D ::= a | La | Ma | Na | Oa | Pa | Qa | Ra | Sa", "E ::= a | Ea | Fa | Ga | Ha | Ia | Ja | Ka | La", "E ::= a | Ma | Na | Oa | Pa | Qa | Ra | Sa | Ta", "F ::= a | Fa | Ga | Ha | Ia | Ja | Ka | La | Ma", "F ::= a | Na | Oa | Pa | Qa | Ra | Sa | Ta | Ua", "G ::= a | Ga | Ha | Ia | Ja | Ka | La | Ma | Na", "G ::= a | Oa | Pa | Qa | Ra | Sa | Ta | Ua | Va", "H ::= a | Ha | Ia | Ja | Ka | La | Ma | Na | Oa", "H ::= a | Pa | Qa | Ra | Sa | Ta | Ua | Va | Wa", "I ::= a | Ia | Ja | Ka | La | Ma | Na | Oa | Pa", "I ::= a | Qa | Ra | Sa | Ta | Ua | Va | Wa | Xa", "J ::= a | Ja | Ka | La | Ma | Na | Oa | Pa | Qa", "J ::= a | Ra | Sa | Ta | Ua | Va | Wa | Xa | Ya", "K ::= a | Ka | La | Ma | Na | Oa | Pa | Qa | Ra", "K ::= a | Sa | Ta | Ua | Va | Wa | Xa | Ya | Aa", "L ::= a | La | Ma | Na | Oa | Pa | Qa | Ra | Sa", "L ::= a | Ta | Ua | Va | Wa | Xa | Ya | Aa | Ba", "M ::= a | Ma | Na | Oa | Pa | Qa | Ra | Sa | Ta", "M ::= a | Ua | Va | Wa | Xa | Ya | Aa | Ba | Ca", "N ::= a | Na | Oa | Pa | Qa | Ra | Sa | Ta | Ua", "N ::= a | Va | Wa | Xa | Ya | Aa | Ba | Ca | Da", "O ::= a | Oa | Pa | Qa | Ra | Sa | Ta | Ua | Va", "O ::= a | Wa | Xa | Ya | Aa | Ba | Ca | Da | Ea", "P ::= a | Pa | Qa | Ra | Sa | Ta | Ua | Va | Wa", "P ::= a | Xa | Ya | Aa | Ba | Ca | Da | Ea | Fa", "Q ::= a | Qa | Ra | Sa | Ta | Ua | Va | Wa | Xa", "Q ::= a | Ya | Aa | Ba | Ca | Da | Ea | Fa | Ga", "R ::= a | Ra | Sa | Ta | Ua | Va | Wa | Xa | Ya", "R ::= a | Aa | Ba | Ca | Da | Ea | Fa | Ga | Ha", "S ::= a | Sa | Ta | Ua | Va | Wa | Xa | Ya | Aa", "S ::= a | Ba | Ca | Da | Ea | Fa | Ga | Ha | Ia", "T ::= a | Ta | Ua | Va | Wa | Xa | Ya | Aa | Ba", "T ::= a | Ca | Da | Ea | Fa | Ga | Ha | Ia | Ja", "U ::= a | Ua | Va | Wa | Xa | Ya | Aa | Ba | Ca", "U ::= a | Da | Ea | Fa | Ga | Ha | Ia | Ja | Ka", "V ::= a | Va | Wa | Xa | Ya | Aa | Ba | Ca | Da", "V ::= a | Ea | Fa | Ga | Ha | Ia | Ja | Ka | La", "W ::= a | Wa | Xa | Ya | Aa | Ba | Ca | Da | Ea", "W ::= a | Fa | Ga | Ha | Ia | Ja | Ka | La | Ma", "X ::= a | Xa | Ya | Aa | Ba | Ca | Da | Ea | Fa", "X ::= a | Ga | Ha | Ia | Ja | Ka | La | Ma | Na", "Y ::= a | Ya | Aa | Ba | Ca | Da | Ea | Fa | Ga", "Y ::= a | Ha | Ia | Ja | Ka | La | Ma | Na | Oa"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'F'; string Arg2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg3 = -1; verify_case(0, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"A ::= BD",
 "B ::= bB | b | Bb",
 "D ::= dD",
 "D ::= d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; string Arg2 = "bbd"; int Arg3 = 2; verify_case(1, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"A ::= BD",
 "B ::= bB | b | Bb",
 "D ::= dD",
 "D ::= d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; string Arg2 = "ddbb"; int Arg3 = 0; verify_case(2, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"B ::= topcoder | topcoder",
 "B ::= topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'B'; string Arg2 = "topcoder"; int Arg3 = 3; verify_case(3, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"A ::= BCD",
 "Z ::= z",
 "B ::= Cz | Dz | Zz",
 "C ::= Bz | Dz",
 "D ::= Cz | Bz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'X'; string Arg2 = "zzz"; int Arg3 = 0; verify_case(4, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"B ::= bB | bB | bB | bB | b" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'B'; string Arg2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; int Arg3 = -1; verify_case(5, Arg3, countParsingTrees(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
    ContextFreeGrammars ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
