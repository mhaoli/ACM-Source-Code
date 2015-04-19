/*
 * Author:  Plumrain
 * Created Time:  2014/8/31 20:07:17
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
const int maxs = 4;
const int maxn = int(1e5) + 9;
typedef int64 matrix[4][4];

struct SAM{
    struct State{
        State *suf, *ch[maxs], *nxt;
        int mx, cnt;
    }*rt, *last;

    int L;
    int dis[maxn<<1];
    State memo[maxn<<1], *bat;
    State *head[maxn];

    void init (){
        bat = memo;
        rt = last = bat ++; 
    }
    void extend (int w){
        State *p = last, *np = bat++; 
        np->mx = p->mx + 1;
        np->cnt = 1;
        while (p && !p->ch[w])
            p->ch[w] = np, p = p->suf;
        if (!p) np->suf = rt;
        else{
            State *q = p->ch[w];
            if (p->mx + 1 == q->mx) np->suf = q;
            else{
                State *nq = bat++; 
                memcpy (nq->ch, q->ch, sizeof q->ch);
                nq->mx = p->mx + 1;
                nq->suf = q->suf;
                q->suf = nq;
                np->suf = nq;
                while (p && p->ch[w] == q)
                    p->ch[w] = nq, p = p->suf;
            }
        }
        last = np;
    }

    void topo (int _L){
        L = _L;
        memset (head, 0, sizeof head);
        for (State *p = memo; p != bat; ++ p)
            p->nxt = head[p->mx], head[p->mx] = p;
    }

    /*********************/

    int idx (State *p){
        return p - memo;
    }
    void calc (int r, matrix &A){
        clr (dis, 127);
        dis[idx (rt->ch[r])] = 1;
        rep (i, 1, L)
            for (State *p = head[i]; p; p = p->nxt){
                int tmp = dis[idx (p)];
                rep (j, 0, 3){
                    if (p->ch[j]) chmin (dis[idx (p->ch[j])], tmp + 1);
                    else chmin (A[r][j], (int64)tmp);
                }
            }
    }
}gao;

int64 up = 1e18;
char str[maxn];

void mtx_clear(matrix &a){
    clr (a, 0); rep (i, 0, 3) a[i][i] = 1;
}

void mtx_eql(matrix &an, matrix bn){
    rep (i, 0, 3) rep (j, 0, 3) an[i][j] = bn[i][j];
}

void mtx_mul (matrix &a, matrix b){
    matrix ret;
    rep (i, 0, 3) rep (j, 0, 3){
        ret[i][j] = up;
        rep (k, 0, 3) chmin (ret[i][j], a[i][k] + b[k][j]);
    }
    mtx_eql (a, ret);
}

void mtx_pow(matrix &p, int64 n){
    matrix ret; mtx_clear(ret);
    while (n){
        if (n & 1) mtx_mul (ret, p);
        n >>= 1;
        mtx_mul (p, p);
    }
    mtx_eql(p, ret);
}

int ok (int64 t, matrix &A, const int64 &n){
    mtx_pow (A, t);
    int64 mi = A[0][0];
    rep (i, 0, 3) rep (j, 0, 3) chmin (mi, A[i][j]);
    return mi >= n;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int64 n; scanf ("%I64d", &n);
    scanf ("%s", str);

    gao.init ();
    int L = strlen (str);
    rep (i, 0, L-1) gao.extend (str[i] - 'A');
    gao.topo (L);

    matrix A;
    clr (A, 127);
    rep (i, 0, 3) gao.calc (i, A);

    matrix bak; mtx_eql (bak, A);
    
    int64 l = 0, r = 1e18, ans = r;
    while (l <= r){
        int64 mid = (l + r) >> 1;
        if (mtx_eql (A, bak), ok (mid, A, n)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf ("%I64d\n", ans);
    return 0;
}
