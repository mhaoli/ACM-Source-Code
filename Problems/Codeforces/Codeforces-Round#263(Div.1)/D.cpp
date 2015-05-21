/*
 * Author:  Plumrain
 * Created Time:  2014/9/1 0:38:26
 * File Name: D.cpp
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

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
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
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(1e5) + 9;
const int mod = 1000000007;
struct Edge{
    int v, w;
    Edge(){ }
    Edge(int v, int w) : v(v), w(w){ }
};

int n;
bool ans_u;
int col[maxn];
vector<Edge> pat[maxn];

void add (int u, int v, int w){
    //tst (u), tst (v), out (w);
    pat[u].pb (Edge (v, w));
    pat[v].pb (Edge (u, w));
}

void constraint (int r, int c, int v){
    int L = abs (r - c) + 1;
    int R = r + c - 1; chmin (R, 2*n - R);
    L -= 2;
    chmax (L, 0);
    //tst (r), tst (c), tst (L), tst (R), out (v);
    add (L, R, v);
}

void dfs (int x, int c){
    if (~col[x]){
        if (col[x] != c) ans_u = true;
        return;
    }

    col[x] = c;
    repeach (i, pat[x]){
        dfs (i->v, c ^ i->w);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int k;
    scanf ("%d%d", &n, &k);
    while (k--){
        char ch;
        int r, c;
        scanf ("%d %d %c", &r, &c, &ch);
        constraint (r, c, ch == 'o');
    }

    clr (col, -1);
    ans_u = false;
    dfs (0, 0);
    int cnt = 0;
    rep (i, 1, n){
        if (col[i] == -1) dfs (i, 0), ++ cnt;
        if (ans_u) break;
    }
    int ans = !ans_u;
    while (cnt --) ans = (ans + ans) % mod;
    printf ("%d\n", ans);
    return 0;
}
