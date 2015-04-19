/*
 * Author:  Plumrain
 * Created Time:  2014-03-03 15:41
 * File Name: DS-HDU-3397.cpp
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
const int maxn = 100001;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int lsum[2][maxn<<2], rsum[2][maxn<<2], msum[2][maxn<<2], sum[maxn<<2], cov[maxn<<2], cha[maxn<<2];

void COV (int v, int rt, int l, int r){
    cov[rt] = v; cha[rt] = 0;
    lsum[1][rt] = msum[1][rt] = rsum[1][rt] = v ? r - l + 1 : 0;
    lsum[0][rt] = msum[0][rt] = rsum[0][rt] = !v ? r - l + 1 : 0;
    sum[rt] = v ? r - l + 1 : 0;
}

void CHA (int rt, int l, int r){
    if (cov[rt] != -1) cov[rt] ^= 1;
    else cha[rt] ^= 1;

    swap (lsum[0][rt], lsum[1][rt]); swap (rsum[1][rt], rsum[0][rt]); swap (msum[1][rt], msum[0][rt]);
    sum[rt] = r - l + 1 - sum[rt];
}

void gao(int t, int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
    lsum[t][rt] = lsum[t][ls]; rsum[t][rt] = rsum[t][rs];
    if (lsum[t][ls] == m - l + 1) lsum[t][rt] += lsum[t][rs];
    if (rsum[t][rs] == r - m) rsum[t][rt] += rsum[t][ls];
    msum[t][rt] = max ( max (msum[t][ls], msum[t][rs]), rsum[t][ls] + lsum[t][rs]);
}

void pushdown (int rt, int l, int r){
    int m = (l + r) >> 1;
    if (cov[rt] != -1){
        COV (cov[rt], lson); COV (cov[rt], rson);
        cha[rt] = 0; cov[rt] = -1;
    }

    if (cha[rt]){
        CHA (lson); CHA (rson);
        cha[rt] = 0; 
    }
}

void pushup (int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1;
    sum[rt] = sum[rs] + sum[ls];
    gao (0, rt, l, r); gao (1, rt, l, r);
}

void build (int rt, int l, int r){
    if (l == r){
        scanf ("%d", &cov[rt]);
        COV (cov[rt], rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    pushdown (rt, l, r);
    build (lson); build (rson); 
    pushup (rt, l, r);
}

void update (bool u, int ql, int qr, int v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        if (!u) COV (v, rt, l, r);
        else CHA (rt, l, r);
        return;
    }

    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) update (u, ql, qr, v, lson);
    if (qr > m) update (u, ql, qr, v, rson);
    pushup (rt, l, r);
}

int query (bool u, int ql, int qr, int rt, int l, int r){
    if (ql <= l && qr >= r){
        if (!u) return sum[rt];
        else return msum[1][rt];
    }

    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    int ret = 0;
    if (ql <= m) ret = query (u, ql, qr, lson);
    if (u){
        if (ql <= m && qr > m){
            int tl = max (ql, m - rsum[1][rt<<1] + 1);
            int tr = min (qr, m + lsum[1][rt<<1|1]);
            checkmax (ret, tr - tl + 1);
        }
        if (qr > m) checkmax (ret, query (u, ql, qr, rson));
    }
    else if (qr > m) ret += query (u, ql, qr, rson);
    return ret;

}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, n, m;
    scanf ("%d", &T);
    while (T --){
        scanf ("%d%d", &n, &m);
        -- n;
        build (1, 0, n);
        int op, a, b;
        while (m --){
            scanf ("%d%d%d", &op, &a, &b);
            if (op == 0) update (0, a, b, 0, 1, 0, n);
            else if (op == 1) update (0, a, b, 1, 1, 0, n);
            else if (op == 2) update (1, a, b, 1, 1, 0, n);
            else if (op == 3) printf ("%d\n", query (0, a, b, 1, 0, n));
            else printf ("%d\n", query (1, a, b, 1, 0, n));
        }
    }
    return 0;
}
