/*
 * Author:  Plumrain
 * Created Time:  2014-03-21 09:52
 * File Name: AC-HDU-2825.cpp
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
    const static int maxn = 105;
    const static int maxs = 26;

    int ch[maxn][maxs];
    int val[maxn], f[maxn];
    int tot;
    vi pat[maxn];

    int idx(char c){
        return c - 'a';
    }
    void clear(){
        tot = 1; clr (ch[0], -1); val[0] = 0;
    }
    void insert (char *s, int id){
        int n = strlen(s), u = 0;
        repf (i, 0, n-1){
            int c = idx(s[i]);
            if (ch[u][c] == -1){
                clr (ch[tot], -1);
                val[tot] = 0;
                ch[u][c] = tot ++;
            }
            u = ch[u][c];
        }
        val[u] = 1 << id;
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
                val[v] |= val[f[v]];
            }
        }
    }
    void build(){
        repf (u, 0, tot-1){
            pat[u].clear();
            repf (c, 0, maxs-1){
                int v = ch[u][c];
                if (v == -1){
                    int r = f[u];
                    while (r && ch[r][c] == -1) r = f[r];
                    v = ch[r][c] == -1 ? 0 : ch[r][c];
                }
                pat[u].pb (v);
            }
        }
    }
};

AC ac;
char s[15];
int d[2][105][1<<10];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m, k;
    while (scanf ("%d%d%d", &n, &m, &k) != EOF && n){
        ac.clear();
        repf (i, 0, m-1) scanf ("%s", s), ac.insert (s, i);
        ac.fail(); ac.build();
        
        int tot = ac.tot, cur = 0, nxt = 1;
        clr (d, 0); d[0][0][0] = 1;
        repf (i, 0, n-1){
            clr (d[nxt], 0);
            repf (j, 0, tot-1) repf (k, 0, (1<<m)-1) if (d[cur][j][k]){
                repf (t, 0, sz(ac.pat[j])-1){
                    int tmp = ac.pat[j][t];
                    int &ta = d[nxt][tmp][k|ac.val[tmp]];
                    ta += d[cur][j][k];
                    if (ta > mod) ta -= mod;
                }
            }
            swap (cur, nxt);
        }
        
        int ans = 0;
        repf (i, 0, tot-1) repf (j, 0, (1<<m)-1) if (__builtin_popcount(j) >= k) ans = (ans + d[cur][i][j]) % mod;
        printf ("%d\n", ans);
    }
    return 0;
}
