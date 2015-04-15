/*
 * Author:  Plumrain
 * Created Time:  2014/9/11 23:41:57
 * File Name: C.cpp
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
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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

const int maxn = int(1e5) + 9;
struct RMQ{
    int gd[maxn][25], log2[maxn];
    void init (int n, int *a){ //a: 0...n-1
        for (int i = 0; i < n; ++ i){
            gd[i][0] = a[i];
            log2[i] = (!i ? -1 : log2[i>>1] + 1);
        }
        for (int j = 1, l = 2; l < n; ++ j, l <<= 1){
            for (int i = 0; i + l <= n; ++ i)
                gd[i][j] = __gcd (gd[i][j-1], gd[i+(l>>1)][j-1]);
        }
    }
    int query (int a, int b){ //[a, b]
        int k = log2[b - a + 1];
        return __gcd (gd[a][k], gd[b-(1<<k)+1][k]);
    }
}rmq;

struct Calc{
    int val, n, tot;
    int left[maxn], right[maxn], f[maxn], idx[maxn];
    int bL[maxn], bR[maxn];
    int64 s[maxn], sl[maxn];
    void init (int *a, int _n, int _val){
        val = _val; n = _n;
        for (int i = 0, p1 = 0, p2 = 0; i < n; ++ i){
            if (a[i] % val == 0){
                while (p1 < i) ++ p1;
                while (p1 < n && a[p1]%val == 0 && rmq.query (i, p1) != val) ++ p1;
                chmax (p2, p1);
                while (p2 < n && a[p2]%val == 0) ++ p2;
                left[i] = p1; right[i] = p2;
            } else left[i] = right[i] = i;
        }

        //int __ = 3;
        //if (val == __){
            //out (val);
            //rep (i, 0, n-1) tst (left[i]); cout << endl;
            //rep (i, 0, n-1) tst (right[i]); cout << endl;
        //}

        f[n-1] = right[n-1] - left[n-1];
        for (int i = n-2; i >= 0; -- i){
            if (left[i] < right[i]) f[i] = f[i+1] + right[i] - left[i];
            else f[i] = 0;
        }

        //if (val == __){
            //reptest (f, n);
        //}
//
        tot = 0;
        bL[0] = 0;
        s[0] = f[0];
        for (int i = 0; i < n; ++ i){
            if (a[i] % val){
                bR[tot] = i;
                idx[i] = tot++;
                bL[tot] = i + 1;
                s[tot] = s[tot-1] + f[i+1];
            }
            else idx[i] = tot;
        }
        bR[tot] = n;
        ++ tot;

        //if (val == __){
            //reptest (idx, n);
            //reptest (bL, tot);
            //reptest (bR, tot);
            //reptest (s, tot);
        //}

        sl[0] = left[0];
        for (int i = 1; i < n; ++ i) sl[i] = sl[i-1] + left[i];
    }
    int64 query (int l, int r){
        int tl = idx[l], tr = idx[r];
        if (tl == tr){
            if (r == bR[tr]) -- r;
            return query (l, r, tr);
        } else{
            int64 ret = 0;
            if (tl != tr - 1) ret = s[tr-1] - s[tl];
            if (r == bR[tr]) -- r;
            //if (val == 3) out (ret), out (query (l, bR[tl]-1, tl)), out (query (bL[tr], r, tr));
            return query (l, bR[tl]-1, tl) + query (bL[tr], r, tr) + ret;
        }
    }
    int64 query (int ql, int qr, int id){
        if (ql > qr) return 0;
        int l = ql, r = qr, res = l-1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (left[mid] <= qr) res = mid, l = mid + 1;
            else r = mid - 1;
        }

        if (res < ql) return 0;
        return (res - ql + 1LL) * (qr + 1) - (sl[res] - (ql > 0 ? sl[ql-1] : 0));
    }
}gao[55];

int a[maxn], b[maxn], rb[maxn];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m, q;
    while (scanf ("%d%d%d", &n, &m, &q) != EOF){
        rep (i, 0, n-1){
            scanf ("%d", a + i);
        }
        rmq.init (n, a);
        rep (i, 0, m-1){
            scanf ("%d", b + i);
        }
        sort (b, b + m);
        rep (i, 0, m-1){
            rb[b[i]] = i;
        }
        rep (i, 0, m-1) gao[i].init (a, n, b[i]);

        while (q--){
            int t, l, r;
            scanf ("%d%d%d", &l, &r, &t);
            printf ("%lld\n", gao[rb[t]].query (l, r-1));
        }
    }
    return 0;
}
