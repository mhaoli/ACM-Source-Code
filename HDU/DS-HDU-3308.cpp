/*
 * Author:  Plumrain
 * Created Time:  2014-03-03 00:10
 * File Name: DS-HDU-3308.cpp
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
const int maxn = 100000;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int num[maxn<<2], lsum[maxn<<2], rsum[maxn<<2], msum[maxn<<2];

void pushup (int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
    lsum[rt] = lsum[ls]; rsum[rt] = rsum[rs];
    if (lsum[ls] == (m - l + 1) && num[m+1] > num[m])
        lsum[rt] += lsum[rs]; 
    if (rsum[rs] == (r - m) && num[m+1] > num[m])
        rsum[rt] += rsum[ls];
    msum[rt] = max (msum[ls], msum[rs]);
    if (num[m+1] > num[m]) checkmax (msum[rt], rsum[ls] + lsum[rs]);
}

void build (int rt, int l, int r){
    if (l == r){
        scanf ("%d", &num[l]);
        lsum[rt] = rsum[rt] = msum[rt] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson); pushup (rt, l, r);
}

void update (int q, int v, int rt, int l, int r){
    if (l == r){
        num[l] = v;
        lsum[rt] = msum[rt] = rsum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    if (q <= m)  update (q, v, lson);
    else update (q, v, rson);
    pushup (rt, l, r);
}

int query (int ql, int qr, int rt, int l, int r){
    //tst (l), tst (r), tst (rt), out (msum[rt]);
    if (ql <= l && qr >= r) return msum[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (ql <= m && qr > m && num[m+1] > num[m]){
        int tl = max (ql, m - rsum[rt<<1] + 1);
        int tr = min (qr, m + 1 + lsum[rt<<1|1] - 1);
        checkmax (ret, tr - tl + 1);
    }
    if (ql <= m) checkmax (ret, query (ql, qr, lson));
    if (qr > m) checkmax (ret, query (ql, qr, rson));
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m, T;
    scanf ("%d", &T);
    while (T --){
        scanf ("%d%d", &n, &m);
        -- n;
        build (1, 0, n);
        char op[5];
        int a, b;
        while (m --){
            scanf ("%s%d%d", op, &a, &b);
            if (op[0] == 'U') update (a, b, 1, 0, n);
            else printf ("%d\n", query (a, b, 1, 0, n));
        }
    }
    return 0;
}
