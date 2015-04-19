/*
 * Author:  Plumrain
 * Created Time:  2014/9/26 14:37:04
 * File Name: HDU5030.cpp
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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(1e5) + 9;

struct SA{
    int n;
    int sa[maxn];       //排第几的是谁, sa[i] = j, i from 1 to n, j from 0 to n-1
    int rank[maxn];     //你排第几, rank[i] = j, i from 0 to n-1, j from 1 to n
    int h[maxn];        //hei[i] = LCP(suffix(sa[i-1], sa[i]), i from 1 to n
    int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    //r[], from 0 to n-1
    void build(int *r, int n, int m)
    {
        r[n] = 0; this -> n = n ++;
        
        int i, j, p, *x=wa, *y=wb, *t;
        for (int i = 0; i < m; ++ i) wt[i] = 0;
        for (int i = 0; i < n; ++ i) wt[x[i]=r[i]] ++;
        for (int i = 1; i < m; ++ i) wt[i] += wt[i-1];
        for (int i = n-1; i >= 0; -- i) sa[--wt[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for(p = 0, i = n-j; i < n; i++) y[p++] = i;
            for (int i = 0; i < n; ++ i) if (sa[i] >= j) y[p++] = sa[i] - j;
            for (int i = 0; i < n; ++ i) wv[i] = x[y[i]];
            for (int i = 0; i < m; ++ i) wt[i] = 0;
            for (int i = 0; i < n; ++ i) wt[wv[i]] ++;
            for (int i = 1; i < m; ++ i) wt[i] += wt[i-1];
            for (int i = n-1; i >= 0; -- i) sa[--wt[wv[i]]] = y[i];
            for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
                x[sa[i]] = cmp (y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        return;
    }

    void calhei(int *r){
        int i, j, k = 0;
        for (int i = 1; i <= n; ++ i) rank[sa[i]] = i;
        for(i = 0; i < n; h[rank[i++]] = k)
            for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
        return;
    }
}sa;

int ss[maxn];
ll num[maxn];
int ans_x, ans_y, L, K;
int idx1[maxn], idx2[maxn];
bool vis[maxn];
char str[maxn], stk[maxn];
pii an[maxn];

int calc (ll p){
    int l = 1, r = L, res = L;
    while (l <= r){
        int m = (l + r) >> 1;
        if (num[m-1] < p + 1) res = m, l = m + 1;
        else r = m - 1;
    }
    ans_x = sa.sa[res];
    ans_y = ans_x + sa.h[res] - 1 + (p + 1 - num[res-1]);
    return res;
}

bool cmp1 (int a, int b){
    return an[a].y == an[b].y ? an[a].x < an[b].x : an[a].y < an[b].y;
}
bool cmp2 (int a, int b){
    return an[a].x == an[b].x ? an[a].y < an[b].y : an[a].x < an[b].x;
}

int ok (ll p){
    int t1 = 0;
    int pos = calc (p);
    if (ans_y != L - 1 && !K) return 0;
    an[t1].x = ans_x; an[t1++].y = ans_y;
    for (int i = pos+1, mi = ans_y - ans_x + 1; i <= L; ++ i){
        chmin (mi, sa.h[i]);
        if (!mi) return 0;
        an[t1].x = sa.sa[i];
        an[t1++].y = sa.sa[i] + mi - 1;
    }
    
    clr (vis, 0);
    rep (i, 0, t1-1) idx1[i] = idx2[i] = i;
    sort (idx1, idx1+t1, cmp1);
    sort (idx2, idx2+t1, cmp2);
    for (int cnt = 0, i = 0, j = 0; i < t1; ++ i) if (!vis[idx1[i]]){
        if (an[idx1[i]].y < L - 1) ++ cnt;
        if (cnt > K) return 0;

        while (j < t1 && an[idx2[j]].x <= an[idx1[i]].y){
            vis[idx2[j++]] = 1;
        }
    }
    return 1;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    while (scanf ("%d", &K) && K){
        -- K;
        scanf ("%s", str);
        L = strlen (str);
        rep (i, 0, L-1) ss[i] = str[i] - 'a' + 1;

        sa.build (ss, L, 30);
        sa.calhei (ss);
        rep (i, 1, L){
            num[i] = num[i-1] + L - sa.sa[i] - sa.h[i];
        }

        ll l = 0, r = num[L] - 1;
        int ansl = 0, ansr = 0;
        while (l <= r){
            ll m = (l + r) >> 1;
            if (ok (m)) ansl = ans_x, ansr = ans_y, r = m - 1;
            else l = m + 1;
        }

        int top = 0;
        rep (i, ansl, ansr) stk[top++] = str[i];
        stk[top] = 0;
        puts (stk);
    }
    return 0;
}

