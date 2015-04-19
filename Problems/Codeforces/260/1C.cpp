/*
 * Author:  Plumrain
 * Created Time:  2014/8/9 9:38:12
 * File Name: C.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 3e5 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi pat[maxn];
int dia;
int f[maxn], d[maxn], len[maxn], vis[maxn];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

void merge (int t1, int t2){
    int f1 = find (t1), f2 = find (t2);
    if (f1 == f2) return;
    f[f1] = f2;
    int tmp = ceil (len[f2] / 2.0) + 1 + ceil (len[f1] / 2.0);
    chmax (tmp, len[f2]); chmax (tmp, len[f1]);
    len[f2] = tmp;
}

void dfs (int x){
    vis[x] = 1;
    repf (i, 0, sz(pat[x])-1){
        int v = pat[x][i];
        if (vis[v]) continue;
        d[v] = d[x] + 1; 
        if (d[v] > d[dia]) dia = v;
        dfs (v);
    }
    vis[x] = 0;
}

int find_dia (int x){
    dia = x; d[x] = 0; dfs (x);
    d[dia] = 0; dfs (dia);
    return d[dia];
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, q;
    while (scanf ("%d%d%d", &n, &m, &q) != EOF){
        repf (i, 0, n-1) f[i] = i, pat[i].clear();
        repf (i, 0, m-1){
            int u, v; scanf ("%d%d", &u, &v);  -- u; -- v;
            int f1 = find (u), f2 = find (v);
            if (f1 != f2) f[f1] = f2;
            pat[u].pb (v); pat[v].pb (u);
        }

        clr (len, 0); clr (vis, 0);
        repf (i, 0, n-1) if (find(i) == i) len[i] = find_dia (i);

        while (q--){
            int op, x, y; scanf ("%d%d", &op, &x); -- x;
            if (op == 1) printf ("%d\n", len[find(x)]);
            else{
                scanf ("%d", &y);
                merge (x, y-1);
            }
        }
    }
    return 0;
}
