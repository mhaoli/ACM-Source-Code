/*
 * Author:  Plumrain
 * Created Time:  2014/9/11 14:15:39
 * File Name: I.cpp
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
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define lson x->ch[0]
#define rson x->ch[1]
#define ket r->ch[1]->ch[0]
const int maxn = int(3e5) + 111;

struct nod{
    nod *pre, *ch[2];
    int s, v, sta;
    int gd[2];
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
        if (v == inf || v == -inf){
        } else{
            gd[sta] = v; gd[sta^1] = 0;
        }

        gd[0] = __gcd (gd[0], __gcd (ch[0]->gd[0], ch[1]->gd[0]));
        gd[1] = __gcd (gd[1], __gcd (ch[0]->gd[1], ch[1]->gd[1]));
    }
    void down ();
    void mdf_v (int x){
        gd[sta] = v = x;
    }
    void mdf_s (){
        gd[sta^1] = v;
        gd[sta] = 0;
        sta ^= 1;
    }
    void revIt (){
    }
    bool q(){
        return this == pre->ch[1];
    }
    void setc (nod *c, int d){
        ch[d] = c;
        c->pre = this;
        this->up ();
    }
}Tnull, *null = &Tnull, memo[maxn], *bat = memo;

void nod::down (){
}

nod *rt;

void rotate (nod *x, int c){
    nod *y = x->pre;
    y->down(); x->down();

    y->ch[!c] = x->ch[c];
    if (x->ch[c] != null) x->ch[c]->pre = y;
    x->pre = y->pre;
    if (y->pre != null) y->pre->ch[y->pre->ch[1]==y] = x;
    x->ch[c] = y; y->pre = x;

    y->up();
}

void splay (nod *x, nod *go, nod *&r){
    while (x->pre != go){
        if (x->pre->pre == go) rotate (x, x->pre->ch[0] == x);
        else{
            nod *y = x->pre, *z = y->pre;
            int f = z->ch[1] == y;
            if (y->ch[f] == x) rotate (y, !f);
            else rotate (x, f);
            rotate (x, !f);
        }
    }
    x->up();
    if (go == null) r = x;
}

void rto(int k, nod *go, nod *&r){
    nod *x = r;
    x->down();
    while (lson->s != k){
        if (lson->s > k) x = lson;
        else{
            k -= lson->s + 1;
            x = rson;
        }
        x->down();
    }
    splay (x, go, r);
}

void del (int p, nod *&r){
    rto (p-1, null, r);
    rto (p+1, r, r);
    ket = null;
    r->ch[1]->up(); r->up();
}

/*
void debug (nod *x){
    if (x != null){
        printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d",
                x->id, lson->id, rson->id, x->s);
        if (x->link != 0) printf (" link: %2d", x->link->cnt ());
        puts ("");
        x->down();
        debug (lson);
        debug (rson);
    }
}
*/

nod *newnod (int c, int sta){
    nod *x = bat++;
    x->v = c; x->s = 1; x->sta = sta;
    x->gd[sta] = c; x->gd[sta^1] = 0;

    lson = rson = null;
    return x;
}
void init(nod *&r){
    bat = memo;
    r = newnod (-inf, 0); r->pre = null;
    r->setc (newnod (inf, 0), 1);
}

int state[maxn], val[maxn];

nod *build (int l, int r){
    int m = (l + r) >> 1;
    nod *x = newnod (val[m], state[m]);

    if (l < m) x->setc (build (l, m-1), 0);
    if (r > m) x->setc (build (m+1, r), 1);
    return x;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, q;
    while (scanf ("%d%d", &n, &q) != EOF){
        init (rt);
        rep (i, 1, n){
            scanf ("%d%d", val + i, state + i);
        }
        rt->ch[1]->setc (build (1, n), 0);

        int id, v, sta, L, R;
        char op[33];
        while (q--){
            scanf ("%s", op);
            if (op[0] == 'R'){
                scanf ("%d", &id);
                rto (id-1, null, rt);
                rto (id+1, rt, rt);
                rt->ch[1]->ch[0]->mdf_s ();

            } else if (op[0] == 'M'){
                scanf ("%d%d", &id, &v);
                rto (id-1, null, rt);
                rto (id+1, rt, rt);
                rt->ch[1]->ch[0]->mdf_v (v);

            } else if (op[0] == 'D'){
                scanf ("%d", &id);
                rto (id-1, null, rt);
                rto (id+1, rt, rt);
                rt->ch[1]->ch[0] = null;
                rt->ch[1]->up (); rt->up ();

            } else if (op[0] == 'I'){
                scanf ("%d%d%d", &id, &v, &sta);
                rto (id, null, rt);
                rto (id+1, rt, rt);
                rt->ch[1]->setc (newnod (v, sta), 0);
                rt->ch[1]->up (); rt->up ();

            } else if (op[0] == 'Q'){
                scanf ("%d%d%d", &L, &R, &sta);
                rto (L-1, null, rt);
                rto (R+1, rt, rt);

                int ans = rt->ch[1]->ch[0]->gd[sta];
                if (!ans) ans = -1;
                printf ("%d\n", ans);
            }
        }
    }
    return 0;
}
