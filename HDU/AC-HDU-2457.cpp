/*
 * Author:  Plumrain
 * Created Time:  2014-03-22 01:14
 * File Name: AC-HDU-2457.cpp
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

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct AC{
    const static int maxn = 1005;
    const static int maxs = 4;

    int ch[maxn][maxs];
    int val[maxn], f[maxn];
    int tot;

    int idx(char c){
        if (c == 'A') return 0;
        if (c == 'C') return 1; 
        if (c == 'T') return 2;
        return 3;
    }
    void clear(){
        tot = 1; clr (ch[0], -1); val[0] = 0;
    }
    void insert (char *s){
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
        val[u] = 1;
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
};

AC ac;
char s[1005];
int d[1005][1005];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, cas = 0;
    while (scanf ("%d", &n) != EOF && n){
        ac.clear();
        repf (i, 0, n-1) scanf ("%s", s), ac.insert (s);
        ac.fail();
        scanf ("%s", s + 1);

        int n = strlen(s) - 1, tot = ac.tot - 1;
        clr (d, 127); d[0][0] = 0;
        repf (i, 0, n-1) repf (j, 0, tot) if (d[i][j] <= 10000){
            int id = ac.idx(s[i+1]);
            repf (c, 0, 3){ 
                int r = ac.ch[j][c];
                if (r == -1){
                    int v = ac.f[j];
                    while (v && ac.ch[v][c] == -1) v = ac.f[v];
                    r = ac.ch[v][c] == -1 ? 0 : ac.ch[v][c];
                }
                if (!ac.val[r]) checkmin (d[i+1][r], d[i][j] + (c != id));
            }
        }

        int ans = inf;
        repf (i, 0, tot) checkmin (ans, d[n][i]);
        printf ("Case %d: %d\n", ++ cas, ans==inf?-1:ans);
    }
    return 0;
}
