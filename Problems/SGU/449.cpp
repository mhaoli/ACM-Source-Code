/*
 * Author:  Plumrain
 * Created Time:  2014/7/28 19:37:01
 * File Name: 449.cpp
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
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int ans[maxn];
int f[maxn], nxt[maxn], last[maxn];

int find (int x){
    return x == f[x] ? f[x] : f[x] = find (f[x]);
}

struct nod{
    int h;
    vi vec;
    bool operator < (const nod &a)const{
        return h > a.h;
    }
    void clear(){
        vec.clear();
    }
    void apd (int x){
        vec.pb (x);
    }
    void adjust (){
        repf (i, 0, sz(vec)-1) vec[i] = find (vec[i]);
        sort (all (vec));
    }
    void merge (){
        int u = vec[0];
        repf (i, 1, sz(vec)-1){
            if (find (vec[i]) == u) continue;
            f[vec[i]] = u;
            nxt[last[u]] = vec[i];
            last[u] = last[vec[i]];
        }
    }
}an[maxn];

int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int cases = 0;
    int n, m, q;
    while (cin >> n >> m >> q){
        if (cases) puts (""); ++ cases;

        repf (i, 0, m) an[i].clear();
        repf (i, 0, m-1){
            int t, tt;
            scanf ("%d%d", &an[i].h, &t);
            while (t--) scanf ("%d", &tt), an[i].apd (tt-1);
        }
        repf (i, 0, n-1) an[m].apd (i);
        an[++m].h = -1;

        repf (i, 0, n-1) nxt[i] = i, last[i] = i, f[i] = i;

        sort (an, an + m);
        repf (i, 0, m-1){
            an[i].adjust();
            an[i].merge();
        }

        int ans_cnt = 0;
        for (int p = 0; ; p = nxt[p]){
            ans[++ans_cnt] = p;
            if (nxt[p] == p) break;
        }

        while (q--){
            int t; scanf ("%d", &t);
            printf ("%d\n", ans[t] + 1);
        }
    }
    return 0;
}
