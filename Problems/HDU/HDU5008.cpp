/*
 * Author:  Plumrain
 * Created Time:  2014/9/14 14:18:51
 * File Name: 1002.cpp
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
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define log2 lg2
const int maxn = int(1e5) + 9;
int lmi[maxn][30], log2[maxn], mi[maxn][30];

void build_mx (int n, int *a, int mx[][30]){ //a: 0...n-1
    for (int i = 1; i <= n; ++ i){
        mx[i][0] = a[i];
    }
    for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
        for (int i = 1; i + l - 1 <= n; ++ i)
            mx[i][j] = max (mx[i][j-1], mx[i+(l>>1)][j-1]);
    }
}
void build_mi (int n, int *a, int mi[][30]){
    for (int i = 1; i <= n; ++ i){
        mi[i][0] = a[i];
    }
    for (int j = 1, l = 2; l <= n; ++ j, l <<= 1){
        for (int i = 1; i + l - 1 <= n; ++ i)
            mi[i][j] = min (mi[i][j-1], mi[i+(l>>1)][j-1]);
    }
}
int query_mx (int a, int b, int mx[][30]){ //[a, b]
    int k = log2[b - a + 1];
    return max (mx[a][k], mx[b-(1<<k)+1][k]);
}
int query_mi (int a, int b, int mi[][30]){
    int k = log2[b - a + 1];
    return min (mi[a][k], mi[b-(1<<k)+1][k]);
}

struct SA{
    const static int maxn = int(2e5) + 9;

    int n;
    int sa[maxn];       //排第几的是谁, sa[i] = j, i from 1 to n, j from 0 to n-1
    int rank[maxn];     //你排第几, rank[i] = j, i from 0 to n-1, j from 1 to n
    int h[maxn];        //hei[i] = LCP(suffix(sa[i-1], sa[i]), i from 1 to n
    int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

    int cmp(int *r, int a, int b, int l){
        return r[a]==r[b] && r[a+l]==r[b+l];
    }

    //r[], from 0 to n-1
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

int ql, qr, L;
char str[maxn];
int sdig[maxn];
int64 num[maxn];

void init (char *s){
    rep (i, 0, L-1) sdig[i] = s[i] - 'a' + 1;
    gao.build_sa (sdig, L, 30);
    gao.calhei (sdig);

    //build_mx (L, gao.h);
    build_mi (L, gao.h, lmi);
    build_mi (L, gao.sa, mi);

    num[0] = 0;
    rep (i, 1, L){
        num[i] = num[i-1] - gao.h[i] + (L - gao.sa[i]);
    }
}

int lcp (int t1, int t2){
    if (t1 == t2) return L - gao.sa[t1];
    return query_mi (t1+1, t2, lmi);
}

void calc(int64 k){
    if (num[L] < k){
        ql = qr = -1; return;
    }

    int p = 0, l = 0, r = L;
    while (l <= r){
        int m = (l + r) >> 1;
        if (num[m] >= k) p = m, r = m - 1;
        else l = m + 1;
    }

    int pos = gao.h[p] + (k - num[p-1]) - 1;

    int tL = p, tR = p;
    l = 1; r = p;
    while (l <= r){
        int m = (l + r) >> 1;
        if (lcp (m, p) >= pos+1) tL = m, r = m - 1;
        else l = m + 1;
    }
    l = p; r = L;
    while (l <= r){
        int m = (l + r) >> 1;
        if (lcp (p, m) >= pos+1) tR = m, l = m + 1;
        else r = m - 1;
    }
    ql = query_mi (tL, tR, mi);
    qr = ql + pos;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    log2[0] = -1;
    for (int i = 1; i < maxn-5; ++ i) log2[i] = log2[i>>1] + 1;

    while (scanf ("%s", str) != EOF){
        L = strlen (str);
        init (str);

        //rep (i, 0, L) tst (num[i]); cout << endl;

        //rep (i, 0, 2){
            //rep (j, 0, 3) tst (lmi[j][i]); cout << endl;
        //}
//
        int q;
        scanf ("%d", &q);
        ql = qr = 0;
        int64 k;
        while (q--){
            scanf ("%I64d", &k);
            int64 ll = ql + 1, rr = qr + 1;
            k = (k ^ ll ^ rr) + 1;
            //cout << ll << " " << rr << " ";
            //out (k);
            calc (k);
            printf ("%d %d\n", ql + 1, qr + 1);
        }
    }
    return 0;
}
