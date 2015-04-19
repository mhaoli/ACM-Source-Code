/*
 * Author:  Plumrain
 * Created Time:  2014/8/10 15:06:46
 * File Name: F.cpp
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
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
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;
const int maxm = 1e6 + 5;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an[maxn], bn[maxn], pre[maxn], pos[maxm], stk[maxn];

struct Seg{
    #define lson l, m, rt<<1
    #define rson m+1, r, rt<<1|1

    int ma[maxm<<2];
    int num[maxm]; 

    void pushup (int rt){
        ma[rt] = ma[rt<<1];
        if (num[ma[rt]] < num[ma[rt<<1|1]]) ma[rt] = ma[rt<<1|1];
    }

    void build (int l, int r, int rt){
        if (l == r){
            ma[rt] = l; return;
        }

        int m = (l + r) >> 1;
        build (lson); build (rson);
        pushup (rt);
    }
    void update (int q, int l, int r, int rt){
        if (l == r) return;
        int m = (l + r) >> 1;
        if (m >= q) update (q, lson);
        else update (q, rson);
        pushup (rt);
    }
    int calc (int ql, int qr, int l, int r, int rt){
        if (ql > qr) return maxm-3;
        if (ql <= l && qr >= r) return ma[rt];

        int m = (l + r) >> 1, ret = maxm-3;
        if (m >= ql){
            int tidx = calc (ql, qr, lson);
            if (num[ret] <= num[tidx]) ret = tidx;
        }
        if (m < qr){
            int tidx = calc (ql, qr, rson);
            if (num[ret] <= num[tidx]) ret = tidx;
        }
        return ret;
    }
    void solve (int nn, int tot, int mx){
        build (0, mx, 1);
        int ans = 0, tmp, ans_idx = 0;
        clr (num, 0); clr (pos, -1);
        repf (i, 0, tot-1){
            tmp = num[an[i]]; pre[i] = pos[an[i]]; pos[an[i]] = i;

            int tidx = calc (0, an[i]-2, 0, mx, 1);
            if (chmax (tmp, num[tidx])) pre[i] = pos[tidx];

            tidx = calc (an[i]+2, mx, 0, mx, 1);
            if (chmax (tmp, num[tidx])) pre[i] = pos[tidx];

            tmp += bn[i];
            num[an[i]] = tmp;
            update (an[i], 0, mx, 1);
            if (chmax (ans, tmp)) ans_idx = i;
        }

        printf ("%d\n", nn - ans);

        int top = 0;
        while (1){
            stk[top++] = ans_idx;
            ans_idx = pre[ans_idx];
            if (ans_idx == -1) break;
        }

        repd (i, top-1, 0){
            if (i != top-1) printf (" ");
            repf (j, 0, bn[stk[i]]-1){
                if (j) printf (" ");
                printf ("%d", an[stk[i]]);
            }
        }
        puts ("");
    }
}gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, t, last, cnt = 1; scanf ("%d%d", &n, &last);
    int tot = 0, mx = last;
    repf (i, 0, n-2){
        scanf ("%d", &t); chmax (mx, t);
        if (t == last) ++ cnt;
        else{
            an[tot] = last; bn[tot++] = cnt;
            last = t; cnt = 1;
        }
    }
    an[tot] = last; bn[tot++] = cnt;
            
    gao.solve (n, tot, mx);
    return 0;
}
