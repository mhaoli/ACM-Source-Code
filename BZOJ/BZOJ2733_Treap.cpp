//bzoj 2733
#include<bits/stdc++.h>
namespace Treap{
    const int Max_N = 9 + (int)1e5;
    bool random (int a, int b){
        return rand () % (a + b) < a;
    }
    struct Node;
    typedef std::pair<Node*, Node*> Droot;
    struct Node{
        Node *ch[2];
        int sz, v;
        int get_rank (int x);
        Node* upd ();
        Droot split (int k);
    }mem[Max_N], Tnull, *null=&Tnull, *bat=mem, *rt[Max_N];
    Node* Node::upd (){
        if (this != null){
            sz = 1 + ch[0]->sz + ch[1]->sz;
        }
        return this;
    }
    Node* New_Node (int v){
        Node *x = bat++;
        x->ch[0] = x->ch[1] = null;
        x->sz = 1; x->v = v;
        return x;
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
    int Node::get_rank (int x){
        if (!sz) return 0;
        return v <= x ? ch[1]->get_rank(x) + ch[0]->sz + 1 : ch[0]->get_rank (x);
    }
    Node* find_kth (Node *r, int k){ //查找第k小
        Droot t1 = r->split (k-1), t2 = t1.second->split (1);
        Node *ret = t2.first;
        r = merge (merge (t1.first, t2.first), t2.second);
        return ret;
    }
    /***************************/
    void insert (Node *&r, Node *x){
        int k = r->get_rank (x->v);
        Droot t = r->split (k);
        r = merge (merge (t.first, x), t.second);
    }
    void merge_dfs (Node *x, Node *&y){
        if (!x->sz) return;
        merge_dfs (x->ch[0], y);
        merge_dfs (x->ch[1], y);

        x->ch[0] = x->ch[1] = null;
        x->sz = 1;
        insert (y, x);
    }
    void init (){
        srand (192737);
        null->ch[0] = null->ch[1] = null;
    }

    void Merge (int t1, int t2, int *f){
        if (rt[t1]->sz > rt[t2]->sz) std::swap (t1, t2);
        f[t1] = t2;
        merge_dfs (rt[t1], rt[t2]);
    }
    int Query (int x, int v){
        if (v > rt[x]->sz) return -1;
        Droot t1 = rt[x]->split (v-1), t2 = t1.second->split (1);
        int ret = t2.first - mem + 1;
        rt[x] = merge (merge (t1.first, t2.first), t2.second);
        return ret;
    }
}
const int Max_N = 9 + (int)1e5;
int f[Max_N];
int find (int x){
    return x == f[x] ? x : f[x] = find (f[x]);
}
int main(){
    //freopen("tst.in","r",stdin);
    //freopen("my.out","w",stdout);
    Treap::init ();
    int n, m; scanf ("%d%d", &n, &m);
    for (int i = 0, t; i < n; ++i){
        scanf ("%d", &t);
        Treap::rt[i] = Treap::New_Node (t);
        f[i] = i;
    }
    for (int i = 0, u, v; i < m; ++i){
        scanf ("%d%d", &u, &v);
        if (find (--u) != find (--v)){
            Treap::Merge (find (u), find (v), f);
        }
    }
    char op[10];
    int q, u, v;
    for (scanf ("%d", &q); q--; ){
        scanf ("%s%d%d", op, &u, &v);
        if (op[0] == 'Q'){
            printf ("%d\n", Treap::Query (find (--u), v));
        } else{
            if (find (--v) != find (--u)){
                Treap::Merge (find(v), find(u), f);
            }
        }
    }
    return 0;
}
