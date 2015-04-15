/*
 * Author:  Plumrain
 * Created Time:  2014-02-27 16:35
 * File Name: DS-POJ-2528.cpp
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
const int maxx = 10005;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

vi has;
int ans;
bool st[maxx<<2];
pii an[maxx<<2];
int num[maxx<<8];
map<int, int> idx;

void pushdown(int rt, int l, int r){
    if (num[rt] != -1){
        num[rt<<1] = num[rt<<1|1] = num[rt];
        num[rt] = -1;
    }
}

void build(int rt, int l, int r, bool u){
    if (u) num[rt] = -1;
    if (l == r){
        if (num[rt] >= 0 && !st[num[rt]]) ++ ans, st[num[rt]] = 1;
        num[rt] = -1; return;
    }
    int m = (l + r) >> 1;
    pushdown (rt, l, r);
    build (lson, u); build (rson, u);
}

void update (int ql, int qr, int v, int rt, int l, int r){
    if (ql <= l && qr >= r){
        num[rt] = v; return;
    }
    int m = (l + r) >> 1;
    pushdown (rt, l, r);
    if (ql <= m) update (ql, qr, v, lson);
    if (qr > m) update (ql , qr, v, rson);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T;
    scanf ("%d", &T);
    while (T--){
        has.clear();
        int n, tot = 0;
        scanf ("%d", &n);
        repf (i, 0, n-1){
            scanf ("%d%d", &an[i].first, &an[i].second);
            has.pb (an[i].first); has.pb (an[i].second);
        }
        sort (all(has)); 
        has.erase (unique(all(has)), has.end());

        idx.clear();
        repf (i, 0, sz(has)-1){
            idx[has[i]] = ++ tot;
            if (i && has[i] != has[i-1]+1) idx[has[i]] = ++ tot;
        }
        
        build (1, 1, tot, 1);
        repf (i, 0, n-1) update (idx[an[i].first], idx[an[i].second], i+1, 1, 1, tot);
        ans = 0; clr (st, 0); build (1, 1, tot, 0);
        printf ("%d\n", ans);
    }
    return 0;
}
