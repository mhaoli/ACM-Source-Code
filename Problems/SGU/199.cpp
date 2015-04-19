/*
 * Author:  Plumrain
 * Created Time:  2014/7/15 11:39:07
 * File Name: 199.cpp
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
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
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
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

piii an[maxn];

bool cmp1 (piii a, piii b){
    return a.x.y < b.x.y;
}

struct Set{
    int ma[maxn<<2];

    void pushup (int rt){
        int ls = rt << 1, rs = ls | 1;
        ma[rt] = max (ma[ls], ma[rs]);
    }
    void update (int q, int w, int l, int r, int rt){
        if (l == r){
            chmax (ma[rt], w); return;
        }
        int m = (l + r) >> 1;
        if (m >= q) update (q, w, lson);
        else update (q, w, rson);
        pushup (rt);
    }
    int ask(int ql, int qr, int l, int r, int rt){
        if (qr < ql) return 0;
        if (ql <= l && qr >= r) return ma[rt];
        int m = (l + r) >> 1, ret = 0;
        if (m >= ql) chmax (ret, ask (ql, qr, lson));
        if (m < qr) chmax (ret, ask (ql, qr, rson));
        return ret;
    }
}gao;

int d[maxn], idx_tmp[maxn];

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    repf (i, 0, n-1) scanf ("%d%d", &an[i].x.x, &an[i].x.y), an[i].y = i + 1;

    int idx = 0;
    sort (an, an+n, cmp1);
    repf (i, 0, n-1) 
        if (!i || an[i].x.y != an[i-1].x.y) idx_tmp[i] = ++idx;
        else idx_tmp[i] = idx;
    repf (i, 0, n-1) an[i].x.y = idx_tmp[i];

    sort (an, an+n);

    clr (gao.ma, 0);
    repf (i, 0, n-1){
        int r = i;
        d[r] = 1 + gao.ask (1, an[r].x.y-1, 1, idx, 1); ++ r;
        while (r < n && an[r].x.x == an[r-1].x.x){
            d[r] = 1 + gao.ask (1, an[r].x.y-1, 1, idx, 1); ++ r;
        }
        repf (j, i, r-1) gao.update (an[j].x.y, d[j], 1, idx, 1);
        i = r - 1;
    }

    int pos = 0;
    repf (i, 0, n-1) if (d[i] > d[pos]) pos = i;
    vi ans; ans.pb (an[pos].y);
    repd (i, pos-1, 0){
        if (an[i].x.y < an[pos].x.y && an[i].x.x < an[pos].x.x && d[i] + 1 == d[pos]) ans.pb (an[i].y), pos = i;
    }
    printf ("%d\n", sz(ans));
    repf (i, 0, sz(ans)-1){
        if (i) printf (" ");
        printf ("%d", ans[i]);
    }
    puts ("");
    return 0;
}
