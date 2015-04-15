/*
 * Author:  Plumrain
 * Created Time:  2014-03-04 01:12
 * File Name: DS-HDU-1542.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

struct seg{
    double x1, x2, y;
    int u;
    seg(){}
    seg(double a,double b,double c,int d) : x1(a) , x2(b) , y(c) , u(d) {}
    bool operator < (const seg &cmp) const{
        return y < cmp.y;
    }
}sn[500];

double xn[500], sum[500<<2];
int cnt[500<<2];

void pushup (int rt, int l, int r){
    if (cnt[rt]) sum[rt] = xn[r+1] - xn[l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void update (int ql, int qr, int v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        cnt[rt] += v;
        pushup (rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, v, lson);
    if (qr > m) update (ql, qr, v, rson);
    pushup (rt, l, r);
}

int bin_sch(double tar, int l, int r){
    int m, ret = -1;
    while (l <= r){
        m = (l + r) >> 1;
        //if (tar == 25) tst (l), tst (r), tst (m), out (xn[m]);
        if (fabs(tar - xn[m]) < eps) ret = m;
        if (xn[m] < tar + eps) l = m + 1;
        else r = m - 1;
    }
    //if (tar == 25) out (ret);
    return ret;
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, T = 0;
    while (scanf ("%d", &n) != EOF && n){
        int m = 0;
        double x1, y1, x2, y2;
        repf (i, 0, n-1){
            scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            xn[m] = x1;
            sn[m++] = seg (x1, x2, y1, 1);
            xn[m] = x2;
            sn[m++] = seg (x1, x2, y2, -1);
        }
        sort (xn, xn + m); sort (sn, sn + m);

        int k = 1;
        repf (i, 1, m-1)
            if (xn[i] != xn[i-1]) xn[k++] = xn[i];

        //repf (i, 0, k-1) tst (i), out (xn[i]);
        //cout << endl << endl;
//
        double ans = 0;
        clr (sum, 0); clr (cnt, 0);
        repf (i, 0, m - 2){
            int ql = bin_sch (sn[i].x1, 0, k - 1);
            int qr = bin_sch (sn[i].x2, 0, k - 1) - 1;
            if (ql <= qr) update (ql, qr, sn[i].u, 1, 0, k - 1);
            ans += sum[1] * (sn[i+1].y - sn[i].y);
        }
        printf ("Test case #%d\nTotal explored area: %.2f\n\n", ++ T, ans); 
    }
    return 0;
}
