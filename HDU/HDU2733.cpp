#pragma comment(linker,"/STACK:102400000,102400000")
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
const int inf = ~0u>>1;
const int Max_N = 9 + (int)1e5;
const long long mod = 3 + (long long)1e6;
struct Node;
void Update_Ans (Node*x, Node*y);
typedef std::pair<Node*, Node*> Droot;
void Read(int &ret){
    ret=0; int c,ok=0;
	for(;;) if ((c=getchar()) >= '0' && c <= '9') ret=(ret<<3)+(ret<<1)+c-'0',ok=1; else if (ok) return;
}
void Read(long long &ret){
    ret=0; int c,ok=0;
	for(;;) if ((c=getchar()) >= '0' && c <= '9') ret=(ret<<3)+(ret<<1)+c-'0',ok=1; else if (ok) return;
}

struct Edge{
    int v; Edge *nxt;
    void add (int _v, Edge *n){ v = _v; nxt = n;}
}mem2[Max_N<<1], *stp, *head[Max_N];
void adde (int u, int v){
    stp->add (v, head[u]); head[u] = stp++;
}

bool random (int a, int b){
    return rand () % (a + b) < a;
}
struct Node{
    Node *ch[2];
    int sz, v, id;
    Node* upd ();
    Droot split (int k);
    int get_rank (int k);
}mem[Max_N], *bat, *rt[Max_N], Tnull, *null=&Tnull;
Node* Node::upd (){
    if (this != null){
        sz = ch[0]->sz + ch[1]->sz + 1;
    }
    return this;
}
Node* merge (Node *x, Node *y){
    if (!x->sz) return y;
    if (!y->sz) return x;
    if (random (x->sz, y->sz)){
        x->ch[1] = merge (x->ch[1], y);
        return x->upd ();
    } else{
        y->ch[0] = merge (x, y->ch[0]);
        return y->upd ();
    }
}
Droot Node::split (int k){
    if (!sz) return Droot (null, null);
    if (k <= ch[0]->sz){
        Droot ret = ch[0]->split (k);
        ch[0] = ret.second;
        ret.second = upd ();
        return ret;
    } else{
        Droot ret = ch[1]->split (k - ch[0]->sz - 1);
        ch[1] = ret.first;
        ret.first = upd ();
        return ret;
    }
}

int ID;
long long val[Max_N], inv[mod + 5];
int Node::get_rank (int x){
    if (!sz) return 0;
    if (v == x){
        if (ID == -1) return ID = id;
        return id > ID ? std::swap (id,ID), -1 : ID = id;
    }
    return v <= x ? ch[1]->get_rank(x) + ch[0]->sz + 1 : ch[0]->get_rank (x);
}
Node* New_Node (int id, int v){
    Node *x = bat++;
    x->v = v; x->id = id; x->sz = 1;
    x->ch[0] = x->ch[1] = null;
    return x;
}
Node* insert (Node *x, Node *y){
    if (!y->sz) return x;
    Update_Ans (x, y);
    ID = x->id;
    int k = y->get_rank (x->v);
    if (ID != x->id) return y;
    Droot t1 = y->split (k);
    return merge (merge (t1.first, x), t1.second);
}
Node* Merge_dfs (Node *x, Node *y){
    if (!x->sz) return y;
    y = Merge_dfs (x->ch[0], y);
    y = Merge_dfs (x->ch[1], y);
    x->ch[0] = x->ch[1] = null;
    x->sz = 1;
    return insert (x, y);
}
Node* Merge (Node *x, Node *y){
    if (!y->sz) return x;
    if (x->sz > y->sz) std::swap (x, y);
    return Merge_dfs (x, y);
}

std::pair<int, int> ans, tmp;
int tar, TAR;

void Update_Ans (Node *x, Node *y){
    ID = -1;
    y->get_rank (TAR * inv[x->v] % mod);
    if (ID != -1){
        tmp.first = ID; tmp.second = x->id;
        if (tmp.first > tmp.second) std::swap (tmp.first, tmp.second);
        ans = std::min (ans, tmp);
    }
}
void dfs (int x, int pre){
    int t = val[x], xt; 
    if (pre != -1) val[x] = val[pre] * val[x] % mod;
    rt[x] = null;
    xt = inv[(inv[val[x]] * inv[val[x]] % mod) * t % mod] * tar % mod;
    for (Edge*p = head[x]; p; p = p->nxt) if (p->v != pre){
        dfs (p->v, x);
        TAR = xt;
        rt[x] = Merge (rt[p->v], rt[x]);
    }
    TAR = xt;
    rt[x] = insert (New_Node (x, val[x]), rt[x]);
}

void init (const int &n){
    memset (head, 0, (n+5) * sizeof (Edge*));
    stp = mem2;
    bat = mem;
    ans = std::make_pair (inf, inf);
}
int main(){
    srand (192737);
    null->ch[0] = null->ch[1] = null;
    inv[1] = 1;
    register int i = 2;
    for (int t, k; i < mod; ++ i){
        t = mod / i; k = mod - t * i; 
        inv[i] = ((long long)i * t % mod) * t % mod;
        inv[i] = (inv[i] * inv[k] % mod) * inv[k] % mod;
    }

    for (int n, u, v; scanf ("%d", &n) != EOF; ){
        Read (tar);
        for (i = 0; i < n; ++i) Read (val[i]);
        init (n);
        for (i = 0; i < n-1; ++i){
            Read (u); Read (v);
            adde (--u, --v); adde (v, u);
        }
        dfs (0, -1);
        if (ans.first == inf) puts ("No solution");
        else printf ("%d %d\n", ans.first + 1, ans.second + 1);
    }
    return 0;
}
