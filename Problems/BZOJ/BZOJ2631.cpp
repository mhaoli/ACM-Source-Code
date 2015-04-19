#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 9 + (int)1e5;
const int mod = 51061;
void debug(int n);
struct Mark {
        unsigned int add, mul;
        Mark() {
                mul = 1; add = 0;
        }
        Mark(unsigned int ad, unsigned int m) {
                add = ad; mul = m;
        }
        bool empty() {
                return mul == 1 && add == 0;
        }
};
Mark operator*(Mark a, Mark b) {
        return Mark((a.add * b.mul + b.add) % mod, a.mul * b.mul % mod);
}
struct Node {
        Node*ch[2], *f;
        bool rev, isRoot;
        unsigned int sum, val;
        int sz;
        Mark m;
        bool d() {
                return this == f->ch[1];
        }
        void setc(Node*c, int d){
                ch[d] = c;
                c->f = this;
        }
        void apply(Mark t) {
                m = m * t;
                sum = (sum * t.mul + t.add * sz) % mod;
                val = (val * t.mul + t.add) % mod;
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
}Tnull, *null=&Tnull, mem[Max_N], *bat;
void Node::splayRoot(Node*fa) {
        f = fa;
        isRoot = true;
}
void Node::upd(){
        sum = (val + ch[0]->sum + ch[1]->sum) % mod;
        sz = 1 + ch[0]->sz + ch[1]->sz;
}
void Node::relax() {
        if (!m.empty()) {
                for (int i = 0; i < 2; ++i)
                        if (ch[i] != null) ch[i]->apply(m);
                m = Mark();
        }
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

Node*NewNode(int v) {
        bat->val = bat->sum = v;
        bat->f = bat->ch[0] = bat->ch[1] = null;
        bat->m = Mark();
        bat->sz = 1;
        bat->isRoot = true;
        bat->rev = 0;
        return bat++;
}
/*void debug(Node*x) {
        if (x == null) return;
        printf ("%d fa : %d ls : %d rs : %d sz %d\n", x-mem, x->f-mem, x->ch[0]-mem, x->ch[1]-mem, x->sz);
        debug (x->ch[0]); debug (x->ch[1]);
}*/
Node*expose(Node*u) {
        Node*v = null;
        for (; u != null; v = u, u = u->f) {
                u->splay();
                u->ch[1]->isRoot = true;
                u->setc(v, 1);
                v->isRoot = false;
                u->upd();
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
void modify(Node*u, Node*v, Mark m) {
        makeRoot(u);
        expose(v);
        v->splay();
        v->apply(m);
}
int query(Node*u, Node*v) {
        makeRoot(u);
        expose(v);
        v->splay();
        return v->sum;
}
std::vector<int> E[Max_N];
int fa[Max_N], q[Max_N];
void bfs() {
        q[0] = 0; fa[0] = -1;
        for (int ql = 0, qr = 1, x; ql != qr; ++ql) {
                x = q[ql];
                snuke(it, E[x]) if (*it != fa[x]) {
                        fa[*it] = x; q[qr++] = *it; (mem + (*it))->f = mem + x;
                }
        }
}
void init() {
        bat = mem;
}
//void debug(int n) {
        //for (int i = 0; i < n; ++i)
                //printf ("%d isRoot:%d f:%d ch[0]:%d ch[1]:%d\n", i, mem[i].isRoot(), mem[i].f-mem, mem[i].ch[0]-mem, mem[i].ch[1]-mem);
//}
int main() {
        null->ch[0] = null->ch[1] = null;
        null->m = Mark();
        init();

        int n, nq;
        scanf ("%d%d", &n, &nq);
        for (int i = 0, u, v; i < n-1; ++i) {
                scanf ("%d%d", &u, &v);
                E[--u].push_back (--v);
                E[v].push_back (u);
        }

        for (int i = 0; i < n; ++i) NewNode(1);
        bfs();

        char op[10];
        for (int x, y, z, t; nq--; ) {
                scanf ("%s%d%d", op, &x, &y); --x; --y;
                if (op[0] == '+') {
                        scanf ("%d", &z);
                        modify(mem + x, mem + y, Mark(z, 1));
                } else if (op[0] == '*') {
                        scanf ("%d", &z);
                        modify(mem + x, mem + y, Mark(0, z));
                } else if (op[0] == '-') {
                        cut(mem + x, mem + y);
                        scanf ("%d%d", &z, &t);
                        link(mem + z - 1, mem + t - 1);
                } else {
                        printf ("%d\n", query(mem + x, mem + y));
                }
        }
        return 0;
}
