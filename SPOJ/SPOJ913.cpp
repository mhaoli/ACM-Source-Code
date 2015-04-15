#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 10009;
namespace LCT{
        struct Node*null, *bat, *pos;
        void debug(int n);
        struct Node {
                Node*ch[2], *f;
                int sz, sum, val;
                bool isRoot;
                inline bool d() { return this == f->ch[1]; }
                inline void setc(Node*c, int d) { ch[d] = c; c->f = this; }
                inline void upd() {
                        sz = 1 + ch[0]->sz + ch[1]->sz;
                        sum = val + ch[0]->sum + ch[1]->sum;
                }
                inline void splayRoot(Node*fa) {
                        f = fa; isRoot = true;
                }
                inline void rot() {
                        Node*p = f;
                        int d = this->d();
                        if(p->isRoot) p->isRoot = false, splayRoot(p->f);
                        else p->f->setc(this, p->d());
                        p->setc(ch[!d], d);
                        setc(p, !d);
                        p->upd();
                }
                inline void splay() {
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
                inline int exposeToLca(int K) {
                        for(Node*v = null, *u = this; u != null; v = u, u = u->f) {
                                u->splay();
                                if(u->f == null) {
                                        if (K >= 0) {
                                                if (u->ch[1]->sz >= K) {
                                                        return u->ch[1]->select(u->ch[1]->sz - K + 1) - pos;
                                                } else {
                                                        if (u->ch[1]->sz == K-1) return u - pos;
                                                        return v->select(K - u->ch[1]->sz - 1) - pos;
                                                }

                                        } else{
                                                return v->sum + u->ch[1]->sum;
                                        }
                                }
                                u->ch[1]->isRoot = true;
                                u->setc(v, 1);
                                v->isRoot = false;
                                u->upd();
                        }
                }
                inline Node*select(int K) {
                        Node*res = this;
                        for(; ; ) {
                                if(K <= res->ch[0]->sz) res = res->ch[0];
                                else if(K - 1 == res->ch[0]->sz) return res;
                                else K -= res->ch[0]->sz + 1, res = res->ch[1];
                        }
                }
        } Tnull, mem[Max_N];
        /************/
        inline void newNode(int c, Node*fa) {
                bat->ch[0] = bat->ch[1] = null;
                bat->f = fa;
                bat->sum = bat->val = c;
                bat->sz = 1;
                bat->isRoot = true;
                bat++;
        }
        inline void init(int n, int *fa, int *cost) {
                null = &Tnull;
                null->ch[0] = null->ch[1] = null;
                null->sz = null->sum = 0;
                pos = bat = mem;
                newNode(0, null);
                for(int i = 1; i < n; ++i)
                        newNode(cost[i], mem + fa[i]);
        }
        int queryDist(int x, int y) {
                (mem + x)->expose();
                return (mem + y)->exposeToLca(-1);
        }
        int queryKth(int x, int y, int K) {
                (mem + x)->expose();
                return (mem + y)->exposeToLca(K) + 1;
        }
        void debug(int n) {
                for(int i = 0; i < n; ++i)
                        printf("%d isRoot:%d val:%d f:%d ch[0]:%d ch[1]:%d\n", i, mem[i].isRoot, mem[i].val, mem[i].f-mem, mem[i].ch[0]-mem, mem[i].ch[1]-mem);
        }
}
std::vector<std::pair<int, int> > E[Max_N];
int fa[Max_N], q[Max_N], cost[Max_N];
void bfs() {
        fa[q[0] = 0] = -1;
        for(int x, ql = 0, qr = 1; ql != qr; ++ql) {
                x = q[ql];
                snuke(it, E[x]) if(fa[x] != it->first){
                        q[qr++] = it->first; fa[it->first] = x; cost[it->first] = it->second;
                }
        }
}
int main() {
        int _; scanf("%d", &_);
        for(int n; _--; ) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) E[i].clear();
                for(int u, v, c, i = 0; i < n-1; ++i) {
                        scanf("%d%d%d", &u, &v, &c);
                        E[--u].push_back(std::make_pair(--v, c));
                        E[v].push_back(std::make_pair(u, c));
                }
                bfs();
                LCT::init(n, fa, cost);
                char op[11];
                for(int u, v, c; ; ) {
                        scanf("%s", op);
                        if(op[1] == 'O') break;
                        scanf("%d%d", &u, &v);
                        if(op[1] == 'I') {
                                printf("%d\n", LCT::queryDist(--u, --v));
                        } else {
                                scanf("%d", &c);
                                printf("%d\n", LCT::queryKth(--u, --v, c));
                        }
                }
                puts("");
        }
        return 0;
}
