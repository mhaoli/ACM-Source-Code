/*
 * Author:  Plumrain
 * Created Time:  2014/4/29 17:27:21
 * File Name: Maxflow-COGS-736.cpp
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
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct edge{
    int s, e;
    int cap, flow;
    edge(){ }
    edge (int _s, int _e, int c, int f) : s(_s), e(_e), cap(c), flow(f){ }
};

template <class T> struct dinic{
    const static int maxn = 126000;
    
    int n, m, s, t;         // 0,1,2...n-1
    vector<edge> pat;       // edge
    vector<int> g[maxn];    // graph
    int d[maxn], cur[maxn]; // distance
    bool vis[maxn];    

    void init(int _n){
        n = _n; m = 0;
        repf (i, 0, n-1) g[i].clear();
        pat.clear(); m = 0;
    }
    void add (int s, int e, T cap){
        pat.pb (edge(s, e, cap, 0));
        pat.pb (edge(e, s, 0, 0));
        m += 2;
        g[s].pb (m - 2); g[e].pb (m - 1);
    }
    bool bfs(){
        queue<int> q;
        q.push (s); d[s] = 0;
        clr (vis, 0); vis[s] = 1; 
        while (sz(q)){
            int x = q.front(); q.pop();
            repf (i, 0, sz(g[x])-1){
                edge e = pat[g[x][i]];
                if (!vis[e.e] && e.cap > e.flow){
                    q.push (e.e);
                    vis[e.e] = 1;
                    d[e.e] = d[x] + 1;
                }
            }
        }
        return vis[t];
    }
    T dfs (int x, T rf){
        if (x == t || sgn(rf) == 0) return rf;
        T flow = 0, ff;
        for (int &i = cur[x]; i < sz(g[x]); ++ i){
            edge &e = pat[g[x][i]];
            T tmp = rf; chmin (tmp, T(e.cap - e.flow));
            if (d[e.e] == d[x] + 1 && (ff = dfs (e.e, tmp)) > 0){
                e.flow += ff;
                pat[g[x][i]^1].flow -= ff;
                flow += ff; rf -= ff;
                if (sgn(rf) == 0) break;
            }
        }
        return flow;
    }
    T maxflow(int _s, int _t){
        s = _s; t = _t;
        T flow = 0;
        while (bfs()){
            clr (cur, 0);
            flow += dfs (s, inf);
        }
        return flow;
    }
};

dinic<int> gao;
int n, m, k;
int an[60][60], tot[60], idx[60][2100], pos[60];

int calc(int day){
    int cnt = 1;
    repf (i, 0, n) repf (j, 0, day) idx[i][j] = cnt ++;
    //repf (i, 0, n) repf (j, 0, day){
        //tst (i), tst (j), out (idx[i][j]);
    //}
    //cout << " -------------- " << endl;

    int sta = 0, tar = cnt;
    gao.init (tar + 1);
    repf (i, 0, day) gao.add (sta, idx[0][i], inf);
    repf (i, 0, n) repf (j, 0, day-1) gao.add (idx[i][j], idx[i][j+1], inf);

    repf (i, 0, m-1) pos[i] = 1;
    repf (i, 0, day-1){
        repf (j, 0, m-1){
            int t1, t2;
            if (pos[j] == an[j][0]){
                t1 = an[j][pos[j]];
                if (t1 == -1) t1 = tar;
                else t1 = idx[t1][i];
                
                t2 = an[j][1];
                if (t2 == -1) t2 = tar;
                else t2 = idx[t2][i+1];

                pos[j] = 1;
            }
            else{
                t1 = an[j][pos[j]]; 
                if (t1 == -1) t1 = tar;
                else t1 = idx[t1][i];
                
                t2 = an[j][pos[j]+1];
                if (t2 == -1) t2 = tar;
                else t2 = idx[t2][i+1];
                pos[j] ++;
            }

            //tst (i), tst (j), tst (t1), tst (t2), cout << endl;
            gao.add (t1, t2, tot[j]);
        }
    }

    return gao.maxflow(sta, tar);
}

int main()
{
    freopen("home.in","r",stdin);
    freopen("home.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    repf (i, 0, m-1){
        cin >> tot[i] >> an[i][0];
        repf (j, 1, an[i][0]) cin >> an[i][j];
    }

    int l = 1, r = 1080, ans = 1080;
    while (l <= r){
        int m = (l + r) >> 1;
        if (calc (m) >= k) ans = m, r = m - 1;
        else l = m + 1;
    }
    if (ans >= 1080) cout << "0" << endl;
    else cout << ans << endl;
    return 0;
}
