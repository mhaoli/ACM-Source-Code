/*
 * Author:  Plumrain
 * Created Time:  2014/8/30 16:46:19
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

const int maxn = 1005;
int pos[maxn][10];

int ru[maxn], ans, d[maxn];
vi pat[maxn];

void dfs (int u){
    chmax (ans, d[u]);
    for (auto v : pat[u]){
        if (d[v] >= d[u] + 1) continue;
        d[v] = d[u] + 1;
        dfs (v);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m; scanf ("%d%d", &n, &m);
    rep (i, 0, m-1){
        int t;
        rep (j, 0, n-1){
            scanf ("%d", &t);
            pos[--t][i] = j;
        }
    }

    clr (ru, 0);
    rep (i, 0, n-1) pat[i].clear ();
    rep (i, 0, n-1) rep (j, i+1, n-1){
        int v = 0;
        rep (k, 0, m-1) v |= (1 << (pos[i][k] < pos[j][k]));
        if (v == 3){
            continue;
        } else if (v == 1){
            pat[j].pb (i); ++ ru[i];
        } else{
            pat[i].pb (j); ++ ru[j];
        }
    }

    ans = 1;
    clr (d, 0);
    rep (i, 0, n-1) if (!ru[i])
        d[i] = 1, dfs (i);
    printf ("%d\n", ans);
    return 0;
}
