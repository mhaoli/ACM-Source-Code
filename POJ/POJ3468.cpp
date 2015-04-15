/*
 * Author:  Plumrain
 * Created Time:  2014/8/11 15:15:16
 * File Name: POJ3468.cpp
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
const int64 inf = 1LL<<60;
//const int inf = 2139062143;
const int maxn = 200005;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

struct nod{
    nod *pre, *ch[2];
    int id, s;
    int64 u, val, sum;
    void up (){
        s = 1; sum = val;
        if (ch[0]->pre) s += ch[0]->s, sum += ch[0]->sum;
        if (ch[1]->pre) s += ch[1]->s, sum += ch[1]->sum;
    }
    void down (){
        if (u){
            if (ch[0]->id != -1){
                ch[0]->val += u;
                ch[0]->u += u;
                ch[0]->sum += u * ch[0]->s;
            }
            if (ch[1]->id != -1){
                ch[1]->val += u;
                ch[1]->u += u;
                ch[1]->sum += u * ch[1]->s;
            }
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

    //删除区间[x, y]
    void del (int x, int y){
        rto (x-1, null); rto (y+1, r);
        r->ch[1]->ch[0] = null;
        r->ch[1]->up(); r->up();
    }


    //void debug (nod *x){
        //if (x != null){
            //printf ("节点: %2d 左儿子: %2d 右儿子: %d size: %2d val: %2d\n",
                    //x->id, lson->id, rson->id, x->s, x->val);
            //x->down();
            //debug (lson);
            //debug (rson);
        //}
    //}

    nod *newnod (int c, int val, nod *f){
        nod *x = &an[tot++];
        x->id = c; x->s = 1; x->u = 0; x->val = val; x->sum = val;
        x->pre = f; lson = rson = null;
        return x;
    }
    //初始时根节点为0
    //最小的元素是第0小，为-inf
    //from 1
    void init(){
        null = &nod0;
        null->id = -1; null->s = null->val = null->u = null->sum = 0;
        tot = 1;
        r = newnod (-10 * maxn, 0, null);
        r->ch[1] = newnod (10 * maxn, 0, r);
        r->ch[1]->up(); r->up();
    }
    //c与节点值相同时放右子树
    void insert (int c, int v){
        nod *x = r;
        while (x->ch[x->id <= c] != null){
            x->down();
            x = x->ch[x->id <= c];
        }
        x->down();
        x->ch[x->id <= c] = newnod (c, v, x);
        splay (x->ch[x->id <= c], null);
    }

    void query (int x, int y){
        if (x > y) swap (x, y);
        rto (x, null); rto (y+2, r);
        printf ("%I64d\n", ket->sum);
    }
    void add (int x, int y, int c){
        if (x > y) swap (x, y);
        rto (x, null); rto (y+2, r);
        ket->val += c; ket->u += c; ket->sum += 1LL * c * ket->s;
    }
}gao;

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n, q; scanf ("%d%d", &n, &q);
    gao.init ();
    repf (i, 0, n-1){
        int t; scanf ("%d", &t); gao.insert (i, t);
    }

    char op[5];
    int a, b, c;
    while (q--){
        scanf ("%s%d%d", op, &a, &b); -- a; -- b;
        if (op[0] == 'Q') gao.query (a, b);
        else{
            scanf ("%d", &c);
            gao.add (a, b, c);
        }
    }
    return 0;
}
