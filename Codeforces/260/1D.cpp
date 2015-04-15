/*
 * Author:  Plumrain
 * Created Time:  2014/8/18 23:17:23
 * File Name: D.cpp
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
const int DX[]={1,0,-1,0}, DY[]={0,1,0,-1};
const int maxn = (int)1e5 + 5;
const int inf = (int)1e8;     //-inf is min value and inf is max value

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *pre, *ch[2], *link;
    int id, s;
    void up (){
        if (id == -1) return;
        s = ch[0]->s + ch[1]->s + 1;
    }
    nod (){
        id = -1; s = 0;
        pre = ch[0] = ch[1] = link = 0;
    }
    void down (){
    }
    bool q(){
        return this == pre->ch[1];
    }
    int cnt ();
    //int cnt (){
        //int ret = 1 + ch[0]->s;
        //nod *last = this, *x = pre;
        //while (x->ch[0]){
            //if (x->ch[1] == last) ret += 1 + x->ch[0]->s;
            //last = x; x = x->pre;
        //}
        //return ret - 1;
    //}
}Tnull, *null = &Tnull, memo[maxn<<3], *bat = memo;

nod *pos[maxn], *rt[maxn];

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

int nod::cnt (){
    splay (this, null, rt[0]);
    return rt[0]->ch[0]->s + 1 - 1;
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
nod *del (int p, nod *&r){
    rto (p-1, null, r);
    rto (p+1, r, r);
    nod *x = ket;
    ket = null;
    r->ch[1]->up(); r->up();
    return x;
}

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



nod *newnod (int c, nod *f){
    nod *x = bat++;
    x->id = c; x->s = 1;
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
//c与节点值相同时放右子树
void insert (int c, nod *&r){
    nod *x = r;
    while (x->ch[x->link->cnt () <= c] != null){
        x = x->ch[x->link->cnt() <= c];
    }
    x->ch[x->link->cnt() <= c] = newnod (c, x);
    splay (x->ch[x->link->cnt () <= c], null, r);
}

nod *find (nod *x, int c){
    while (x->ch[c]->pre) x = x->ch[c];
    return x;
}

void del_nod (nod *x, nod *&r){
    splay (x, null, r);
    nod *y = find (x->ch[0], 1), *z = find (x->ch[1], 0);
    splay (y, null, r); splay (z, r, r); 
    ket = null; r->ch[1]->up (); r->up ();
}

//from 0 begin
nod *find_kth (nod *x, int k){
    if (lson->s == k) return x;
    if (lson->s > k) return find_kth (lson, k);
    return find_kth (rson, k - lson->s - 1);
}

int lanstans, n, a[maxn];

void trans (int &x){
    x = (x + lanstans - 1) % n;
}

bool calc (int l, int r, int key, int k, nod *x){
    nod *res;
    while (l <= r){
        int m = (l + r) >> 1;
        nod *y = find_kth (rt[k], m);
        if (y != x) splay (y, x, rt[k]);
        if (y->link->cnt () <= key) res = y, l = m + 1;
        else r = m - 1;
    }

    if (x == rt[k] && res == x) return 0;
    splay (res, x, rt[k]);
    //rto (res, x, rt[k]);
    return 1;
}

nod *build (int l, int r, nod *f){
    int m = (l + r) >> 1;
    nod *x = newnod (a[m], f);
    pos[m] = x;

    if (l < m) lson = build (l, m-1, x);
    if (r > m) rson = build (m+1, r, x);
    x->up ();
    return x;
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    scanf ("%d", &n);
    rep (i, 0, n-1) scanf ("%d", a+i);
    rep (i, 0, n){
        init (rt[i]);
        if (i){
            rt[i]->link = rt[0];
            rt[i]->ch[1]->link = rt[0]->ch[1];
        }
    }
    rt[0]->ch[1]->ch[0] = build (0, n-1, rt[0]->ch[1]);
    rt[0]->ch[1]->up (); rt[0]->up ();

    rep (i, 0, n-1){
        insert (i, rt[a[i]]);
        rt[a[i]]->link = pos[i];
        pos[i]->link = rt[a[i]];
    }

    lanstans = 0;
    int q; scanf ("%d", &q);
    while (q--){
        int op, l, r, k; 
        scanf ("%d%d%d", &op, &l, &r);
        trans (l); trans (r); if (l > r) swap (l, r);
        if (op == 1){
            if (l == r) continue;
            nod *x = del (r+1, rt[0]);
            rto (l, null, rt[0]); rto (l+1, rt[0], rt[0]);
            x->pre = rt[0]->ch[1]; rt[0]->ch[1]->ch[0] = x;
            rt[0]->ch[1]->up (); rt[0]->up ();

            del_nod (x->link, rt[x->id]);
            insert (l, rt[x->id]);
            rt[x->id]->link = x;
            x->link = rt[x->id];
        }
        else{
            scanf ("%d", &k); trans (k); ++ k;
            int ans;
            if (rt[k]->s == 2) ans = 0;
            else{
                calc (0, rt[k]->s-1, l, k, null);
                if (!calc (0, rt[k]->s-1, r+1, k, rt[k])) ans = 0;
                else ans = rt[k]->ch[1]->ch[0]->s + (rt[k]->ch[1]->id != inf);
            }
            printf ("%d\n", lanstans = ans);
        }
    }
    return 0;
}
