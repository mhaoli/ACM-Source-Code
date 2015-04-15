/*
 * Author:  Plumrain
 * Created Time:  2014-03-20 16:30
 * File Name: AC-HDU-2243.cpp
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

typedef unsigned long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef int64 matrix[105][105];

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int64 mod = 10330176681277348905;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct AC{
    const static int maxn = 50;
    const static int maxs = 26;
    
    int ch[maxn][maxs];
    int val[maxn], f[maxn];
    int tot;
    
    int idx (char c){
        return c - 'a';
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
                int j = ch[u][c];
                if (j == -1) continue;
                q.push (j);

                int v = f[u];
                while (v && ch[v][c] == -1) v = f[v];
                f[j] = ch[v][c] == -1 ? 0 : ch[v][c];
                if (val[f[j]]) val[j] = 1;
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
matrix an, bn;
int tot;
char s[10];

void mtx_clear(matrix &a){
    clr (a, 0); repf (i, 0, tot) a[i][i] = 1;
}

void mtx_eql(matrix &an, matrix bn){
    repf (i, 0, tot) repf (j, 0, tot) an[i][j] = bn[i][j];
}

void mtx_gao (matrix &a, matrix b){
    clr (a, 0); mtx_eql (a, b);
    repf (i, tot+1, tot<<1|1){
        repf (j, 0, tot) a[i][j] = b[i-tot-1][j];
        a[i][i] = 1;
    }
}

void mtx_mul (matrix &a, matrix b){
    matrix ret;
    repf (i, 0, tot) repf (j, 0, tot){
        ret[i][j] = 0;
        repf (k, 0, tot) ret[i][j] += a[i][k] * b[k][j];
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
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, l;
    while (scanf ("%d%d", &n, &l) != EOF){
        ac.clear();
        repf (i, 0, n-1) scanf ("%s", s), ac.insert (s);
        ac.fail(); ac.mtx_build (an);

        tot = ac.tot - 1;
        mtx_gao (bn, an);
        tot = 2*ac.tot - 1;
        mtx_pow (bn, l);
        int64 ans2 = 0;
        repf (i, 0, ac.tot-1) ans2 += bn[ac.tot][i];

        tot = 1; bn[0][0] = bn[1][0] = 26; bn[1][1] = 1; bn[0][1] = 0;
        mtx_pow (bn, l);
        int64 ans1 = bn[1][0];

        int64 ans = ans1 - ans2;
        if (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return 0;
}
