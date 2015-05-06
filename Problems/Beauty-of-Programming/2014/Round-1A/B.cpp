/*
 * Author:  Plumrain
 * Created Time:  2014/4/19 15:30:56
 * File Name: B.cpp
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
#define INF 999999999999999999
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 100005;
const int mod = 1000000007; // 10^9 + 7

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}

struct nod{
    int l, r, del;
};

int n, m;
vi son[maxn];
int64 sum[maxn], ans[maxn];
vector<nod> an[maxn];

int Lowbit(int x){
        return x & (-x);
}
void Update(int pos, int val){
        while (pos > 0){
            sum[pos] += val;
            sum[pos] %= mod;
            pos -= Lowbit(pos);
        }
}
int64 Query(int pos){
        int64 ret = 0;
        while (pos <= n) {
            ret = (ret + sum[pos]) % mod;
            pos += Lowbit(pos);
        }
        return ret;
}
void Add(int l, int r, int val){
        Update(r, val);
        Update(l - 1, -val);
}

void dfs (int p, int len){
    repf (i, 0, sz(an[p])-1){
        nod tmp = an[p][i];
        Add (tmp.l, tmp.r, tmp.del);
    }

    ans[p] = Query (len);
    repf (i, 0, sz(son[p])-1) dfs (son[p][i], len+1);

    repf (i, 0, sz(an[p])-1){
        nod tmp = an[p][i];
        Add (tmp.l, tmp.r, -tmp.del);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &n);
        repf (i, 1, n) son[i].clear(), an[i].clear();
        int t;
        repf (i, 2, n) scanf ("%d", &t), son[t].pb (i);
        int q, u;
        nod nod_tmp;
        scanf ("%d", &q);
        while (q--){
            scanf ("%d%d%d%d", &u, &nod_tmp.l, &nod_tmp.r, &nod_tmp.del);
            an[u].pb (nod_tmp);
        }

        clr (sum, 0); clr (ans, 0);
        dfs (1, 1);

        int64 MOD = mod; // 10^9 + 7
        int64 MAGIC = 12347;
        int64 Hash = 0;
        repf (i, 1, n){
            Hash = (Hash * MAGIC + ans[i]) % MOD;
        }
        Hash = ( Hash + MOD ) % MOD;
        printf ("Case %d: %d\n", ++ cas, (int)Hash);
    }
    return 0;
}
