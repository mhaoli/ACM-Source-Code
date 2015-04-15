/*
 * Author:  Plumrain
 * Created Time:  2014/7/20 13:36:14
 * File Name: D.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct RMQ{
    int d[maxn][35];

    void init(int *an, int n){
        repf (i, 1, n) d[i][0] = an[i];
        for (int j = 1; (1<<j) <= n; ++ j)
            for (int i = 1; i + (1<<j) - 1 <= n; ++ i)
                d[i][j] = min (d[i][j-1], d[i+(1<<(j-1))][j-1]);
    }

    int calc(int *an, int a, int b){
        if (a > b) return 0;
        int k = 0;
        while ((1<<(k+1)) <= b - a + 1) ++ k;
        return min (d[a][k], d[b-(1<<k)+1][k]);
    }
}rmq;

struct SA{
    int n;
    int sa[maxn];
    int rank[maxn];
    int h[maxn];
    int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    void build_sa(int *r, int n, int m)
    {
        r[n] = 0; this -> n = n ++;
        
        int i, j, p, *x=wa, *y=wb, *t;
        repf (i, 0, m-1) wt[i] = 0;
        repf (i, 0, n-1) wt[x[i]=r[i]] ++;
        repf (i, 1, m-1) wt[i] += wt[i-1];
        repd (i, n-1, 0) sa[--wt[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for(p = 0, i = n-j; i < n; i++) y[p++] = i;
            repf (i, 0, n-1) if (sa[i] >= j) y[p++] = sa[i] - j;
            repf (i, 0, n-1) wv[i] = x[y[i]];
            repf (i, 0, m-1) wt[i] = 0;
            repf (i, 0, n-1) wt[wv[i]] ++;
            repf (i, 1, m-1) wt[i] += wt[i-1];
            repd (i, n-1, 0) sa[--wt[wv[i]]] = y[i];
            for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        return;
    }

    void calhei(int *r){
        int i, j, k = 0;
        repf (i, 1, n) rank[sa[i]] = i;
        for(i = 0; i < n; h[rank[i++]] = k)
            for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        return;
    }
}gao;

char ss[maxn];
int s[maxn];
bool vis[maxn];    //pos in string

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    scanf ("%s", ss);
    int n = strlen(ss);
    repf (i, 0, n-1) s[i] = ss[i] - 'A' + 1;
    gao.build_sa (s, n, 50);
    gao.calhei (s);

    int cnt = 1;
    clr (vis, 0);
    int p0 = gao.rank[0], tma = n;
    repf (i, p0+1, n){
        int tp = gao.sa[i], tl = n - tp;
        chmin (tma, gao.h[i]);
        if (tma >= tl) vis[tl] = 1, ++ cnt;
    }
    tma = n;
    repd (i, p0, 2){
        int tp = gao.sa[i-1], tl = n - tp;
        chmin (tma, gao.h[i]);
        if (tma >= tl) vis[tl] = 1, cnt ++;
    }

    printf ("%d\n", cnt);

    rmq.init (gao.h, n);
    repf (tl, 1, n-1) if (vis[tl]){
        printf ("%d ", tl);
        int tp = gao.rank[n-tl], ans = 0;

        int l = 1, r = tp, tpos = tp;
        while (l <= r){
            int m = (l + r) >> 1;
            if (rmq.calc (gao.h, m+1, tp) >= tl) tpos = m, r = m - 1;
            else l = m + 1;
        }
        ans += tp - tpos + 1;

        l = tp+1, r = n; tpos = tp;
        while (l <= r){
            int m = (l + r) >> 1;
            if (rmq.calc (gao.h, tp+1, m) >= tl) tpos = m, l = m + 1;
            else r = m - 1;
        }

        printf ("%d\n", ans + tpos - tp);
    }
    printf ("%d 1\n", n);
    return 0;
}
