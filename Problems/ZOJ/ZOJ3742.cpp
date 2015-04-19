/*
 * Author:  Plumrain
 * Created Time:  2014/9/27 22:39:50
 * File Name: ZOJ3742.cpp
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

const int N = 50000 + 9;

struct edge{
    int u, v, w;
    void read(){
        scanf ("%d%d%d", &u, &v, &w);
    }
}e[N];

vi hev;
vii pat[N];
ll sum[N][2];
int flag[N], deg[N];
int n, m, siz;

void modify (int x){
    rep (i, 0, sz(pat[x])-1){
        int v = pat[x][i].x, w = pat[x][i].y;
        w *= flag[x] * flag[v];
        if (deg[v] <= siz) v = 0;
        sum[v][0] -= w; sum[v][1] -= w;
    }
    if (deg[x] > siz){
        sum[x][0] = -sum[x][0]; sum[x][1] = -sum[x][1];
        swap (sum[x][0], sum[x][1]);
    }
    flag[x] *= -1;
}

ll getS (int x){
    ll ret = sum[0][x];
    rep (i, 0, sz (hev)-1) ret += sum[hev[i]][x];
    return ret;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, q;
    bool u = 0;
    while (scanf ("%d%d%d", &n, &m, &q) != EOF){
        clr (deg, 0);
        rep (i, 0, m-1){
            e[i].read ();
            ++ deg[e[i].u];
            ++ deg[e[i].v];
        }

        siz = (int)sqrt (2 * m); hev.clear ();
        rep (i, 0, n){
            pat[i].clear (); flag[i] = 1;
            sum[i][0] = sum[i][1] = 0;
            if (deg[i] > siz) hev.pb (i);
        }

        rep (i, 0, m-1){
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if (deg[u] > siz){
                pat[v].pb (pii (u, w));
                sum[u][w > 0] += w;
            } else if (deg[v] > siz){
                pat[u].pb (pii (v, w));
                sum[v][w > 0] += w;
            } else{
                pat[v].pb (pii (u, w));
                pat[u].pb (pii (v, w));
                sum[0][w > 0] += w;
            }
        }

        if (u) puts ("");
        u = 1;
        char op[10];
        int t;
        while (q--){
            scanf ("%s", op);
            if (op[0] == 'Q'){
                scanf ("%s", op);
                ll ret;
                if (op[0] == 'A') ret = getS (0) + getS (1);
                else if (op[0] == '+') ret = getS (1);
                else ret = getS (0);
                printf ("%lld\n", ret);
            } else{
                scanf ("%d", &t);
                modify (t);
            }
        }
    }
    return 0;
}
