#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
void Read(int &ret){
    ret=0; int c,ok=0;
    for(;;) if ((c=getchar())>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+c-'0',ok=1; else if (ok) return;
}
const int N = 9 + (int)1e5;
struct nod;
struct edge{
    nod *v; edge *nxt;
    void add (nod *_v, edge *n){ v = _v; nxt = n;}
}memo2[N], *stp;
inline void adde (nod *v, edge *&hd){
    stp->add (v, hd); hd = stp++;
}

struct nod{
    nod *ch[26], *f, *belong, *son;
    edge *head;
    int dep, l, pos, sz;
    void clear (){
        son = f = belong = 0;
        head = 0;
        memset (ch, 0, sizeof ch);
    }
}memo[N], *rt, *Q[N];
void trie_init (const int &n){
    rt = memo; stp = memo2;
    for (nod *bat = memo; bat-memo < n; ++ bat) bat->clear ();
}
void AC_init (){
    int ql = 0, qr = 0, c;
    Q[qr++] = rt;
    for (nod *x, *last; ql != qr; ++ ql){
        x = Q[ql];
        if (ql) adde (x, x->f->head);
        for (c = 0; c < 26; ++ c) if (x->ch[c]){
            last = x->f;
            while (last && !last->ch[c]) last = last->f;
            x->ch[c]->f = last ? last->ch[c] : rt;
            Q[qr++] = x->ch[c];
        }
    }
}

int dfs_clock, tot;
void fail_dfs (nod *r){
    r->l = dfs_clock++;
    r->sz = 1;
    nod *id = 0;
    for (edge*p = r->head; p; p = p->nxt){
        p->v->dep = r->dep + 1;
        fail_dfs (p->v);
        r->sz += p->v->sz;
        if (!id || p->v->sz > id->sz) id = p->v;
    }
    r->son = id;
}
void fail_dfs2 (nod *r){
    if (r->son){
        r->son->pos = ++tot;
        r->son->belong = r->belong;
        fail_dfs2 (r->son);
    }
    for (edge *p = r->head; p; p = p->nxt) if (p->v != r->son){
        p->v->belong = p->v;
        p->v->pos = ++tot;
        fail_dfs2 (p->v);
    }
}
void fail_init (){
    tot = dfs_clock = rt->dep = 0; 
    rt->belong = rt;
    fail_dfs (rt);
    rt->pos = ++tot;
    fail_dfs2 (rt);
}

#define lowbit(x) ((x)&(-x))
typedef std::pair<int, long long> pil;
int cnt[N];
long long sum[N];
void insert (nod *x){
    for (int i = x->pos; i <= tot; i += lowbit(i))
        ++cnt[i], sum[i] += x->dep;
}
pil query (int x){
    pil ret; ret.first = ret.second = 0;
    for (; x; x -= lowbit(x))
        ret.first += cnt[x], ret.second += sum[x];
    return ret;
}
pil query (int ql, int qr){
    pil ret; ret.first = ret.second = 0;
    ret = query (qr);
    if (--ql){
        pil tmp = query (ql);
        ret.first -= tmp.first; ret.second -= tmp.second;
    }
    return ret;
}
long long ask (nod *x){
    long long d = x->dep + 1;
    pil ret, tmp; ret.first = ret.second = 0;
    while (x){
        tmp = query (x->belong->pos, x->pos);
        ret.first += tmp.first; ret.second += tmp.second;
        x = x->belong->f;
    }
    return ret.first * d - ret.second;
}

nod *LCA (nod *x, nod *y){
    while (1){
        if (x->dep < y->dep) std::swap (x, y);
        if (x->belong == y->belong) return y;
        if (x->belong->dep < y->belong->dep) std::swap (x, y);
        x = x->belong->f;
    }
    return x;
}
bool cmp (int t1, int t2){
    return memo[t1].l < memo[t2].l;
}
int a[N*5];
void solve (){
    int m; 
    nod *A, *t1, *t2;
    long long ans;
    Read (m);
    memset (cnt, 0, sizeof cnt);
    memset (sum, 0, sizeof sum);
    for (int t, k, j, i = 1; i <= m; ++ i){
        Read (t); Read (k);
        for (j = 0; j < k; ++ j) Read (a[j]), --a[j];
        std::sort (a, a + k, cmp);

        if (t == 1){
            insert (&memo[a[0]]);
            t1 = &memo[a[0]];
            for (j = 1; j < k; ++ j){
                t2 = &memo[a[j]];
                A = LCA (t1, t2);
                if (A != t1) insert (t2), t1 = t2;
            }
        } else{
            ans = ask (&memo[a[0]]);
            t1 = &memo[a[0]];
            for (j = 1; j < k; ++ j){
                t2 = &memo[a[j]];
                A = LCA (t1, t2);
                if (t2 != A) ans += ask (t2) - ask (A);
                t1 = t2;
            }
            printf ("%I64d\n", ans);
        }
    }
}
char* MyStack=new char[33554432];
int main(){
    char* SysStack=NULL;
    MyStack+=33554432-1048576;  //32M
    __asm__
    (
        "movl %%esp,%%eax\n\t"
        "movl %1,%%esp\n\t"
        :"=a"(SysStack)
        :"m"(MyStack)
    );
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    int _; scanf ("%d", &_);
    while (_--){
        int n; Read (n);
        char op[2];
        trie_init (n);
        for (int i = 1, t; i < n; ++ i){
            Read (t); scanf ("%s", op);
            memo[--t].ch[op[0]-'a'] = &memo[i];
        }
        AC_init ();
        fail_init ();
        solve ();
    }
    __asm__
    (
        "movl %0,%%esp\n\t"
       ::"m"(SysStack) 
    );
    return 0;
}
