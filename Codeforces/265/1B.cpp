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
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0U >> 1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define sqr(x) ((x) * (x))
int A[11][11];

pair<int, int> temp[3];
map<int64, int> has;

inline int64 dis (int x, int y){
    int64 ret = 0;
    rep (i, 0, 2) ret += sqr ((int64)A[x][i] - A[y][i]);
    return ret;
}

inline bool check (){
    has.clear ();
    rep (i, 0, 7) rep (j, i+1, 7) has[dis (i, j)] ++;
    int64 a = has.begin() -> first;
    if (sz (has) != 3) return 0;
    if (!a) return 0;
    int cnt = 0;
    for (map<int64, int>::iterator it = has.begin(); it != has.end (); ++ it){
        if (it->first != a * temp[cnt].x || it->second != temp[cnt].y) return 0;
        ++ cnt;
    }
    return 1;
}

bool dfs (int p){
    if (p == 8) return check ();
    do{
        if (dfs (p + 1)) return 1;
    }while (next_permutation (A[p], A[p] + 3));
    return 0;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    temp[0] = pii (1, 12);
    temp[1] = pii (2, 12);
    temp[2] = pii (3, 4);

    rep (i, 0, 7){
        rep (j, 0, 2) scanf ("%d", &A[i][j]);
        sort (A[i], A[i] + 3);
    }
    if (!dfs (1)) puts ("NO");
    else{
        puts ("YES");
        rep (i, 0, 7) rep (j, 0, 2) 
            printf ("%d%c", A[i][j], " \n"[j==2]);
    }
    return 0;
}
