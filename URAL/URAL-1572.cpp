/*
 * Author:  Plumrain
 * Created Time:  2014/7/24 11:03:11
 * File Name: URAL-1572.cpp
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
typedef pair<pii, int> piii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 20005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int an_cnt, dn_cnt;
int d[maxn], dn[maxn], fa[maxn], an[maxn], num[maxn], ans[50006], is_d[maxn];
vector<pii > qn[maxn];
vi pat[maxn];

void dfs (int u, int pre){
    d[u] = pre == -1 ? 0 : d[pre] + 1;
    fa[u] = pre;
    for (int v : pat[u]) if (v != pre) dfs (v, u);
}

void dfs2 (int x, int pre){
    fa[x] = pre;
    if (!is_d[x]){
        an[an_cnt++] = x;
        for (auto q : qn[x]){
            if (q.x < an_cnt) ans[q.y] = an[an_cnt-1-q.x];
            else if (num[fa[an[0]]] - (q.x - an_cnt) >= 0) ans[q.y] = dn[num[fa[an[0]]]-(q.x-an_cnt)];
            else if (num[fa[an[0]]] + (q.x - an_cnt) < dn_cnt) ans[q.y] = dn[num[fa[an[0]]] + (q.x-an_cnt)];
        }
    }
    for (int v : pat[x]) if (v != pre) dfs2 (v, x);
    if (!is_d[x]) -- an_cnt;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n, Q;
    scanf ("%d%d", &n, &Q);
    repf (i, 0, n-1) pat[i].clear(), qn[i].clear();
    repf (i, 0, n-2){
        int t1, t2;
        scanf ("%d%d", &t1, &t2); -- t1; -- t2;
        pat[t1].pb (t2); pat[t2].pb (t1);
    }
    repf (i, 0, Q-1){
        int t, d;
        scanf ("%d%d", &t, &d); -- t;
        qn[t].pb (mp (d, i));
    }

    clr (fa, -1); clr (d, 0); dfs (0, -1);
    int ma = 0;
    repf (i, 0, n-1) if (d[i] > d[ma]) ma = i;
    clr (fa, -1); clr (d, 0); dfs (ma, -1);

    repf (i, 0, n-1) if (d[i] > d[ma]) ma = i;
    
    clr (is_d, 0); clr (ans, -1);
    dn_cnt = 0;
    while (ma != -1){
        dn[dn_cnt] = ma;
        is_d[ma] = 1;
        num[ma] = dn_cnt++;
        ma = fa[ma];
    }

    repf (i, 0, dn_cnt-1){
        for (auto x : qn[dn[i]]){
            if (x.x <= i) ans[x.y] = dn[i-x.x];
            else if (x.x + i < dn_cnt) ans[x.y] = dn[x.x+i];
        }
    }

    clr (fa, -1);
    an_cnt = 0;
    dfs2 (dn[0], -1);

    repf (i, 0, Q-1) printf ("%d\n", ans[i] + 1);
    return 0;
}
