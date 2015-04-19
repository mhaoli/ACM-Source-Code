/*
 * Author:  Plumrain
 * Created Time:  2014-02-25 21:35
 * File Name: DS-HDU-1698.cpp
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
#define lson 2*rt, l, m
#define rson 2*rt+1, m+1, r
#define repf(i, a, b) for(int i = (a); i <= (b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int col[maxn<<2], sum[maxn<<2];

void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushdown(int rt, int l, int r) {
    if (col[rt] > 0){
        int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
        col[ls] = col[rs] = col[rt];
        sum[ls] = col[ls] * (m - l + 1);
        sum[rs] = col[rs] * (r - m);
        col[rt] = -1;
    }
}

void build (int rt, int l, int r) {
    col [rt] = -1;
    if (l == r){
        sum[rt] = 1; return;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson); pushup (rt);
}

void update (int ql, int qr, int v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        col[rt] = v; 
        sum[rt] = col[rt] * (r - l + 1);
        return;
    }
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, v, lson);
    if (qr > m) update (ql, qr, v, rson);
    pushup (rt);
}

int query (int ql, int qr, int rt, int l, int r){
    if (ql <= l && qr >= r) return sum[rt];
    pushdown (rt, l, r);
    int m = (l + r) >> 1, ret = 0;
    if (ql <= m) ret += query (ql, qr, lson);
    if (qr > m) ret += query (ql, qr, rson);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        int n, q, t1, t2, v;
        scanf ("%d%d", &n, &q);
        build(1, 1, n);
        while (q --){
            scanf ("%d%d%d", &t1, &t2, &v);
            update (t1, t2, v, 1, 1, n);
        }
        printf ("Case %d: The total value of the hook is %d.\n", ++ cas, query (1, n, 1, 1, n));
    }
    return 0;
}
