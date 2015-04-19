/*
 * Author:  Plumrain
 * Created Time:  2014/6/1 20:45:36
 * File Name: graph-POJ-1392.cpp
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

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
const int maxn = 1 << 16;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int top, n;
bool vis[maxn];
int cnt[maxn], adj[maxn][10], stk[maxn];

void dfs (int x){
    repf (i, 0, cnt[x]-1) if (!vis[ adj[x][i] ]){
        vis[ adj[x][i] ] = 1;
        int tmp = adj[x][i]; tmp = min (tmp, tmp ^ (1 << (n-1)));
        dfs (tmp);
        stk[ top++ ] = adj[x][i];
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int k;
    while (scanf ("%d%d", &n, &k) != EOF){
        if (!n && !k) break;
        clr (cnt, 0);
        repf (i, 0, (1<<n)-1){
            int tmp = i >> 1;
            adj[tmp][ cnt[tmp]++ ] = i;
        }
        clr (vis, 0); top = 0; dfs (0);
        //repd (i, top-1, 0) tst (stk[i]);
        //cout << endl;
        cout << stk[top-k-1] << endl;
    }
    return 0;
}
