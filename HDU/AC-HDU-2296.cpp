/*
 * Author:  Plumrain
 * Created Time:  2014-03-21 14:30
 * File Name: AC-HDU-2296.cpp
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
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
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
const int mod = 20090717;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct AC{
    const static int maxn = 1005;
    const static int maxs = 26;

    int ch[maxn][maxs];
    char g[maxn];
    int val[maxn], f[maxn];
    int tot;
    vi pat[maxn], rpat[maxn];

    int idx(char c){
        return c - 'a';
    }
    void clear(){
        tot = 1; clr (ch[0], -1); val[0] = 0;
    }
    void insert (char *s, int cost){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (ch[u][c] == -1){
                clr (ch[tot], -1);
                val[tot] = 0; 
                g[tot] = s[i];
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        val[u] = cost;
    }
    void fail(){
        queue<int> q;
        f[0] = 0;
        repf (c, 0, maxs-1){
            int v = ch[0][c];
            if (v != -1){
                q.push (v); f[v] = 0;
            }
        }
        while (!q.empty()){
            int u = q.front(); q.pop();
            repf (c, 0, maxs-1){
                int v = ch[u][c];
                if (v == -1) continue;
                q.push (v);

                int r = f[u];
                while (r && ch[r][c] == -1) r = f[r];
                f[v] = ch[r][c] == -1 ? 0 : ch[r][c];
                val[v] += val[f[v]];
            }
        }
    }
    void build(){
        repf (i, 0, tot-1) rpat[i].clear();
        repf (u, 0, tot-1){
            pat[u].clear();
            repf (c, 0, maxs-1){
                int v = ch[u][c];
                if (v == -1){
                    int r = f[u];
                    while (r && ch[r][c] == -1) r = f[r];
                    v = ch[r][c] == -1 ? 0 : ch[r][c];
                }
                pat[u].pb (v); rpat[v].pb (u);
            }
        }
    }
};

AC ac;
vector<pii > an;
string ans;
char stmp[55];
char s[105][15];
int d[55][1005];

void dfs (int l, int p, int n){
    if (l == -1){
        string tmp;
        repf (i, 0, n-1) tmp.pb (stmp[i]);
        if (!sz(ans)) ans = tmp;
        else checkmin (ans, tmp);
        return;
    }

    stmp[l] = ac.g[p];
    vi t = ac.rpat[p];
    repf (i, 0, sz(t)-1)
        if (d[l][t[i]] + ac.val[p] == d[l+1][p]) dfs (l-1, t[i], n + 1);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m, k, T;
    scanf ("%d", &T);
    while (T --){
        scanf ("%d%d%d", &n, &m, &k);
        ac.clear();
        repf (i, 0, m-1) scanf ("%s", s[i]);
        int tmp;
        repf (i, 0, m-1) scanf ("%d", &tmp), ac.insert (s[i], tmp);
        ac.fail(); ac.build();

        int tot = ac.tot;
        clr (d, -1); d[0][0] = 0;
        repf (i, 0, n-1) repf (j, 0, tot-1) if (d[i][j] != -1){
            vi t = ac.pat[j];
            repf (k, 0, sz(t)-1)
                checkmax (d[i+1][t[k]], d[i][j] + ac.val[t[k]]);
        }

        an.clear();
        int lans = 0, pos = 0;
        repf (i, 1, n) repf (j, 0, tot-1) {
            if (d[i][j] > d[lans][pos]) lans = i, pos = j, an.clear();
            else if (d[i][j] == d[lans][pos] && i == lans) an.pb (mp (i, j));
        }
        an.pb (mp (lans, pos));
        //repf (i, 0, sz(an)-1) tst (an[i].first), out (an[i].second);

        ans.clear();
        repf (i, 0, sz(an)-1) clr (stmp, 0), dfs (an[i].first-1, an[i].second, 0);
        cout << ans << endl;
    }
    return 0;
}
