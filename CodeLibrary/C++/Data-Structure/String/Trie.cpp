namespace Trie {
        struct node {
                //-------------------------sz of son
                node *son[2];
                int sz;
                void clear(){
                        sz = 0; clr(son);
                }
                void dfs() {
                        rep(i, 0, 2) if(son[i] != 0){
                                son[i]->dfs();
                                sz += son[i]->sz;
                        }
                }
                node *go(int c);
        };
        node memo[35*300000], *rt, *bat;
        void newNode(node*&o) {
                bat->clear(); o = bat++;
        }
        node *node::go(int c) {
                if(son[c] == 0) newNode(son[c]);
                return son[c];
        }
        void clear() {
                bat = memo; bat->clear(); rt = bat++;
        }
        void insert(int *s, int n) {
                node *x = rt;
                rep(i, 0, n) x = x->go(s[i]);
                x->sz = 1;
        }
        vi find(int *s, int n) {
                vi res;
                node *x = rt, *y = x;
                rep(i, 0, n) {
                        y = x;
                        x = x->son[s[i]];
                        res.pb(y->sz - x->sz);
                }
                return res;
        }
}
