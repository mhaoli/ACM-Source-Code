/*
 * Author:  Plumrain
 * Created Time:  2014/10/1 14:42:11
 * File Name: H.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

int n, m;
int col[111][111];
char ans[111][111];
const int Dx[]={-1,0}, Dy[]={0,-1};

char solve2 (int x, int y1, int y2){
    if (y1 < 0 || y2 >= m || col[x][y1] != col[x][y2]) return '|';
    return ' ';
}

char solve1 (int x, int y, bool u){
    rep (t, 0, 1){
        int tx = x + Dx[t], ty = y + Dy[t];
        if (tx < 0 || ty < 0) continue;
        if (col[tx][ty] == col[x][y]) return ' ';
    }
    if (!u) return x + '1';
    return y + '1';
}

char calc (int x1, int x2, int y){
    if (x1 < 0 || x2 >= n || col[x1][y] != col[x2][y]) return '-';
    return ' ';
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    while (scanf ("%d", &n) != EOF && n){
        clr (col, -1);
        m = 0;
        int tot = 0;
        rep (i, 0, n-1){
            int p = 0, x, y, cnt;
            scanf ("%d", &cnt);
            while (cnt--){
                while (~col[i][p]) ++ p;
                scanf ("%d%d", &x, &y);
                chmax (m, p + y);
                rep (j, i, i+x-1) rep (k, p, p+y-1) col[j][k] = tot;
                ++ tot; ++ p;
            }
        }

        rep (i, 0, (n<<1)){
            if (i & 1){
                rep (k, 0, 3*m-1) ans[i][k] = (k%3 ? solve1(i>>1, k/3, k%3-1) : solve2(i>>1, k/3-1, k/3));
                ans[i][3*m] = '|';
                ans[i][3*m+1] = 0;
            } else{
                rep (k, 0, 3*m-1) ans[i][k] = (k%3 ? calc((i>>1)-1, i>>1, k/3) : ' ');
                ans[i][3*m] = ' ';
                ans[i][3*m+1] = 0;
                int p = 3*m;
                while (p >= 0 && ans[i][p] == ' ') ans[i][p--] = 0;
            }
            puts (ans[i]);
        }
        puts ("");
    }
    return 0;
}
