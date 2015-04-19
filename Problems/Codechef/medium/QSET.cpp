#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define lowbit(x) ((x)&(-x))
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
/****head****/
const int Max_N = 9 + (int)1e5;
bool random(int a, int b) {
        return rand() % (a + b) < a;
}
struct Node;
typedef std::pair<Node*, Node*> Droot;
struct Node {
        Node*ch[2];
        int sz, v;
        Node*upd();
        Node*merge(Node*y);
        Droot split(int k);
        int get_rank (int x); 
}Tnull, *null = &Tnull, mem[Max_N<<1], *bat=mem;
Node *Node::upd() {
        if(this != null) sz = ch[0]->sz + ch[1]->sz + 1;
        return this;
}
Node *Node::merge(Node*y) {
        if(!sz) return y;
        if(!y->sz) return this;
        if(random(sz, y->sz)) {
                ch[1] = ch[1]->merge(y);
                return this->upd();
        } else {
                y->ch[0] = this->merge(y->ch[0]);
                return y->upd();
        }
}
Droot Node::split(int k) {
        if(!sz) return std::make_pair(null, null);
        if(k <= ch[0]->sz) {
                Droot ret = ch[0]->split(k);
                ch[0] = ret.second;
                ret.second = this->upd();
                return ret;
        } else {
                Droot ret = ch[1]->split(k - ch[0]->sz - 1);
                ch[1] = ret.first;
                ret.first = this->upd();
                return ret;
        }
}
int Node::get_rank (int x){
        if (!sz) return 0;
        return v < x ? ch[1]->get_rank(x) + ch[0]->sz + 1 : ch[0]->get_rank(x);
}
void init() {
        srand(192737);
        null->ch[0] = null->ch[1] = null;
        null->sz = 0;
}
struct Tree {
        Node*rt;
        Node*newNode(int v) {
                bat->v = v;
                bat->sz = 1; bat->ch[0] = bat->ch[1] = null;
                return bat++;
        }
        void insert(int v) {
                rt = rt->merge(newNode(v));
        }
        Node *split(int v) {
                int k = rt->get_rank(v);
                Droot t = rt->split(k);
                rt = t.first;
                return t.second;
        }
        void merge(Node*y) {
                rt = rt->merge(y);
        }
        int query(int l, int r) {
                int t1 = rt->get_rank(l), t2 = rt->get_rank(r+1);
                return t2 - t1;
        }
} T[10];

void debug(Node*r) {
        if(r == null) return;
        printf("%d : l %d r %d\n", r->v, r->ch[0]==null?-1:r->ch[0]->v, r->ch[1]==null?-1:r->ch[1]->v);
        debug(r->ch[0]); 
        debug(r->ch[1]);
}

int n;
char str[Max_N];
int a[Max_N], c[Max_N];
long long C(long long t) {
        return t * (t-1) / 2;
}
int query(int p) {
        if(p == 0) return 0;
        int ret = 0;
        for(; p <= n; p += lowbit(p)) ret += c[p];
        return ret;
}
void modify(int p, int v) {
        for(; p > 0; p -= lowbit(p)) {
                c[p] += v; if(c[p] >= 3) c[p] -= 3;
        }
}
void add(int l, int r, int v) {
        modify(r, v); modify(l-1, 3-v);
}
int main() {
        //freopen("tst.in","r",stdin);
        //freopen("my.out","w",stdout);
        init();
        for(int i = 0; i < 10; ++i) T[i].rt = null;

        int nq, sum = 0;
        scanf("%d%d%s", &n, &nq, str);

        T[0].insert(0);
        for(int i = 1; i <= n; ++i) {
                a[i] = (str[i-1] - '0') % 3;
                sum = (sum + a[i]) % 3;
                T[sum].insert(i);
        }

        long long res = 0;
        for(int op, l, r, i, t, ta; nq--; ) {
                scanf("%d%d%d", &op, &l, &r);
                if(op == 2) {
                        res = 0;
                        for(i = 0; i < 3; ++i) res += C(T[i].query(l-1, r));
                        printf("%lld\n", res);
                } else {
                        r %= 3;
                        ta = a[l];
                        if(r == ta) continue;
                        for(i = 0; i < 3; ++i) T[i+3].rt = T[i].split(l);
                        //for(i = 3; i < 6; ++i) {
                                //printf("%d %d : \n", i, T[i].rt->sz);
                                //debug(T[i].rt);
                                //puts("");
                        //}
                        t = ((r + 1) % 3 == ta) ? 2 : 1;
                        for(i = 3; i < 6; ++i) T[(i+t)%3].merge(T[i].rt);
                        a[l] = r;
//
                        //puts("\n");
                        //for(i = 0; i < 3; ++i) printf("%d %d\n", i, T[i].rt->sz);
                }
        }
        return 0;
}
