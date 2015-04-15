/*
 * Author:  Plumrain
 * Created Time:  2014/9/28 14:24:19
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
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(5e5) + 9;

struct edge{
    int v, p;
    edge *nxt;
    void add (int _v, int _p, edge*n){
        v = _v; p = _p; nxt = n;
    }
}memo[maxn], *bat, *head[maxn];

vi odd;
map<int, int> has;
int x[maxn], y[maxn];
bool vis[maxn];
int ans[maxn], deg[maxn];

void adde (int u, int v, int p){
    bat->add (v, p, head[u]); head[u] = bat++;
}

void dfs (int u){
    for (edge*p = head[u]; p; p = p->nxt) if (!vis[p-memo]){
        edge*rp = &memo[(p-memo)^1];
        vis[p-memo] = vis[rp-memo] = 1;
        ans[p->p] = u > p->v; 
        //ans[rp->p] = p->v > u;
        -- deg[u]; -- deg[p->v];
        dfs (p->v);
        break;
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    set<int> st; 
    //st.insert (0); 
    //st.insert (int(2e9) + 10);
    rep (i, 0, n-1){
        scanf ("%d%d", x + i, y + i);
        x[i] <<= 1; y[i] = y[i]<<1|1;
        st.insert (x[i]);
        st.insert (y[i]);
    }

    int tot = 0;
    for (auto it: st) has[it] = tot++;

    bat = memo;
    clr (head, 0); clr (deg, 0);
    rep (i, 0, n-1){
        int t1 = has[x[i]], t2 = has[y[i]];
        //tst (t1); out (t2);
        adde (t1, t2, i); ++ deg[t1];
        adde (t2, t1, i); ++ deg[t2];
    }

    odd.clear ();
    rep (i, 0, tot-1) if (deg[i] & 1) odd.pb (i);
    for (int i = 0; i < sz(odd); i += 2){
        //tst (odd[i]); out (odd[i+1]);
        adde (odd[i], odd[i+1], n);
        adde (odd[i+1], odd[i], n);
    }

    clr (vis, 0);
    rep (i, 0, tot-1) if (deg[i]) dfs (i);
    rep (i, 0, n-1) printf ("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
