/*
 * Author:  Plumrain
 * Created Time:  2014/8/15 0:43:10
 * File Name: 433E.cpp
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
const int maxn = 207;
const int maxs = 20;
const int mod = 1000000007;

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

int M, K;
int dig_l[205], dig_r[205];
int d[205][205][505];

inline void add (int &a, int b){
    a += b; if (a >= mod) a -= mod;
}

struct nod{
    nod *ch[maxs], *f;
    nod *jump[maxs];
    int v;
    nod *go (int c);
}*bat;

nod *nod::go (int c){
    if (ch[c] == 0) ch[c]=bat++, clr (ch[c]->ch, 0), ch[c]->v = 0;
    return ch[c];
}

struct AC{
    nod an[maxn], *rt, *q[maxn];
    void newnod (nod *&o){
        o = bat++; clr (o->ch, 0); o->v = 0;
    }
    void init (){
        bat = an; newnod (rt);
    }
    int idx (nod *x){
        return x - an;
    }
    void insert (int *s, int n, int v){
        nod *x = rt;
        repf (i, 0, n-1) x = x->go (s[i]);
        x->v += v;
    }
    void build(){
        int ql = 0, qr = 0;
        q[qr++] = rt;
        while (ql != qr){
            nod *x = q[ql++];
            repf (c, 0, maxs-1){
                nod *v = x->ch[c];
                if (!v) continue;

                nod *last = x->f;
                while (last && last->ch[c] == 0) last = last->f;
                if (last) v->f = last->ch[c];
                else v->f = rt;
                q[qr++] = v;
            }
        }

        repf (i, 0, maxs-1) rt->jump[i] = rt->ch[i] ? rt->ch[i] : rt;
        repf (i, 1, qr-1){
            nod *x = q[i];
            repf (j, 0, maxs-1)
                if (x->ch[j]) x->jump[j] = x->ch[j];
                else x->jump[j] = x->f->jump[j];
        }

        /*******/
        repf (i, 0, qr-1){
            nod *x = q[i];
            if (x->f) x->v += x->f->v;
        }
    }
    /*********/
    int dfs (int p, nod *u, int k, bool first, bool sl, bool sr){
        if (p == -1) return 1;
        int safe = !(sl || sr);
        int s = idx (u);
        if (safe && ~d[p][s][k]) return d[p][s][k];

        int ret = 0;
        repf (i, 0, M-1){
            if (sl && i < dig_l[p]) continue;
            if (sr && i > dig_r[p]) continue;

            nod *v = u;
            if (!first || i) v = u->jump[i];
            if (k + v->v <= K) add (ret, dfs (p-1, v, k+v->v, first&&(!i), sl&&i==dig_l[p], sr&&i==dig_r[p]));
        }
        return safe ? d[p][s][k] = ret : ret;
    }
}gao;

int td[205];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    while (~scanf ("%d%d%d", &n, &M, &K)){
        int l1, l2;
        scanf ("%d", &l1);
        repd (i, l1-1, 0) scanf ("%d", dig_l + i);
        scanf ("%d", &l2);
        repd (i, l2-1, 0) scanf ("%d", dig_r + i);

        while (l1 < l2) dig_l[l1++] =  0;

        gao.init ();
        repf (i, 0, n-1){
            int l, val;
            scanf ("%d", &l);
            repf (j, 0, l-1) scanf ("%d", td+j);
            scanf ("%d", &val);
            gao.insert (td, l, val);
        }
        gao.build ();
        clr (d, -1);
        printf ("%d\n", gao.dfs (l2-1, gao.rt, 0, 1, 1, 1));
    }
    return 0;
}
