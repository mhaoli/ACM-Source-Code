/*
 * Author:  Plumrain
 * Created Time:  2014-02-27 20:45
 * File Name: E.cpp
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
const int N = 300005;
const int mod = 1000000007;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int flag;
vi pat[N];
int64 xn[N<<2], vn[N<<2], sum[N<<2];
int bgn[N], end[N], len[N];

void dfs (int x, int tlen){
    bgn[x] = ++ flag; len[x] = tlen;
    repf (i, 0, sz(pat[x])-1)
        dfs (pat[x][i], tlen + 1);
    end[x] = flag;
}

void pushdown(int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1;
    xn[ls] = (xn[ls] + xn[rt] + mod) % mod;
    xn[rs] = (xn[rs] + xn[rt] + mod) % mod;
    xn[rt] = 0;
    vn[ls] = (vn[ls] + vn[rt] + mod) % mod;
    vn[rs] = (vn[rs] + vn[rt] + mod) % mod;
    vn[rt] = 0;
}

int64 query (int a, int64 tlen, int rt, int l, int r){
    if (l == r && a == l){
        int64 ret = (xn[rt] - vn[rt] * tlen % mod) % mod;
        return ret < 0 ? ret+mod : ret;
    }
    int m = (l + r) >> 1;
    pushdown (rt, l, r);
    if (a <= m) return query (a, tlen, lson);
    else return query (a, tlen, rson);
}

void update (int ql, int qr, int64 x, int64 v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        xn[rt] = (xn[rt] + x + mod) % mod;
        vn[rt] = (vn[rt] + v + mod) % mod;
        return ;
    }
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) update (ql, qr, x, v, lson);
    if (qr > m) update (ql, qr, x, v, rson);
}

int64 calc (int x, int v, int a){
    return (x + (int64)v * len[a]) % mod;
}

int main()
{
//    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n;
    while (scanf ("%d", &n) != EOF){
        int t, q;
        repf (i, 1, n) pat[i].clear();
        repf (i, 2, n){
            scanf ("%d", &t);
            pat[t].pb (i);
        }
        clr (bgn, 0); clr (end, 0); clr (len, 0);
        flag = 0;
        dfs (1, 0);

        //repf (i, 1, n){
            //cout << i << " : ";
            //repf (j, 0, sz(pat[i])-1) tst (pat[i][j]);
            //cout << endl;
//
        //}
//
        clr (xn, 0); clr (vn, 0); clr (sum, 0);
        scanf ("%d", &q);
        while (q--){
            int op, a, x, v;
            scanf ("%d", &op);
            if (op == 2){
                scanf ("%d", &a);
                printf ("%d\n", (int)query (bgn[a], (int64)len[a], 1, 1, n));
            }
            else{
                scanf ("%d%d%d", &a, &x, &v);
                update (bgn[a], end[a], calc(x, v, a), (int64)v, 1, 1, n);
            }
        }
    }
    return 0;
}
