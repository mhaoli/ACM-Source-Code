/*
 * Author:  Plumrain
 * Created Time:  2014/8/17 17:05:41
 * File Name: E.cpp
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

#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
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
const int inf = 2147483647 / 2;
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct pat{
    int u, v, d;
    pat(){ }
    pat(int _u, int _v) : u(_u), v(_v){ }
};

vi ans;
int g[505][505], n, cnt[505][505];
vector<pat> an;
vi src[505];

bool calc (int u, int v, int sub){
    rep (i, 0, sz (src[u])-1){
        int t = src[u][i];
        if (cnt[u][t] == 1 && g[t][v]) return 0;
    }
    if (!sub) return 1;

    rep (i, 0, sz (src[u])-1){
        int t = src[u][i];
        if (g[t][v]) cnt[u][t] = --cnt[t][u];
    }
    return 1;
}

bool ok (int u, int v){
    if (g[u][v] > 1){
        g[v][u] = --g[u][v]; return 1;
    }

    int flag = 0;
    rep (i, 0, n-1) if (i != u && i != v && g[u][i] && g[i][v]) ++ flag;
    if (!flag) return 0;

    if (!calc (u, v, 0) || !calc (v, u, 0)) return 0;

    calc (u, v, 1); calc (v, u, 1);
    cnt[v][u] = cnt[u][v] = flag;
    src[u].pb (v); src[v].pb (u);
    g[u][v] = --g[v][u];
    return 1;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int m;
    while (scanf ("%d%d", &n, &m) != EOF){
        if (!n && !m) break;
        clr (g, 0);
        an.clear(); ans.clear(); 
        rep (i, 0, m-1){
            int u, v;
            scanf ("%d%d", &u, &v); -- u; -- v;
            if (u == v){
                ans.pb (i); continue;
            }
            an.pb (pat (u, v));
            g[u][v] = ++g[v][u];
        }

        clr (cnt, 0);
        rep (i, 0, n-1) src[i].clear();
        red (i, m-1, 0) if (ok (an[i].u, an[i].v)) ans.pb (i);

        sort (all (ans));
        printf ("%d", sz(ans));
        rep (i, 0, sz(ans)-1) printf (" %d", ans[i] + 1);
        puts ("");
    }
    return 0;
}
