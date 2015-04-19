/*
 * Author:  Plumrain
 * Created Time:  2014-02-24 13:12
 * File Name: DS-HDU-1754.cpp
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

#define clr(x) memset(x, 0, sizeof(x))
#define clrs(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

const double eps = 1e-8;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 200000;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}

int minv[maxn<<2];

int query(int ql, int qr, int o, int l, int r)
{
    int m = (l + r) >> 1;
    if (ql <= l && qr >= r) return minv[o];
    int ret = 0;
    if (ql <= m) ret = max(ret, query (ql, qr, 2*o, l, m));
    if (qr > m) ret = max(ret, query (ql, qr, 2*o+1, m+1, r));
    return ret;
}

void update (int p, int v, int o, int l, int r)
{
    int m = (l + r) >> 1;
    if (l == r){
        minv[o] = v; return;
    }
    if (p <= m) update (p, v, 2*o, l, m);
    else update (p, v, 2*o+1, m+1, r);
    minv[o] = max (minv[2*o], minv[2*o+1]);
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        clr (minv);
        int tmp;
        for (int i = 1; i <= n; ++ i) 
            scanf ("%d", &tmp), update(i, tmp, 1, 1, n);
//
        //for (int i = 1; i <= n; ++ i) tst (i), printf ("%d\n", query (i, i, 1, 1, n));

        char op[10];
        int t1, t2;
        while (m--){
            scanf ("%s%d%d", op, &t1, &t2);
            if (op[0] == 'Q') printf ("%d\n", query (t1, t2, 1, 1, n));
            else update (t1, t2, 1, 1, n);
        }
    }
    return 0;
}
