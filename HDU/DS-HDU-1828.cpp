/*
 * Author:  Plumrain
 * Created Time:  2014-03-04 12:42
 * File Name: DS-HDU-1828.cpp
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
const int maxn = 40002;
const int add = 20000;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct seg{
    int x1, x2, y, u;
    seg(){}
    seg(int a, int b, int c, int d) : x1(a), x2(b), y(c), u(d) {}
    bool operator < (const seg &cmp) const{
        return y < cmp.y;
    }
};

seg sn[maxn];
bool lbd[maxn<<2], rbd[maxn<<2];
int cnt[maxn<<2], len[maxn<<2], cov[maxn<<2];

void pushup (int rt, int l, int r){
    if (cov[rt]){
        lbd[rt] = rbd[rt] = 1;
        len[rt] = r - l + 1;
        cnt[rt] = 2;
    }
    else if (l == r) lbd[rt] = rbd[rt] = len[rt] = cnt[rt] = 0;
    else{
        lbd[rt] = lbd[rt<<1]; rbd[rt] = rbd[rt<<1|1];
        cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
        len[rt] = len[rt<<1] + len[rt<<1|1];
        if (lbd[rt<<1|1] && rbd[rt<<1]) cnt[rt] -= 2;
    }
}

void update (int ql, int qr, int v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        cov[rt] += v;
        pushup (rt, l, r);
        return;
    }

    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, v, lson);
    if (qr > m) update (ql, qr, v, rson);
    pushup (rt, l, r);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        int x1, y1, x2, y2;
        int m = 0;
        repf (i, 0, n-1){
            scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
            sn[m++] = seg (x1, x2, y1, 1);
            sn[m++] = seg (x1, x2, y2, -1);
        }
        sort (sn, sn + m);

        clr (rbd, 0); clr (lbd, 0);
        clr (cnt, 0); clr (len, 0); clr (cov, 0);
        int ans = 0, last = 0;
        repf (i, 0, m-1){
            x1 = sn[i].x1 + add; x2 = sn[i].x2 + add;
            update (x1, x2-1, sn[i].u, 1, 0, maxn);
            ans += cnt[1] * (sn[i + 1].y - sn[i].y);
            ans += abs(len[1] - last);
            last = len[1];
        }
        printf ("%d\n", ans);
    }
    return 0;
}
