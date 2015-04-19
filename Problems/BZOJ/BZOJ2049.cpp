#include<bits/stdc++.h>
const int Max_N = 10009;
struct Node*null, *bat, *memPos;
struct Node {
        Node*ch[2], *f;
        bool isRoot, rev;
        void setc(Node*c, int d) { ch[d] = c; c->f = this; }
        bool d() { return this == f->ch[1];}
        void revIt() { rev ^= 1; std::swap(ch[0], ch[1]);}
        void splayRoot(Node*fa) {
                f = fa; isRoot = true;
        }
        void relax() {
                if(rev) {
                        for(int i = 0; i < 2; ++i)
                                if(ch[i] != null) ch[i]->revIt();
                        rev = 0;
                }
        }
        void rot() {
                Node*p = f;
                p->relax(); relax();
                int d = this->d();
                if (p->isRoot) p->isRoot = false, splayRoot(p->f);
                else p->f->setc(this, p->d());
                p->setc(ch[!d], d);
                setc(p, !d);
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
        }
        void expose() {
                for(Node*v = null, *u = this; u != null; v = u, u = u->f) {
                        u->splay();
                        u->ch[1]->isRoot = true;
                        u->setc(v, 1);
                        v->isRoot = false;
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
} Tnull, mem[Max_N];
void newNode(Node*fa) {
        bat->f = fa;
        bat->ch[0] = bat->ch[1] = null;
        bat->rev = false;
        bat->isRoot = true;
        bat++;
}
void init(int n) {
        null = &Tnull;
        null->f = null->ch[0] = null->ch[1] = null;
        null->rev = 0;
        memPos = bat = mem;
        for(int i = 0; i < n; ++i) newNode(null);
}
void cut(Node*x, Node*y) {
        x->makeRoot();
        y->expose();
        y->splay();
        y->ch[0]->splayRoot(null);
        y->setc(null, 0);
}

int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        char op[33];
        for(int u, v; m--; ) {
                scanf("%s%d%d", op, &u, &v); --u; --v;
                if(op[0] == 'Q') puts((mem+u)->root() == (mem+v)->root() ? "Yes" : "No");
                else if(op[0] == 'C') (mem + u)->link(mem + v);
                else cut(mem + u, mem + v);
        }
        return 0;
}
