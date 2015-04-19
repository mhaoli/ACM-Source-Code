#include<bits/stdc++.h>
#define out(x) std::cout<<#x<<":"<<(x)<<std::endl
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 10009;
struct Node*null;
void debug(int n);
namespace LCT{
        struct Node*null;
        struct Node {
                Node*ch[2], *f;
                int sz, mx, val;
                bool isRoot;
                inline bool d() { return this == f->ch[1]; }
                inline void setc(Node*c, int d) { ch[d] = c; c->f = this; }
                inline void apply(const int &w) {
                        val = w; 
                        mx = std::max(val, std::max(ch[0]->mx, ch[1]->mx));
                }
                inline void upd() {
                        sz = 1 + ch[0]->sz + ch[1]->sz;
                        mx = std::max(val, std::max(ch[0]->mx, ch[1]->mx));
                }
                inline void relax() {
                        if(rev) {
                                for(int i = 0; i < 2; ++i)
                                        if (ch[i] != null) ch[i]->revIt();
                                rev = 0;
                        }
                }
                inline void splayRoot(Node*fa) {
                        f = fa; isRoot = true;
                }
                inline void rot() {
                        Node*p = f;
                        p->relax(); relax();
                        int d = this->d();
                        if(p->isRoot) p->isRoot = false, splayRoot(p->f);
                        else p->f->setc(this, p->d());
                        p->setc(ch[!d], d);
                        setc(p, !d);
                        p->upd();
                }
                inline void relaxTo() {
                        static Node*stk[Max_N];
                        int top = 0;
                        for(Node*t = this; stk[top++]=t, !t->isRoot; t = t->f);
                        for(; top; ) stk[--top]->relax();
                }
                inline void splay() {
                        relaxTo();
                        while(!isRoot) {
                                if(f->isRoot) rot();
                                else if(d() == f->d()) f->rot(), rot();
                                else rot(), rot();
                        }
                        upd();
                }
                inline void expose() {
                        for(Node*v = null, *u = this; u != null; v = u, u = u->f) {
                                u->splay();
                                u->ch[1]->isRoot = true;
                                u->setc(v, 1);
                                v->isRoot = false;
                                u->upd();
                        }
                }
                void makeRoot() {
                        expose(); splay(); revIt();
                }
                inline Node* root() {
                        expose();
                        for(Node*x = this; ; x = x->ch[0])
                                if (x->ch[0] == null) return x;
                }
                inline int exposeToLca() {
                        for(Node*v = null, *u = this; u != null; v = u, u = u->f) {
                                u->splay();
                                if(u->f == null) {
                                        return std::max(v->mx, u->ch[1]->mx);
                                }
                                u->ch[1]->isRoot = true;
                                u->setc(v, 1);
                                v->isRoot = false;
                                u->upd();
                        }
                }
                inline void modify(const int &w) {
                        splay();
                        apply(w);
                }
        }Tnull, mem[Max_N], *bat;
        /************/
        inline int query(int x, int y) {
                (mem + x)->expose();
                return (mem + y)->exposeToLca();
        }
        inline void modify(int x, int w) {
                (mem + x)->splay();
                (mem + x)->modify(w);
        }
        inline void newNode(int c, Node*fa) {
                bat->ch[0] = bat->ch[1] = null;
                bat->f = fa;
                bat->mx = bat->val = c;
                bat->sz = 1;
                bat->isRoot = true;
                bat++;
        }
        inline void init(int n) {
                null = &Tnull;
                null->ch[0] = null->ch[1] = null;
                null->mx = -(~0u>>1);
                bat = mem;
        }
        void debug(int n) {
                for(int i = 0; i < n; ++i)
                        printf("%d isRoot:%d f:%d ch[0]:%d ch[1]:%d\n", i, mem[i].isRoot, mem[i].f-mem, mem[i].ch[0]-mem, mem[i].ch[1]-mem);
        }
}
int main() {
        return 0;
}
