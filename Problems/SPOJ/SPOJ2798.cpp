#include<bits/stdc++.h>
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define snuke(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++it)
const int Max_N = 200009;
namespace LCT{
        struct Node*null, *bat, *memPos;
        struct Node {
                Node*ch[2], *f;
                int sz;
                bool isRoot, state;
                inline bool d() { return this == f->ch[1]; }
                inline void setc(Node*c, int d) { ch[d] = c; c->f = this; }
                inline void modify() { state ^= 1; upd(); }
                inline void splayRoot(Node*fa) { f = fa; isRoot = true; }
                inline void upd() { sz = state + ch[0]->sz + ch[1]->sz; }
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
                int select() {
                        if(!sz) return -1;
                        Node*p = this;
                        for( ; p->ch[0]->sz || !p->state; )
                                p = p->ch[0]->sz ? p->ch[0] : p->ch[1];
                        return p - memPos + 1;
                }
        } Tnull, mem[Max_N];
        void modify(int x) {
                (mem + x)->splay();
                (mem + x)->modify();
        }
        int query(int x) {
                (mem + x)->expose();
                mem->splay();
                return mem->select();
        }
        void newNode(Node*fa) {
                bat->ch[0] = bat->ch[1] = null;
                bat->f = fa;
                bat->sz = 1;
                bat->isRoot = true;
                bat->state = 0;
                bat++;
        }
        void init(int n, int *fa) {
                null = &Tnull;
                null->ch[0] = null->ch[1] = null;
                null->state = 0;
                memPos = bat = mem;
                newNode(null);
                for(int i = 1; i < n; ++i) newNode(mem + fa[i]);
        }
        void debug(int n) {
                for(int i = 0; i < n; ++i)
                        printf("%d isRoot:%d f:%d ch[0]:%d ch[1]:%d\n", i, mem[i].isRoot, mem[i].f-mem, mem[i].ch[0]-mem, mem[i].ch[1]-mem);
        }
}
std::vector<int> E[Max_N];
int q[Max_N], fa[Max_N];
void bfs() {
        fa[q[0] = 0] = -1;
        for(int x, ql = 0, qr = 1; ql != qr; ++ql) {
                x = q[ql];
                snuke(it, E[x]) if(*it != fa[x]) {
                        q[qr++] = *it; fa[*it] = x;
                }
        }
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        int n, q;
        scanf("%d%d", &n, &q);
        for(int u, v, i = 0; i < n-1; ++i) {
                scanf("%d%d", &u, &v);
                E[--u].push_back(--v);
                E[v].push_back(u);
        }
        bfs();
        LCT::init(n, fa);
        for(int op, t; q--; ) {
                scanf("%d%d", &op, &t);
                if(op) printf("%d\n", LCT::query(--t));
                else LCT::modify(--t);
        }
        return 0;
}

