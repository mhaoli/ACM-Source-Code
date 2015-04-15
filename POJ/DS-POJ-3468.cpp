/*
 * Author:  Plumrain
 * Created Time:  2014-02-25 19:46
 * File Name: DS-POJ-3468.cpp
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

int64 sum[maxn<<2], add[maxn<<2];

void pushup(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushdown(int rt, int l, int r)
{
    if (add[rt]){
        int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
        add[ls] += add[rt];
        add[rs] += add[rt];
        sum[ls] += add[rt] * (m - l + 1);
        sum[rs] += add[rt] * (r - m);
        add[rt] = 0;
    }
}

void build(int rt, int l, int r)
{
    add[rt] = 0;
    if (l == r){
        scanf ("%lld", &sum[rt]); return;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson); pushup (rt);
}

int64 query(int ql, int qr, int rt, int l, int r)
{
    if (ql <= l && qr >= r) return sum[rt];
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    int64 ret = 0;
    if (ql <= m) ret += query (ql, qr, lson);
    if (qr > m) ret += query (ql, qr, rson);
    return ret;
}

void update(int ql, int qr, int64 v, int rt, int l, int r)
{
    if (ql <= l && qr >= r){
        add[rt] += v; 
        sum[rt] += v * (r - l + 1);
        return;
    }
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, v, lson);
    if (qr > m) update (ql, qr, v, rson);
    pushup (rt);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, q;
    while (scanf ("%d%d", &n, &q) != EOF){
        build (1, 1, n);

        char op[10];
        int t1, t2, v;
        while (q --){
            scanf ("%s", op);
            if (op[0] == 'Q'){
                scanf ("%d%d", &t1, &t2);
                printf ("%lld\n", query (t1, t2, 1, 1, n));
            }
            else{
                scanf ("%d%d%d", &t1, &t2, &v);
                update (t1, t2, (int64)v, 1, 1, n);
            }
        }
    }
    return 0;
}
