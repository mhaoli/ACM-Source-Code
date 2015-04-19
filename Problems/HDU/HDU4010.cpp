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
#define snuke(it,T) for(std::vector<int>::iterator it = T.begin(); it != T.end(); ++it)
const int Max_N = 300000 + 9;
struct Node*null;
struct Node {
        Node*ch[2], *f;
        int sz, val, add, mx;
        bool isRoot, rev;
        void setc(Node*c, int d) { ch[d] = c; c->f = this; }
        bool d() { return this == f->ch[1];}
        void revIt() { rev ^= 1; std::swap(ch[0], ch[1]);}
        void addIt(int ad) { mx += ad; val += ad; add += ad; }
        void upd() {
                sz = 1 + ch[0]->sz + ch[1]->sz;
                mx = std::max(val, std::max(ch[0]->mx, ch[1]->mx));
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
        Node* expose() {
                for(Node*v = null, *u = this; u != null; v = u, u = u->f) {
                        u->splay();
                        u->ch[1]->isRoot = true;
                        u->setc(v, 1);
                        v->isRoot = false;
                        u->upd();
                }
                return splay(), this;
        }
        Node* root() {
                for(Node*x = expose(); ; x = x->ch[0])
                        if(x->ch[0] == null) return x;
        }
        void makeRoot() {
                expose(); splay(); revIt();
        }
        void link(Node*b) {
                makeRoot();
                splayRoot(b);
        }
        void cut() {
                expose();
                ch[0]->splayRoot(null);
                setc(null, 0);
        }
}mem[Max_N], *bat;
//void debug(int n) {
        //for(int i = 0; i < n; ++i) {
                //printf ("%d Root:%d rev:%d f:%d ch0:%d ch1:%d\n", i, mem[i].isRoot, mem[i].rev, mem[i].f-mem, mem[i].ch[0]-mem, mem[i].ch[1]-mem);
        //}
//}

void newNode(int t) {
        bat->f = bat->ch[0] = bat->ch[1] = null;
        bat->sz = 1;
        bat->isRoot = true;
        bat->val = bat->mx = t;
        bat->add = 0;
        bat->rev = 0;
        bat++;
}
void modify(Node*x, Node*y, int w) {
        x->makeRoot();
        y->expose();
        y->splay();
        y->addIt(w);
}
int query(Node*x, Node*y) {
        x->makeRoot();
        y->expose();
        y->splay();
        return y->mx;
}
std::vector<int> E[Max_N];
int n, fa[Max_N], q[Max_N];
void init() {
        bat = mem;
        for(int i = 0; i < n; ++i) E[i].clear();
}
void bfs() {
        fa[q[0] = 0] = -1;
        for(int x, ql = 0, qr = 1; ql != qr; ++ql) {
                x = q[ql];
                snuke(it, E[x]) if(*it != fa[x]) {
                        fa[*it] = x; q[qr++] = *it; (mem + (*it))->f = (mem + x);
                }
        }
}
int main() {
        null = new Node();
        null = null->ch[0] = null->ch[1] = null;
        null->sz = null->mx = 0;
        while(scanf("%d", &n) != EOF) {
                init();
                for(int u, v, i = 0; i < n-1; ++i) {
                        scanf("%d%d", &u, &v);
                        E[--u].push_back(--v);
                        E[v].push_back(u);
                }
                for (int i = 0, t; i < n; ++i) 
                        scanf("%d", &t), newNode(t);
                bfs();

                Node*u, *v;
                int q; scanf ("%d", &q);
                for(int a, b, c, op; q--; ) {
                        scanf("%d%d%d", &op, &a, &b); 
                        if(op == 1) {
                                u = mem + a - 1; v = mem + b - 1;
                                if(u->root() == v->root()) puts ("-1");
                                else u->link(v);
                        } else if(op == 2) {
                                u = mem + a - 1; v = mem + b - 1;
                                if(u == v || u->root() != v->root()) puts ("-1");
                                else u->makeRoot(), v->cut();
                        } else if(op == 3) {
                                scanf("%d", &c);
                                u = mem + b - 1; v = mem + c - 1;
                                if(u->root() != v->root()) puts("-1");
                                else modify(u, v, a);
                        } else {
                                u = mem + a - 1; v = mem + b - 1;
                                if(u->root() != v->root()) puts("-1");
                                else printf ("%d\n", query(u, v));
                        }
                }
                puts("");
        }
        return 0;
}
