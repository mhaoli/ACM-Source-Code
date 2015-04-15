/*
 * Author:  Plumrain
 * Created Time:  2014/7/24 19:04:03
 * File Name: URAL-1382.cpp
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 5005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    int e, c, n;
};

struct SAT{
    //const static int maxn = ;
    const static int maxe = 4000010;

    int n, top, tot;
    int col[maxn], stk[maxn], head[maxn][3];
    nod en[maxe];

    void init (int _n){
        tot = 0; n = _n; clr (head, -1); clr (col, 0);
    }
    //when use, you should write twice, add (x,c1,y,c2) and add(y,c2,x,c1)
    void add (int x, int c1, int y, int c2){
        en[tot].e = y; en[tot].c = c2;
        en[tot].n = head[x][c1]; head[x][c1] = tot++;
    }
    bool dfs (int u, int v){
        stk[top++] = u; col[u] = v;
        for (int i = head[u][v]; i != -1; i = en[i].n){
            int v = en[i].e;
            if (!col[v] && !dfs (v, 3-en[i].c)) return 0;
            if (col[v] == en[i].c) return 0;
        }
        return 1;
    }
    bool ok (int x, int v){
        top = 0;
        if (dfs (x, v)) return 1;
        while (top) col[stk[--top]] = 0;
        return 0;
    }
    bool calc (){
        clr (col, 0);
        repf (i, 0, n-1) if (!col[i]){
            if (!ok (i, 1) && !ok (i, 2)) return 0;
        }
        return 1;
    }
};

SAT gao;
int an[maxn], bn[maxn], cn[maxn];

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n; scanf ("%d", &n);
    gao.init (n);
    repf (i, 0, n-1) scanf ("%d%d%d", an+i, bn+i, cn+i), -- bn[i];
    repf (i, 0, n-1){
        repf (j, i+1, n-1){
            if (an[j] == an[i]) gao.add (i, 1, j, 1), gao.add (j, 1, i, 1);
            if ((bn[j] == i) != (cn[j] == an[i])) gao.add (i, 1, j, 2), gao.add (j, 2, i, 1);
            if ((bn[i] == j) != (cn[i] == an[j])) gao.add (i, 2, j, 1), gao.add (j, 1, i, 2);
            if ((bn[j] == bn[i]) != (cn[j] == cn[i])) gao.add (i, 2, j, 2), gao.add (j, 2, i, 2);
        }
    }

    gao.calc ();
    repf (i, 0, n-1){
        if (i) printf (" ");
        printf ("%d", gao.col[i]);
    }
    puts ("");
    return 0;
}
