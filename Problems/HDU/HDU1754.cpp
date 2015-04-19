/*
 * Author:  Plumrain
 * Created Time:  2014/8/11 1:51:17
 * File Name: HDU1754.cpp
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
const int maxn = 300005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *pre, *ch[2];
    int id, v, mx, s;
    void up (){
        mx = v; s = 1;
        if (ch[0]->s){
            chmax (mx, ch[0]->mx);
            s += ch[0]->s;
        }
        if (ch[1]->s){
            chmax (mx, ch[1]->mx);
            s += ch[1]->s;
        }
    }
    //void down (){
        //if (u){
            //if (ch[0]->pre){
            //}
            //if (ch[1]->pre){
            //}
            //u = 0;
        //}
    //}
};

struct Splay{
#define lson x->ch[0]
#define rson x->ch[1]
    const static int maxn = 300005; // max node number
    const static int inf = 6e8;     //-inf is min value and inf is max value

    int tot;
    nod an[maxn], nod0, *null, *r;

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
        if (go == null) r = x;
    }

    //把第k大的数旋转到go
    void rto(int k, nod *go){
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
    }

    //删除区间[x, y]
    void del (int x, int y){
        rto (x-1, null); rto (y+1, r);
        r->ch[1]->ch[0] = null;
        r->ch[1]->up(); r->up();
    }


    void debug (nod *x){
        if (x != null){
            printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d val: %2d\n max: %2d\n",
                    x->id, lson->id, rson->id, x->s, x->v, x->mx);
            //x->down();
            debug (lson);
            debug (rson);
        }
    }

    nod *newnod (int id, int v, nod *f){
        nod *x = &an[tot++];
        x->id = id; x->v = v; x->s = 1;
        x->pre = f; lson = rson = null;
        return x;
    }
    //初始时根节点为0
    //最小的元素是第0小，为-inf
    //from 1
    void init(){
        null = &nod0;
        null->id = -1; null->s = null->v = null->mx = 0;
        tot = 1;
        r = newnod (-inf, 0, null);
        r->ch[1] = newnod (inf, 0, r);
        r->ch[1]->up(); r->up();
    }
    //c与节点值相同时放右子树
    void insert (int id, int v){
        nod *x = r;
        while (x->ch[x->id <= id] != null){
            //x->down();
            x = x->ch[x->id <= id];
        }
        //x->down();
        x->ch[x->id <= id] = newnod (id, v, x);
        splay (x->ch[x->id <= id], null);
    }

    
    //调用的时候x为r
    //以x为根的树上，比c小的元素有多少个(包含-inf)
    int find_cnt(nod *x, int c){
        if (x == null) return 0;
        //x->down();
        if (x->id < c) return lson->s + 1 + find_cnt (rson, c);
        else return find_cnt (lson, c);
    }

    int query (int a, int b){
        rto (a, null);
        rto (b+2, r);
        return r->ch[1]->ch[0]->mx;
    }
    void update (int q, int c){
        del (q+1, q+1);
        insert (q, c);
    }
};

Splay gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF){
        gao.init();
        repf (i, 0, n-1){
            int t; scanf ("%d", &t);
            gao.insert (i, t);
        }

        int a, b; char op[10];
        while (m--){
            scanf ("%s%d%d", op, &a, &b);
            if (op[0] == 'Q') printf ("%d\n", gao.query (min(a,b)-1, max(a,b)-1));
            else gao.update (a-1, b);
        }
    }
    return 0;
}
