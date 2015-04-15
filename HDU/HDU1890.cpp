/*
 * Author:  Plumrain
 * Created Time:  2014/8/14 8:10:22
 * File Name: HDU1890.cpp
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
const int inf = -1u>>1;
//const int inf = 2139062143;
const int maxn = 100005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct oo{
    int val, id, pos;
    bool operator<(const oo &a)const{
        return a.val == val ? id < a.id : val < a.val;
    }
}bn[maxn];

struct nod{
    nod *pre, *ch[2];
    int id, s, u;
    void up (){
        s = ch[0]->s + ch[1]->s + 1;
    }
    void down (){
        if (u){
            swap (ch[0], ch[1]);
            if (ch[0]->pre) ch[0]->u ^= 1;
            if (ch[1]->pre) ch[1]->u ^= 1;
            u = 0;
        }
    }
};

struct Splay{
#define lson x->ch[0]
#define rson x->ch[1]
#define ket (r->ch[1]->ch[0])
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

    //把第k大的数旋转到go, idx from 0
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
            printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d u: %2d\n",
                    x->id, lson->id, rson->id, x->s, x->u);
            x->down();
            debug (lson);
            debug (rson);
        }
    }

    nod *newnod (int c, nod *f){
        nod *x = &an[tot++];
        x->id = c; x->s = 1; x->u = 0;
        x->pre = f; lson = rson = null;
        return x;
    }
    //初始时根节点为0
    //最小的元素是第0小，为-inf
    //from 1
    void init(){
        null = &nod0;
        null->id = -1; null->s = null->u = 0;
        tot = 1;
        r = newnod (-inf, null);
        r->ch[1] = newnod (inf, r);
        r->ch[1]->up(); r->up();
    }

    nod *build(int a, int b, nod *f){
        int m = (a + b) >> 1;
        nod *x = newnod (bn[m].val, f);
        bn[m].pos = tot - 1;

        if (a == b) return x;
        if (a <= m-1) lson = build (a, m-1, x); 
        if (m+1 <= b) rson = build (m+1, b, x);
        x->up();
        return x;
    }

    void solve (int n){
        repf (i, 0, n-1){
            scanf ("%d", &bn[i].val);
            bn[i].id = i;
        }
        init();
        ket = build (0, n-1, r->ch[1]);
        r->ch[1]->up(); r->up();

        sort (bn, bn+n);
        repf (i, 0, n-1){
            if (i) printf (" ");
            printf ("%d", calc (bn[i].pos) + i);
        }
        puts ("");
    }
    int calc (int p){
        nod *x = &an[p];
        update_up (x);
        splay (x, null);
        int ret = lson->s;
        rto (0, null);
        rto (ret+1, r);
        ket->u ^= 1;
        rto (0, null);
        rto (2, r);
        ket = null;
        r->ch[1]->up(); r->up();
        return ret;
    }
    void update_up (nod *x){
        if (x == null) return;
        update_up (x->pre);
        x->down();
    }
}gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (scanf ("%d", &n) != EOF && n) gao.solve (n);
    return 0;
}
