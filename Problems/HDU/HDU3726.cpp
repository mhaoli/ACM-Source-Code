/*
 * Author:  Plumrain
 * Created Time:  2014/8/30 0:20:05
 * File Name: G.cpp
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

const int maxn = int(2e4) + 9;
const int maxe = int(6e4) + 9;

#define lson x->ch[0]
#define rson x->ch[1]

struct nod{
    nod *pre, *ch[2];
    int s, sum, v;
    int add;
    bool rev;
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down ();
    void addIt (int x){
        add += x; v += x; sum += x;
    }
    void revIt (){
        swap (ch[0], ch[1]); 
        rev ^= 1;
    }
    bool q(){
        return this == pre->ch[1];
    }
    void setc (nod *c, int d){
        ch[d] = c;
        c->pre = this;
        this->up ();
    }
}Tnull, *null = &Tnull, memo[666666], *bat;

nod *link[maxn];

void nod::down (){
    if (add != 0){
        for (int i = 0; i < 2; ++ i)
            if (ch[i] != null) ch[i]->addIt (add);
        add = 0;
    }
    if (rev){
        for (int i = 0; i < 2; ++ i)
            if (ch[i] != null) ch[i]->revIt ();
        rev = 0;
    }
}

//c = 0 left, c = 1 right
void rotate (nod *x, int c){
    nod *y = x->pre;
    //y->down(); x->down();

    y->ch[!c] = x->ch[c];
    if (x->ch[c] != null) x->ch[c]->pre = y;
    x->pre = y->pre;
    if (y->pre != null) y->pre->ch[y->pre->ch[1]==y] = x;
    x->ch[c] = y; y->pre = x;

    y->up();
}

//旋转到go节点下面，如果旋转到根go = null
void splay (nod *x, nod *go){
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
}

//把第k大的数旋转到go, idx from 0
nod *rto(int k, nod *go, nod *r){
    nod *x = r;
    //x->down();
    while (lson->s != k){
        if (lson->s > k) x = lson;
        else{
            k -= lson->s + 1;
            x = rson;
        }
        //x->down();
    }
    splay (x, go);
    return x;
}

//删除区间[x, y]
void del (int p, nod *x){
    splay (x, null);
    x = rto (p-1, null, x);
    rto (p+1, x, x);
    x->ch[1]->ch[0] = null;
    x->ch[1]->up(); x->up();
}

void debug (nod *x){
    if (x != null){
        printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d",
                x->v, lson->v, rson->v, x->s);
        puts ("");
        x->down();
        debug (lson);
        debug (rson);
    }
}

nod *newnod (int c, nod *f = null){
    nod *x = bat++;
    x->v = c; x->s = 1;
    x->pre = f;
    lson = rson = null;
    return x;
}
//初始时根节点为0
//最小的元素是第0小，为-inf
//from 1
nod *init(int c){
    nod *r = newnod (-inf);
    r->setc (newnod (inf), 1);
    r->ch[1]->setc (newnod (c), 0);
    r->up ();
    return r->ch[1]->ch[0];
}
//c与节点值相同时放右子树
void insert (nod *x, nod *r){
    int tid = 0;
    nod *pre = null;
    while (r->pre){
        pre = r;
        if (x->v <= r->v) r = r->ch[0], tid = 0;
        else r = r->ch[1], tid = 1;
    }
    x->s = 1;
    x->ch[0] = x->ch[1] = null;
    pre->setc (x, tid);
    splay (x, null);
}

// 0 prev, 1 next
nod *find (nod *x, int c){
    while (x->ch[c]->pre) x = x->ch[c];
    return x;
}

nod *del_nod (nod *x){
    splay (x, null);
    nod *y = find (x->ch[0], 1), *z = find (x->ch[1], 0);
    splay (y, null); splay (z, y); 
    z->ch[0] = null; z->up (); y->up ();
    return y;
}

struct query{
    int op, x, k;
}que[666666];

struct Val{
    Val *nxt;
    int v;
};

Val val[444444];
Val *head[maxn], *val_bat;

int vis[maxe];
int fa[maxn];
pii pat[maxe];

int find (int x){
    return x == fa[x] ? fa[x] : fa[x] = find (fa[x]);
}

void merge (int x, int y){
    int t1 = find (x), t2 = find (y);
    if (t1 == t2) return;

    splay (link[t2], null);
    splay (link[t1], null);
    if (link[t1]->s > link[t2]->s) swap (t1, t2);
    fa[t1] = t2;

    nod *r = rto (0, null, link[t1]), *rt = link[t2];
    while (r->s > 2){
        rto (2, r, r);
        nod *tmp = r->ch[1]->ch[0];
        r->ch[1]->ch[0] = null;
        r->ch[1]->up (); r->up ();

        insert (tmp, rt);
        rt = tmp;
    }
}

int main()
{
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n, m, cas = 0;
    while (scanf ("%d%d", &n, &m) != EOF){
        if (!n) break;
        bat = memo; val_bat = val;
        clr (head, 0);

        rep (i, 0, n-1){
            int t; scanf ("%d", &t);
            val_bat->v = t;
            val_bat->nxt = head[i];
            head[i] = val_bat ++;
        }

        rep (i, 0, m-1){
            scanf ("%d%d", &pat[i].x, &pat[i].y);
            -- pat[i].x; -- pat[i].y;
        }
        
        int cnt = 0;
        char op[10];
        clr (vis, 0);
        while (scanf ("%s", op) && op[0] != 'E'){
            if (op[0] == 'D'){
                que[cnt].op = 0;
            } else if (op[0] == 'C'){
                que[cnt].op = 1;
            } else{
                que[cnt].op = 2;
            }
            
            scanf ("%d", &que[cnt].x); -- que[cnt].x;
            if (op[0] == 'D'){
                ++ vis[que[cnt].x];
            } else{
                scanf ("%d", &que[cnt].k);
                if (op[0] == 'C'){
                    val_bat->v = que[cnt].k;
                    val_bat->nxt = head[que[cnt].x];
                    head[que[cnt].x] = val_bat ++;
                }
            }

            ++ cnt;
        }

        rep (i, 0, n-1) link[i] = init (head[i]->v);
        rep (i, 0, n-1) fa[i] = i;
        rep (i, 0, m-1) if (!vis[i]){
            merge (pat[i].x, pat[i].y);
        }

        double ans_sum = 0.0;
        int ans_cnt = 0;
        red (i, cnt-1, 0){
            if (que[i].op == 0){
                -- vis[que[i].x];
                if (!vis[que[i].x]) merge (pat[que[i].x].x, pat[que[i].x].y);
            } else if (que[i].op == 1){
                nod *r = del_nod (link[que[i].x]);
                head[que[i].x] = head[que[i].x]->nxt;
                link[que[i].x]->v = head[que[i].x]->v;
                insert (link[que[i].x], r);
            } else{
                splay (link[que[i].x], null);
                if (que[i].k <= 0 || que[i].k > link[que[i].x]->s - 2){
                    //tst1 (a);
                    ++ ans_cnt; continue;
                }

                nod *r = rto (link[que[i].x]->s - 1 - que[i].k, null, link[que[i].x]);
                //cout << r->v << endl;
                ans_sum += r->v;
                ++ ans_cnt;
            }
        }
        if (!ans_cnt) ans_cnt = 1;
        printf ("Case %d: %.6f\n", ++ cas, ans_sum / ans_cnt);
    }
    return 0;
}
