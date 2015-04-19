/*
 * Author:  Plumrain
 * Created Time:  2014/10/7 18:44:25
 * File Name: BZOJ2434.cpp
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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define clr(x,y) memset(x, y, sizeof(x))
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define posin(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
#define rep(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define red(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define lowbit(x) ((x)&(-x))
const int N = 9 + (int)1e5;
const int maxs = 26;

struct nod;
struct query{
    nod *x, *y;
    int ans;
}que[N];

struct edge{
    nod *v;
    edge *nxt;
    void add (nod *t, edge *n){
        v = t; nxt = n;
    }
}memo2[N<<1], *bat2;

int dfs_clock;
int C[N<<1];

void bit_add (int x, int v){
    for (++x; x <= dfs_clock; C[x] += v, x += lowbit(x));
}
int bit_sum (int x){
    int ret = 0;
    while (x > 0) ret += C[x], x -= lowbit(x);
    return ret;
}
int bit_sum (int l, int r){
    ++ l; ++ r;
    return bit_sum (r) - bit_sum (l-1);
}

struct nod{
    nod *ch[maxs+2], *f, *fa;
    nod *jump[maxs+2];
    int v, le, ri;
    nod *go(int c);

    /******/
    edge *head;
    vector<query*> q;
}memo[N<<1], *bat, *q[N<<1], *rt;

void newnod (nod *&r, nod*fa){
    r = bat++; memset (r->ch, 0, sizeof r->ch); r->v = 0; 
    r->fa = fa; r->head = 0; r->q.clear ();
}
nod *nod::go (int c){
    if (!ch[c]) newnod (ch[c], this);
    return ch[c];
}
void AC_init (){
    bat = memo; newnod (rt, 0);
    bat2 = memo2;
}
void AC_build (){
    int qr = 0;
    q[qr++] = rt;
    for (int ql = 0; ql != qr;){
        nod *x = q[ql++];
        for (int c = 0; c < maxs; ++ c){
            nod *v = x->ch[c];
            if (!v) continue;

            nod *last = x->f;
            while (last && last->ch[c] == 0) last = last->f;
            if (last) v->f = last->ch[c];
            else v->f = rt;
            bat2->add (v, v->f->head);
            v->f->head = bat2++;
            q[qr++] = v;
        }
    }
}

void dfs_fail (nod *u){
    u->le = dfs_clock ++;
    for (edge*p = u->head; p; p = p->nxt) dfs_fail (p->v);
    u->ri = dfs_clock - 1;
}

void dfs (nod *u){
    bit_add (u->le, 1);
    rep (i, 0, sz(u->q)-1){
        query *t = u->q[i];
        t->ans = bit_sum (t->x->le, t->x->ri);
    }
    rep (c, 0, maxs-1) if (u->ch[c]) dfs (u->ch[c]);
    bit_add (u->le, -1);
}

char s[N];
nod *idx[N];
int tot, L;

void str_init (char *s){
    AC_init ();
    nod *cur = rt;
    for (tot = 0; s[0]; ++ s){
        if (s[0] == 'P') idx[tot++] = cur;
        else if (s[0] == 'B') cur = cur->fa;
        else cur = cur->go (s[0] - 'a');
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf ("%s", s);
    L = strlen (s);
    str_init (s);
    
    int m;
    scanf ("%d", &m);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf ("%d%d", &u, &v);
        que[i].x = idx[--u];
        que[i].y = idx[--v];
        idx[v]->q.pb (&que[i]);
    }

    AC_build ();
    dfs_clock = 0;
    dfs_fail (rt);
    dfs (rt);
    rep (i, 0, m-1) printf ("%d\n", que[i].ans);
    return 0;
}
