/*
 * Author:  Plumrain
 * Created Time:  2014/8/30 23:24:50
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
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define INF 999999999999999999LL
#define zero(x) (((x)>0?(x):-(x))<eps)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
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
const int inf = ~0U >> 1;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = int(2e6) + 9;
bool check[maxn];
int prm[maxn];

int primes(int n){
    clr (check, 0);
    int tot = 0;
    for (int i = 2; i <= n; ++ i){
        if (!check[i]) prm[tot++] = i;
        for (int j = 0; j < tot; j ++){
            if (i * prm[j] > n) break;
            check[i*prm[j]] = 1;
            if (i % prm[j] == 0) break;
        }
    }
    return tot;
}

int prm_cnt, dfs_cnt;
vi pat[maxn];
pii pii_tmp;
int val[maxn], pos[maxn], ans[maxn], dfs_idx[maxn];

void dfs (int x, int fa){
    dfs_idx[++dfs_cnt] = x;
    vii fac;
    int &res = ans[x], tval = val[x];
    res = -1;
    for (int i = 0; i < prm_cnt && prm[i]*prm[i] <= tval; ++ i){
        if (tval % prm[i] == 0){
            chmax (res, pos[prm[i]]);
            pii_tmp.x = prm[i]; pii_tmp.y = pos[prm[i]];
            fac.pb (pii_tmp);
            pos[prm[i]] = dfs_cnt;

            while (tval % prm[i] == 0) tval /= prm[i];
        }
    }

    if (tval > 1){
        chmax (res, pos[tval]);
        pii_tmp.x = tval; pii_tmp.y = pos[tval];
        fac.pb (pii_tmp);
        pos[tval] = dfs_cnt;
    }

    for (auto v : pat[x]) if (v != fa) dfs (v, x);

    for (auto t : fac) pos[t.x] = t.y;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    prm_cnt = primes (maxn - 5);
    int n, q; scanf ("%d%d", &n, &q);
    rep (i, 0, n-1){
        scanf ("%d", val + i);
        pat[i].clear ();
    }
    rep (i, 0, n-2){
        int t1, t2; 
        scanf ("%d%d", &t1, &t2); -- t1; -- t2;
        pat[t1].pb (t2); pat[t2].pb (t1);
    }

    dfs_cnt = 0; clr (pos, -1); dfs (0, -1);
    while (q--){
        int op, x, w; 
        scanf ("%d%d", &op, &x); -- x;
        if (op == 1){
            printf ("%d\n", ans[x] == -1 ? -1 : dfs_idx[ans[x]] + 1);
        } else{
            scanf ("%d", &w);
            val[x] = w;
            dfs_cnt = 0; clr (pos, -1); dfs (0, -1);
        }
    }
    return 0;
}
