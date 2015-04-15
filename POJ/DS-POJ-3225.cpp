/*
 * Author:  Plumrain
 * Created Time:  2014-03-01 20:25
 * File Name: DS-POJ-3225.cpp
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
const int maxn = 65535;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

bool hash[(maxn<<1) + 5];
vector<pii > tmp, ans;
int cov[maxn<<3], cha[maxn<<3];

void pushdown(int rt, int l, int r){
    int ls = rt << 1, rs = ls | 1;
    if (cov[rt] != -1){
        cha[ls] = cha[rs] = 0;
        cov[ls] = cov[rs] = cov[rt];
        cov[rt] = -1;
        return;
    }

    if (cha[rt]){
        if (cov[rs] != -1) cov[rs] ^= 1;
        else cha[rs] ^= 1;
        if (cov[ls] != -1) cov[ls] ^= 1;
        else cha[ls] ^= 1;
        cha[rt] = 0;
    }
}

void vupdate (int ql, int qr, int v, int rt, int l, int r){
    if (ql > qr) return;
    if (ql <= l && qr >= r){
        cov[rt] = v; cha[rt] = 0; return;
    }
    int m = (l + r) >> 1;
    pushdown (rt, l, r);
    if (ql <= m) vupdate (ql, qr, v, lson);
    if (qr > m) vupdate (ql, qr, v, rson);
}

void stupdate (int ql, int qr, int rt, int l, int r){
    if (ql > qr) return;
    if(ql <= l && qr >= r){
        if (cov[rt] != -1) cov[rt] ^= 1, cha[rt] = 0;
        else cha[rt] ^= 1;
        return ;
    }
    pushdown (rt, l, r);
    int m = (l + r) >> 1;
    if (ql <= m) stupdate (ql, qr, lson);
    if (qr > m) stupdate (ql, qr, rson);
}

void query (int ql, int qr, int rt, int l, int r){
    if (ql > qr) return;
    if (ql <= l && qr >= r && cov[rt] != -1){
        if (!cov[rt]) return;
        tmp.pb (mp (l, r)); return;
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    pushdown (rt, l, r);
    if (ql <= m) query (ql, qr, lson);
    if (qr > m) query (ql, qr, rson);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int l, r, n = maxn << 1;
    char s[10], t1, t2;
    cov[1] = cha[1] = 0;
    while (scanf ("%s %c%d,%d%c", s, &t1, &l, &r, &t2) != EOF){
        l <<= 1; r <<= 1;
        if (t1 == '(') ++ l; if (t2 == ')') -- r;
        if (l > r){
            if (s[0] == 'C' || s[0] == 'I') cov[1] = cha[1] = 0;
            continue;
        }

        if (s[0] == 'U') vupdate (l, r, 1, 1, 0, n);
        else if (s[0] == 'I'){
            vupdate (0, l-1, 0, 1, 0, n);
            vupdate (r+1, n, 0, 1, 0, n);
        }
        else if (s[0] == 'D') vupdate (l, r, 0, 1, 0, n);
        else if (s[0] == 'C'){
            vupdate (2, l-1, 0, 1, 0, n);
            vupdate (r+1, n, 0, 1, 0, n);
            stupdate (l, r, 1, 0, n);
        }
        else stupdate (l, r, 1, 0, n);
    }

    ans.clear(); tmp.clear();
    query (0, n, 1, 0, n);
    repf (i, 1, sz(tmp)-1){
        if (tmp[i].first == tmp[i-1].second + 1)
            tmp[i].first = tmp[i-1].first;
        else ans.pb (tmp[i-1]);
    }
    if (sz(tmp)) ans.pb (tmp[sz(tmp)-1]);

    if (!sz(ans)) printf ("empty set");
    repf (i, 0, sz(ans)-1){
        if (i) printf (" ");
        pii cur = ans[i];
        if (cur.first & 1) printf ("(");
        else printf ("[");
        printf ("%d,", cur.first / 2);
        if (cur.second & 1) printf ("%d)", cur.second / 2 + 1);
        else printf ("%d]", cur.second / 2);
    }
    printf ("\n");
    return 0;
}
