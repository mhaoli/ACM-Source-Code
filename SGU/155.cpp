/*
 * Author:  Plumrain
 * Created Time:  2014/7/2 0:54:54
 * File Name: 155.cpp
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
const int maxn = 50005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

piii an[maxn];
int akey[maxn], kkey[maxn];
int fa[maxn], ls[maxn], rs[maxn];

struct RMQ{
    int d[maxn][35];     //the position of the min value

    //an[i], from 1 to n
    void init(piii *an, int n){
        repf (i, 1, n) d[i][0] = i;
        for (int j = 1; (1<<j) <= n; ++ j)
            for (int i = 1; i + (1<<j) - 1 <= n; ++ i){
                int t1 = d[i][j-1], t2 = d[i+(1<<(j-1))][j-1];
                d[i][j] = (an[t1].x.y <= an[t2].x.y ? t1 : t2); 
            }
    }

    //return the pos;
    int calc(piii *an, int a, int b){
        if (a > b) swap (a, b);
        int k = 0;
        while ((1<<(k+1)) <= b - a + 1) ++ k;

        int t1 = d[a][k], t2 = d[b-(1<<k)+1][k];
        return an[t1].x.y <= an[t2].x.y ? t1 : t2;
    }
}gao;

void dfs (int x, int l, int r){
    int pos;
    if (x > l){
        pos = gao.calc (an, l, x-1);
        ls[an[x].y] = an[pos].y;
        fa[an[pos].y] = an[x].y;
        dfs (pos, l, x-1);
    }
    if (x < r){
        pos = gao.calc (an, x+1, r);
        rs[an[x].y] = an[pos].y;
        fa[an[pos].y] = an[x].y;
        dfs (pos, x+1, r);
    }
}

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int n; scanf ("%d", &n);
    repf (i, 1, n) {
        scanf ("%d%d", kkey+i, akey+i);
        an[i].x.x = kkey[i]; 
        an[i].x.y = akey[i];
        an[i].y = i;
    }
    sort (an+1, an+1+n);
    //repf (i, 1, n) tst (i), tst (an[i].x.x), out (an[i].x.y);
    gao.init(an, n);

    clr (fa, 0); clr (ls, 0); clr (rs, 0);
    dfs (gao.calc (an, 1, n), 1, n);
    bool ans = 1;
    repf (i, 1, n){
        if (fa[i] && akey[fa[i]] > akey[i]) ans = 0;
        if (ls[i] && kkey[ls[i]] > kkey[i]) ans = 0;
        if (rs[i] && kkey[rs[i]] < kkey[i]) ans = 0;
    }
    if (!ans) puts ("NO");
    else {
        puts ("YES");
        repf (i, 1, n) printf ("%d %d %d\n", fa[i], ls[i], rs[i]);
    }
    return 0;
}
