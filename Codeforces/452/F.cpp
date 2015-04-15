/*
 * Author:  Plumrain
 * Created Time:  2014/8/16 22:44:22
 * File Name: F.cpp
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
const int inf = 2147483647 / 2;
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};
const int maxn = 300005; 

const int64 has_key = 100003;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int64 b[maxn], key;
int a[maxn];

struct SegTree{
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

    int64 h[maxn<<2];
    void init(){
        clr (h, 0);
    }
    void up (int l, int r, int rt){
        int m = (l + r) >> 1;
        h[rt] = h[rt<<1] * b[r-m] + h[rt<<1|1];
    }
    void insert (int p, int l, int r, int rt){
        if (l == r){
            h[rt] = 1; return;
        }
        int m = (l + r) >> 1;
        if (p <= m) insert (p, lson);
        else insert (p, rson);
        up (l, r, rt);
    }
    void query (int ql, int qr, int l, int r, int rt){
        if (ql > qr) return;
        if (ql <= l && r <= qr){
            key = key * b[r-l+1] + h[rt]; return;
        }
        int m = (l + r) >> 1;
        if (ql <= m) query (ql, qr, lson);
        if (qr > m) query (ql, qr, rson);
        return;
    }
}gao1, gao2;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    rep (i, 0, n-1){
        scanf ("%d", a+i); -- a[i];
        b[i] = i ? b[i-1] * has_key : 1;
    }

    bool ans = 0;
    gao1.init (); gao2.init ();
    rep (i, 0, n-1){
        int v = a[i], l = min (v, n - v - 1);
        key = 0;
        gao1.query (v-l, v-1, 0, n-1, 1);
        int64 t1 = key; key = 0;
        gao2.query (n-v-l-1, n-v-2, 0, n-1, 1);
        if (t1 != key){
            ans = 1; break;
        }
        gao1.insert (v, 0, n-1, 1);
        gao2.insert (n-v-1, 0, n-1, 1);
    }
    if (ans) puts ("YES");
    else puts ("NO");
    return 0;
}
