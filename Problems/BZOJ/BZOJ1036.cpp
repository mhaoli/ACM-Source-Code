#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 30009;
struct Node {
        Node*ch[2], *f;
        int sz, val, mx, sum;
        bool isRoot, rev;
        void upd() {
                mx = std::max(val, std::max(ch[0]->mx, ch[1]->mx));
                sum = val + ch[0]->sum + ch[1]->sum;
                sz = 1 + ch[0]->sz + ch[1]->sz;
        }
        void revIt() {
                rev ^= 1;
                std::swap (ch[0], ch[1]);
        }
        bool d() {
                return this == f->ch[1];
        }
        void setc(Node*x, int d) {
                ch[d] = x;
                x->f = this;
        }
        void relax();
        void splayRoot(Node*fa);
        void rot();
        void relaxTo();
        void splay();
}Tnull, mem[Max_N], *null=&Tnull, *bat=mem;
void Node::splayRoot(Node*fa) {
        f = fa;
        isRoot = true;
}
void Node::relax() {
        if(rev) {
                for (int i = 0; i < 2; ++i)
                        if (ch[i] != null) ch[i]->revIt();
                rev = 0;
        }
}
void Node::rot() {
        Node*p = f;
        p->relax(); relax();
        int d = this->d();
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
        while(!isRoot) {
                if (f->isRoot) rot();
                else if (d() == f->d()) f->rot(), rot();
                else rot(), rot();
        }
        upd();
}
void expose(Node*u) {
        for(Node*v = null; u != null; v = u, u = u->f) {
                u->splay();
                u->ch[1]->isRoot = true;
                u->setc(v, 1);
                v->isRoot = false;
                u->upd();
        }
}
void makeRoot(Node*x) {
        expose(x);
        x->splay();
        x->revIt();
}
void modify(Node*x, int val) {
        x->splay();
        x->val = val;
        x->upd();
}
std::pair<int, int> query(Node*u, Node*v) {
        makeRoot(u);
        expose(v);
        u->splay();
        return std::make_pair(u->mx, u->sum);
}
Node*NewNode(int w) {
        bat->ch[0] = bat->ch[1] = null;
        bat->isRoot = true;
        bat->sz = 1;
        bat->mx = bat->sum = bat->val = w;
        return bat++;
}

std::vector<int> E[Max_N];
int q[Max_N], fa[Max_N];
void bfs() {
        fa[q[0] = 0] = -1;
        mem->f = null;
        Node*u;
        for(int ql = 0, qr = 1, x; ql != qr; ql++) {
                u = mem + (x = q[ql]);
                snuke(it, E[x]) if(*it != fa[x]) {
                        fa[*it] = x; (mem + (*it))->f = u; q[qr++] = *it;
                }
        }
}
int main() {
        null->ch[0] = null->ch[1] = null;
        null->mx = -30010;
        int n;
        scanf ("%d", &n);
        for(int u, v, i = 0; i < n-1; ++i){
                scanf ("%d%d", &u, &v);
                E[--u].push_back(--v);
                E[v].push_back(u);
        }
        for(int i = 0, t; i < n; ++i) 
                scanf ("%d", &t), NewNode(t);
        bfs();
        int q;
        char op[11];
        scanf ("%d", &q);
        std::pair<int, int> tmp;
        for(int u, v; q--; ) {
                scanf ("%s%d%d", op, &u, &v);
                if (op[0] == 'C') {
                        modify(mem + u - 1, v);
                } else {
                        tmp = query(mem + u - 1, mem + v - 1);
                        printf ("%d\n", op[1] == 'M' ? tmp.first : tmp.second);
                }
        }
        return 0;
}
