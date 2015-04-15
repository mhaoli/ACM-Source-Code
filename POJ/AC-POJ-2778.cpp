/*
 * Author:  Plumrain
 * Created Time:  2014-03-20 14:57
 * File Name: AC-POJ-2778.cpp
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
#define repf(i, a, b) for(int64 i = (a); i <= (int64)(b); i ++)
#define repd(i, a, b) for(int64 i = (a); i >= (int64)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef int64 matrix[105][105];

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int mod = 100000;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct AC{
    const static int maxn = 105;
    const static int maxs = 4;

    int ch[maxn][maxs];
    int val[maxn];
    int f[maxn], last[maxn];
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
    void fail (){
        queue<int> q;
        f[0] = 0; last[0] = 0;
        repf (c, 0, maxs-1){
            int r = ch[0][c];
            if (r != -1){
                f[r] = last[r] = 0; q.push (r);
            }
        }
        while (!q.empty()){
            int u = q.front(); q.pop();
            repf (c, 0, maxs-1){
                int &j = ch[u][c];
                if (j == -1) continue;
                q.push(j);

                int v = f[u];
                while (v && ch[v][c] == -1) v = f[v];
                f[j] = ch[v][c] == -1 ? 0 : ch[v][c];
                if (val[f[j]]) val[j] = 1;
                last[j] = val[f[j]] ? f[j] : last[f[j]];
            }
        }
    }
    void mtx_build(matrix &an){
        clr (an, 0);
        repf (u, 0, tot-1) if (!val[u])
            repf (c, 0, maxs-1){
                int v = ch[u][c];
                if (v == -1){
                    v = f[u];
                    while (v && ch[v][c] == -1) v = f[v];
                    if (ch[v][c] == -1) ++ an[u][0];
                    else if (!val[ch[v][c]]) ++ an[u][ch[v][c]];
                }
                else if (!val[v]) ++ an[u][v];
            }
    }
};

AC ac;
int tot;
char s[15];
matrix an;

void mtx_clear(matrix &a){
    clr (a, 0); repf (i, 0, tot) a[i][i] = 1;
}

void mtx_eql(matrix &an, matrix bn){
    repf (i, 0, tot) repf (j, 0, tot) an[i][j] = bn[i][j];
}

void mtx_mul (matrix &a, matrix b){
    matrix ret;
    repf (i, 0, tot) repf (j, 0, tot){
        ret[i][j] = 0;
        repf (k, 0, tot) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
    }
    mtx_eql (a, ret);
}

void mtx_pow(matrix &p, int n){
    matrix ret; mtx_clear(ret);
    while (n){
        if (n & 1) mtx_mul (ret, p);
        n >>= 1;
        mtx_mul (p, p);
    }
    mtx_eql(p, ret);
}

void mtx_out(matrix a){
    repf (i, 0, tot){
        repf (j, 0, tot) tst (a[i][j]);
        cout << endl;
    }
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int m, n;
    while (cin >> m >> n){
        ac.clear();
        repf (i, 0, m-1) scanf ("%s", s), ac.insert (s);
        ac.fail(); ac.mtx_build(an);
        tot = ac.tot - 1;

        //out (tot); mtx_out (an);
        mtx_pow (an, n);
        int ans = 0;
        repf (i, 0, tot) ans = (ans + an[0][i]) % mod;
        cout << ans << endl;
    }
    return 0;
}
