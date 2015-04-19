/*
 * Author:  Plumrain
 * Created Time:  2014/8/5 22:25:50
 * File Name: BZOJ1208.cpp
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
const int mod = 1000000;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *pre, *ch[2];
    int v, id, s, u;
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down (){
        if (u){
            if (ch[0]->pre){
            }
            if (ch[1]->pre){
            }
            u = 0;
        }
    }
};

struct Splay{
#define lson x->ch[0]
#define rson x->ch[1]
    const static int maxn = 40010; 
    const static int inf = 2e9;     //-inf is min value and inf is max value

    int tot, u;
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

    void del (int x, int y){
        rto (x-1, null); rto (y+1, r);
        r->ch[1]->ch[0] = null;
        r->ch[1]->up(); r->up();
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
    //from 1
    void init(){
        null = &nod0;
        null->id = null->s = null->v = null->u = 0;
        tot = 1;
        r = newnod (-inf, null);
        r->ch[1] = newnod (inf, r);
        r->ch[1]->up(); r->up();
    }
    //c与节点值相同时放右子树
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

    int find_cnt (nod *x, int c){
        if (x == null) return 0;
        x->down();
        if (x->v <= c) return lson->s + 1 + find_cnt (rson, c);
        else return find_cnt (lson, c);
    }

    //from 0 begin
    nod *find_kth (nod *x, int k){
        if (lson->s == k) return x;
        if (lson->s > k) return find_kth (lson, k);
        return find_kth (rson, k - lson->s - 1);
    }

    int solve (int op, int t){
        if (r->s == 2 || u == op){
            u = op; insert (t); return 0;
        }
        int cnt = find_cnt (r, t);
        //debug (r);
        nod *x1 = find_kth (r, cnt-1), *x2 = find_kth (r, cnt);
        if (t - x1->v <= x2->v - t){
            del (cnt-1, cnt-1);
            return t - x1->v;
        }
        else{
            del (cnt, cnt);
            return x2->v - t;
        }
    }
};

Splay gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n; scanf ("%d", &n);
    int ans = 0;
    gao.init ();
    while (n--){
        int t1, t2; scanf ("%d%d", &t1, &t2);
        ans += (gao.solve (t1, t2) % mod);
        if (ans >= mod) ans -= mod;
    }
    printf ("%d\n", ans);
    return 0;
}
