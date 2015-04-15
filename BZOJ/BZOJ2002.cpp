#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
const int Max_N = 200009;
void debug(int n);
struct Node {
        Node*ch[2], *f;
        bool rev, isRoot;
        int sz;
        bool d() {
                return this == f->ch[1];
        }
        void setc(Node*c, int d){
                ch[d] = c;
                c->f = this;
        }
        void revIt() {
                rev ^= 1;
                std::swap (ch[0], ch[1]);
        }
        void splayRoot(Node*fa);
        void upd();
        void relax();
        void rot();
        void relaxTo();
        void splay();
}Tnull, mem[Max_N], *bat, *null=&Tnull;
void Node::splayRoot(Node*fa) {
        f = fa;
        isRoot = true;
}
void Node::upd(){
        sz = 1 + ch[0]->sz + ch[1]->sz;
}
void Node::relax() {
        if (rev) {
                for (int i = 0; i < 2; ++i)
                        if (ch[i] != null) ch[i]->revIt();
                rev = 0;
        }
}
void Node::rot() {
        Node*p = f;
        p->relax(); relax();
        bool d = this->d();
        if (p->isRoot) splayRoot(p->f), p->isRoot = false;
        else p->f->setc(this, p->d());
        p->setc(ch[!d], d);
        setc(p, !d);
        p->upd();
}
void Node::relaxTo() {
        static Node*stk[Max_N];
        int top = 0;
        for (Node*t = this; stk[top++]=t, !t->isRoot; t = t->f);
        for (; top; ) stk[--top]->relax();
}
void Node::splay() {
        relaxTo();
        while (!isRoot) {
                if (f->isRoot) rot();
                else if (d() == f->d()) f->rot(), rot();
                else rot(), rot();
        }
        upd();
}
/**************/

Node*NewNode(Node*fa) {
        bat->f = fa;
        bat->ch[0] = bat->ch[1] = null;
        bat->sz = 1;
        bat->isRoot = 1;
        bat->rev = 0;
        return bat++;
}
Node*expose(Node*u) {
        Node*v = null;
        for (; u != null; v = u, u = u->f) {
                u->splay();
                u->ch[1]->isRoot = 1;
                u->setc(v, 1);
                v->isRoot = 0;
        }
        return v;
}
void makeRoot(Node*u) {
        expose(u);
        u->splay();
        u->revIt();
}
void link(Node*u, Node*v) {
        makeRoot(v);
        v->splayRoot(u);
}
void cut(Node*u, Node*v) {
        makeRoot(u);
        expose(v);
        u->splay();
        u->setc(null, 1);
        u->upd();
        v->splayRoot(null);
}
int query(Node*u, Node*v) {
        makeRoot(u);
        expose(v);
        v->splay();
        return v->sz;
}
void init() {
        bat = mem;
}
Node*pos[Max_N];
void debug(int n) {
        for (int i = 0; i < n; ++i)
                printf ("%d isRoot:%d rev:%d f:%d ch[0]:%d ch[1]:%d\n", i, mem[i].isRoot, mem[i].rev, mem[i].f-mem, mem[i].ch[0]-mem, mem[i].ch[1]-mem);
        puts ("---");
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        null->ch[0] = null->ch[1] = null;
        init();
        int n;
        scanf ("%d", &n);
        for (int i = 0, t; i < n; ++i) {
                scanf ("%d", &t);
                t = std::min (t + i, n);
                NewNode(pos[i] = (mem + t));
        }
        NewNode(pos[n] = null);
        int nq; scanf ("%d", &nq);
        for (int x, y, z; nq--; ) {
                scanf ("%d%d", &x, &y);
                if (x == 1) {
                        printf ("%d\n", query(mem + y, mem + n) - 1);
                } else {
                        scanf("%d", &z); z = std::min (z + y, n);
                        cut(mem + y, pos[y]);
                        link(mem + y, pos[y] = (mem + z));
                }
        }
        return 0;
}
