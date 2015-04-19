/*
 * Author:  Plumrain
 * Created Time:  2014/8/2 10:01:13
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
const int maxn = 1e5 + 5;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

set<int> has;
int cnt, n;
vi pat[maxn], ans;
int vis[maxn], tar[maxn], f[maxn];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

void dfs (int x, int pre){
    vis[x] = 1;
    if (vis[x] == tar[x]) ++ cnt;
    else -- cnt;
    ans.pb (x);
    for (int v : pat[x]) if (cnt != n){
        if (vis[v] != -1) continue;
        dfs (v, x);
        if (cnt != n){
            if (vis[x] == tar[x]) -- cnt;
            else ++ cnt;
            vis[x] ^= 1;
            ans.pb (x);
        }
    }
    if (vis[x] != tar[x] && pre != -1){
        ++ cnt; vis[x] ^= 1;
        if (vis[pre] == tar[pre]) -- cnt;
        else ++ cnt;
        vis[pre] ^= 1;
        ans.pb (pre); ans.pb (x);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int m;
    while (scanf ("%d%d", &n, &m) != EOF){
        repf (i, 0, n-1) pat[i].clear();
        repf (i, 0, n-1) f[i] = i;
        repf (i, 0, m-1){
            int t1, t2;
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            pat[t1].pb (t2); pat[t2].pb (t1);
            int f1 = find (t1), f2 = find (t2);
            if (f1 != f2) f[f1] = f2;
        }

        cnt = 0; ans.clear(); clr (vis, -1);
        repf (i, 0, n-1) scanf ("%d", tar + i), cnt += (!tar[i]);

        if (cnt == n){
            puts ("0"); continue;
        }

        has.clear(); 
        int num = 0, idx = 0;
        repf (i, 0, n-1) if (tar[i]){
            int fa = find (i);
            if (!has.count(fa)) has.insert (fa), ++ num, idx = fa;
        }

        if (num > 1){
            puts ("-1"); continue;
        }

        dfs (idx, -1);

        int pos = 0;
        while (cnt != n && pos < sz(ans)){
            if (vis[ans[pos]] == tar[ans[pos]]) -- cnt;
            else ++ cnt;
            vis[ans[pos]] ^= 1;
            ++ pos; 
        }

        if (cnt != n) puts ("-1");
        else{
            int tmp = sz(ans) - pos;
            printf ("%d\n", tmp);
            if (tmp){
                repf (i, pos, sz(ans)-1){
                    if (i != pos) printf (" ");
                    printf ("%d", ans[i] + 1);
                }
                puts ("");
            }
        }
    }
    return 0;
}
