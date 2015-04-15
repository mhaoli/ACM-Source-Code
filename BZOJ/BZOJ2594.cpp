#include<bits/stdc++.h>
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 100009;
const int Max_M = 1000009;
const int Max_Q = 100009;
namespace LCT {
        struct Node*null, *bat, *memPos;
        struct Node {
                Node*ch[2], *f, *suf, *pre;
                int sz, val, mx;
                bool isRoot, rev;
                void setc(Node*c, int d) { ch[d] = c; c->f = this; }
                bool d() { return this == f->ch[1];}
                void revIt() { rev ^= 1; std::swap(ch[0], ch[1]);}
                void upd() {
                        sz = 1 + ch[0]->sz + ch[1]->sz;
                        mx = std::max(val, std::max(ch[0]->mx, ch[1]->mx));
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
                        return this;
                }
                void makeRoot() {
                        expose(); splay(); revIt();
                }
                void link(Node*b) {
                        makeRoot();
                        splayRoot(b);
                }
        } Tnull, mem[Max_N << 2];
        Node* newNode(int c) {
                bat->f = bat->ch[0] = bat->ch[1] = null;
                bat->mx = bat->val = c;
                bat->sz = 1;
                bat->isRoot = true;
                bat->rev = false;
                return bat++;
        }
        void init(int n, int *fa, int *cost) {
                null = &Tnull;
                null->f = null->ch[0] = null->ch[1] = null;
                null->sz = 0;
                null->rev = 0;
                null->mx = -1;
                bat = memPos = mem;
                for(int i = 0; i < n; ++i) newNode(-1);
                Node*t;
                for(int i = 1; i < n; ++i) {
                        t = newNode(cost[i]);
                        t->link(t->pre = mem + i);
                        t->link(t->suf = mem + fa[i]);
                }
        }
        Node* query(int a, int b) {
                (mem + a)->makeRoot();
                (mem + b)->expose();
                (mem + b)->splay();
                for(Node*t = mem + b; ; ) {
                        if(t->val >= t->ch[0]->mx && t->val >= t->ch[1]->mx) return t;
                        if(t->ch[0] != null && t->ch[0]->mx > t->val && t->ch[0]->mx > t->ch[1]->mx) t = t->ch[0];
                        else t = t->ch[1];
                }
                return mem;
        }
        void cut(Node*a, Node*b) {
                a->makeRoot();
                b->expose();
                b->splay();
                b->setc(null, 0);
                b->upd();
                a->splayRoot(null);
        }
        void link(int a, int b, int c) {
                if((mem+a)->root() == (mem+b)->root()) {
                        Node*mid = query(a, b);
                        if(mid->val <= c) return;
                        cut(mid, mid->pre);
                        cut(mid, mid->suf);
                } 
                Node*t = newNode(c);
                t->link(t->pre = mem + a);
                t->link(t->suf = mem + b);
        }
}
struct Edge {
        int u, v, c;
        bool operator<(const Edge&t) const {
                return c < t.c;
        }
        Edge() { }
        Edge(int _u, int _v, int _c) {
                u = _u; v = _v; c = _c;
        }
};
std::map<std::pair<int,int>, int> has;
int f[Max_N];
std::vector<Edge> E;
std::vector<std::pair<int, int> > E2[Max_N];
int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
}
void MST(int n) {
        for(int i = 0; i < n; ++i) f[i] = i;
        snuke(it, has){
                E.push_back(Edge(it->first.first, it->first.second, it->second));
        }
        std::sort(E.begin(), E.end());
        int m = E.size();
        for(int u, v, i = 0; i < m; ++i) {
                u = E[i].u; v = E[i].v;
                if(find(u) == find(v)) continue;
                E2[u].push_back(std::make_pair(v, E[i].c));
                E2[v].push_back(std::make_pair(u, E[i].c));
                f[find(u)] = find(v);
        }
}
int q[Max_N], fa[Max_N], cost[Max_N];
void bfs() {
        fa[q[0] = 0] = -1;
        for(int x, ql = 0, qr = 1; ql != qr; ++ql) {
                x = q[ql];
                snuke(it, E2[x]) if(it->first != fa[x]) {
                        q[qr++] = it->first; fa[it->first] = x; cost[it->first] = it->second;
                }
        }
}
int op[Max_Q], qa[Max_Q], qb[Max_Q], qc[Max_Q], ans[Max_Q];
int main() {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 0, u, v, c; i < m; ++i) {
                scanf("%d%d%d", &u, &v, &c);
                has[std::make_pair(--u, --v)] = c;
        }
        for(int i = 0; i < q; ++i) {
                scanf("%d%d%d", op + i, qa + i, qb + i); --qa[i]; --qb[i];
                if(--op[i]) {
                        std::map<std::pair<int,int>, int>::iterator it;
                        it = has.find(std::make_pair(qa[i], qb[i]));
                        qc[i] = it->second;
                        has.erase(it);
                }
        }
        MST(n);
        bfs();
        LCT::init(n, fa, cost);
        for(int i = q-1; i >= 0; --i) {
                if(op[i]) {
                        LCT::link(qa[i], qb[i], qc[i]);
                } else {
                        ans[i] = (LCT::query(qa[i], qb[i]))->val;
                }
        }
        for(int i = 0; i < q; ++i) 
                if(!op[i]) printf("%d\n", ans[i]);
        return 0;
}
