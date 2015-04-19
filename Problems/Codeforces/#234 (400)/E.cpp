/*
 * Author:  Plumrain
 * Created Time:  2014-03-10 21:16
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
#define two(x) (1LL<<(x))
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
const int maxn = 100006;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int ansl, ansr;
int an[maxn], num[20][maxn];
int lsum[20][maxn<<2], rsum[20][maxn<<2], msum[20][maxn<<2];

void pushup (int idx, int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1, m = (l + r) >> 1;
    lsum[idx][rt] = lsum[idx][ls]; rsum[idx][rt] = rsum[idx][rs];
    if (lsum[idx][ls] == m - l + 1) lsum[idx][rt] += lsum[idx][rs];
    if (rsum[idx][rs] == r - m) rsum[idx][rt] += rsum[idx][ls];
    msum[idx][rt] = max (max (msum[idx][ls], msum[idx][rs]), rsum[idx][ls] + lsum[idx][rs]);
}

void build (int rt, int l, int r){
    if (l == r){
        int tmp, idx = 0;
        scanf ("%d", &tmp);
        while (tmp){
            int t = tmp & 1;
            num[idx][l] = t;
            lsum[idx][rt] = rsum[idx][rt] = msum[idx][rt] =  t;
            ++ idx;
            tmp >>= 1;
        }
        return;
    }
    int m = (l + r) >> 1;
    build (lson); build (rson);
    repf (i, 0, 19) pushup (i, rt, l, r);
}

void update (int t1, int idx, int v, int rt, int l, int r){
    if (l == r){
        lsum[idx][rt] = rsum[idx][rt] = msum[idx][rt] = v;
        num[idx][l] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (t1 <= m) update (t1, idx, v, lson);
    if (t1 > m) update (t1, idx, v, rson);
    pushup (idx, rt, l, r);
}

void query (int t1, int idx, int rt, int l, int r){
    //if (idx == 1) tst (rt), tst (l), tst (r), out (msum[idx][rt]);
    if (msum[idx][rt] == r - l + 1){
        checkmin (ansl, l); checkmax (ansr, r); return;
    }
    //if (rt == 1) tst (idx), out (msum[idx][rt]);
    if (l == r) return;

    int m = (l + r) >> 1;
    if (m - rsum[idx][rt<<1] + 1 <= t1 && t1 <= m + lsum[idx][rt<<1|1])
        checkmin (ansl, m - rsum[idx][rt<<1] + 1), checkmax (ansr, m + lsum[idx][rt<<1|1]);
    if (t1 <= m) query (t1, idx, lson);
    else query (t1, idx, rson);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        clr (num, 0); clr (lsum, 0); clr (rsum, 0); clr (msum, 0);
        int64 ans = 0;
        build (1, 1, n);
        repf (i, 0, 19){
            int64 t = 0;
            repf (j, 0, n){
                if (num[i][j]) ++ t;
                else ans += two(i) * (t+1) * t / 2, t = 0;
            }
            if (t) ans += two(i) * (t+1) * t / 2;
        }

        int t1, t2;
        while (m --){
            scanf ("%d%d", &t1, &t2);
            int tmp = t2, idx = 0;
            while (tmp){
                int c = tmp & 1, tc = num[idx][t1];
                if (c != tc){
                    ansl = n+1; ansr = 0;
                    if (c == 1){
                        update (t1, idx, c, 1, 1, n);
                        query (t1, idx, 1, 1, n);
                        ans += two(idx) * (1 + ansr - ansl + (int64)(ansr-t1)*(t1-ansl));
                    }
                    else{
                        query (t1, idx, 1, 1, n);
                        ans -= two(idx) * (1 + ansr - ansl + (int64)(ansr-t1) * (t1-ansl));
                        update (t1, idx, c, 1, 1, n);
                    }
                }
                ++ idx; tmp >>= 1;
            }

            repf (i, idx, 19) if (num[i][t1]){
                ansl = n + 1; ansr = 0;
                query (t1, i, 1, 1, n);
                ans -= two (i) * (1 + ansr - ansl + (int64)(ansr-t1) * (t1-ansl));
                update (t1, i, 0, 1, 1, n);
            }
            printf ("%I64d\n", ans);
        }
    }
    return 0;
}
