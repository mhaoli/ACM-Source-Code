//Uva 12538
#include<bits/stdc++.h>
namespace Treap{
    bool random (int a, int b){
        return rand () % (a + b) < a;
    }
    struct Node;
    typedef std::pair<Node*, Node*> Droot;
    const int Max_N = 9 + (int)1e6;
    struct Node{
        Node *ch[2];
        int sz;
        char c;
        Node* upd ();
        Droot split (int k);
    }memo[Max_N*20], *bat, *rt[Max_N], Tnull, *null=&Tnull;
    Node* Node::upd (){
        if (this != null){
            sz = ch[0]->sz + ch[1]->sz + 1;
        }
        return this;
    }
    Node* New_Node (char c){
        Node *x = bat++;
        x->ch[0] = x->ch[1] = null;
        x->c = c; x->sz = 1;
        return x;
    }
    Node* New_Node (Node *x){
        *bat = *x; return bat++;
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
            Droot ret = New_Node(ch[0])->split (k);
            ch[0] = ret.second;
            ret.second = upd ();
            return ret;
        } else{
            Droot ret = New_Node(ch[1])->split (k - ch[0]->sz - 1);
            ch[1] = ret.first;
            ret.first = upd ();
            return ret;
        }
    }
    /*************************/
    void init (){ //version numbered from 1
        srand (192737);
        null->ch[0] = null->ch[1] = null;
        null->sz = 0; null->c = 0;
        bat = memo; rt[0] = null;
    }
    Node* build (char *s, int l, int r){
        if (l > r) return null;
        int m = l + r >> 1;
        Node *x = New_Node (s[m]);
        x->ch[0] = build (s, l, m-1);
        x->ch[1] = build (s, m+1, r);
        return x->upd ();
    }
    void Insert (int v, int p, Node *x){
        rt[v] = New_Node (rt[v-1]);
        //printf ("%d %d %c\n", v, p, x->c);
        Droot ret = rt[v]->split (p);
        rt[v] = merge (merge (ret.first, x), ret.second);
        rt[v]->upd ();
    }
    void Delete (int v, int p, int l){
        rt[v] = New_Node (rt[v-1]);
        Droot t1 = rt[v]->split (p-1), t2 = t1.second->split (l);
        rt[v] = merge (t1.first, t2.second);
        rt[v]->upd ();
    }
    int top;
    char ans[Max_N];
    void dfs (Node *x, int &flag){
        if (x == null) return ;
        dfs (x->ch[0], flag); 
        if ((ans[top++] = x->c) == 'c') ++flag;
        dfs (x->ch[1], flag);
    }
    void Query (int v, int p, int l, int &flag){
        Droot t1 = New_Node (rt[v])->split (p-1), t2 = t1.second->split (l);
        top = 0;
        dfs (t2.first, flag);
        ans[top] = 0;
        puts (ans);
    }
}
const int N = 9 + (int)1e6;
int flag;
char str[N];
int main(){
    Treap::init ();
    int _, op, p, v, l, cnt = 1;
    scanf ("%d", &_);
    for (; _--; ){
        scanf ("%d", &op);
        if (op == 1){
            scanf ("%d%s", &p, str);
            Treap::Insert (cnt++, p - flag, Treap::build (str, 0, strlen (str) - 1));
        } else if (op == 2){
            scanf ("%d%d", &p, &l);
            Treap::Delete (cnt++, p - flag, l - flag);
        } else{
            scanf ("%d%d%d", &v, &p, &l);
            Treap::Query (v - flag, p - flag, l - flag, flag); 
        }
    }
    return 0;
}
