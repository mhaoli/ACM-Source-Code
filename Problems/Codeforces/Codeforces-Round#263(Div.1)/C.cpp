/*
 * Author:  Plumrain
 * Created Time:  2014/8/26 23:23:59
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
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define two(x) (1<<(x))
#define twol(x) (1ll<<(x))
#define lson x->ch[0]
#define rson x->ch[1]
#define ket r->ch[1]->ch[0]
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

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

const int maxn = (int)2e5;

struct nod{
    nod *pre, *ch[2];
    int id, s, sum, rev, v;
    nod (){
        id = -1; s = sum = v = rev = 0;
        pre = ch[0] = ch[1] = 0;
    }
    void addIt (int x){
        v += x; sum += x;
    }
    void up (){
        if (id == -1) return;
        sum = ch[0]->sum + ch[1]->sum + v;
        s = 1 + ch[0]->s + ch[1]->s;
    }
    void down ();
    void revIt (){
        swap (ch[0], ch[1]);
        rev ^= 1;
    }
    bool q(){
        return this == pre->ch[1];
    }
}Tnull, *null = &Tnull, memo[maxn<<3], *bat = memo;

void nod::down (){
    if (rev){
        rep (i, 0, 1) if (ch[i] != null)
            ch[i]->revIt ();
        rev = 0;
    }
}

nod *rt, *rt_tmp;

//c = 0 left, c = 1 right
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

//旋转到go节点下面，如果旋转到根go = null
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

//把第k大的数旋转到go, idx from 0
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

//删除区间[x, y]
nod *del (int x, int y, nod *&r){
    rto (x-1, null, r);
    rto (y+1, r, r);
    nod *ret = ket; ret->pre = null;
    ket = null;
    r->ch[1]->up(); r->up();
    return ret;
}

void debug (nod *x){
    if (x != null){
        printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d sum: %2d v: %2d",
                x->id, lson->id, rson->id, x->s, x->sum, x->v);
        //if (x->link != 0) printf (" link: %2d", x->link->cnt ());
        puts ("");
        x->down();
        debug (lson);
        debug (rson);
    }
}

nod *newnod (int c, nod *f){
    nod *x = bat++;
    x->id = c; x->s = 1; x->sum = x->rev = x->v = 0;
    x->pre = f; lson = rson = null;
    return x;
}
//初始时根节点为0
//最小的元素是第0小，为-inf
//from 1
void init(nod *&r){
    r = newnod (-inf, null);
    r->ch[1] = newnod (inf, r);
    r->ch[1]->up(); r->up();
}

nod *build (int l, int r, nod *f){
    int m = (l + r) >> 1;
    nod *x = newnod (m, f);
    x->v = x->sum = 1;

    if (l <= m-1) lson = build (l, m-1, x);
    if (m + 1 <= r) rson = build (m+1, r, x);
    x->up ();
    return x;
}

void split (nod *&r, nod *y){
    init (r);
    ket = y; y->pre = r->ch[1];
    r->ch[1]->up (); r->up ();
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init (rt);

    int n, q;
    scanf ("%d%d", &n, &q);
    rt->ch[1]->ch[0] = build (1, n, rt->ch[1]);
    rt->ch[1]->up (); rt->up ();

    while (q--){
        int op, l, r;
        scanf ("%d%d", &op, &l);
        if (op == 1){
            int tmp = n - l;
            if (l <= tmp){
                split (rt_tmp, del (1, l, rt));
                rt_tmp->revIt ();

                rep (i, 1, l){
                    rto (i, null, rt_tmp);
                    rto (i, null, rt);
                    rt->addIt (rt_tmp->v);
                }
                n -= l;
            }
            else{
                split (rt_tmp, del (l+1, n, rt));
                rt->revIt ();

                rep (i, 1, tmp){
                    rto (i, null, rt_tmp);
                    rto (i, null, rt);
                    rt->addIt (rt_tmp->v);
                }
                n -= tmp;
            }
        }
        else{
            scanf ("%d", &r);
            rto (l, null, rt);
            rto (r+1, rt, rt);
            printf ("%d\n", rt->ch[1]->ch[0]->sum);
        }
    }
    return 0;
}
