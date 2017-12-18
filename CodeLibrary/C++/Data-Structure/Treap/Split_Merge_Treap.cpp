// based poj 3580
// add some new function
#include <cstdio>
#include <algorithm>
const int inf = ~0u>>2;
namespace Treap{
    const int Max_N = 9 + (int)1e5;
    //int ran(){
        //static unsigned ranx = 654123789;
        //return ranx += ranx<<2|1; 
    //}
    bool random (int a, int b){
        return rand () % (a + b) < a;
    }
    struct Node;
    typedef std::pair<Node*, Node*> Droot;
    struct Node{
        Node *ch[2];
        int sz, v, add, mi;
        bool rev;
        void addIt (int t){
            add += t; mi += t; v += t;
        }
        void revIt (){
            rev ^= 1;
        }
        void relax ();
        Node* upd();
        Droot split (int k);
        Node* remove_by_val(int _v);
        //int get_rank (int x); //查询key <= x的有多少个
    }Tnull, *null=&Tnull, mem[Max_N<<1], *bat, *rt, *stk[Max_N];
    Node *Node::upd (){
        if (this != null){
            sz = ch[0]->sz + ch[1]->sz + 1;
            mi = std::min (v, std::min (ch[0]->mi, ch[1]->mi));
        }
        return this;
    }
    void Node::relax (){
        if (add != 0){
            for (int i = 0; i < 2; ++i){
                if (ch[i] != null) ch[i]->addIt (add);
            }
            add = 0;
        }
        if (rev){
            std::swap (ch[0], ch[1]);
            for (int i = 0; i < 2; ++i){
                if (ch[i] != null) ch[i]->revIt ();
            }
            rev = 0;
        }
    }
    Node *merge (Node *x, Node *y){  //max(x) <= min (y)
        if (!x->sz) return y;
        if (!y->sz) return x;
        if (random (x->sz, y->sz)){
            x->relax ();
            x->ch[1] = merge (x->ch[1], y);
            return x->upd ();
        } else{
            y->relax ();
            y->ch[0] = merge (x, y->ch[0]);
            return y->upd ();
        }
    }
    Droot Node::split (int k){   //max (first) <= min (second)
        if (!sz) return std::make_pair (null, null);
        relax ();
        if (k <= ch[0]->sz){
            Droot ret = ch[0]->split (k);
            ch[0] = ret.second;
            ret.second = this->upd ();
            return ret;
        } else{
            Droot ret = ch[1]->split (k - ch[0]->sz - 1);
            ch[1] = ret.first;
            ret.first = this->upd ();
            return ret;
        }
    }
    //int Node::get_rank (int x){
        //if (!sz) return 0;
        //return key <= x ? ch[1]->get_rank (x) + ch[0]->sz + 1 : ch[0]->get_rank (x);
    //}
    /*
     * slow version find_kth, at least 3 times slower
    Node* find_kth (Node *&r, int k){ //查找第k小, index 1-based
        Droot t1 = r->split (k-1), t2 = t1.second->split (1);
        Node *ret = t2.first;
        r = merge (merge (t1.first, t2.first), t2.second);
        return ret;
    }
    */
    Node* find_kth(Node *r, int K){ //查找第k小, index 1-based
        if(K > r->sz) return null;
        while(1){
            if(r->ch[0]->sz >= K) r = r->ch[0];
            else if(r->ch[0]->sz + 1 < K) {
                K -= r->ch[0]->sz + 1;
                r = r->ch[1];
            } else return r;
        }
    }
    Node* Node::remove_by_val(int _v){  //_v should be in Treap
        if(v == _v){
            return merge(ch[0], ch[1]);
        } else if(v > _v){
            ch[0] = ch[0]->remove_by_val(_v);
        } else {
            ch[1] = ch[1]->remove_by_val(_v);
        }
        return upd();
    }

    /*****************/
    Node *newnod (int v){
        Node *x = bat++;
        x->sz = 1; x->add = x->rev = 0;
        x->mi = x->v = v;
        x->ch[0] = x->ch[1] = null;
        return x;
    }
    void build (int *a, int n){
        //index 0-based, i.e. [0,n)
        Node *x, *last;
        int top = 0;
        for (int i = 0; i < n; ++i){
            x = newnod (a[i]);
            last = null;
            while (top && !random (stk[top-1]->sz, x->sz))
                last = stk[--top]->upd ();
            if (top) stk[top-1]->ch[1] = x;
            x->ch[0] = last;
            stk[top++] = x;
        }
        while (top) stk[--top]-> upd ();
        rt = stk[0];
    }
    void init (){
        srand (192737);
        bat = mem; rt = null;
        null->ch[0] = null->ch[1] = null;
        null->mi = inf;
    }
    void Add (int l, int r, int v){
        Droot t1 = rt->split (l-1), t2 = t1.second->split (r - l + 1);
        t2.first->addIt (v);
        rt = merge (merge (t1.first, t2.first), t2.second);
    }
    void Insert (int x, int y){
        Droot t1 = rt->split (x);
        Node *t = newnod (y);
        rt = merge (merge (t1.first, t), t1.second);
    }
    void Delete (int x){
        Droot t1 = rt->split (x-1), t2 = t1.second->split (1);
        rt = merge (t1.first, t2.second);
    }
    int Query_min (int l, int r){
        Droot t1 = rt->split (l-1), t2 = t1.second->split (r - l + 1);
        int ret = t2.first->mi;
        rt = merge (merge (t1.first, t2.first), t2.second);
        return ret;
    }
    void Reverse (int l, int r){
        Droot t1 = rt->split (l-1), t2 = t1.second->split (r - l + 1);
        t2.first->revIt ();
        rt = merge (merge (t1.first, t2.first), t2.second);
    }
    void Rotate (int l, int r, int x){
        Droot t1 = rt->split (l-1), t2 = t1.second->split (r - l + 1);
        Droot t3 = t2.first->split (r - l + 1 - x);
        rt = merge (merge (merge (t1.first, t3.second), t3.first), t2.second);
    }
}

const int N = 9 + (int)1e5;
int a[N];
char op[10];
int main(){
    Treap::init ();
    int m, n, i; scanf ("%d", &n);
    for (i = 1; i <= n; ++ i) scanf ("%d", a + i); //1...n
    Treap::build (a, n);

    scanf ("%d", &m);
    for (int x, y, z; m--;){
        scanf ("%s%d", op, &x);
        if (op[0] == 'A'){
            scanf ("%d%d", &y, &z);
            Treap::Add (x, y, z);
        } else if (op[0] == 'I'){
            scanf ("%d", &y);
            Treap::Insert (x, y);
        } else if (op[0] == 'D'){
            Treap::Delete (x);
        } else if (op[0] == 'M'){
            scanf ("%d", &y);
            printf ("%d\n", Treap::Query_min (x, y));
        } else if (op[3] == 'E'){
            scanf ("%d", &y);
            Treap::Reverse (x, y);
        } else{
            scanf ("%d%d", &y, &z);
            z %= (y - x + 1);
            if (z < 0) z += y - x + 1;
            Treap::Rotate (x, y, z);
        }
    }
    return 0;
}
