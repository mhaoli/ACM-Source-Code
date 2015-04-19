/*
 * Author:  Plumrain
 * Created Time:  2014/7/31 23:17:43
 * File Name: C.cpp
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
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 1; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 300005;
const int mod = 1e9 + 9;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int sum[maxn<<2];
pii num[maxn<<2];
pii fib[maxn], fsum[maxn];

void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

void add (pii &a, pii b){
    add (a.x, b.x); add (a.y, b.y);
}

int ask_sum (int l, int r, int rt){
    int ret = sum[rt];
    add (ret, (int)(1LL * fsum[r-l+1].x * num[rt].x % mod));
    add (ret, (int)(1LL * fsum[r-l+1].y * num[rt].y % mod));
    return ret;
}

void pushup (int l, int r, int rt){
    int m = (l + r) >> 1;
    sum[rt] = ask_sum (lson); add (sum[rt], ask_sum (rson));
}

void pushdown (int l, int r, int rt){
    int m = (l + r) >> 1, ls = rt<<1, rs = ls|1;
    sum[rt] = ask_sum (l, r, rt);
    add (num[ls], num[rt]);
    int tmp = m - l + 2;
    add (num[rs].x, (int)(1LL * num[rt].x * fib[tmp].x % mod));
    add (num[rs].x, (int)(1LL * num[rt].y * fib[tmp].y % mod));
    add (num[rs].y, (int)(1LL * num[rt].x * fib[tmp+1].x % mod));
    add (num[rs].y, (int)(1LL * num[rt].y * fib[tmp+1].y % mod));
    num[rt].x = num[rt].y = 0;
}

void build (int l, int r, int rt){
    num[rt].x = num[rt].y = 0;
    if (l == r){
        scanf ("%d", &sum[rt]); return ;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson);
    pushup (l, r, rt);
}

void update (int ql, int qr, int t1, int t2, int l, int r, int rt){
    if (ql <= l && r <= qr){
        int p = l - ql + 1;
        int tmp = 1LL * t1 * fib[p].x % mod; add (tmp, (int)(1LL * t2 * fib[p].y % mod));
        add (num[rt].x, tmp);
        tmp = 1LL * t1 * fib[p+1].x % mod; add (tmp, (int)(1LL * t2 * fib[p+1].y % mod));
        add (num[rt].y, tmp); return;
    }
    pushdown (l, r, rt);
    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, t1, t2, lson);
    if (qr > m) update (ql, qr, t1, t2, rson);
    pushup (l, r, rt);
}

int query (int ql, int qr, int l, int r, int rt){
    if (ql <= l && r <= qr) return ask_sum (l, r, rt);
    int m = (l + r) >> 1, ret = 0;
    pushdown (l, r, rt);
    if (ql <= m) add (ret, query (ql, qr, lson));
    if (qr > m) add (ret, query (ql, qr, rson));
    pushup (l, r, rt);
    return ret;
}

void fib_init(int n){
    fib[1].x = 1; fib[1].y = 0;
    fib[2].x = 0; fib[2].y = 1;
    repf (i, 3, n){
        //fib[i].x = fib[i-1].x; add (fib[i].x, fib[i-2].x);
        //fib[i].y = fib[i-1].y; add (fib[i].y, fib[i-2].y);
        fib[i] = fib[i-1]; add (fib[i], fib[i-2]);
    }

    fsum[1] = fib[1];
    repf (i, 2, n){
        //fsum[i].x = fib[i].x; add (fsum[i].x, fsum[i-1].x);
        //fsum[i].y = fib[i].y; add (fsum[i].y, fsum[i-1].y);
        fsum[i] = fsum[i-1]; add (fsum[i], fib[i]);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    fib_init (300000);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        build (1, n, 1);
        while (m--){
            int t, x, y; scanf ("%d%d%d", &t, &x, &y);
            if (t == 1) update (x, y, 1, 1, 1, n, 1);
            else printf ("%d\n", query (x, y, 1, n, 1));
        }
    }
    return 0;
}
