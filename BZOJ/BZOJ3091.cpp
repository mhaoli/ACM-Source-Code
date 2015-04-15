/*
 * Author:  Plumrain
 * Created Time:  2014/12/6 13:02:56
 * File Name: BZOJ3091.cpp
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
#include<functional>
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
#include <complex>

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
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define reptest(a,n) tst1(a); for (int i = 0; i < (int)(n); ++ i) tst (a[i]); cout << endl;
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef complex<double> CD;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = ~0u>>1;
const int Dx[]={1,0,-1,0}, Dy[]={0,1,0,-1};

template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}
/*head*/

#define sqr(x) ((x) * (x))
const int Max_N = 9 + (int)5e4;
namespace LCT{
        void fac_output(ll a, ll b) {
                ll t = __gcd(a, b);
                printf("%lld/%lld\n", a/t, b/t);
        }
        //void debug(int n);
        struct Node*null, *bat, *memPos;
        struct Node {
                Node*ch[2], *f;
                int sz, val, add;
                ll s0, s1, s2, rs1, rs2;      //(sz+1)*s1 - s2
                bool isRoot, rev;
                void setc(Node*c, int d) { ch[d] = c; c->f = this; }
                bool d() { return this == f->ch[1];}
                void revIt() { 
                        rev ^= 1;
                        std::swap(ch[0], ch[1]);
                        std::swap(rs1, s1);
                        std::swap(rs2, s2);
                }
                void addIt(int ad) {
                        val += ad; add += ad;
                        s0 += sz * ad;
                        s1 += (ll)sz * (sz + 1) / 2 * ad;
                        s2 += (ll)sz * (sz + 1) * (sz << 1|1) / 6 * ad;

                        rs1 += (ll)sz * (sz + 1) / 2 * ad;
                        rs2 += (ll)sz * (sz + 1) * (sz << 1|1) / 6 * ad;
                }
                void upd() {
                        sz = 1 + ch[0]->sz + ch[1]->sz;
                        s0 = ch[0]->s0 + val + ch[1]->s0;
                        s1 = ch[0]->s1 + (ch[0]->sz + 1ll) * val + ch[1]->s1 + (ch[0]->sz + 1ll) * ch[1]->s0;
                        s2 = ch[0]->s2 + sqr(ch[0]->sz + 1ll) * val + ch[1]->s2 + 2 * (ch[0]->sz + 1ll) * ch[1]->s1 + sqr(ch[0]->sz + 1ll) * ch[1]->s0;

                        rs1 = ch[1]->rs1 + (ch[1]->sz + 1ll) * val + ch[0]->rs1 + (ch[1]->sz + 1ll) * ch[0]->s0;
                        rs2 = ch[1]->rs2 + sqr(ch[1]->sz + 1ll) * val + ch[0]->rs2 + 2 * (ch[1]->sz + 1ll) * ch[0]->rs1 + sqr(ch[1]->sz + 1ll) * ch[0]->s0;
                }
                void relax() {
                        if(add) {
                                for (int i = 0; i < 2; ++i) 
                                        if (ch[i] != null) ch[i]->addIt(add);
                                add = 0;
                        }
                        if(rev) {
                                for (int i = 0; i < 2; ++i)
                                        if (ch[i] != null) ch[i]->revIt();
                                rev = 0;
                        }
                }
                void splayRoot(Node*fa) {
                        f = fa; isRoot = true;
                }
                void rot() {
                        Node*p = f;
                        p->relax(); relax();
                        int d = this->d();
                        if (p->isRoot) p->isRoot = false, splayRoot(p->f);
                        else p->f->setc(this, p->d());
                        p->setc(ch[!d], d);
                        setc(p, !d);
                        p->upd();
                }
                void relaxTo() {
                        static Node*stk[Max_N];
                        int top = 0;
                        for(Node*t = this; stk[top++]=t, !t->isRoot; t = t->f);
                        for(; top; ) stk[--top]->relax();
                }
                void splay() {
                        relaxTo();
                        while(!isRoot) {
                                if(f->isRoot) rot();
                                else if(d() == f->d()) f->rot(), rot();
                                else rot(), rot();
                        }
                        upd(); 
                }
                void expose() {
                        for(Node*v = null, *u = this; u != null; v = u, u = u->f) {
                                u->splay();
                                u->ch[1]->isRoot = true;
                                u->setc(v, 1);
                                v->isRoot = false;
                                u->upd();
                        }
                }
                Node* root() {
                        for(Node*x = (expose(), splay(), this); x->relax(), 1; x = x->ch[0])
                                if(x->ch[0] == null) return x;
                }
                void makeRoot() {
                        expose(); splay(); revIt();
                }
                void link(Node*b) {
                        makeRoot();
                        splayRoot(b);
                }
                //void debug() {
                        //printf("%d isRoot:%d rev:%d s0:%I64d s1:%I64d s2:%I64d f:%d ch[0]:%d ch[1]:%Id\n", this - memPos, 
                                        //isRoot, rev, s0, s1, s2, f-memPos, ch[0]-memPos, ch[1]-memPos);
                //}
                void output() {
                        fac_output((sz + 1) * s1 - s2, sz * (sz + 1ll) / 2);
                }
        } Tnull, mem[Max_N];
        void newNode(int c, Node*f) {
                bat->ch[0] = bat->ch[1] = null;
                bat->f = f;
                bat->add = 0;
                bat->sz = 1;
                bat->isRoot = true;
                bat->val = c;
                bat->upd();
                bat++;
        }
        void init(int n, int *fa, int *cost) {
                null = &Tnull;
                null->ch[0] = null->ch[1] = null;
                null->sz = 0;
                null->add = 0;
                null->val = null->s0 = null->s1 = null->s2 = null->rs1 = null->rs2 = 0;
                bat = memPos = mem;
                newNode(cost[0], null);
                for(int i = 1; i < n; ++i) newNode(cost[i], mem + fa[i]);
        }
        void delEdge(int u, int v) {
                if((mem + u)->root() != (mem + v)->root()) return;
                (mem + u)->makeRoot();
                (mem + v)->expose();
                (mem + v)->splay();
                if((mem + v)->sz != 2) return;
                (mem + u)->splayRoot(null);
                (mem + v)->setc(null, 0);
                (mem + v)->upd();
        }
        void addEdge(int u, int v) {
                if((mem + u)->root() == (mem + v)->root()) return;
                (mem + u)->link(mem + v);
        }
        void modify(int u, int v, int d) {
                if((mem + u)->root() != (mem + v)->root()) return;
                (mem + u)->makeRoot();
                (mem + v)->expose();
                (mem + v)->splay();
                (mem + v)->addIt(d);
        }
        void query(int u, int v) {
                if((mem + u)->root() != (mem + v)->root()) {
                        puts("-1"); return;
                }
                (mem + u)->makeRoot();
                (mem + v)->expose();
                (mem + v)->splay();
                (mem + v)->output();
        }
        //void debug(int n) {
                //null->debug();
                //for(int i = 0; i < n; ++i) (mem + i)->debug();
        //}
}

vector<int> E[Max_N];
int cost[Max_N], fa[Max_N], q[Max_N];

void bfs() {
        fa[q[0] = 0] = -1;
        for(int x, ql = 0, qr = 1; ql != qr; ++ql) {
                x = q[ql];
                snuke(it, E[x]) if(*it != fa[x]){
                        q[qr++] = *it; fa[*it] = x; fa[*it] = x;
                }
        }
}

int main()
{
        //freopen("a.in","r",stdin);
        //freopen("a.out","w",stdout);
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", cost + i);
        for(int u, v, i = 0; i < n-1; ++i) {
                scanf("%d%d", &u, &v);
                E[--v].pb(--u);
                E[u].pb(v);
        }
        bfs();
        LCT::init(n, fa, cost);
        for(int op, u, v, d; m--; ) {
                scanf("%d%d%d", &op, &u, &v); --u; --v;
                if(op == 1) LCT::delEdge(u, v);
                else if(op == 2) LCT::addEdge(u, v);
                else if(op == 4) LCT::query(u, v);
                else {
                        scanf("%d", &d);
                        LCT::modify(u, v, d);
                }
        }
        return 0;
}
