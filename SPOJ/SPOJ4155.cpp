#include<bits/stdc++.h>
const int Max_N = 30009;
struct Node*bat, *memPos, *null;
struct Node {
        Node*ch[2], *f;
        int sz, val, sum;
        bool isRoot, rev;
        void setc(Node*c, int d) { ch[d] = c; c->f = this; }
        bool d() { return this == f->ch[1];}
        void revIt() { rev ^= 1; std::swap(ch[0], ch[1]);}
        void modify(int c) { splay(); val = c; upd(); }
        void upd() {
                sz = 1 + ch[0]->sz + ch[1]->sz;
                sum = val + ch[0]->sum + ch[1]->sum;
        }
        void relax() {
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
} mem[Max_N], Tnull;
void newNode(int c) {
        bat->ch[0] = bat->ch[1] = null;
        bat->splayRoot(null);
        bat->val = bat->sum = c;
        bat->rev = false;
        bat->sz = 1;
        bat++;
}
void init() {
        null = &Tnull;
        null->ch[0] = null->ch[1] = null;
        null->sum = null->val = 0;
        bat = memPos = mem;
}
int query(Node*a, Node*b) {
        a->makeRoot();
        b->expose();
        return b->splay(), b->sum;
}
int main() {
        int n;
        scanf("%d", &n);
        init();
        for(int i = 0, t; i < n; ++i)
                scanf("%d", &t), newNode(t);
        int q;
        scanf("%d", &q);
        char op[33];
        Node*u, *v;
        for(int a, b; q--; ) {
                scanf("%s%d%d", op, &a, &b);
                if(op[0] == 'b') {
                        u = mem + a - 1; v = mem + b - 1;
                        if(u->root() == v->root()) puts("no");
                        else u->link(v), puts(("yes"));
                } else if(op[0] == 'p') {
                        (mem + a - 1)->modify(b);
                } else {
                        u = mem + a - 1; v = mem + b - 1;
                        if(u->root() == v->root()) printf("%d\n", query(u, v));
                        else puts("impossible");
                }
        }
        return 0;
}
