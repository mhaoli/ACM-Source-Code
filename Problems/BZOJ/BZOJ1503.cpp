/*
 * Author:  Plumrain
 * Created Time:  2014/8/4 19:34:54
 * File Name: BZOJ1503.cpp
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
//const int inf = 2139062143;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *pre, *ch[2];
    int v, id, s, u;
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down(){
        if (u){
            if (ch[0]->pre){
                ch[0]->u += u;
                ch[0]->v += u;
            }
            if (ch[1]->pre){
                ch[1]->u += u;
                ch[1]->v += u;
            }
            u = 0;
        }
    }
};

struct Splay{
#define lson x->ch[0]
#define rson x->ch[1]
    const static int maxn = 200005;
    const static int inf = 1e7;

    int tot;
    nod an[maxn], nod0, *null, *r;

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
        if (go == null) r = x;
    }

    //把第k大的数旋转到go
    void rto(int k, nod *go){
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
        splay (x, go);
    }

    void debug (nod *x){
        if (x != null){
            printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d val: %2d\n",
                    x->id, lson->id, rson->id, x->s, x->v);
            x->down();
            debug (lson);
            debug (rson);
        }
    }

    nod *newnod (int c, nod *f){
        nod *x = &an[tot];
        x->v = c; x->s = 1; x->u = 0; x->id = tot++;
        x->pre = f; lson = rson = null;
        return x;
    }
    //初始时根节点为0
    //最小的元素是第0小，为-inf
    void init(){
        null = &nod0;
        null->id = null->s = null->v = null->u = 0;
        tot = 1;
        r = newnod (-inf, null);
        r->ch[1] = newnod (inf, r);
        r->ch[1]->up(); r->up();
    }
    void insert (int c){
        nod *x = r;
        while (x->ch[x->v <= c] != null){
            x->down();
            x = x->ch[x->v <= c];
        }
        x->down();
        x->ch[x->v <= c] = newnod (c, x);
        splay (x->ch[x->v <= c], null);
    }
    //调用的时候x为r
    int find_cnt(nod *x, int c){
        if (x == null) return 0;
        x->down();
        if (x->v < c) return lson->s + 1 + find_cnt (rson, c);
        else return find_cnt (lson, c);
    }
};

Splay gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int ans, n, mi;
    scanf ("%d%d", &n, &mi);
    gao.init();
    ans = 0;
    while (n--){
        int t; char op[5];
        scanf ("%s%d", op, &t);
        if (op[0] == 'I'){
            if (t >= mi) gao.insert (t);
        }
        else if (op[0] == 'A'){
            gao.r->v += t; gao.r->u += t;
        }
        else if (op[0] == 'S'){
            gao.r->v -= t; gao.r->u -= t;
            int cnt = gao.find_cnt (gao.r, mi);
            if (cnt >= 2){
                ans += cnt - 1;
                gao.rto (0, gao.null);
                gao.rto (cnt, gao.r);
                gao.r->ch[1]->ch[0] = gao.null;
                gao.r->ch[1]->up(); gao.r->up();
            }
        }
        else{
            if (gao.r->s - 2 < t) puts ("-1");
            else{
                gao.rto (gao.r->s-2 - t + 1, gao.null);
                printf ("%d\n", gao.r->v);
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}
