/*
 * Author:  Plumrain
 * Created Time:  2014-03-02 16:01
 * File Name: DS-POJ-3667.cpp
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
#define lson rt<<1, l, m
#define rson rt<<1|1, m+1, r
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

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 50005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int cov[maxn<<2], lsum[maxn<<2], msum[maxn<<2], rsum[maxn<<2];

void pushdown (int rt, int l, int r){
    if (cov[rt] != -1){
        int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
        cov[rs] = cov[ls] = cov[rt];
        lsum[rs] = rsum[rs] = msum[rs] = cov[rt] ? 0 : (r - m);
        lsum[ls] = rsum[ls] = msum[ls] = cov[rt] ? 0 : (m - l + 1);
        cov[rt] = -1;
    }
}

void pushup(int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
    lsum[rt] = lsum[ls]; rsum[rt] = rsum[rs];
    if (lsum[ls] == (m - l + 1)) lsum[rt] += lsum[rs];
    if (rsum[rs] == (r - m)) rsum[rt] += rsum[ls];
    msum[rt] = max(max (msum[rs], msum[ls]), rsum[ls] + lsum[rs]);
}

void build (int rt, int l, int r){
    lsum[rt] = rsum[rt] = msum[rt] = r - l + 1;
    cov[rt] = -1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build (lson); build (rson);
}

void update (int ql, int qr, int v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        cov[rt] = v;
        lsum[rt] = rsum[rt] = msum[rt] = v ? 0 : (r - l + 1);
        return;
    }
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, v, lson);
    if (qr > m) update (ql, qr, v, rson);
    pushup(rt, l, r);
}

int query(int v, int rt, int l, int r){
    if (msum[rt] < v) return 0;
    if (l == r) return l;
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (msum[rt<<1] >= v) return query (v, lson);
    if (rsum[rt<<1] + lsum[rt<<1|1] >= v) return m - rsum[rt<<1] + 1;
    return query (v, rson);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        build (1, 1, n);
        int op, a, b;
        while (m --){
            scanf ("%d", &op);
            if (op == 1){
                scanf ("%d", &a);
                int p = query (a, 1, 1, n);
                printf ("%d\n", p);
                if (p) update (p, p+a-1, 1, 1, 1, n);
            }
            else{
                scanf ("%d%d", &a, &b);
                update (a, a + b - 1, 0, 1, 1, n);
            }
        }
    }
    return 0;
}
